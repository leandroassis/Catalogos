#include "Filme.h"
#include "Catalogo.h"

int main(int argc, char *argv[]){

    Filme filme, filme2;
    Catalogo catalogo;

    filme.nome = "O Poderoso Chefão";
    filme.produtora = "Paramount Pictures";
    filme.nota = 9.2;

    filme2.nome = "O Poderoso Chefao 2";
    filme2.produtora = "Paramount Pictures";
    filme2.nota = 9.0;

    cout << filme << endl;

    cout << filme2 << endl;

    catalogo += filme;
    catalogo -= filme2;

    cout << catalogo("O Poderoso Chefão") << endl;

    return 0;
}