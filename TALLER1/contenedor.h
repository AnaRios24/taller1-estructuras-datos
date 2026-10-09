#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#define LONG_CODIGO 4
#define LONG_TIPO   30

/* Datos de un contenedor */
typedef struct {
    char  codigo[LONG_CODIGO + 1];  /* 4 caracteres alfanumericos + '\0' */
    float peso;                     /* toneladas */
    char  tipo[LONG_TIPO];          /* tipo de mercancia */
} Contenedor;

/* Retorna 1 si el codigo tiene exactamente 4 caracteres alfanumericos */
int validar_codigo(const char *codigo);

/* Construye un contenedor con los datos recibidos */
Contenedor crear_contenedor(const char *codigo, float peso, const char *tipo);

/* Muestra un contenedor por consola */
void imprimir_contenedor(const Contenedor *c);

#endif