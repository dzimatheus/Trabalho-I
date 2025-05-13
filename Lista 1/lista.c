#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializar(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int retornar_tamanho(Lista* lista) {
    return lista->tamanho;
}

void imprimir_lista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("\n");
}

void inserir_inicio(Lista* lista, int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;
    if (lista->inicio)
        lista->inicio->anterior = novo;
    else
        lista->fim = novo;
    lista->inicio = novo;
    lista->tamanho++;
}

void inserir_final(Lista* lista, int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    if (lista->fim)
        lista->fim->proximo = novo;
    else
        lista->inicio = novo;
    lista->fim = novo;
    lista->tamanho++;
}

No* buscar_chave(Lista* lista, int chave) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        if (atual->chave == chave)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void remover_inicio(Lista* lista) {
    if (lista->inicio == NULL) return;
    No* temp = lista->inicio;
    lista->inicio = temp->proximo;
    if (lista->inicio)
        lista->inicio->anterior = NULL;
    else
        lista->fim = NULL;
    free(temp);
    lista->tamanho--;
}

void remover_final(Lista* lista) {
    if (lista->fim == NULL) return;
    No* temp = lista->fim;
    lista->fim = temp->anterior;
    if (lista->fim)
        lista->fim->proximo = NULL;
    else
        lista->inicio = NULL;
    free(temp);
    lista->tamanho--;
}

void remover_chave(Lista* lista, int chave) {
    No* atual = buscar_chave(lista, chave);
    if (!atual) return;
    if (atual->anterior)
        atual->anterior->proximo = atual->proximo;
    else
        lista->inicio = atual->proximo;

    if (atual->proximo)
        atual->proximo->anterior = atual->anterior;
    else
        lista->fim = atual->anterior;

    free(atual);
    lista->tamanho--;
}

void reinicializar_lista(Lista* lista) {
    while (lista->inicio != NULL)
        remover_inicio(lista);
}
