#include <bits/stdc++.h>
#include "Catalogo.h"

// funções externas
ostream &operator<<(ostream &out, const Catalogo &catalogo){
    out << "Catalogo: " << endl;
    
    for(auto file : catalogo.filmes) out << file << endl;
    
    return out;
}

// funções membro
Catalogo::Catalogo(unsigned tamanhoMaximo){
    this->tamanhoMaximo = tamanhoMaximo;

    this->filmes.reserve(tamanhoMaximo);

    vector<Filme> filmes;

    int status = leFilmes("filmes.csv", filmes);
    
    if(status) *this += filmes;
    else exit(1);
}

Catalogo::~Catalogo(){
    fstream arquivo;

    arquivo.open("filmes.csv", ios::out);

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo." << endl;
        exit(1);
    }

    for(auto filme : this->filmes){
        arquivo << filme.nome << ";" << filme.produtora << ";" << filme.nota;
        if(filme.nome != this->filmes.back().nome) arquivo << endl;
    }

    arquivo.close();
}

int Catalogo::operator+=(const Filme &filme){
    int indice = 0;

    indice = insereFilme(filme);

    return indice;
}

int Catalogo::operator+=(const vector<Filme> &filmes){
    int indice = 0;

    // tenta inserir cada filme do vetor
    for(auto filme : filmes){
        indice = insereFilme(filme);
        if(indice == -1) cout << "O filme " << filme.nome << " não foi inserido." << endl;
    }

    return indice; // retorna indice do último filme adicionado
}

int Catalogo::operator-=(const Filme &filme){
    int indice = 0;

    indice = verificaFilme(filme);


    if(indice == -1){
        cout << "O filme não existe no catalogo." << endl;
        return -1;
    }

    this->filmes.erase(this->filmes.begin() + indice);
    return indice;
}

int Catalogo::operator()(string nomeFilme, int show){
    int indice = 0;

    for(auto filme : this->filmes){
        if(filme.nome == nomeFilme){
            if(show) cout << filme;
            return indice;
        }
        indice++;
    }

    return -1;
}

int Catalogo::operator()(string nomeFilme, string nomeAtribuito, string NovoAtributo){
    
    // primeiro verifica o atributo
    if(nomeAtribuito != "nome" && nomeAtribuito != "produtora"){
        cout << "Atributo inválido." << endl;
        return -1;
    }

    // procura o filme
    int indice = this->operator()(nomeFilme, 0);

    if(indice == -1){
        cout << "O filme não existe no catalogo." << endl;
        return -1;
    }

    // verifica se não existe um filme com o novo atributo, caso seja nome
    if(nomeAtribuito == "nome"){
        if(this->operator()(NovoAtributo) != -1){
            cout << "Já existe um filme com esse nome." << endl;
            return -1;
        }
    }

    // altera o atributo
    if(nomeAtribuito == "nome") this->filmes[indice].nome = verificaNomeFilme(NovoAtributo);
    else this->filmes[indice].produtora = verificaProdutora(NovoAtributo);

    return indice;
}

int Catalogo::operator()(string nomeFilme, string nomeAtribuito, double notaFilme){
    // primeiro verifica o atributo
    if(nomeAtribuito != "nota"){
        cout << "Atributo inválido." << endl;
        return -1;
    }

    // procura o filme
    int indice = this->operator()(nomeFilme, 0);

    if(indice == -1){
        cout << "O filme não existe no catalogo." << endl;
        return -1;
    }

    // altera o atributo
    this->filmes[indice].nota = verificaNota(notaFilme);

    return indice;
}

// funções auxiliares
int Catalogo::verificaFilme(const Filme &filme){
    int indice = 0;
    // percorre o catalogo inteiro
    for(auto filmeCatalogo : this->filmes){
        // verifica se o filme ja existe
        if(filmeCatalogo == filme){
            cout << "O filme existe no catalogo." << endl;
            return indice;
        }
        indice++;
    }

    // se não existe retorna -1
    return -1;
}

int Catalogo::insereFilme(const Filme &filme){
    int indice = 0;
    
    // se for o primeiro filme, insere
    if(this->filmes.size() == 0){
        this->filmes.push_back(filme);
        return 0;
    }

    // verifica se o catalogo não está cheio
    if((this->filmes.size() < this->tamanhoMaximo)){
        // se achar o filme no catalogo
        if(verificaFilme(filme) != -1){
            cout << "Tentando inserir filme repetido." << endl;
            return -1;
        }
        
        // se não achar, insere
        this->filmes.push_back(filme);
        sort(this->filmes.begin(), this->filmes.end(), ordenacaoCrescente); // ordena

        // retorna o indice do filme inserido
        for(auto filmeCatalogo : this->filmes){
            if(filmeCatalogo == filme) return indice;
            indice++;
        }
    }
    
    cout << "Catalogo cheio. Não é possível adicionar mais filmes." << endl;
    return -1;
}

// funções externas

int leFilmes(string nomeArquivo, vector<Filme> &filmes){
    fstream arquivo;

    arquivo.open(nomeArquivo, ios::in);

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo. Verifique se o arquivo \'" << nomeArquivo << "\' está no mesmo diretório que esse executável, ou passe o path completo." << endl;
        return 0;
    }

    string nomeFilme, produtoraFilme, notaFilme;

    while(!arquivo.eof()){

        getline(arquivo, nomeFilme, ';');
        getline(arquivo, produtoraFilme, ';');
        getline(arquivo, notaFilme);

        Filme filme;

        try{    
            filme.nome = nomeFilme;
            filme.produtora = produtoraFilme;
            filme.nota = std::stod(notaFilme);
        }
        catch(...){
            cout << "Erro ao ler o arquivo." << endl;
            cout << "Certifique-se que o arquivo possui o formato correto." << endl;
            cout << "O formato deve ser: <nome>;<produtora>;<nota>" << endl;
            arquivo.close();
            return 0;
        }
        
        filmes.push_back(filme);
    }

    arquivo.close();
    return 1;
}