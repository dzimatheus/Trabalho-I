#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* anterior;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Lista;

void inicializar(Lista* lista);
int retornar_tamanho(Lista* lista);
void imprimir_lista(Lista* lista);
void inserir_inicio(Lista* lista, int chave);
void inserir_final(Lista* lista, int chave);
No* buscar_chave(Lista* lista, int chave);
void remover_inicio(Lista* lista);
void remover_final(Lista* lista);
void remover_chave(Lista* lista, int chave);
void reinicializar_lista(Lista* lista);
