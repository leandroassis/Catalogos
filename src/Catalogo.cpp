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

    fstream arquivo;

    arquivo.open("filmes.csv", ios::in);

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo. Verifique se o arquivo \'filmes.csv\' está no mesmo diretório que esse executável." << endl;
        exit(1);
    }

    string nomeFilme, produtoraFilme, notaFilme;

    while(!arquivo.eof()){

        getline(arquivo, nomeFilme, ';');
        getline(arquivo, produtoraFilme, ';');
        getline(arquivo, notaFilme);

        Filme filme;

        filme.nome = nomeFilme;
        filme.produtora = produtoraFilme;
        filme.nota = std::stod(notaFilme);

        insereFilme(filme);
    }

    arquivo.close();
}

Catalogo::~Catalogo(){
    fstream arquivo;

    arquivo.open("filmes.csv", ios::out);

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo." << endl;
        exit(1);
    }

    for(auto filme : this->filmes){
        arquivo << filme.nome << ";" << filme.produtora << ";" << filme.nota << endl;
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
        if(indice == -1) return -1; // se não conseguir inserir, retorna -1
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

int Catalogo::operator()(string nomeFilme){
    int indice = 0;

    for(auto filme : this->filmes){
        if(filme.nome == nomeFilme) return indice;
        indice++;
    }

    return -1;
}

// funções auxiliares
int Catalogo::verificaFilme(const Filme &filme){
    int indice = 0;
    // percorre o catalogo inteiro
    for(auto filmeCatalogo : this->filmes){
        // verifica se o filme ja existe
        if(filmeCatalogo == filme){
            cout << "O filme já existe no catalogo." << endl;
            return indice;
        }
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
        if(verificaFilme(filme) != -1) return -1;
        
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