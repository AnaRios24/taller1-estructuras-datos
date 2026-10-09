#include <stdio.h>
#include <string.h>
#include "patio.h"

void iniciar_patio(Patio *p) {
    p->tope = 0;
}

int patio_lleno(const Patio *p) {
    return p->tope == CAPACIDAD;
}

int patio_vacio(const Patio *p) {
    return p->tope == 0;
}

int ingresar_contenedor(Patio *p, Contenedor c) {
    if (patio_lleno(p))
        return 0;
    if (buscar_contenedor(p, c.codigo) != -1)
        return -1;
    p->items[p->tope] = c;
    p->tope++;
    return 1;
}

int retirar_contenedor(Patio *p, Contenedor *salida) {
    if (patio_vacio(p))
        return 0;
    p->tope--;
    *salida = p->items[p->tope];
    return 1;
}

int buscar_contenedor(const Patio *p, const char *codigo) {
    for (int i = 0; i < p->tope; i++) {
        if (strcmp(p->items[i].codigo, codigo) == 0)
            return i;
    }
    return -1;
}

void listar_patio(const Patio *p) {
    if (patio_vacio(p)) {
        printf("El patio esta vacio.\n");
        return;
    }
    printf("Patio (%d/%d) - del tope a la base:\n", p->tope, CAPACIDAD);
    for (int i = p->tope - 1; i >= 0; i--) {
        printf("  [%d] ", i + 1);
        imprimir_contenedor(&p->items[i]);
    }
}