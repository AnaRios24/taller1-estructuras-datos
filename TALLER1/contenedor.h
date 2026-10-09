#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define LONG_CODIGO 4
#define LONG_TIPO   30

typedef struct {
    char  codigo[LONG_CODIGO + 1];
    float peso;
    char  tipo[LONG_TIPO];
} Contenedor;

int validar_codigo(const char *codigo);
Contenedor crear_contenedor(const char *codigo, float peso, const char *tipo);
void imprimir_contenedor(const Contenedor *c);

#endif