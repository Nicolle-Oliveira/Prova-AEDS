#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "filaMEU.h"
#include "pilha.h"

#define STACK 3
#define QUEUE 4
#define PRIORITY_QUEUE 5
#define IMPOSSIBLE 0

#define FALHA 1
#define SUCESSO 0

int main(int argc, char** argv) {

	int num_op, op, tmp;
	int j = 0;
	int* tmp_pilha, * tmp_fila;
	Pilha_lst* minha_pilha = pilha_lst_cria();
	Fila_l* minha_fila = fila_cria_l();

	printf("\nDigite quantas operacoes fara\n> ");
	scanf("%d", &num_op);

	printf("(0) Sair\n(1) inserir\n(2) remover\n\n");

	tmp_fila = (int*)malloc(num_op * sizeof(int));
	tmp_pilha = (int*)malloc(num_op * sizeof(int));


	for (int i = 0; i < num_op; i++) {

		scanf("%d %d", &op, &tmp);

		switch (op)
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
	int result = 0;

	do {

		tmp = fila_retira_l(minha_fila);

		if (tmp_fila[a] == tmp) {
			result += QUEUE;
		}
		else {
			result += FALHA;
		}
		a++;
	} while (a != j);

	do {

		tmp = pilha_lst_pop(minha_pilha);

		if (tmp_pilha[b] == tmp) {
			result += STACK;
		}
		else {
			result += FALHA;
		}
		b++;
	} while (b != j);

	if (result == QUEUE) {
		printf("\n\nqueue\n\n");
	}
	else if(result == STACK) {
		printf("\n\nstack\n\n");
	}
	else if(result == IMPOSSIBLE){
		printf("\n\nimpossible\n\n");
	}

	fila_libera_l(minha_fila);
	pilha_lst_libera(minha_pilha);

	return SUCESSO;
}
