	// ALUMNO: GABRIEL OCAMPO
	// DIVISION: 1°G
	// REPASO SABADOS EJERCICIO 1.2
	//Ejercicio 2:
	//Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en
	//qué orden fue ingresado.

	#include <stdio.h>
	#include <stdlib.h>

	int main(void) {
		int bufferInt;
		int posicionMaximo;
		int posicionMinimo;
		int i;
		int numeroMaximo;
		int numeroMinimo;

		for(i=0;i<5;i++)
		{
			printf("Ingrese el numero #%d: ",i+1);
			scanf("%d",&bufferInt);
			if(i==0)
			{
				numeroMaximo=bufferInt;
				numeroMinimo=bufferInt;
				posicionMaximo=i+1;
				posicionMinimo=i+1;
			}
			else
			{
				if(bufferInt>numeroMaximo)
				{
					numeroMaximo=bufferInt;
					posicionMaximo=i+1;
				}
				if(bufferInt<numeroMinimo)
				{
					numeroMinimo=bufferInt;
					posicionMinimo=i+1;
				}
			}
		}
		printf("El numero maximo es el %d y fue ingresado con el numero de orden #%d\n.",numeroMaximo,posicionMaximo);
		printf("El numero minimo es el %d y fue ingresado con el numero de orden #%d\n.",numeroMinimo,posicionMinimo);
		return 0;
	}


// para purgar antes de leer caracteres (letras, con numeros no hace falta) con scanf:
// fflush(stdio); en windows
//__fpurge;  en linux
