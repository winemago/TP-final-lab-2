#ifndef DECKS_H_INCLUDED
#define DECKS_H_INCLUDED
const char NombrearchiDECK[40]="arreglo_de_decks.bin";
ListaDecks * InicDeck();
ListaDecks * CrearNodoDeck();
void Verdecks(ListaDecks * Lista);
ListaDecks * IngresarNuevoDeck(ListaDecks * Lst);
ListaDecks * AgregarDeck(ListaDecks * Lista, ListaDecks * aux);
void BuscarMazo(ListaDecks * Lst);
void Vermazo(ListaDecks * D);
void Guardardeck(ListaDecks * lista);
void verarchi();
ListaDecks * ArchivodeckAstruct(ListaDecks * lista);
void Modificardeck(ListaDecks * lista);
#endif // DECKS_H_INCLUDED
