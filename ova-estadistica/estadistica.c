#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "estadistica.h"

int comparar_enteros(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

float calcular_media(int *datos, int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += datos[i];
    }
    return suma / n;
}

float calcular_mediana(int *datos, int n) {
    qsort(datos, n, sizeof(int), comparar_enteros);

    if (n % 2 == 0) {
        return (datos[n/2 - 1] + datos[n/2]) / 2.0;
    } else {
        return datos[n/2];
    }
}

float calcular_desviacion_estandar(int *datos, int n) {
    float media = calcular_media(datos, n);
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += pow(datos[i] - media, 2);
    }
    return sqrt(suma / n);
}

int* calcular_moda(int *datos, int n, int *cantidad_moda) {
    qsort(datos, n, sizeof(int), comparar_enteros);

    int max_reps = 1, reps = 1;
    int* modas = malloc(n * sizeof(int));
    *cantidad_moda = 0;

    for (int i = 1; i < n; i++) {
        if (datos[i] == datos[i - 1]) {
            reps++;
        } else {
            if (reps > max_reps) {
                max_reps = reps;
                modas[0] = datos[i - 1];
                *cantidad_moda = 1;
            } else if (reps == max_reps) {
                modas[*cantidad_moda] = datos[i - 1];
                (*cantidad_moda)++;
            }
            reps = 1;
        }
    }

    if (reps > max_reps) {
        max_reps = reps;
        modas[0] = datos[n - 1];
        *cantidad_moda = 1;
    } else if (reps == max_reps) {
        modas[*cantidad_moda] = datos[n - 1];
        (*cantidad_moda)++;
    }

    return modas;
}

