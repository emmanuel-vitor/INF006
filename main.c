#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <locale.h>

int main(){

setlocale(LC_ALL, "Portuguese");

	carregarArquivoDeCompras();
	carregarArquivoDeVendas();


	int op;

	while(1){
		printf("\nBem-vindo ao Mercado Simulado de Ações\n");
		printf("\n1 - Listar ofertas\n");
		printf("\n2 - Inserir ofertas\n");
		printf("\n3 - Negociar ofertas\n");
		printf("\n4 - Sair\n");
		
		scanf("%d",&op);
		switch(op){

			case 1:
			listarOfertas();
			break;
			case 2:
			addOfertas();
			break;
			case 3:
			negociarOfertas();
			break;
			case 4:
			finalizar();
			break;
			default:
			printf("Escolha Inválida.");
			break;
		}
	}
	return 0;

}
