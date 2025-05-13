#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar_ordenada(Lista* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int retornar_tamanho_ordenada(Lista* lista) {
    return lista->tamanho;
}

void imprimir_lista_ordenada(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

void inserir_chave(Lista* lista, int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->anterior = NULL;
    novo->proximo = NULL;

    No* atual = lista->inicio;
    No* anterior = NULL;

    while (atual != NULL && atual->chave < chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    novo->proximo = atual;
    novo->anterior = anterior;

    if (anterior)
        anterior->proximo = novo;
    else
        lista->inicio = novo;

    if (atual)
        atual->anterior = novo;

    lista->tamanho++;
}

No* buscar_chave_ordenada(Lista* lista, int chave) {
    No* atual = lista->inicio;
    while (atual && atual->chave <= chave) {
        if (atual->chave == chave)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void remover_chave_ordenada(Lista* lista, int chave) {
    No* atual = buscar_chave_ordenada(lista, chave);
    if (!atual) return;

    if (atual->anterior)
        atual->anterior->proximo = atual->proximo;
    else
        lista->inicio = atual->proximo;

    if (atual->proximo)
        atual->proximo->anterior = atual->anterior;

    free(atual);
    lista->tamanho--;
}

void reinicializar_lista_ordenada(Lista* lista) {
    while (lista->inicio != NULL) {
        No* temp = lista->inicio;
        lista->inicio = temp->proximo;
        free(temp);
    }
    lista->tamanho = 0;
}
