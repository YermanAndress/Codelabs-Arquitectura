#include <stdio.h>
#include "ecuaciones_diferenciales.h"

void simular_resorte_masa(float m, float c, float k, float x0, float v0, int t_final, float paso) {
    float t = 0.0;
    float x = x0;  // Posición inicial
    float v = v0;  // Velocidad inicial
    float x_ant = x0 - v0 * paso;  // Aproximación para x(t-h)

    printf("\n📉 Simulacion de resorte-masa-amortiguador:\n");

    while (t <= t_final) {
        printf("Tiempo: %.2f s - Posicion: %.2f m - Velocidad: %.2f m/s\n", t, x, v);

        // Usamos la aproximación de Euler para la segunda derivada y resuelvo la ecuación directamente:
        // m * ((x(t+h) - 2x(t) + x(t-h)) / h^2) + c * (x(t+h) - x(t)) / h + k * x(t) = 0

        float x_ant_ant = x_ant;
        // Aproximación de la posición en el siguiente paso de tiempo:
        float x_nueva = 2 * x - x_ant - (c * v + k * x) * paso * paso / m;

        // Actualizamos la posición y la velocidad:
        v = (x_nueva - x) / paso;  // Nueva velocidad aproximada
        x_ant = x;
        x = x_nueva;
        t += paso;
    }
}
