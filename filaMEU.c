#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaMEU.h"

#define FALHA 1
#define SUCESSO 0

//Fila vetor
Fila* fila_cria_vet() {
	Fila* local = (Fila*)malloc(sizeof(Fila));
	local->quant = 0;
	local->ini = 0;
	return local;
}
int fila_vazia_vet(Fila* local) {
	int aux;
	if (local->quant == SUCESSO) {
		return aux = FALHA;
	}
	else {
		return SUCESSO;
	}
}
void fila_insere_vet(Fila* local, int elemento) {
	int fim;
	if (local->quant == TAMANHO_MAX) {
		printf("\nCapacidade da fila estourou\n\n");
		return;
	}
	fim = (local->ini + local->quant) % TAMANHO_MAX;
	local->vet[fim] = elemento;
	local->quant++;
}
int fila_retira_vet(Fila* local) {
	int elemento;
	if (fila_vazia_vet(local) == FALHA) {
		printf("\nFila vazia - retornando 1 (FALHA)\n\n");
		return FALHA;
	}
	elemento = local->vet[local->ini];
	local->ini = (local->ini + 1) % TAMANHO_MAX;
	local->quant--;

	return elemento;
}
void fila_imprime_vet(Fila* local) {
	int i;
	for (i = 0; i < local->quant; i++) {
		printf("%d\n", local->vet[(local->ini + i) % TAMANHO_MAX]);
	}
}
void fila_libera_vet(Fila* local) {
	free(local);
}

//Fila lista
Fila_l* fila_cria_l() {

	Fila_l* local = (Fila_l*)malloc(sizeof(Fila_l));
	local->ini = local->fim = NULL;

	return local;
}
int fila_vazia_l(Fila_l* local) {
	int aux;
	if (local->ini == NULL) {
		return aux = 1;
	}
	else {
		return SUCESSO;
	}
}
void fila_insere_l(Fila_l* local, int elemento) {

	Lista* tmp = (Lista*)malloc(sizeof(Lista));

	tmp->info = elemento;
	tmp->prox = NULL;

	if (local->fim != NULL) {
		local->fim->prox = tmp;
	}
	else {
		local->ini = tmp;
	}

	local->fim = tmp;
}
int fila_retira_l(Fila_l* local) {
	Lista* tmp;
	int elemento;

	if (fila_vazia_l(local) == FALHA) {
		printf("\nFila vazia - 1 retornado (FALHA)");
		return FALHA;
	}

	tmp = local->ini;
	elemento = tmp->info;
	local->ini = tmp->prox;

	if (local->ini == NULL) {
		local->fim == NULL;
	}
	free(tmp);
	return elemento;
}
void fila_imprime_l(Fila_l* local) {
	Lista* tmp;
	for (tmp = local->ini; tmp != NULL; tmp = tmp->prox) {
		printf("%d\n", tmp->info);
	}
}
void fila_libera_l(Fila_l* local) {
	Lista* tmp = local->ini;

	while (tmp != NULL) {
		Lista* tmp2 = tmp->prox;
		free(tmp);
		tmp = tmp2;
	}
	free(local);
}
