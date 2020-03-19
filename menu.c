#include<stdio.h>

int main(){
	
	int opcion;
	char usuario[50];
	
	printf("Bienvenido al comprardor de propiedades, introduzca su nombre de usuario:\n");
	
	gets(usuario);

	do {printf("- Selecccione una opcion: \n");
	
		printf("1-Buscar elemento. \n");
		printf("2-Buscar grupo periodico. \n");
		printf("3-Buscar periodo de la tabla periodica. \n");
		printf("4-Buscar por caracter metalico. \n");
		printf("5-Comparador de elementos. \n");
		printf("0-Salir del programa. \n");
		scanf("%d",&opcion);
	}
	
	
	while (opcion!=0);



}
