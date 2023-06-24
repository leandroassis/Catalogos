#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Filme.h"

using namespace std;

class Catalogo{
    friend ostream &operator<<(ostream &, const Catalogo &);

    public:
        Catalogo(unsigned = 100);
        ~Catalogo();

        // operadores

        // +=
        int operator+=(const Filme &);
        int operator+=(const vector<Filme> &);

        // -=
        int operator-=(const Filme &);

        // ()
        int operator()(string);


        
    private:
        vector<Filme> filmes;
        unsigned tamanhoMaximo;

        // funções auxiliares
        int verificaFilme(const Filme &);
        int insereFilme(const Filme &);
};