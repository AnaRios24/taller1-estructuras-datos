#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contenedor.h"

int validar_codigo(const char *codigo) {
    if (strlen(codigo) != LONG_CODIGO)
        return 0;
    for (int i = 0; i < LONG_CODIGO; i++) {
        if (!isalnum((unsigned char)codigo[i]))
            return 0;
    }
    return 1;
}

Contenedor crear_contenedor(const char *codigo, float peso, const char *tipo) {
    Contenedor c;
    strcpy(c.codigo, codigo);
    c.peso = peso;
    strncpy(c.tipo, tipo, LONG_TIPO - 1);
    c.tipo[LONG_TIPO - 1] = '\0';
    return c;
}

void imprimir_contenedor(const Contenedor *c) {
    printf("Codigo: %s | Peso: %.1f t | Tipo: %s\n", c->codigo, c->peso, c->tipo);
}