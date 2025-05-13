#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista lista;
    inicializar(&lista);

    inserir_inicio(&lista, 10);
    inserir_final(&lista, 20);
    inserir_inicio(&lista, 5);
    imprimir_lista(&lista);

    remover_chave(&lista, 10);
    imprimir_lista(&lista);

    reinicializar_lista(&lista);
    return 0;
}
