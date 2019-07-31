#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILAS 6      //constantes para la matriz 6x7
#define COLUMNAS 7
#include "funciones.h"
void mostrartablero(char *tablero) //funcion que muestra
{
   int fila, columna;
   system("cls");
    system("color 70"); //color a la ventana
   puts("****CONECTA 4****\n");
   for(fila=0;fila<FILAS;fila++)
    {
      for(columna=0;columna<COLUMNAS;columna++)
      {
         printf("| %c ",tablero[COLUMNAS*fila+columna]); //permite colocar las fichas en el tablero
      }
      puts("|");
      puts("-----------------------------");
   }
   puts("  1   2   3   4   5   6   7\n");

}
int turno(char *tablero, int jugador, const char *fichas)
{
   int fila, columna=0;
   int i;
   printf("Jugador %d (%c):\nIngrese el numero de la columna: ", jugador + 1, fichas[jugador]);

   while(1)
    {
      if(1 != scanf("%d", &columna) || columna < 1 || columna > 7 )
      {
         while(getchar() != '\n');
         tablero = (char *) realloc(tablero, (i + 2) * sizeof(char));
         puts("Numero incorrecto!");
      } else {
         break;
      }
    }
   columna--;

   for(fila=FILAS-1;fila>=0;fila--)
    {
      if(tablero[COLUMNAS*fila+columna] == ' ')
      {
         tablero[COLUMNAS*fila+columna]=fichas[jugador];
         return 1;
      }
    }
   return 0;

}
int revisa_si_gana(char *tablero) //revisa las funciones en las diferentes formas que se puede ganar
{
    return (revisa_horizontal(tablero)||revisa_vertical(tablero)||revisa_diagonal(tablero));

}
int revisa_cuatro(char *tablero, int a, int b, int c, int d) //revisa el lugar de la ficha y los espacios en blanco
{
    return (tablero[a] == tablero[b] && tablero[b] == tablero[c] && tablero[c] == tablero[d] && tablero[a] != ' ');

}
int revisa_horizontal(char *tablero)
{
    int fila, columna, ordenar;
    const int ancho=1;

    for(fila=0;fila<FILAS;fila++)
        {
       for(columna=0;columna<COLUMNAS-3;columna++) //revisa horizontal y entra las ganadas en 4 columnas
       {
          ordenar=COLUMNAS*fila+columna;
          if(revisa_cuatro(tablero, ordenar, ordenar+ancho, ordenar+ancho*2, ordenar+ancho*3))
          {
             return 1;
          }
       }
    }
    return 0;

}
int revisa_vertical(char *tablero)
{
    int fila, columna, ordenar;
    const int alto=7;

    for(fila=0;fila<FILAS-3;fila++) //revisa horizontal y entra las ganadas en 4 filas
        {
       for(columna= 0; columna<COLUMNAS;columna++){
          ordenar=COLUMNAS*fila+columna;
          if(revisa_cuatro(tablero, ordenar, ordenar+alto, ordenar+alto*2, ordenar+alto*3)){
              return 1;
          }
       }
    }
    return 0;

}
int revisa_diagonal(char *tablero)
{
   int fila, columna, ordenar, cont=0;
   const int diagonal_der=6, diagonal_izq=8; //debido al tamaño de la matriz para poder ganar ubicando las fichas diagonal

   for(fila=0;fila<FILAS-3;fila++)
    {
      for(columna=0;columna<COLUMNAS;columna++){
         ordenar=COLUMNAS*fila+columna;
         if(cont<=3 && revisa_cuatro(tablero, ordenar, ordenar+diagonal_izq, ordenar+diagonal_izq*2, ordenar+diagonal_izq*3) || cont>= 3 && revisa_cuatro(tablero, ordenar, ordenar+diagonal_der, ordenar+diagonal_der*2, ordenar+diagonal_der*3)){
            return 1;
         }
         cont++;
      }
      cont=0;
   }
   return 0;

}
void menu()
{
    int opt;
    system("color 70");
 printf("Bienvenidos al juego Conecta 4!\n");
 printf("\n\n");
    printf("Seleccione lo que desea hacer:\n");
    printf("1. Nuevo Juego\n");
    printf("2. Scores\n");
    printf("3. Salir\n");
    printf("\n");
    scanf("%d", &opt);
     system("cls");
        switch (opt)
        {
            case 1:
                 juego_clasico();
                 return menu();
                break;
            case 2:
                score();
                score2();
                  break;
            case 3:
                break;
            default:
                printf("El valor introducido no es valido\n");
                printf("Intente de nuevo: \n");
                scanf("%d", &opt);
                break;
        }
}
void juego_clasico()
{
     const char *fichas= "XO";
   char tablero[FILAS*COLUMNAS];
   memset(tablero, ' ',FILAS*COLUMNAS); //chequea si esta vacio y me le asigna la ficha mucho mas rapido por ejemplo "columnas" es el nombre de la variable, "0" es el valor que vas a guardar, en "n" lugares, que en este caso es el tamaño de la variable columnas

   int turno_otro, jugada=0;

   for(turno_otro=0;turno_otro<FILAS*COLUMNAS&&!jugada; turno_otro++){
      mostrartablero(tablero);
      while(!turno(tablero, turno_otro%2, fichas)) //revisa si la columna ya no admite mas fichas
        {
         mostrartablero(tablero);
         puts("La columna esta llena!\n");
      }
      jugada= revisa_si_gana(tablero);

   }
    mostrartablero(tablero);

   if(turno_otro ==FILAS*COLUMNAS&&!jugada){
      puts("Hay un empate!");
   } else {
      turno_otro--;
      printf("Jugador %d (%c) GANA!\n", turno_otro % 2 + 1, fichas[turno_otro%2]);
      printf("\n");
      ganador();
      perdedor();
        system("cls");
   }
}
int ganador() //guarda el nombre de los ganadores
{
    char nombre[30];
    FILE *archivo;
    archivo=fopen("ganador.txt","a+");
    if(archivo==NULL)
    {
        return -1;
    }
    else
    {
    printf("Ingrese el nombre del ganador: ");
    printf("\n");
    scanf("%s",nombre);
    fprintf(archivo,"%s\n",nombre);
    fclose(archivo);
    return 1;
    }
}
void score() //guarda el nombre de los jugadores que han ganado
{
    FILE *scorear;
    scorear = fopen("ganador.txt", "r");
     char nom[30];

    if (nom!=-1)
    {
        printf("\nNombres de Jugadores Ganadores\n\n");
        while(fgets(nom, 30,scorear))
        {
            printf("%s", nom);
        }

    }

    fclose(scorear);
}
int perdedor()
{
    char nombre[30];
    FILE *archivo;
    archivo=fopen("perdedor.txt","a+");
    if(archivo==NULL)
    {
        return -1;
    }
    else
    {
    printf("Ingrese el nombre del perdedor: \n ");
    scanf("%s",nombre);
    fprintf(archivo,"%s\n",nombre);
    fclose(archivo);
    return 1;
    }
}
void score2() //guarda el nombre de los jugadores que han perdido
{
    FILE *scorear;
    scorear = fopen("perdedor.txt", "r");
     char nom[30];

    if (nom!=-1)
    {
        printf("\nNombres de Jugadores Perdedores\n\n");
        while(fgets(nom, 30,scorear))
        {
            printf("%s", nom);
        }

    }

    fclose(scorear);
}


