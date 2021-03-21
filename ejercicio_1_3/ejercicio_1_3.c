// ALUMNO: GABRIEL OCAMPO
// DIVISION: 1°H
// REPASO SABADOS 1.1
//Ejercicio 3:
//Realizar el algoritmo que permita ingresar los datos de los alumnos de una
//división de la UTN FRA, los datos solicitados son:
//Legajo
//Tipo cursada(L: &quot;libre&quot; - P: &quot;presencial&quot; – R: &quot;remota&quot;)
//Cantidad de materias( mas de cero y menos de 8)
//Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
//Nota promedio (entre 0 y 10)
//Edad (validar)
//Se debe informar de existir, o informar que no existe , en el caso que
//corresponda.
//a) El Legajo del mejor promedio femenino.
//b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
//c) El promedio de nota por sexo.
//d) La edad y legajo del que cursa más materias. (Sin importar su género)

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
	int numeroLegajo;
	char tipoCursada; // l-libre / p-presencial / r-remota
	int cantidadMaterias; // entre 0 y 8
	char sexoAlumno; // m-masculino / f-femenino / o-no binario
	int notaPromedio; // entre 0 y 10
	int edadAlumno;
	int continuar;
	int flagMejorPromedioFemenino=TRUE;
	int legajoMejorPromedioFemenino;
	int promedioMejorPromedioFemenino;
	int flagMasJovenMasculinoLibre=TRUE;
	int legajoMasJovenMasculinoLibre;
	int edadMasJovenMasculinoLibre;
	int acumuladorNotaMasculino=0;
	int contadorMasculino=0;
	float promedioNotaMasculino;
	int acumuladorNotaFeminino=0;
	int contadorFemenino=0;
	float promedioNotaFemenino;
	int acumuladorNotaNoBinario=0;
	int contadorNoBinario=0;
	float promedioNotaNoBinario;
	int flagMasMaterias=TRUE;
	int edadMasMaterias;
	int legajoMasMaterias;
	int cantidadMasMaterias;

	do
	{
		printf("Ingrese el numero de legajo: ");
		scanf("%d",&numeroLegajo);
		while(numeroLegajo<0)
		{
			printf("Dato no valido. Ingrese el numero de legajo: ");
			scanf("%d",&numeroLegajo);
		}
		printf("Ingrese el tipo de cursada (l:libre / p:presencial / r:remota): ");
		__fpurge(stdin);
		scanf("%c",&tipoCursada);
		while(tipoCursada!='l' && tipoCursada!='p' && tipoCursada!='r')
		{
			printf("Dato no valido. Ingrese el tipo de cursada (l:libre / p:presencial / r:remota): ");
			__fpurge(stdin);
			scanf("%c",&tipoCursada);
		}
		printf("Ingrese la cantidad de materias (entre 1 y 8): ");
		scanf("%d",&cantidadMaterias);
		while(cantidadMaterias<1 || cantidadMaterias>8)
		{
			printf("Dato no valido. Ingrese la cantidad de materias (entre 1 y 8): ");
			scanf("%d",&cantidadMaterias);
		}
		printf("Ingrese el sexo del alumno (m:masculino / f:femenino / o:no binario): ");
		__fpurge(stdin);
		scanf("%c",&sexoAlumno);
		while(sexoAlumno!='m' && sexoAlumno!='f' && sexoAlumno!='o')
		{
			printf("Dato no valido. Ingrese el sexo del alumno (m:masculino / f:femenino / o:no binario): ");
			__fpurge(stdin);
			scanf("%c",&sexoAlumno);
		}
		printf("Ingrese el promedio de notas (entre 0 y 10)");
		scanf("%d",&notaPromedio);
		while(notaPromedio<0 || notaPromedio>10)
		{
			printf("Dato no valido. Ingrese el promedio de notas (entre 0 y 10): ");
			scanf("%d",&notaPromedio);
		}
		printf("Ingrese la edad del alumno: ");
		scanf("%d",&edadAlumno);
		while(edadAlumno<0 || edadAlumno>150)
		{
			printf("Dato no valido. Ingrese la edad del alumno: ");
			scanf("%d",&edadAlumno);
		}
		switch(sexoAlumno)
		{
			case 'm':
				acumuladorNotaMasculino+=notaPromedio;
				contadorMasculino++;
				if(tipoCursada=='l')
				{
					if(flagMasJovenMasculinoLibre)
					{
						legajoMasJovenMasculinoLibre=numeroLegajo;
						edadMasJovenMasculinoLibre=edadAlumno;
						flagMasJovenMasculinoLibre=FALSE;
					}
					else if(edadAlumno<edadMasJovenMasculinoLibre)
					{
						legajoMasJovenMasculinoLibre=numeroLegajo;
						edadMasJovenMasculinoLibre=edadAlumno;
					}
				}
				break;
			case 'f':
				acumuladorNotaFeminino+=notaPromedio;
				contadorFemenino++;
				if(flagMejorPromedioFemenino)
				{
					promedioMejorPromedioFemenino=notaPromedio;
					legajoMejorPromedioFemenino=numeroLegajo;
					flagMejorPromedioFemenino=FALSE;
				}
				else if(notaPromedio>promedioMejorPromedioFemenino)
				{
					promedioMejorPromedioFemenino=notaPromedio;
					legajoMejorPromedioFemenino=numeroLegajo;
				}
				break;
			case 'o':
				acumuladorNotaNoBinario+=notaPromedio;
				contadorNoBinario++;
				break;
		}
		if(flagMasMaterias)
		{
			edadMasMaterias=edadAlumno;
			legajoMasMaterias=numeroLegajo;
			cantidadMasMaterias=cantidadMaterias;
			flagMasMaterias=FALSE;
		}
		else if(cantidadMaterias>cantidadMasMaterias)
		{
			edadMasMaterias=edadAlumno;
			legajoMasMaterias=numeroLegajo;
			cantidadMasMaterias=cantidadMaterias;
		}
		printf("\n¿Desea ingresar otro alumno? [si:1 / no:0]");
		scanf("%d",&continuar);
	}while(continuar==1);

	if(contadorMasculino>0)
	{
		promedioNotaMasculino=acumuladorNotaMasculino/(float)contadorMasculino;
	}
	if(contadorFemenino>0)
	{
		promedioNotaFemenino=acumuladorNotaFeminino/(float)contadorFemenino;
	}
	if(contadorNoBinario>0)
	{
		promedioNotaNoBinario=acumuladorNotaNoBinario/(float)contadorNoBinario;
	}

	if(flagMejorPromedioFemenino==FALSE)
	{
		printf("a) El Legajo del mejor promedio femenino es: %d\n",legajoMejorPromedioFemenino);
	}
	else
	{
		printf("a) No se ingresaron alumnos femeninos\n");
	}
	if(flagMasJovenMasculinoLibre==FALSE)
	{
		printf("b) El legajo del más joven de los alumnos masculinos que da libre es: %d\n",legajoMasJovenMasculinoLibre);
	}
	else
	{
		printf("b) No se ingresaron alumnos masculinos que rindan libre\n");
	}
	printf("c) El promedio de nota por sexo:\n");
	if(contadorMasculino>0)
	{
		printf("* masculino: %.02f\n",promedioNotaMasculino);
	}
	else
	{
		printf("* no se ingresaron alumnos masculinos\n");
	}
	if(contadorFemenino>0)
	{
		printf("* femenino: %.02f\n",promedioNotaFemenino);
	}
	else
	{
		printf("* no se ingresaron alumnos femeninos\n");
	}
	if(contadorNoBinario>0)
	{
		printf("* no binario: %.02f\n",promedioNotaNoBinario);
	}
	else
	{
		printf("* no se ingresaron alumnos no binarios\n");
	}
	printf("d) La edad y legajo del que cursa más materias: \n"
			"* edad: %d\n* legajo: %d", edadMasMaterias,legajoMasMaterias);
	return 0;
}


// para purgar antes de leer caracteres (letras, con numeros no hace falta) con scanf:
// fflush(stdio); en windows
//__fpurge();  en linux
