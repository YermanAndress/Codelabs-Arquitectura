#include <stdio.h>
#include <stdlib.h>
#include "estadistica.h"

int main() {
    int n;
    printf("¿Cuántos números quieres ingresar? ");
    scanf("%d", &n);

    int* datos = malloc(n * sizeof(int));
    if (!datos) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Introduce los %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Dato %d: ", i + 1);
        scanf("%d", &datos[i]);
    }

    float media = calcular_media(datos, n);
    float mediana = calcular_mediana(datos, n);
    float desviacion = calcular_desviacion_estandar(datos, n);

    int cantidad_moda;
    int* modas = calcular_moda(datos, n, &cantidad_moda);

    printf("\n📊 Resultados estadísticos:\n");
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Desviación estándar: %.2f\n", desviacion);

    printf("Moda(s): ");
    for (int i = 0; i < cantidad_moda; i++) {
        printf("%d ", modas[i]);
    }
    printf("\n");

    free(datos);
    free(modas);
    return 0;
}

