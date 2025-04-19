#include <stdio.h>
#include <stdlib.h>

float comparar_float(float, float);

int main (int numArgumentos, char ** argumentos){
	printf("Casos De Prueba (1: Verdadero, 0: Falso)\r\n");
	float casos[][2]=	{{-0.5, -0.4}, {-0.5, 0.4}, {0.5, -0.4}, {0.5, 0.4},
				 {-0.5, -0.4}, {-0.5, 0.4}, {0.5, -0.4}, {0.5, 0.4}};

	float resultado;

	for(int i=0; i < sizeof(casos)/sizeof(casos[0]); i++){
		resultado=comparar_float(casos[i][0], casos[i][1]);
		printf("%f + %f = %f \r\n", casos[i][0], casos[i][1], resultado);

	}

	exit(EXIT_SUCCESS);
}
