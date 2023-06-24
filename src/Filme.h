#pragma once

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

typedef struct{
    string nome;
    string produtora;
    double nota;
    
} Filme;


ostream &operator<<(ostream &, const Filme &);
istream &operator>>(istream &, Filme &);
bool operator==(const Filme &, const Filme &);
bool operator<(const Filme &, const Filme &);
bool operator>(const Filme &, double);

// funções auxiliares
double verificaNota(double);
string verificaNomeFilme(string);
string verificaProdutora(string);
bool ordenacaoCrescente(Filme, Filme);