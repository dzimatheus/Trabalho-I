#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista lista;
    inicializar_ordenada(&lista);

    inserir_chave(&lista, 30);
    inserir_chave(&lista, 10);
    inserir_chave(&lista, 20);
    imprimir_lista_ordenada(&lista);

    remover_chave_ordenada(&lista, 20);
    imprimir_lista_ordenada(&lista);

    reinicializar_lista_ordenada(&lista);
    return 0;
}
