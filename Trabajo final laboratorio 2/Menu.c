#include "Menu.h"
#include "Estructuras.c"
#include "CartasColeccion.c"
#include "Torneos.c"
#include "Decks.c"
void Iniciarmenu()
{
    int salida;
    do
    {
        system("cls");
        printf("Bienvenido al software de Magic: The programming\n");
        system("pause");
        printf("\n\n");
        salida = SwitchMenuPrincipal();
    }
    while (salida != 0);
}

int IngreseOpcion()
{
    int opcion = 0;
    printf("\nIngrese una opcion\n");
    scanf("%d", &opcion);
    return opcion;
}

int SwitchMenuPrincipal()
{
    int opciones=0;

    system("cls");
    OpcionesMenuPrincipal();
    opciones = IngreseOpcion();
    switch(opciones)
    {
    case 0:
        printf("Saliendo");
        break;
    case 1:
        SubMenuColeccion();
        break;
    case 2:
        SubMenuJugadores();
        break;
    case 3:
        SubMenuDecks();
        break;
    default:
        printf("Opcion incorrecta\n");
        break;
    }

    return opciones;
}

void SubMenuColeccion()
{
    system("cls");
    printf("Ha ingresado al menu de Coleccion de Cartas\n");
    arbol * arb=IniciarArbol();
    arb=PasararchiAarbol(arb);
    int opciones=0;
    do
    {
        OpcionesSubMenuColeccion();
        opciones = IngreseOpcion();
        switch(opciones)
        {
            case 1:
                printf("\nHa elegido la opcion de ingresar una Carta\n");
                system("pause");
                system("cls");
                arb=AgregarCartas(arb);
                break;
            case 2:
                printf("\nHa elegido la opcion de Ver la coleccion\n");
                system("pause");
                system("cls");
                Vercoleccion(arb);
                if (arb==NULL)
                    printf("Aun no hay cartas en la base de datos\n");
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            case 3:
                printf("\nHa elegido la opcion de Buscar Cartas\n");
                system("pause");
                system("cls");
                BuscarCarta(arb);
                system("pause");
                system("cls");
                break;
            case 4:
                printf("\nHa elegido la opcion de modificar una Carta\n");
                system("pause");
                system("cls");
                arb=ModificarCarta(arb);
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
        }
            PasarArbolaArchi(arb);
    }
    while (opciones!=0);

}

void SubMenuJugadores()
{
    system("cls");
    printf("Ha ingresado al menu de Jugadores\n");
    Listatorneos * Lst;
    int opciones=0;
    do
    {
    Lst=IniciarTorneo();
    Lst=PasarArchiALista(Lst);
    OpcionesSubMenuJugadores();
    opciones = IngreseOpcion();
     switch(opciones)
     {
     case 1:
        printf("\nHa elegido la opcion de Agregar Jugador\n");
        system("pause");
        system("cls");
        Lst=NuevoJugador(Lst);
        printf("\n");
        system("pause");
        system("cls");
        break;
     case 2:
        printf("\nHa elegido la opcion de Ver todos los jugadores\n");
        system("pause");
        system("cls");
        MostrarJugadores(Lst);
        if(Lst==NULL)
            printf("Aun no hay jugadores en la base de datos");
        printf("\n");
        system("pause");
        system("cls");
        break;
     case 3:
        printf("\nHa elegido la opcion de modificar un jugador\n");
        system("pause");
        system("cls");
        Lst=ModificarJugador(Lst);
        printf("\n");
        system("pause");
        system("cls");
        break;
     default:
        printf("\nOpcion incorrecta\n");
        break;
     }
     PasarListaJugadoresAArchi(Lst);
    }
    while(opciones!=0);
}

void SubMenuDecks()
{
    system("cls");
    printf("Ha ingresado al menu de Mazos\n");
    ListaDecks * Lista;
    Lista=InicDeck();
    Lista=ArchivodeckAstruct(Lista);
    int opciones;
    do
    {
        OpcionesSubmenuDecks();
        opciones=IngreseOpcion();
        switch(opciones)
        {
        case 1:
            printf("Ha elegido la opcion de Agregar un mazo");
            system("pause");
            system("cls");
            Lista=IngresarNuevoDeck(Lista);

            break;
        case 2:
            printf("Ha elegido la opcion de modificar un mazo");
            system("pause");
            system("cls");
            Modificardeck(Lista);
            break;
        case 3:
            printf("Ha elegido la opcion de mostrar todos los mazos");
            system("pause");
            system("cls");
            Verdecks(Lista);
            printf("\n");
            break;
        case 4:
            printf("Ha elegido la opcion de buscar un mazo");
            system("pause");
            system("cls");
            BuscarMazo(Lista);
            break;
        default:
            printf("Opcion incorrecta");
            break;
        }

    }
    while(opciones!=0);
    Guardardeck(Lista);
}

void OpcionesMenuPrincipal()
{
    printf("Menu principal");
    printf("\n---------------");
    printf("\n1- Coleccion de Cartas");
    printf("\n2- Jugadores");
    printf("\n3- Repertorio de Mazos");
    printf("\n0- Salir\n");
}

void OpcionesSubMenuColeccion()
{
    printf("Coleccion de cartas");
    printf("\n------------------");
    printf("\n1-Ingresar una carta");
    printf("\n2-Ver la coleccion");
    printf("\n3-Buscar Carta");
    printf("\n4-Modificar carta");
    printf("\n0-Volver al menu principal\n");
}

void OpcionesSubMenuJugadores()
{
    printf("Jugadores");
    printf("\n-----------------");
    printf("\n1- Agregar Jugador");
    printf("\n2- Ver todos los jugadores");
    printf("\n3- Modificar jugador");
    printf("\n0- Volver al menu principal\n");
}

void OpcionesSubmenuDecks()
{
    printf("\nMazos");
    printf("\n-----------------");
    printf("\n1-Agregar un mazo");
    printf("\n2-Modificar mazo");
    printf("\n3-Mostrar todos los mazos");
    printf("\n4-Buscar mazo");
    printf("\n0-Volver al menu principal\n");
}
