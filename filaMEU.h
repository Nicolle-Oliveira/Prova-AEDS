#define TAMANHO_MAX 100
#define SUCESSO 0
#define FALHA 1

typedef struct fila {
	int quant;
	int ini;
	int vet[TAMANHO_MAX];
}Fila;

typedef struct lista {
	int info;
	struct lista* prox;
}Lista;

typedef struct filal {
	Lista* ini;
	Lista* fim;
}Fila_l;

Fila* fila_cria_vet();
void fila_insere_vet(Fila* local, int elemento);
int fila_retira_vet(Fila* local);
void fila_imprime_vet(Fila* local);
int fila_vazia_vet(Fila* local);
void fila_libera_vet(Fila* local);

Fila_l* fila_cria_l();
void fila_insere_l(Fila_l* local, int elemento);
int fila_retira_l(Fila_l* local);
void fila_imprime_l(Fila_l* local);
int fila_vazia_l(Fila_l* local);
void fila_libera_l(Fila_l* local);
