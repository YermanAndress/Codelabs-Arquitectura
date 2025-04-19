#include <stdio.h>
#include "ecuaciones_diferenciales.h"

int main() {
    float m, c, k, x0, v0, paso;
    int t_final;

    printf("=== Simulador de resorte-masa-amortiguador ===\n");

    // Entrada de parámetros
    printf("Masa (kg): ");
    scanf("%f", &m);

    printf("Coeficiente de fricción (N.s/m): ");
    scanf("%f", &c);

    printf("Constante del resorte (N/m): ");
    scanf("%f", &k);

    printf("Posición inicial (m): ");
    scanf("%f", &x0);

    printf("Velocidad inicial (m/s): ");
    scanf("%f", &v0);

    printf("Duración de la simulación (segundos): ");
    scanf("%d", &t_final);

    printf("Paso de tiempo (segundos): ");
    scanf("%f", &paso);

    // Simulación del sistema
    simular_resorte_masa(m, c, k, x0, v0, t_final, paso);

    return 0;
}
