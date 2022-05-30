#include <stdlib.h>
#include <stdio.h>


//declaração de struct
typedef struct titulo
{
	int quantidade;
	float valor;
	int tipo;//compra ou venda
	int sigla;//título
	struct ponto* proximo;//ponteiro para o próximo elemento
	int resp;
	
}s_titulo;


int main(int argc, char const *argv[])
{
	FILE *titulo_arq;//cria variável ponteiro para o arquivo

	titulo_arq = fopen("arquivo_acoes.txt", "w");

	if(titulo_arq == NULL){
		printf("Erro na abertura do arquivo\n");
		return 1;
	} else{
	s_titulo* ini_titulo;//início da lista
	s_titulo* proximo_titulo;
	int resp;
	int s, s2, atual = 0,
        anterior = 0, codigo = 0,
        novoCodigo = 0, novoAtual =0, 
        novoAnterior =0;

	ini_titulo = (s_titulo *)malloc(sizeof(s_titulo));
	if(ini_titulo == NULL)
		exit(1);

	proximo_titulo= ini_titulo;
	while(1){
		printf("Digite a quantidade: \n");
		scanf("%d", &proximo_titulo->quantidade);
		fprintf(titulo_arq, "%d\n", proximo_titulo->quantidade);

		printf("Digite o valor: \n");
		scanf("%f", &proximo_titulo->valor);
		fprintf(titulo_arq, "%d\n", proximo_titulo->valor);

		do{
			printf("Escolha:\n 1-COMPRA\t 2-VENDA: \n");
			scanf("%d", &s);
			fprintf(titulo_arq, "%d\n", s);


			proximo_titulo->tipo = s;

		}while(s !=1 && s != 2);
		
		do{
			printf("Digite a sigla:\n 4-PETR4\n 5-VALE5\n 6-ITSA4\n 7-USIM5\n 8-LAME3 \n");
			scanf("%d", &s2); 
			//usando fprintf para armazenar a string no arquivo
			fprintf(titulo_arq, "%d\n", s2);

			proximo_titulo->sigla = s2;

		}while((s2 !=4 )&& (s2 != 5) && (s2 != 6) && (s2 != 7) && (s2 != 8));

		printf("Pressione 1 para continuar.\n Pressione 0 parar \n");
		scanf("%d", &resp);

		if(resp == 1){
			proximo_titulo->proximo = (s_titulo*)malloc(sizeof(s_titulo));
			proximo_titulo = proximo_titulo->proximo;
		}if(resp == 0){
			break;
		}
		printf("\n");
		proximo_titulo->proximo = NULL;
		proximo_titulo = ini_titulo;

		while(proximo_titulo != NULL){
			printf("Quantidade: %d, Valor: %.2f, ", proximo_titulo->quantidade, proximo_titulo->valor);

			if(codigo == 0){
				atual = proximo_titulo->valor;
				
			}

			int codigo02 = 0;
			if(codigo02 == 0 && codigo > 0){
				anterior = proximo_titulo->valor;				
			}

			codigo++;
			

			if(proximo_titulo->tipo == 2){
				printf("Tipo: Compra, ");
			}else{
				printf("Tipo: Venda, ");
			}

			//comparando a quantidade
			if(novoCodigo == 0){
				novoAtual = proximo_titulo->quantidade;
				
			}

			int codigo04 = 0;
			if(codigo04 == 0 && novoCodigo > 0){
				novoAnterior = proximo_titulo->quantidade;				
			}

			novoCodigo++;
			

			if(proximo_titulo->tipo == 2){
				printf("Tipo: Compra, ");
			}else{
				printf("Tipo: Venda, ");
			}

			//<4> PETR4 <5> VALE5 <6> ITSA4 <7> USIM5 <8> LAME3

			if(proximo_titulo->sigla == 4){
				printf("Sigla: PETR4\n");
			}else if(proximo_titulo->sigla == 5){
				printf("Sigla: VALE5\n");
			}else if(proximo_titulo->sigla == 6){
				printf("Sigla: ITSA4\n");
			}else if(proximo_titulo->sigla == 7){
				printf("Sigla: USIM5\n");
			}else if(proximo_titulo->sigla == 8){
				printf("Sigla: LAME3\n");
			}

			
			proximo_titulo = proximo_titulo->proximo;

			if (anterior != atual && novoAnterior == novoAtual && proximo_titulo == NULL)
			{
				printf("\n");				
				printf("Desculpa, a operacao nao pode ser realizada. \n");
				printf("Valor deVenda deve ser igual ao de ValorCompra\n");
				printf("Quantidade de venda ou compra deve ser menor das duas quanitdades\n");
			} else if (anterior == atual && novoAnterior == novoAtual && proximo_titulo == NULL){
			
				printf("\n");				
				printf("Desculpa, a operacao nao pode ser realizada. \n");				
				printf("Quantidade de venda ou compra deve ser menor das duas quantidades\n");
			}else if (anterior == atual && novoAnterior != novoAtual && proximo_titulo == NULL){
				printf("\n");
				printf("Operacao realizada com sucesso!!!\n");
			}
			
		}

		fclose(titulo_arq);


	}

	return 0;
}
}