#ifndef PATIO_H
#define PATIO_H

#include "contenedor.h"

#define CAPACIDAD 5

/* Patio = PILA (LIFO): el ultimo contenedor en entrar es el primero en salir */
typedef struct {
    Contenedor items[CAPACIDAD];
    int tope;                      /* cantidad de contenedores almacenados */
} Patio;

void iniciar_patio(Patio *p);
int  patio_lleno(const Patio *p);
int  patio_vacio(const Patio *p);

/* Retorna 1 si ingreso, 0 si el patio esta lleno, -1 si el codigo ya existe */
int  ingresar_contenedor(Patio *p, Contenedor c);

/* Retira el contenedor del tope. Retorna 1 si pudo, 0 si esta vacio */
int  retirar_contenedor(Patio *p, Contenedor *salida);

/* Retorna la posicion del contenedor con ese codigo, o -1 si no existe */
int  buscar_contenedor(const Patio *p, const char *codigo);

void listar_patio(const Patio *p);

#endif