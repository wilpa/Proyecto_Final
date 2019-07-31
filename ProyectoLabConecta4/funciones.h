#ifndef FUNCIONES_H
void mostrartablero(char *tablero);
int turno(char *tablero, int jugador, const char *fichas);
int revisa_si_gana(char *tablero);
int revisa_cuatro(char *tablero, int a, int b, int c, int d);
int revisa_horizontal(char *tablero);
int revisa_vertical(char *tablero);
int revisa_diagonal(char *tablero);
void score2();
int perdedor();
int ganador();
void score();
void juego_clasico();

typedef struct
{
    char *nombre;
}jugador;
#endif // FUNCIONES_H
