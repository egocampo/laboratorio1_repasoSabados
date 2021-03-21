// ALUMNO: GABRIEL OCAMPO
// DIVISION: 1°H
// REPASO SABADOS 1.1

//Ejercicio 1:
//Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
//a) El promedio de los números positivos.
//b) El promedio de los números negativos.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int bufferInt;
	int acumuladorPositivos=0;
	int acumuladorNegativos=0;
	int contadorPositivos=0;
	int contadorNegativos=0;
	float promedioPositivos;
	float promedioNegativos;
	int continuar;

	do
	{
		printf("Ingrese un numero: ");
		scanf("%d",&bufferInt);
		if(bufferInt>0)
		{
			acumuladorPositivos+=bufferInt;
			contadorPositivos++;
		}
		else if(bufferInt<0)
		{
			acumuladorNegativos+=bufferInt;
			contadorNegativos++;
		}
		printf("¿Desea ingresar otro numero? [si:1 / no:0]");
		scanf("%d",&continuar);
	}while(continuar==1);
	if(contadorPositivos!=0)
	{
		promedioPositivos=(float)acumuladorPositivos/contadorPositivos;
	}
	if(contadorNegativos!=0)
	{
		promedioNegativos=(float)acumuladorNegativos/contadorNegativos;
	}
	if(contadorPositivos!=0)
	{
		printf("a) El promedio de positivos es: %.02f\n",promedioPositivos);
	}
	else
	{
		printf("a) No se ingresaron numeros positivos\n");
	}
	if(contadorNegativos!=0)
	{
		printf("a) El promedio de negativos es: %.02f\n",promedioNegativos);
	}
	else
	{
		printf("a) No se ingresaron numeros negativos\n");
	}
	return 0;
}


// para purgar antes de leer caracteres (letras, con numeros no hace falta) con scanf:
// fflush(stdio); en windows
//__fpurge;  en linux
