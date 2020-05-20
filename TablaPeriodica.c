#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Elemento{
	char Nombre[50];
	char Simbolo[3];
	int NAtomico;
	char Estado[20];
	float MAtomica;
	float Radio;
	float Electroneg;
};

struct ElemOrden{
	char Nombre[50];
	float Radio;
};

//struct utilizado en la funcion de Grupos
struct ElemGP{
	char Nombre[50];
	char Simbolo[3];
};

//Declaro la funcion donde se elegiran los grupos y se mostraran.
void funcionGrupos();
void funcionPeriodos();

int main(){
	
	int opcion;
	char usuario[50];
	bool cerrar = false;
	int i, f, j, encontrado, encontrado1;
	encontrado=0;
	encontrado1=0;
	
	struct Elemento tabla[118];
	
	printf("Bienvenido al comparador de propiedades, introduzca su nombre de usuario:\n");
	
	gets(usuario);
	
	//Leemos el fichero con todos los elementos de la tabla.
	FILE * ficher0;
	ficher0 = fopen("ElementosTabla.txt", "r");
	
	if(ficher0 == NULL){
	printf("El fichero no existe.");
	return 1;
	}
	
	j=0;

	while(fscanf(ficher0,"%s\t%s\t%d\t%s\t%f\t%f\t%f",tabla[j].Nombre,tabla[j].Simbolo,&tabla[j].NAtomico,tabla[j].Estado,&tabla[j].MAtomica,&tabla[j].Radio,&tabla[j].Electroneg)!=EOF){

		j++;	

	}
	
	fclose(ficher0);
	
	while(!cerrar){
	
		printf("\n\n-Seleccione una opcion: \n1-Buscar elemento. \n2-Buscar grupo periodico. \n3-Buscar periodo de la tabla periodica. \n4-Ordenar por radio atomico (de menor a mayor). \n5-Comparador de elementos. \n6-Mostrar tabla periodica. \n7-Juego Adivinanza.\n0-Cerrar. \n");
		scanf("%d", &opcion);	
	
		switch(opcion){
			case 1:
				
				int i, j;
				char ElemBuscado[50];
				encontrado=0;
				
				FILE * ficher0;
				ficher0 = fopen("ElementosTabla.txt", "r");
				
				if(ficher0 == NULL){
				printf("El fichero no existe.");
				return 1;
				}
				
				j=0;
	
				while(fscanf(ficher0,"%s\t%s\t%d\t%s\t%f\t%f\t%f",tabla[j].Nombre,tabla[j].Simbolo,&tabla[j].NAtomico,tabla[j].Estado,&tabla[j].MAtomica,&tabla[j].Radio,&tabla[j].Electroneg)!=EOF){

					j++;	
		
				}
				
				fclose(ficher0);
				
				printf("\nIntroduce el Elemento deseado: [PRIMERA LETRA EN MAYUSCULAS]\n");
				scanf("%s", ElemBuscado);
				
				for(i=0; i<118; i++){
					
					if(strcmp(ElemBuscado,tabla[i].Nombre)==0){
						
						printf("\nEl elemento es el %s (%s), con numero atom. %d.\nEn condiciones normales se presenta en forma de %s. Su masa at. es %f g/mol, su radio atomico es %f pm y su electroneg. es %f.\n", tabla[i].Nombre, tabla[i].Simbolo, tabla[i].NAtomico, tabla[i].Estado, tabla[i].MAtomica, tabla[i].Radio, tabla[i].Electroneg);
						encontrado=1;
					break;	
					}
					
				}
				if(encontrado==0){
					printf("\nEl elemento no existe en la tabla.\n");
				}
				break;
				
			case 2:
				
				funcionGrupos(); //Llamo a la funcion Grupos
				
				break;
			
			case 3:
				
				funcionPeriodos(); //Llamo a la funcion Periodos
				
				break;
				
			case 4:
				
				int aux;
				char aux2[50];
				struct ElemOrden tablaOrdenada[118];
				
				for(j=0;j<118;j++){
					
					strcpy(tablaOrdenada[j].Nombre,tabla[j].Nombre);
					tablaOrdenada[j].Radio = tabla[j].Radio;
					
				}
				for(i=0;i<118;i++){
					
					for(f=0;f<118;f++){
						
						if(tablaOrdenada[f].Radio > tablaOrdenada[f+1].Radio){
							
							aux=tablaOrdenada[f].Radio;
							strcpy(aux2,tablaOrdenada[f].Nombre);
							
							tablaOrdenada[f].Radio=tablaOrdenada[f+1].Radio;
							strcpy(tablaOrdenada[f].Nombre,tablaOrdenada[f+1].Nombre);
							
							tablaOrdenada[f+1].Radio=aux;
							strcpy(tablaOrdenada[f+1].Nombre,aux2);
						}
						
					}
					
				}
				printf("\n|-----------------|----------|");
				printf("\n|      NOMBRE     |   RADIO  |");
				printf("\n|-----------------|----------|\n");
				for(i=0;i<118;i++){
					
					printf("| %15s | %8.3f |\n", tablaOrdenada[i].Nombre, tablaOrdenada[i].Radio);
					
				}
				printf("|-----------------|----------|\n");
				break;
			
			case 5:
				
				int k;
				char ElemBuscado1[50], ElemBuscado2[50];
				encontrado=0;
				encontrado1=0;
				
				printf("\nIntroduce el Primero de los Elementos a comparar: [PRIMERA LETRA EN MAYUSCULAS]\n");
				scanf("%s", ElemBuscado1);
				
				printf("\nIntroduce el Segundo de los Elementos a comparar: [PRIMERA LETRA EN MAYUSCULAS]\n");
				scanf("%s", ElemBuscado2);
				
				printf("|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|\n");
				printf("| %15s | %15s | %15s | %15s | %15s | %15s | %15s |\n","Nombre","Simbolo","NAtomico","Estado","MAtomica","Radio","Electroneg");
				printf("|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|\n");
				
				for(i=0; i<118; i++){
					
					if(strcmp(ElemBuscado1,tabla[i].Nombre)==0){
						
						printf("| %15s | %15s | %15d | %15s | %15.4f | %15.2f | %15.2f |\n", tabla[i].Nombre, tabla[i].Simbolo, tabla[i].NAtomico, tabla[i].Estado, tabla[i].MAtomica, tabla[i].Radio, tabla[i].Electroneg);
						encontrado=1;
					break;	
					}
					
				}
				if(encontrado==0){
					printf("\tEl primer elemento no existe en la tabla.\n");
				}
				printf("|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|\n");
				
				for(k=0; k<118; k++){
					
					if(strcmp(ElemBuscado2,tabla[k].Nombre)==0){
						
						printf("| %15s | %15s | %15d | %15s | %15.4f | %15.2f | %15.2f |\n", tabla[k].Nombre, tabla[k].Simbolo, tabla[k].NAtomico, tabla[k].Estado, tabla[k].MAtomica, tabla[k].Radio, tabla[k].Electroneg);
						encontrado1=1;
					break;
					}	
				}
				if(encontrado1==0){
					printf("\nEl segundo elemento no existe en la tabla.\n");
				}
				printf("|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|-----------------|\n");
				
				break;
				
			case 6:
	
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
			
			case 7:
				
				int NASol, intento;
				intento=0;
    			char nomSol[50], nomIntroducido[50];
    			int bandera;
				bandera=0;  			
    			
    			srand((unsigned)time(NULL));
        		NASol=rand()%(118);
        		
        		if(NASol<1){
					NASol=1;
				}
				
				//Bucle buscar nombre solucion.
				for(i=0;i<118;i++){
					
					if(NASol==tabla[i].NAtomico){

						strcpy(nomSol,tabla[i].Nombre);
						
						break;
					}	
				}
				
				printf("\nIntenta adivinar el elemento que he pensado.\n");
				//Bucle de Juego.
				while(bandera==0){
					
					printf("\n\nIntroduce un elemento: [PRIMERA LETRA MAYUSCULA]\n");
                	scanf("%s",nomIntroducido);
                	intento++;
					
					//Comparativa Nombre
					if(strcmp(nomIntroducido,nomSol)==0){
						
						printf("\nEl elemento es correcto!\nEl numero de intentos usados ha sido: %d\n", intento);
						bandera=1;
					
					}
					//Comparativa Numero Atomico.
					else{
						
						for(i=0;i<118;i++){
					
							if(strcmp(nomIntroducido,tabla[i].Nombre)==0){

								if(NASol>tabla[i].NAtomico){
									printf("\nEl elemento solucion tiene MAYOR numero atomico.\n");
								}
								else{
									printf("\nEl elemento solucion tiene MENOR numero atomico.\n");
								}
								encontrado=1;
								break;
							}	
						}
						
						if(encontrado==0){
							printf("\nEse elemento no existe en la tabla.\n");
						}
						
					}
				}
				
				
				break;
			
			case 0:
				
				cerrar=true;
				
				printf("Hasta pronto %s!", usuario);
				
				break;
				
		}
		
	}

}
void funcionGrupos(){
	
	int i, g, opcion;
	
	//Vector de estructuras donde se guardan los elementos de cada grupo.
	struct ElemGP Grupos[7];
	
	printf("\n\nElija una opcion de las siguientes:\n");
	printf("GRUPOS PERIODICOS:\n");
	printf("1 - Alcalinos\n");
	printf("2 - Alcalinoterreos\n");
	printf("3 - MetalesDeTransicion\n");
	printf("4 - Boroideos\n");
	printf("5 - Carbonoideos\n");
	printf("6 - Nitrogenoideos\n");
	printf("7 - Anfigenos\n");
	printf("8 - Halogenos\n");
	printf("9 - GasesNobles\n");
	scanf("%d",&opcion);

	FILE * fichero1;
	FILE * fichero2;
	FILE * fichero3;
	FILE * fichero4;
	FILE * fichero5;
	FILE * fichero6;				
	FILE * fichero7;
	FILE * fichero8;
	FILE * fichero9;
			
	switch (opcion){
		case 1:
			
			fichero1=fopen("Alcalinos.txt","r");
			g=0;
			while(fscanf(fichero1,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}

			fclose(fichero1);
			
			for(i=0;i<7;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			
	        break;
		case 2:
			
			fichero2=fopen("Alcalinoterreos.txt","r");
			g=0;
			while(fscanf(fichero2,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}
			
			fclose(fichero2);
			
			for(i=0;i<6;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			
			break;
		case 3:
			
			fichero3=fopen("Metales_De_Transicion.txt","r");
			g=0;
			while(fscanf(fichero3,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}
				
			fclose(fichero3);
			
			for(i=0;i<40;i+=10){
				
				printf("%13s  (%2s) | %13s  (%2s)| %13s  (%2s)| %13s  (%2s)| %13s  (%2s)| %13s  (%2s)| %13s  (%2s)| %13s  (%2s)| %13s  (%2s)| %13s  (%2s)\n", Grupos[i].Nombre, Grupos[i].Simbolo, Grupos[i+1].Nombre, Grupos[i+1].Simbolo, Grupos[i+2].Nombre, Grupos[i+2].Simbolo, Grupos[i+3].Nombre, Grupos[i+3].Simbolo, Grupos[i+4].Nombre, Grupos[i+4].Simbolo, Grupos[i+5].Nombre, Grupos[i+5].Simbolo, Grupos[i+6].Nombre, Grupos[i+6].Simbolo, Grupos[i+7].Nombre, Grupos[i+7].Simbolo, Grupos[i+8].Nombre, Grupos[i+8].Simbolo, Grupos[i+9].Nombre, Grupos[i+9].Simbolo);
				
			}
			
			break;
		case 4:
			
			fichero4=fopen("Boroideos.txt","r");
			g=0;
			while(fscanf(fichero4,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}

			fclose(fichero4);
			
			for(i=0;i<6;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			
			break;
		case 5:
			
			fichero5=fopen("Carbonoideos.txt","r");
			g=0;
			while(fscanf(fichero5,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}

			fclose(fichero5);
			
			for(i=0;i<6;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			
			break;
		case 6:
			
			fichero6=fopen("Nitrogenoideos.txt","r");
			g=0;
			while(fscanf(fichero6,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}

			fclose(fichero6);
			
			for(i=0;i<6;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			
			break;
				
		case 7:
			
			fichero7=fopen("Anfigenos.txt","r");
			g=0;
			while(fscanf(fichero7,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}

			fclose(fichero7);
			
			for(i=0;i<6;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			
			break;
		case 8:
			
			fichero8=fopen("Halogenos.txt","r");
			g=0;
			while(fscanf(fichero8,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}
			
			fclose(fichero8);
			
			for(i=0;i<6;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			
			break;
		case 9:
				
			fichero9=fopen("Gases_Nobles.txt","r");
			g=0;
			while(fscanf(fichero9,"%s\t%s",Grupos[g].Nombre,Grupos[g].Simbolo)!=EOF){
				g++;
			}
			
			fclose(fichero9);
			
			for(i=0;i<7;i++){
			
				printf("%15s\t | (%s)\n", Grupos[i].Nombre, Grupos[i].Simbolo);
				
			}
			break;		
	}
}
void funcionPeriodos(){
	
	int i, h, opcion;
	
	struct ElemGP Periodos[32];
	
	printf("\nElija una de las siguientes opciones:\n");
	printf("PERIODOS:\n");
	printf("1 - Periodo 1.\n");
	printf("2 - Periodo 2.\n");
	printf("3 - Periodo 3.\n");
	printf("4 - Periodo 4.\n");
	printf("5 - Periodo 5.\n");
	printf("6 - Periodo 6.\n");
	printf("7 - Periodo 7.\n");
	scanf("%d", &opcion);
	
	FILE * fichero1;
	FILE * fichero2;
	FILE * fichero3;
	FILE * fichero4;
	FILE * fichero5;
	FILE * fichero6;
	FILE * fichero7;
	
	switch (opcion){
			case 1:
				
				fichero1=fopen("Per1.txt","r");
				h=0;
				while(fscanf(fichero1,"%s\t%s",Periodos[h].Nombre,Periodos[h].Simbolo)!=EOF){
					h++;
				}

				fclose(fichero1);
				
				for(i=0;i<2;i++){
				
					printf("%15s\t | (%s)\n", Periodos[i].Nombre,Periodos[i].Simbolo);
					
				}
				
		        break;
			case 2:
				
				fichero2=fopen("Per2.txt","r");
				h=0;
				while(fscanf(fichero2,"%s\t%s",Periodos[h].Nombre,Periodos[h].Simbolo)!=EOF){
					h++;
				}
				
				fclose(fichero2);
				
				for(i=0;i<8;i++){
				
					printf("%15s\t | (%s)\n", Periodos[i].Nombre,Periodos[i].Simbolo);
					
				}
				
				break;
			case 3:
				
				fichero3=fopen("Per3.txt","r");
				h=0;
				while(fscanf(fichero3,"%s\t%s",Periodos[h].Nombre,Periodos[h].Simbolo)!=EOF){
					h++;
				}
					
				fclose(fichero3);
				
				for(i=0;i<8;i++){
					
					printf("%15s | (%2s) \n", Periodos[i].Nombre, Periodos[i].Simbolo);
					
				}
				
				break;
			case 4:
				
				fichero4=fopen("Per4.txt","r");
				h=0;
				while(fscanf(fichero4,"%s\t%s", Periodos[h].Nombre, Periodos[h].Simbolo)!=EOF){
					h++;
				}

				fclose(fichero4);
				
				for(i=0;i<18;i++){
				
					printf("%15s\t | (%s)\n", Periodos[i].Nombre, Periodos[i].Simbolo);
					
				}
				
				break;
			case 5:
				
				fichero5=fopen("Per5.txt","r");
				h=0;
				while(fscanf(fichero5,"%s\t%s", Periodos[h].Nombre, Periodos[h].Simbolo)!=EOF){
					h++;
				}

				fclose(fichero5);
				
				for(i=0;i<18;i++){
				
					printf("%15s\t | (%s)\n", Periodos[i].Nombre, Periodos[i].Simbolo);
					
				}
				
				break;
			case 6:
				
				fichero6=fopen("Per6.txt","r");
				h=0;
				while(fscanf(fichero6,"%s\t%s", Periodos[h].Nombre, Periodos[h].Simbolo)!=EOF){
					h++;
				}

				fclose(fichero6);
				
				for(i=0;i<32;i++){
				
					printf("%15s\t | (%s)\n", Periodos[i].Nombre, Periodos[i].Simbolo);
					
				}
				
				break;
					
			case 7:
				
				fichero7=fopen("Per7.txt","r");
				h=0;
				while(fscanf(fichero7,"%s\t%s", Periodos[h].Nombre, Periodos[h].Simbolo)!=EOF){
					h++;
				}

				fclose(fichero7);
				
				for(i=0;i<32;i++){
				
					printf("%15s\t | (%s)\n", Periodos[i].Nombre, Periodos[i].Simbolo);
					
				}
				
				break;
	}
}
