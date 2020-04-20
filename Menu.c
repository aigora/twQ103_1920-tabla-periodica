#include<stdio.h>
#include <string.h>

struct Elemento{
	char Nombre[50];
	char Simbolo[3];
	int NAtomico;
	char Estado[20];
	float MAtomica;
	float Radio;
	float Electroneg;
};

int main(){
	
	int opcion;
	char usuario[50];
	bool cerrar = false;
	int i, f;
	
	struct Elemento tabla[118];
	
	printf("Bienvenido al comprardor de propiedades, introduzca su nombre de usuario:\n");
	
	gets(usuario);
	
	while(!cerrar){
	
		printf("-Selecccione una opcion: \n1-Buscar elemento. \n2-Buscar grupo periodico. \n3-Buscar periodo de la tabla periodica. \n4-Buscar por radio atomico. \n5-Comparador de elementos. \n6-Mostrar tabla periodica. \n7-Juego de preguntas\n0-Cerrar. \n");
		scanf("%d", &opcion);	
	
		switch(opcion){
			case 6:
				
				FILE * fichero;
				fichero = fopen("ElementosTabla.txt", "r");
	
				if(fichero == NULL){
				printf("El fichero no existe.");
				return 1;
				}

				//Rellenamos la lista con los datos del fichero.
				f=0;
	
				while(fscanf(fichero,"%s\t%s\t%d\t%s\t%f\t%f\t%f",tabla[f].Nombre,tabla[f].Simbolo,&tabla[f].NAtomico,tabla[f].Estado,&tabla[f].MAtomica,&tabla[f].Radio,&tabla[f].Electroneg)!=EOF){

					f++;	
		
				}
	
				//Cerramos el fichero.
	
				fclose(fichero);
	
				//Mostramos la tabla por consola.
	
				printf("|=================|=================|=================|=================|=================|=================|=================|\n");
				printf("| %15s | %15s | %15s | %15s | %15s | %15s | %15s |\n","Nombre","Simbolo","NAtomico","Estado","MAtomica","Radio","Electroneg");
				printf("|=================|=================|=================|=================|=================|=================|=================|\n");
				for(i=0;i<118;i++){
		
					printf("| %15s | %15s | %15d | %15s | %15.4f | %15.2f | %15.2f |\n",tabla[i].Nombre,tabla[i].Simbolo,tabla[i].NAtomico,tabla[i].Estado,tabla[i].MAtomica,tabla[i].Radio,tabla[i].Electroneg);
		
				}
				printf("|=================|=================|=================|=================|=================|=================|=================|\n");
	

				return 0;
				
				break;
			
			
			case 0:
				
				cerrar=true;
				break;
				
		}
		
	}


}
