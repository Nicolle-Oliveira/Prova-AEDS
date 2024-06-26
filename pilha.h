#define N 500

typedef struct pilha_vet {
	int n;
	int vet[N];
} Pilha_vet;

struct listap{
	int info;
	struct listap *prox;
};

typedef struct listap Listap;

typedef struct pilha_lst{
	Listap *prim;
} Pilha_lst;

Pilha_vet *pilha_vet_cria();
void pilha_vet_push(Pilha_vet *p, int v);
int pilha_vet_pop(Pilha_vet *p);
int pilha_vet_vazia(Pilha_vet *p);
void pilha_vet_libera(Pilha_vet *p);
void pilha_vet_imprime(Pilha_vet *p);

Pilha_lst *pilha_lst_cria();
void pilha_lst_push(Pilha_lst *p, int v);
int pilha_lst_pop(Pilha_lst *p);
int pilha_lst_vazia(Pilha_lst *p);
void pilha_lst_libera(Pilha_lst *p);
void pilha_lst_imprime(Pilha_lst *p);
