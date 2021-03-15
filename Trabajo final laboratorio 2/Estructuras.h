#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

typedef struct
{
    char nombre[50];
    int costemana;
    int fuerza;
    int resistencia;
    int color; // 1-Azul 2-Blanco 3-Negro 4-Rojo 5-Verde 6-incoloro
    char efecto[500];
    int tipo; // 1- Criatura 2-Tierra 3-Conjuro 4-Instantaneo 5-Encantamiento
} carta;

typedef struct arbol
{
    struct arbol * izq;
    struct arbol * der;
    carta cartas;
} arbol;

typedef struct
{
    char NombreTorneo[30];
    char Campeon[30];
    int Anio;
} Torneo;

typedef struct
{
    carta card;
    int Cantidad;
} deck;

typedef struct ListaDecks
{
    deck card[40];
    int Cant;
    char nombredeck[50];
    struct ListaDecks * Siguiente;
} ListaDecks;

typedef struct
{
    deck card[40];
    int Cant;
    char nombredeck[50];
}RegistroDeck;

typedef struct
{
    char Nombre[20];
    char Apellido[20];
    long int Documento;
    char Posicion[20];
    char Torne[20];
    int annio;
} Jugador;

typedef struct ListaDeJugador
{
    Jugador Jug;
    struct ListaDeJugador * siguiente;
} ListaDeJugador;

typedef struct Listatorneos
{
    Torneo T;
    struct Listatorneos * Anteriores;
    ListaDeJugador * ListadeJugadores;
} Listatorneos;

#endif // ESTRUCTURAS_H_INCLUDED
