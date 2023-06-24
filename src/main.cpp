#include "Filme.h"
#include "Catalogo.h"

int main(int argc, char *argv[]){

    Catalogo catalogo;
    int opcao, status, indice;
    vector<Filme> filmes;
    Filme filme;
    string arquivoFilmes, nome, novoNome, novaProdutora;
    double novaNota;

    if(argc != 2){
        cout << "Uso: " << argv[0] << " <opção>" << endl;
        cout << "Opções:" << endl;
        cout << "1 - Imprimir catálogo." << endl;
        cout << "2 - Inserir filme." << endl;
        cout << "3 - Inserir vários filmes." << endl;
        cout << "4 - Remover filme." << endl;
        cout << "5 - Encontrar filme." << endl;
        cout << "6 - Alterar filme." << endl;
        cout << "7 - Buscar filme mais bem avaliado." << endl;
        return 1;
    }

    try{
        opcao = stoi(argv[1]);
    }
    catch(invalid_argument &e){
        cout << "Opção \"" <<argv[1] << "\" inválida." << endl;
        return 1;
    }

    switch(opcao){
        case 1:
            // imprime o catalogo usando << sobrecarregado
            cout << catalogo;
            break;
        case 2:
            // insere um filme usando += sobrecarregado
            
            cin >> filme;

            if((catalogo += filme) != -1) cout << "Filme inserido com sucesso." << endl;
            else{
                cout << "Erro ao inserir filme." << endl;
                return 1;
            }
            break;
        case 3:
            // insere vários filmes usando += sobrecarregado
            // os filmes são lidos de um arquivo
            
            // lê o nome do arquivo
            cout << "Digite o nome do arquivo: ";
            cin >> arquivoFilmes;

            // lê os filmes do arquivo
            status = leFilmes(arquivoFilmes, filmes);

            // insere os filmes no catálogo através do += sobrecarregado para vetores
            if(status) indice = (catalogo += filmes);
            else{
                cout << "Saindo..." << endl;
                return 1;
            }
            
            if((unsigned) indice == filmes.size()) cout << "Filmes inseridos com sucesso." << endl;
            else cout << "Filmes inseridos até o indice " << indice << "."<< endl;
            break;
        case 4:
            // remove um filme usando -= sobrecarregado
            cin >> filme;

            if((catalogo -= filme) == -1){
                cout << "Erro ao remover filme." << endl;
                return 1;
            }
            cout << "Filme removido com sucesso." << endl;
            break;
        case 5:
            // encontra um filme usando () sobrecarregado

            cout << "Digite o nome do filme: ";
            getline(cin, nome);

            if((catalogo(nome)) == -1){
                cout << "Erro ao encontrar filme." << endl;
                return 1;
            }

            cout << "Filme encontrado com sucesso." << endl;
            break;
        case 6:
            // altera um filme usando () sobrecarregado

            cout << "Digite o nome do filme: ";
            getline(cin, nome);

            cout << "Qual atributo deseja alterar?" << endl;
            cout << "1 - Nome" << endl;
            cout << "2 - Produtora" << endl;
            cout << "3 - Nota" << endl;
            opcao = getchar();

            switch(opcao){
                case '1':
                    cout << "Digite o novo nome: ";
                    cin.ignore();
                    getline(cin, novoNome);

                    if((catalogo(nome, "nome", novoNome)) == -1){
                        cout << "Erro ao alterar filme." << endl;
                        return 1;
                    }
                    break;
                case '2':
                    cout << "Digite a nova produtora: ";
                    cin.ignore();
                    getline(cin, novaProdutora);

                    if((catalogo(nome, "produtora", novaProdutora)) == -1){
                        cout << "Erro ao alterar filme." << endl;
                        return 1;
                    }
                    break;
                case '3':
                    cout << "Digite a nova nota: ";
                    cin >> novaNota;

                    if((catalogo(nome, "nota", novaNota)) == -1){
                        cout << "Erro ao alterar filme." << endl;
                        return 1;
                    }
                    break;
                default:
                    cout << "Opção \"" << opcao << "\" inválida." << endl;
                    return 1;
            }
            
            cout << "Filme alterado com sucesso." << endl;
            catalogo(nome);
            break;
        case 7:
            break;
        default:
            break;
    }

    return 0;
}