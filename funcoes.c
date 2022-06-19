#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "funcoes.h"


struct Compra *cabecoteCompra = NULL;
struct Venda *cabecoteVenda = NULL;

int menu(){

setlocale(LC_ALL,"Portuguese_Brasil.1252");
  
	int op;

	while(1){
		printf("\nBem-vindo ao Mercado Simulado de Ações\n");
		printf("\n1 - Listar ofertas\n");
		printf("\n2 - Incluir ofertas\n");
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


void addOfertas(){

	int escolha;
	printf("\nDeseja incluir uma compra ou uma venda?\n1 - Venda\n2 - Compra\n");
	scanf("%d", &escolha);


	while(escolha!= COMPRA && escolha != VENDA){
		printf("\nOpção inválida.");
		printf("\nDeseja incluir uma compra ou uma venda?\n 1 - Venda\n 2 - Compra\n");
		scanf("%d", &escolha );
	}
	
	if(escolha == VENDA){
		addVenda();
	}
	if(escolha == COMPRA){
		addCompra();
	}
}


void listarOfertas() {

	int escolha;

    printf("\nQuais ações deseja visualizar?\n");
	printf("1 - PETR4\n");
	printf("\n2 - VALE5\n");
	printf("\n3 - USIM5\n");
	printf("\n4 - Voltar\n");
	printf("\n5 - Ver arquivo\n");
	scanf("%d", &escolha);


	while(escolha != PETR4 && escolha != VALE5 && escolha != USIM5 && escolha != ARQUIVO && escolha != VOLTAR){

		printf("\nOpção inválida.\n");
		printf("\nQuais ações deseja visualizar?\n");
		printf("\n 1 - PETR4 \n");
		printf("\n 2 - VALE5 \n");
		printf("\n 3 - USIM5 \n");
		printf("\n 4 - Voltar \n");
		printf("\n 5 - Ver arquivo \n");
		scanf("%d", &escolha);

	}

	switch(escolha){

		case PETR4:
		listarPETR4();
		break;
		case VALE5:
		listar_VALE5();
		break;
		case USIM5:
		listar_USIM5();
		break;
		case VOLTAR:
		menu();
		break;
		case ARQUIVO:
		selecionarArquivos();
		break;
		default:
		break;
	}

}

void listarPETR4(){

	struct Venda *vendaAtual = cabecoteVenda;
	struct Compra *compraAtual = cabecoteCompra;

	if(cabecoteVenda == NULL || cabecoteCompra == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}else{
		printf("**************************** Cotações ***************************\n\n");
   printf("| SIGLA |  TIPO |QTD | PRECO |");
   printf("\t\t| SIGLA |  TIPO |QTD | PRECO |");
		while(compraAtual != NULL && vendaAtual != NULL) {
	
				printf("\n");
			if(compraAtual->papelCompra == PETR4) {
				
				printf("| PETR4 | COMPRA | %d | %.2f |\n", compraAtual->acoesCompra, compraAtual->precoCompra);
			
			}

			if(vendaAtual->papelVenda == PETR4) {
			
				printf("\t\t\t\t\t\t\t\t\t| PETR4 | VENDA | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);
			
			}

			if(vendaAtual != NULL){
				vendaAtual = vendaAtual->proximaVenda;
			}

			if(compraAtual != NULL){
				compraAtual = compraAtual->proximaCompra;
			}
		}
	}
	menu();


}

void listar_VALE5(){

	struct Venda *vendaAtual = cabecoteVenda;
	struct Compra *compraAtual = cabecoteCompra;

	if(cabecoteVenda == NULL || cabecoteCompra == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}else{
		printf("**************************** Cotações ***************************\n\n");
     printf("| SIGLA |  TIPO |QTD | PRECO |");
     printf("\t\t| SIGLA |  TIPO |QTD | PRECO |");
		while(compraAtual != NULL && vendaAtual != NULL) {
				
			if(compraAtual->papelCompra == VALE5) {
				
				printf("| VALE5 | COMPRA | %d | %.2f |\n", compraAtual->acoesCompra, compraAtual->precoCompra);
			
			}

			if(vendaAtual->papelVenda == VALE5) {
			
				printf("\t\t\t\t\t\t\t\t\t| VALE5 | VENDA | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);
			
			}

			if(vendaAtual != NULL){
				vendaAtual = vendaAtual->proximaVenda;
			}

			if(compraAtual != NULL){
				compraAtual = compraAtual->proximaCompra;
			}
		}
	}
	menu();

}

void listar_USIM5(){


	struct Venda *vendaAtual = cabecoteVenda;
	struct Compra *compraAtual = cabecoteCompra;

	if(cabecoteVenda == NULL || cabecoteCompra == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}else{
		printf("**************************** Cotações ***************************\n\n");
     printf("| SIGLA |  TIPO |QTD | PRECO |");
     printf("\t\t| SIGLA |  TIPO |QTD | PRECO |");
		while(compraAtual != NULL && vendaAtual != NULL) {
				
			if(compraAtual->papelCompra == USIM5) {
				
				printf("| USIM5 | COMPRA | %d | %.2f |\n", compraAtual->acoesCompra, compraAtual->precoCompra);
				
			}

			if(vendaAtual->papelVenda == USIM5) {
				
				printf("\t\t\t\t\t\t\t\t\t| USIM5 | VENDA | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);
				
			}

			if(vendaAtual != NULL){
				vendaAtual = vendaAtual->proximaVenda;
			}

			if(compraAtual != NULL){
				compraAtual = compraAtual->proximaCompra;
			}
		}
	}
	menu();

}


void selecionarArquivos(){

	int escolha;
	printf("\nDeseja visualizar o banco de compras ou de vendas?\n1 - Vendas\n2 - Compras");
	scanf("%d", &escolha);


	while(escolha!= COMPRA && escolha != VENDA){

		printf("\nOpção inválida.");
		printf("\nDeseja visualizar o banco de compras ou de vendas?\n1 - Vendas\n2 - Compras");
		scanf("%d", &escolha );

	}

	if(escolha == COMPRA){

		buscarArquivosDeCompra();

	}else{

		buscarArquivosDeVenda();

	}


}



void negociarOfertas(){

	//O nó atual vai apontar para o cabeçote
	struct Compra *compraAtual = cabecoteCompra;
	struct Venda *vendaAtual = cabecoteVenda;
	int papel, acoes, operacao;
	float preco;


	if(cabecoteCompra == NULL || cabecoteVenda == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}

	printf("\nQuais ações deseja negociar?");
	printf("\n 1 - PETR4 \n");
	printf("\n 2 - VALE5 \n");
	printf("\n 3 - USIM5 \n");
	printf("\n 4 - Voltar \n");
	scanf("%d", &papel);


	while(papel != PETR4 && papel != VALE5 && papel != USIM5 && papel != VOLTAR){

		printf("\nOpção inválida.");
		printf("\nQuais ações deseja negociar?");
		printf("\n 1 - PETR4 \n");
		printf("\n 2 - VALE5 \n");
		printf("\n 3 - USIM5 \n");
		printf("\n 4 - Voltar \n");
		scanf("%d", &papel);


	}

	if (papel == VOLTAR)
			menu();

	printf("\n Quantas ações deseja negociar?");
	scanf("%d", &acoes);


	while(acoes < 0){

		printf("\n Quantas ações deseja negociar?");
		scanf("%d", &acoes);
	}

	printf("\n Qual preço?");
	scanf("%f", &preco);


	while(acoes < 0){

		printf("\n Qual preço?");
		scanf("%f", &preco);


	}

	printf("\nQual operação quer realizar?\n1 - Venda\n2 - Compra");
	scanf("%d", &operacao);


	while(operacao != VENDA && operacao != COMPRA){

		printf("\nQual operação quer realizar?");
		scanf("%d", &operacao);


	}

	int posicao_compra = 0, posicao_venda = 0;

	if(operacao == VENDA){

		int flag = 0;

		while(vendaAtual != NULL){

			if(vendaAtual->precoVenda == preco &&
				vendaAtual->papelVenda == papel) {

				flag = 1;
				break;
			}
			vendaAtual = vendaAtual->proximaVenda;
			posicao_venda++;

		}

		if(flag == 0){

			printf("Seu pedido de venda ainda não  cadastrado .\nPor favor, informe um pedido antes de fazer uma negociação.\n");
			menu();

		}

		while(compraAtual != NULL) {

			if(	compraAtual->precoCompra == preco &&
				compraAtual->acoesCompra > 0 &&
				compraAtual->papelCompra == papel) {

				int escolha;
				printf("Encontramos um match para o seu preço de venda\nDeseja realizar  negociação?\n1 - Sim\n2 - Não\n");
				printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compraAtual->acoesCompra, compraAtual->precoCompra, vendaAtual->acoesVenda, vendaAtual->precoVenda);
				scanf("%d", &escolha);


				while(escolha != SIM && escolha != NAO){

					printf("Opção inválida.\n");
					printf("Deseja realizar esta venda?\n 1 - Sim\n 2 - Não\n");
					printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compraAtual->acoesCompra, compraAtual->precoCompra, vendaAtual->acoesVenda, vendaAtual->precoVenda);
					scanf("%d", &escolha);

				}

				int valor_compra;
				int valor_venda;

				if(escolha == SIM){

					if(papel == PETR4){

						if(acoes <= compraAtual->acoesCompra && acoes <= vendaAtual->acoesVenda){

							vendaAtual->acoesVenda = vendaAtual->acoesVenda - acoes;
							compraAtual->acoesCompra = compraAtual->acoesCompra - acoes;

							valor_venda = vendaAtual->acoesVenda;
							valor_compra = compraAtual->acoesCompra;

							printf("| PETR4 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);

						}else{

							printf("Quantidade de ações do seu pedido ultrpassa a oferta dísponível.");
							menu();

						}

						if(valor_venda == 0 || valor_compra == 0){

							excluirfertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == VALE5){

						if(acoes <= compraAtual->acoesCompra && acoes <= vendaAtual->acoesVenda){

							vendaAtual->acoesVenda = vendaAtual->acoesVenda - acoes;
							compraAtual->acoesCompra = compraAtual->acoesCompra - acoes;

							valor_venda = vendaAtual->acoesVenda;
							valor_compra = compraAtual->acoesCompra;

							printf("| VALE5 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);

						}else{

							printf("Quantidade de ações do seu pedido ultrapassa a oferta dísponível.");
							menu();
						}


						if(valor_venda == 0 || valor_compra == 0){

							excluirfertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == USIM5){

						if(acoes <= compraAtual->acoesCompra && acoes <= vendaAtual->acoesVenda){

							vendaAtual->acoesVenda = vendaAtual->acoesVenda - acoes;
							compraAtual->acoesCompra = compraAtual->acoesCompra - acoes;

							valor_venda = vendaAtual->acoesVenda;
							valor_compra = compraAtual->acoesCompra;

							printf("| USIM5 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);

						}else{

							printf("Quantidade de ações do seu pedido ultrapassa a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							excluirfertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

				}else{

					menu();

				}

			}
			posicao_compra++;
			compraAtual = compraAtual->proximaCompra;
		}

	}

	if(operacao == COMPRA){

		int flag = 0;

		while(compraAtual != NULL){

			if(compraAtual->precoCompra == preco &&
			   compraAtual->papelCompra == papel) {

				flag = 1;
				break;

			}
			compraAtual = compraAtual->proximaCompra;
			posicao_compra++;
		}

		if(flag == 0){

			printf("Seu pedido de compra ainda não foi cadastrado online.\nPor favor, informe um pedido antes de fazer uma negociação.\n");
			menu();

		}

		int valor_compra;
		int valor_venda;

		while(vendaAtual != NULL) {

			if(vendaAtual->precoVenda == preco &&
				vendaAtual->acoesVenda > 0 &&
				vendaAtual->papelVenda == papel) {

				int escolha;
				printf("Encontramos um match para o seu preço de compra\nDeseja realizar negociação?\n 1 - Sim\n 2 - Não\n");
				printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compraAtual->acoesCompra, compraAtual->precoCompra, vendaAtual->acoesVenda, vendaAtual->precoVenda);
				scanf("%d", &escolha);


				while(escolha != SIM && escolha != NAO){

					printf("Opção inválida.\n");
					printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
					printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compraAtual->acoesCompra, compraAtual->precoCompra, vendaAtual->acoesVenda, vendaAtual->precoVenda);
					scanf("%d", &escolha);

				}

				if(escolha == SIM){

					if(papel == PETR4){

						if(acoes <= compraAtual->acoesCompra && acoes <= vendaAtual->acoesVenda){

							vendaAtual->acoesVenda = vendaAtual->acoesVenda - acoes;
							compraAtual->acoesCompra = compraAtual->acoesCompra - acoes;

							valor_venda = vendaAtual->acoesVenda;
							valor_compra = compraAtual->acoesCompra;

							printf("| PETR4 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);

						}else{

							printf("Quantidade de ações do seu pedido ultrapassa a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							excluirfertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == VALE5){

						if(acoes <= compraAtual->acoesCompra && acoes <= vendaAtual->acoesVenda){

							vendaAtual->acoesVenda = vendaAtual->acoesVenda - acoes;
							compraAtual->acoesCompra = compraAtual->acoesCompra - acoes;

							valor_venda = vendaAtual->acoesVenda;
							valor_compra = compraAtual->acoesCompra;

							printf("| VALE5 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);

						}else{

							printf("Quantidade de ações do seu pedido ultrapassa a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							excluirfertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == USIM5){

						if(acoes <= compraAtual->acoesCompra && acoes <= vendaAtual->acoesVenda){

							vendaAtual->acoesVenda = vendaAtual->acoesVenda - acoes;
							compraAtual->acoesCompra = compraAtual->acoesCompra - acoes;

							valor_venda = vendaAtual->acoesVenda;
							valor_compra = compraAtual->acoesCompra;

							printf("| USIM5 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", vendaAtual->acoesVenda, vendaAtual->precoVenda);

						}else{

							printf("Quantidade de ações do seu pedido ultrapassa a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							excluirfertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

				}else{

					menu();

				}

			}
			posicao_venda++;
			vendaAtual = vendaAtual->proximaVenda;
		}

	}

	menu();

}


void excluirfertas(int posicao_venda, int valor_venda, int posicao_compra, int valor_compra){

	if(valor_compra == 0){

		struct Compra *temp_compra, *ptr_compra;

		if(cabecoteCompra == NULL){

			printf("Lista vazia. (delete)\n");
			menu();

		}else{

			if(posicao_compra == 0){

				ptr_compra = cabecoteCompra;
				cabecoteCompra = cabecoteCompra->proximaCompra ;
				free(ptr_compra);

			}else{

				ptr_compra = cabecoteCompra;
				for(int i = 0; i < posicao_compra; i++) {
					temp_compra = ptr_compra;
					ptr_compra = ptr_compra->proximaCompra;

					if(ptr_compra == NULL){
						printf("Posição não encontrada.\n");
						return;
					}
				}
				temp_compra->proximaCompra = ptr_compra->proximaCompra;
				free(ptr_compra);
			}

		}
	}

	if(valor_venda == 0){

		struct Venda *temp_venda, *ptr_venda;

			if(cabecoteVenda == NULL){

				printf("Lista vazia (delete)\n");
				return;

			}else{

				if(posicao_venda == 0){

					ptr_venda = cabecoteVenda;
					cabecoteVenda = cabecoteVenda->proximaVenda;
					free(ptr_venda);

				}else{

					ptr_venda = cabecoteVenda;
					for(int i = 0; i < posicao_venda; i++) {
						temp_venda = ptr_venda;
						ptr_venda = ptr_venda->proximaVenda;

						if(ptr_venda == NULL){
							printf("Posição não encontrada.\n");
							return;
						}
					}
					temp_venda->proximaVenda = ptr_venda->proximaVenda;
					free(ptr_venda);
				}

			}

	}

	ordenarVendas();

}

void finalizar(){

     Compra *temp_compra;
     while(cabecoteCompra != NULL){
    	 temp_compra = cabecoteCompra;
    	 cabecoteCompra = cabecoteCompra->proximaCompra;
          free(temp_compra);
     }

     Venda *temp_venda;
	 while(cabecoteVenda != NULL){
		 temp_venda = cabecoteVenda;
		  cabecoteVenda = cabecoteVenda->proximaVenda;
		  free(temp_venda);
	 }

	 printf("\n Até a proxima!\n");
	 exit(0);
}



void carregarArquivoDeCompras(){

	int papel;
	int acoes;
	float preco;

    FILE * file  = fopen("carregarCompras.txt", "r");

    if(file == NULL){

    	printf("Impossivel abrir o arquivo.\n");

    }


    while (fscanf(file, "%d %d %f", &papel, &acoes, &preco) != EOF ){

    	popularListaDeCompras(papel, acoes, preco);

    }

    fclose(file);

}

void popularListaDeCompras(int papel, int acoes, float preco){

	struct Compra* temp = (struct Compra*) malloc(sizeof(struct Compra));//alocação de memoria para temp
 //atribui valores
	temp->papelCompra = papel;
	temp->acoesCompra = acoes;
	temp->precoCompra = preco;
	temp->proximaCompra = NULL;

	struct Compra *atual = cabecoteCompra, *indice = NULL;
// ordenação
	int swap;
	float swap_f;
// verificação se é o primeiro valor, caso seja null  cabeçote aponta para ca
  

	if (cabecoteCompra == NULL){
		cabecoteCompra = temp;
		return;

	}else{
// caso não fazemos a ordenação 
		while(atual != NULL) {
			indice = atual->proximaCompra;

			while(indice != NULL) {

				if(atual->precoCompra < indice->precoCompra) {

					swap_f = atual->precoCompra;
					atual->precoCompra = indice->precoCompra;
					indice->precoCompra = swap_f;

					swap = atual->acoesCompra;
					atual->acoesCompra  = indice->acoesCompra;
					indice->acoesCompra = swap;

					swap = atual->papelCompra;
					atual->papelCompra =  indice->papelCompra;
					indice->papelCompra = swap;

				}
				indice = indice->proximaCompra;
			}
			atual = atual->proximaCompra;
		}
	}


	struct Compra* ultima = cabecoteCompra;

	while (ultima->proximaCompra != NULL)
	        ultima = ultima->proximaCompra;

	    ultima->proximaCompra = temp;
	    return;
}




void addCompra(){

	struct Compra *temp,*ptr;
	temp = (struct Compra *)malloc(sizeof(struct Compra));

	if(temp == NULL){
		printf("Sem espaço na memória\n");
		menu();
	}
	int escolha;

	printf("\nDe qual cotação deseja comprar?");
	printf("\n 1 - PETR4 \n");
	printf("\n 2 - VALE5 \n");
	printf("\n 3 - USIM5 \n");
	printf("\n 4 - Voltar\n");
	scanf("%d", &escolha);


	while(escolha != PETR4 && escolha != VALE5 && escolha != USIM5 && escolha != VOLTAR){

		printf("\nOpção inválida.");
		printf("\nDe qual cotação deseja comprar?");
		printf("\n 1 - PETR4 \n");
		printf("\n 2 - VALE5 \n");
		printf("\n 3 - USIM5 \n");
		printf("\n 4 - Voltar \n");
		scanf("%d", &escolha);


	}

	if(escolha == VOLTAR){

		menu();

	}else{

		temp->papelCompra = escolha;

	}finalizar

	printf("Qual o preço de compra das ações?\n");
	scanf("%f",&temp->precoCompra);


	while(temp->precoCompra < 0){

		printf("\nValor deve ser positivo.");
		printf("Qual o preço de compra das ações?\n");
		scanf("%f",&temp->precoCompra);

	}

	printf("Informe a quantidade de ações: \n");
	scanf("%d", &temp->acoesCompra);


	while(temp->acoesCompra < 0){

		printf("\nValor deve ser positivo.");
		printf("Informe a quantidade de ações: \n");
		scanf("%d",&temp->acoesCompra);


	}
	temp->proximaCompra = NULL;

	if(cabecoteCompra == NULL){
		cabecoteCompra = temp;
	}else{
		ptr = cabecoteCompra;
		while(ptr->proximaCompra != NULL){
			ptr = ptr->proximaCompra ;
		}
		ptr->proximaCompra = temp;
	}

    ordenarCompras();

}


void ordenarCompras(){
	
	struct Compra *atual = cabecoteCompra, *indice = NULL;

	int temp;
	float temp_f;

	if(cabecoteCompra == NULL) {

		printf("Sem espaço em memória. \n");
		menu();

	}else{

		while(atual != NULL) {
		
			indice = atual->proximaCompra;

			while(indice != NULL) {

				if(atual->precoCompra < indice->precoCompra) {

					temp_f = atual->precoCompra;
					atual->precoCompra = indice->precoCompra;
					indice->precoCompra = temp_f;

					temp = atual->acoesCompra;
					atual->acoesCompra  = indice->acoesCompra;
					indice->acoesCompra = temp;

					temp = atual->papelCompra;
					atual->papelCompra =  indice->papelCompra;
					indice->papelCompra = temp;

				}
				indice = indice->proximaCompra;
			}
			atual = atual->proximaCompra;
		}
	}

	salvarArquivosDeCompra();


}

void salvarArquivosDeCompra(){

	struct Compra *temp = cabecoteCompra;

	FILE* file;
	file = fopen ("registroDeCompras.txt", "w");

	 if (file == NULL){

		fprintf(stderr, "Impossivel abrir o arquivo.\n");
		menu();
	}

	while(temp != NULL){

		if(temp->papelCompra == PETR4){

			fprintf(file,"%s","| PETR4 |");

		}else if(temp->papelCompra == VALE5){

			fprintf(file,"%s","| VALE5 |");

		}else if(temp->papelCompra == USIM5){

			fprintf(file,"%s","| USIM5 |");

		}

		fprintf(file," %d | %.2f |\n",temp->acoesCompra,temp->precoCompra);

		temp = temp->proximaCompra;
	}

	fclose(file);
	menu();

}

void buscarArquivosDeCompra(){

	FILE* file;
	file = fopen("historico_compras.txt","r");

	if (file == NULL){

		fprintf(stderr, "Impossivel abrir o arquivo.\n");
		menu();
	}

	 char ch;
	 printf("HISTÓRICO DE PREÇOS: COMPRAS\n");
	 while ((ch = fgetc(file)) != EOF)
	        putchar(ch);

   fclose(file);
   menu();
}


void carregarArquivoDeVendas()
{
	int papel;
	int acoes;
	float preco;

    FILE * file  = fopen("carregarVendas.txt", "r");

    if (file == NULL){

	 printf("Impossivel abrir o arquivo.\n");

   }


    while (fscanf(file, "%d %d %f", &papel, &acoes, &preco) != EOF ){

    	popularListaDeVendas(papel, acoes, preco);

    }
    fclose(file);

}

void popularListaDeVendas(int papel, int acoes, float preco){

	struct Venda* temp = (struct Venda*) malloc(sizeof(struct Venda));

	temp->papelVenda = papel;
	temp->acoesVenda = acoes;
	temp->precoVenda = preco;
	temp->proximaVenda = NULL;

	struct Venda *atual = cabecoteVenda, *indice = NULL;

	int swap;
	float swap_f;

	if (cabecoteVenda == NULL){
		cabecoteVenda = temp;
		return;

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proximaVenda;

			while(indice != NULL) {

				if(atual->precoVenda > indice->precoVenda) {

					swap_f = atual->precoVenda;
					atual->precoVenda = indice->precoVenda;
					indice->precoVenda = swap_f;

					swap = atual->acoesVenda;
					atual->acoesVenda  = indice->acoesVenda;
					indice->acoesVenda = swap;

					swap = atual->papelVenda;
					atual->papelVenda =  indice->papelVenda;
					indice->papelVenda = swap;

				}
				indice = indice->proximaVenda;
			}
			atual = atual->proximaVenda;
		}
	}


	struct Venda* ultima = cabecoteVenda;

	while (ultima->proximaVenda != NULL)
	        ultima = ultima->proximaVenda;

	    ultima->proximaVenda = temp;
	    return;
}



void addVenda(){


	struct Venda *temp,*ptr;
	temp = (struct Venda *)malloc(sizeof(struct Venda));

	if(temp == NULL){
		printf("Espaço fora da memória.\n");
		return;
	}

	int escolha;

	printf("De qual cotação deseja vender?");
	printf("\n1 - PETR4");
	printf("\n2 - VALE5");
	printf("\n3 - USIM5");
	printf("\n4 - Voltar");
	scanf("%d", &escolha);


	while(escolha != PETR4 && escolha != VALE5 && escolha != USIM5 && escolha != VOLTAR){

		printf("\nOpção inválida.");
		printf("\nDe qual cotação deseja vender?");
		printf("\n1 - PETR4");
		printf("\n2 - VALE5");
		printf("\n3 - USIM5");
		printf("\n4 - Voltar");
		scanf("%d", &escolha);

	}

	if(escolha == VOLTAR){

		menu();

	}else{

		temp->papelVenda = escolha;

	}

	printf("Qual o preço de venda das ações?\n");
	scanf("%f",&temp->precoVenda);



	while(temp->precoVenda < 0){

		printf("Qual o preço de venda das ações?\n");
		scanf("%f",&temp->precoVenda);

	}

	printf("Informe a quantidade de ações: \n");
	scanf("%d",&temp->acoesVenda);



	while(temp->acoesVenda < 0){

		printf("Informe a quantidade de ações: \n");
		scanf("%d",&temp->acoesVenda);

	}

	temp->proximaVenda = NULL;

	if(cabecoteVenda == NULL){
		cabecoteVenda = temp;
	}else{
    	ptr = cabecoteVenda;
        while(ptr->proximaVenda != NULL){
            ptr = ptr->proximaVenda ;
        }
        ptr->proximaVenda = temp;
	}

    ordenarVendas();
	

}


void ordenarVendas(){


	struct Venda *atual = cabecoteVenda, *indice = NULL;

	int temp;
	float temp_f;

	if(cabecoteVenda == NULL) {

		printf("Sem espaço em memória. \n");
		menu();

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proximaVenda;

			while(indice != NULL) {

				if(atual->precoVenda > indice->precoVenda) {

					temp_f = atual->precoVenda;
					atual->precoVenda = indice->precoVenda;
					indice->precoVenda = temp_f;

					temp = atual->acoesVenda;
					atual->acoesVenda  = indice->acoesVenda;
					indice->acoesVenda = temp;

					temp = atual->papelVenda;
					atual->papelVenda =  indice->papelVenda;
					indice->papelVenda = temp;

				}
				indice = indice->proximaVenda;
			}
			atual = atual->proximaVenda;
		}
	}

	salvarArquivosDeVenda();


}

void salvarArquivosDeVenda(){

	struct Venda *temp = cabecoteVenda;

	FILE* file = fopen ("registroDeVendas.txt", "w");

	 if (file == NULL){

		fprintf(stderr, "Impossivel abrir o arquivo.(venda)\n");
		menu();
	}

	while(temp != NULL){

		if(temp->papelVenda == PETR4){

			fprintf(file,"%s","| PETR4 |");

		}else if(temp->papelVenda == VALE5){

			fprintf(file,"%s","| VALE5 |");

		}else if(temp->papelVenda == USIM5){

			fprintf(file,"%s","| USIM5 |");

		}

		fprintf(file," %d | %.2f |\n",temp->acoesVenda, temp->precoVenda);
		temp = temp->proximaVenda;
	}

	fclose(file);
	menu();


}

void buscarArquivosDeVenda(){

	FILE* file = fopen("registroDeVendas.txt","r");

	if (file == NULL){

		fprintf(stderr, "\n Impossivel abrir o arquivo.\n");
		menu();
	}

	 char ch;
	 printf("HISTÓRICO DE PREÇOS: VENDAS\n");
	 while ((ch = fgetc(file)) != EOF)
	        putchar(ch);

   fclose(file);
   menu();

}



