#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "filaMEU.h"
#include "pilhas.h"

#define STACK 3
#define QUEUE 4
#define PRIORITY_QUEUE 5
#define NOT_SURE 7
#define IMPOSSIBLE 0

#define FALHA 1
#define SUCESSO 0

int main(int argc, char** argv) {

	int num_op, *op, tmp;
	int j = 0, i;
	int lixu;
	int* tmp_pilha, * tmp_fila;
	Pilha_lst* minha_pilha = pilha_lst_cria();
	Fila_l* minha_fila = fila_cria_l();

	printf("\nDigite quantas operacoes fra\n> ");
	scanf("%d", &num_op);

	printf("(0) Sair\n(1) inserir\n(2) remover\n\n");

	tmp_fila = (int*)malloc(num_op * sizeof(int));
	tmp_pilha = (int*)malloc(num_op * sizeof(int));
	op = (int*)malloc(num_op * sizeof(int));


	for (i = 0; i < num_op; i++) {

		scanf("%d %d", &op[i], &tmp);

		switch (op[i])
		{
		case 1:
			fila_insere_l(minha_fila, tmp);
			pilha_lst_push(minha_pilha, tmp);
			break;
		case 2:

			tmp_fila[j] = tmp;
			tmp_pilha[j] = tmp;
			j++;
			break;
		default:
			break;
		}
	}

	for (i = (num_op - 1); i >= SUCESSO; i--) {
		if (op[i] == FALHA) {
			lixu = fila_retira_l(minha_fila);
			lixu = pilha_lst_pop(minha_pilha);
		}
		else {
			i = SUCESSO;
		}
	}
	printf("\n\n");
	fila_imprime_l(minha_fila);
	printf("\n");
	pilha_lst_imprime(minha_pilha);

	printf("\nVetores\n");
	for (int o = 0; o < j; o++) {
		printf("%d\n", tmp_fila[o]);
	}
	printf("\n");
	for (int p = 0; p < j; p++) {
		printf("%d\n", tmp_pilha[p]);
	}

	int a = 0;
	int b = 0;
	int c = 0;
	int ehPilha = 0, ehFila, ehpriority, result;

	do {

		tmp = fila_retira_l(minha_fila);

		if (tmp_fila[a] == tmp) {
			ehFila= QUEUE;
			a++;
		}
		else {
			ehFila = IMPOSSIBLE;
			a = j;
		}

	} while (a != j);
	printf("\n\nehFila = %d\n\n", ehFila);

	do {

		tmp = pilha_lst_pop(minha_pilha);

		if (tmp_pilha[b] == tmp) {
			ehPilha = STACK;
			b++;
		}
		else {
			ehPilha = IMPOSSIBLE;
			b = j;
		}
	} while (b != j);
	printf("\n\nehPilha = %d\n\n", ehPilha);

	do {

		if (tmp_pilha[c] >= tmp_pilha[c + 1]) {
			ehpriority = PRIORITY_QUEUE;
			c++;
		}
		else {
			ehpriority = IMPOSSIBLE;
			c = (j - 1);
		}

	} while (c != (j - 1));
	printf("\n\nehpriority = %d\n\n", ehpriority);

	result = ehPilha + ehFila + ehpriority;
	printf("\n\nresult = %d\n\n", result);

	if (result >= NOT_SURE) {
		printf("\n\nnot sure\n\n");
	}
	else if (ehFila == QUEUE) {
		printf("\n\nqueue\n\n");
	}
	else if (ehPilha == STACK) {
		printf("\n\nstack\n\n");
	}
	else if (ehpriority == PRIORITY_QUEUE) {
		printf("\n\npriority queue\n\n");
	} 
	else {
		printf("\n\nimpossible\n\n");
	}

	fila_libera_l(minha_fila);
	pilha_lst_libera(minha_pilha);

	return SUCESSO;
}
