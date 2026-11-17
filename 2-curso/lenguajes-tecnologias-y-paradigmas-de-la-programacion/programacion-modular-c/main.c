#include <stdio.h>
#include "lib.h"
#include <ctype.h>
#include <string.h>

int main(){
	
	int num = 4;
	int comp = 0;
	comp = es_primo(num);
	if(comp == 0){
		printf("El numero %i no es primo\n", num);
	}else{
		printf("El numero %i es primo\n", num);
	}
	
	int valores[] = {3, 6, 9, 12};
	float res = 0;
	res = media(valores, 4);
	printf("La media de los valores es %f \n", res);

	int vals_pond[] = {3, 6, 9, 12};
	float ponders[] = {1.3, 2.4, 2, 1.5};
	float res_1 = 0;
	res_1 = media_ponderada(vals_pond, ponders, 4);
	printf("La media ponderada de los valores es %f \n", res_1);
	
	char frase[] = "hola";
	a_mayusculas(frase);

	char palabra_1[] = "Me llamo Andres";
	char palabra_2[] = "Me llamo Andres";
	int valor = contiene(palabra_1, palabra_2);
	if(valor == 0){
		printf("Las palabras no coinciden");
	}else if(valor == 1){
		printf("Las palabras coinciden");
	}
	printf("\n");
}
