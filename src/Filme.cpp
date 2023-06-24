#include "Filme.h"

ostream &operator<<(ostream &out, const Filme &filme){
    out << "Nome: " << filme.nome << endl;
    out << "Produtora: " << filme.produtora << endl;
    out << "Nota: " << fixed << setprecision(2) << filme.nota << endl;
    
    return out;
}

istream &operator>>(istream &in, Filme &filme){
    string _nome;
    double _nota;

    cout << "Nome: ";
    getline(in, _nome);

    filme.nome = verificaNomeFilme(_nome);
    
    cout << "Produtora: ";
    getline(in, _nome);

    filme.produtora = verificaProdutora(_nome);
    
    cout << "Nota: ";
    in >> _nota;

    filme.nota = verificaNota(_nota);
    
    return in;
}

double verificaNota(double nota){
    if(nota >= 0 && nota <= 10)
        return nota;
    else{
        cout << "Nota inválida. Nota será setada para 0." << endl;
        return 0.0;
    }
}

string verificaNomeFilme(string nome){
    if(nome == "" || nome == " "){
        cout << "Nome inválido. Nome será setado para 'Sem nome'" << endl;
        return "Sem nome";
    }
    else if(nome.length() <= 25)
        return nome;
    else{
        string nome_cortado = nome.substr(0, 25);
        cout << "Nome inválido. Nome será setado para " << nome_cortado << endl;
        return nome_cortado;
    }
}

string verificaProdutora(string produtora){
    if(produtora == "" || produtora == " "){
        cout << "Produtora inválida. Produtora será setada para 'Sem produtora'" << endl;
        return "Sem produtora";
    }
    else if(produtora.length() <= 25)
        return produtora;
    else{
        string produtora_cortada = produtora.substr(0, 25);
        cout << "Produtora inválida. Produtora será setada para " << produtora_cortada << endl;
        return produtora_cortada;
    }
}

bool operator==(const Filme &filme1, const Filme &filme2){
    if(!filme1.nome.compare(filme2.nome)) return true;
    
    return false;
}

bool operator<(const Filme &filme1, const Filme &filme2){
    if(filme1.nome.compare(filme2.nome) < 0) return true;
    
    return false;
}

bool ordenacaoCrescente(Filme i1, Filme i2){
    return (i1 < i2);
}

bool operator>(const Filme &filme, double nota){
    return (filme.nota > nota);
}