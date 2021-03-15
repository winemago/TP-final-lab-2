#ifndef TORNEOS_H_INCLUDED
#define TORNEOS_H_INCLUDED
const char NombrearchiJUGADORES[40]="Lista de Jugadores.bin";
Listatorneos * AgregarTorneo(Listatorneos * Lst, Jugador J);
Listatorneos * IniciarTorneo();
Listatorneos * CrearnodoTorneo(Jugador J);
Listatorneos * NuevoJugador(Listatorneos * Lst);
Listatorneos * Insertarjugador(Listatorneos * Lst, Jugador J);
Listatorneos * PasarArchiALista(Listatorneos * Lst);
void MostrarJugadores(Listatorneos * Lst);
Listatorneos * ModificarJugador(Listatorneos * Lst);
void PasarListaJugadoresAArchi(Listatorneos * Lst);



#endif // TORNEOS_H_INCLUDED
