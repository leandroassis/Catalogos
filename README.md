# Especificações de uso

### 1. Compilação
Basta rodar o comando `make` na pasta raiz do projeto. Isso irá gerar o executável `catalogo` na raiz do projeto. Para limpar os arquivos gerados pela compilação, basta rodar o comando `make clean`.

### 2. Execução
Para executar o projeto basta rodar o executável `catalogo`. É necessário especificar através da linha de comando qual opção será executada. As opções são:

        |Cod| Operação |
        |1| Imprime o catálogo |
        |2| Insere um filme a partir das entradas do usuário |
        |3| Insere vários filmes a partir do arquivo de entrada especificado |
        |4| Remove um filme a partir das entradas do usuário |
        |5| Procura um filme a partir das entradas do usuário |
        |6| Altera um atributo do filme especificado pelo usuário |
        |7| Procura no catálogo o filme mais bem avaliado |

O arquivo que mantém a persistência dos filmes é o `filmes.csv`, é possível modificar o path do arquivo dentro do construtor da classe Catalogo no arquivo Catalogo.cpp. 

O arquivo `novosfilmes.csv` contém uma sugestão para filmes que serão inseridos no catálogo quando a opção 3 for selecionada..

```
./catalogo <opção>
```
O comando acima irá executar o programa com a opção escolhida.