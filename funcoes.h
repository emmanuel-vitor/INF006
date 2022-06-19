#ifndef FUNCOES_H
#define FUNCOES_H

// definição de valores no menu
#define VENDA 1
#define COMPRA 2

#define SIM 1
#define NAO 2

#define PETR4 1
#define VALE5 2
#define USIM5 3
#define VOLTAR 4
#define ARQUIVO 5

// Structs dos nós
typedef struct Compra {
	int papelCompra;
    int acoesCompra;
    float precoCompra;
    struct Compra *proximaCompra;
} Compra;

typedef struct Venda {
	int papelVenda;
    int acoesVenda;
    float precoVenda;
    struct Venda *proximaVenda;
} Venda;

// chamadas de funções
int menu();
void carregarArquivoDeCompras();
void carregarArquivoDeVendas();
void finalizar();
void addOfertas();
void addVenda();
void addCompra();
void listarOfertas();
void listarPETR4();
void listar_VALE5();
void listar_USIM5();
void buscarArquivosDeCompra();
void buscarArquivosDeVenda();
void salvarArquivosDeCompra();
void salvarArquivosDeVenda();
void ordenarVendas();
void ordenarCompras();
void selecionarArquivos();
void negociarOfertas();
void popularListaDeCompras(int papel, int acoes, float preco);
void popularListaDeVendas(int papel, int acoes, float preco);
void excluirfertas(int posicao_venda, int valor_venda, int posicao_compra, int valor_compra);

#endif
