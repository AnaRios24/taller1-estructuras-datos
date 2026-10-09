#include <stdio.h>
#include "contenedor.h"
#include "patio.h"

static void limpiar_buffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

static void opcion_ingresar(Patio *p) {
    char codigo[20], tipo[LONG_TIPO];
    float peso;

    if (patio_lleno(p)) {
        printf("BLOQUEO: el patio esta lleno (%d/%d). Retire un contenedor primero.\n",
               p->tope, CAPACIDAD);
        return;
    }

    printf("Codigo (4 caracteres alfanumericos): ");
    scanf("%19s", codigo);
    if (!validar_codigo(codigo)) {
        printf("Codigo invalido.\n");
        return;
    }

    printf("Peso (toneladas): ");
    if (scanf("%f", &peso) != 1 || peso <= 0) {
        printf("Peso invalido.\n");
        limpiar_buffer();
        return;
    }

    printf("Tipo de mercancia: ");
    scanf("%29s", tipo);

    int r = ingresar_contenedor(p, crear_contenedor(codigo, peso, tipo));
    if (r == 1)       printf("Contenedor %s ingresado.\n", codigo);
    else if (r == -1) printf("Ya existe un contenedor con el codigo %s.\n", codigo);
}

static void opcion_retirar(Patio *p) {
    Contenedor c;
    if (retirar_contenedor(p, &c)) {
        printf("Retirado (LIFO): ");
        imprimir_contenedor(&c);
    } else {
        printf("El patio esta vacio.\n");
    }
}

static void opcion_buscar(const Patio *p) {
    char codigo[20];
    printf("Codigo a buscar: ");
    scanf("%19s", codigo);
    int pos = buscar_contenedor(p, codigo);
    if (pos == -1) {
        printf("No se encontro el contenedor %s.\n", codigo);
    } else {
        printf("Encontrado en la posicion %d: ", pos + 1);
        imprimir_contenedor(&p->items[pos]);
    }
}

int main(void) {
    Patio patio;
    int opcion;

    iniciar_patio(&patio);

    do {
        printf("\n=== PUERTO DE BUENAVENTURA - PATIO DE CONTENEDORES ===\n");
        printf("1. Ingresar contenedor\n");
        printf("2. Retirar contenedor (tope)\n");
        printf("3. Buscar contenedor\n");
        printf("4. Listar patio\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            limpiar_buffer();
            opcion = -1;
        }

        switch (opcion) {
            case 1: opcion_ingresar(&patio); break;
            case 2: opcion_retirar(&patio);  break;
            case 3: opcion_buscar(&patio);   break;
            case 4: listar_patio(&patio);    break;
            case 0: printf("Hasta luego.\n"); break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 0);

    return 0;
}