#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* anterior;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Lista;

void inicializar_ordenada(Lista* lista);
int retornar_tamanho_ordenada(Lista* lista);
void imprimir_lista_ordenada(Lista* lista);
void inserir_chave(Lista* lista, int chave);
No* buscar_chave_ordenada(Lista* lista, int chave);
void remover_chave_ordenada(Lista* lista, int chave);
void reinicializar_lista_ordenada(Lista* lista);
