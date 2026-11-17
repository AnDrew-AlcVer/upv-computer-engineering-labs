#include <ctype.h>
#include <string.h>

int es_primo(unsigned int numero){
	if(numero == 0 || numero == 1 || numero == 4){return 0;}
	for(int x = 2; x < numero / 2; x++){
		if(numero % x == 0) {return 0;}
	}
	return 1;
}

float media(int valores[], int num_elementos){
	float suma = 0;
	float res = 0;
	for(int x = 0; x < num_elementos; x++){
		suma = suma + valores[x];
	}
	res = suma/num_elementos;
	return res;
}

float media_ponderada(int valores[], float pesos[], int num_elementos){
	float suma = 0;
	float pond = 0;
	float res = 0;
	for(int x = 0; x < num_elementos; x++){
		suma = suma + valores[x] * pesos[x];
		pond = pond + pesos[x];
	}
	res = suma/pond;
	return res;
}

void a_mayusculas(char cadena[]){
	int x = strlen(cadena);
	char mayus[x];
	for(int i = 0; i < x; i++){
		mayus[i] = toupper(cadena[i]);
		printf("%c", mayus[i]);
	}
	printf("\n");
}

int contiene(char *cadena, char *patron){
	int res = 1;
	if(strcmp(cadena, patron)){
		res = 0;
	}
	return res;
}
