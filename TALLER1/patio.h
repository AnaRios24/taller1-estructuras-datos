#ifndef PATIO_H
#define PATIO_H

#include "contenedor.h"

#define CAPACIDAD 5

typedef struct {
    Contenedor items[CAPACIDAD];
    int tope;
} Patio;

void iniciar_patio(Patio *p);
int  patio_lleno(const Patio *p);
int  patio_vacio(const Patio *p);
int  ingresar_contenedor(Patio *p, Contenedor c);
int  retirar_contenedor(Patio *p, Contenedor *salida);
int  buscar_contenedor(const Patio *p, const char *codigo);
void listar_patio(const Patio *p);

#endif