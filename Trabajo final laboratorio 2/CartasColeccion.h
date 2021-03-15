#ifndef CARTASCOLECCION_H_INCLUDED
#define CARTASCOLECCION_H_INCLUDED
const char NombrearchiCARTAS[40]="Lista de cartas.bin";
arbol * AgregarCartas(arbol * arbolcarta);
arbol * IniciarArbol();
arbol * crearNodoArbol(carta card);
arbol * insertar(arbol * arbol, carta card);
arbol * PasararchiAarbol();
arbol * BuscarxNombre(arbol * arb, char nombre[]);
void BuscarxCostemana(arbol*arb, int Coste);
void MostrarCarta(arbol * arb);
void BuscarxColor(arbol*arb, int Color);
int BuscarxFuerza(arbol * arb, int Fuerza);
void BuscarxResistencia(arbol * arb, int Resistencia);
void Buscarxtipo(arbol * arb, int Tipo);
void Leercarta();
void recorreryescribir(arbol * arb, FILE * archi);
void PasarArbolaArchi(arbol * arb);
void VernombresCartas(arbol * arb);
void Vercoleccion(arbol * arb);
void BuscarCarta(arbol * arb);
arbol * ModificarCarta(arbol * arbolcarta);
void mostrarefecto(char Ef[]);

#endif // CARTASCOLECCION_H_INCLUDED
