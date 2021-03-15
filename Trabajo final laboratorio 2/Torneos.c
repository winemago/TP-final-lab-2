#include "Estructuras.c"
#include "Estructuras.h"
#include "Torneos.h"
#include "string.h"

Listatorneos * IniciarTorneo()
{
    return NULL;
}

Listatorneos * CrearnodoTorneo(Jugador J)
{
    Listatorneos * aux= (Listatorneos*)malloc(sizeof(Listatorneos));
    aux->ListadeJugadores=NULL;
    aux->T.Anio=J.annio;
    strcpy(aux->T.NombreTorneo, J.Torne);
    aux->Anteriores=NULL;
    return aux;
}

ListaDeJugador * CrearNodoJugador(Jugador J)
{
    ListaDeJugador * aux= (ListaDeJugador*)malloc(sizeof(ListaDeJugador));
    aux->siguiente=NULL;
    aux->Jug=J;
    return aux;
}

Listatorneos * AgregarTorneo(Listatorneos * Lst, Jugador J)
{
    Listatorneos * aux=CrearnodoTorneo(J);
    if (Lst==NULL)
    {
        Lst=aux;
    }
    else
    {
        aux->Anteriores=Lst;
        Lst=aux;
    }
    return Lst;
}

ListaDeJugador * AgregarJugador(ListaDeJugador * Lst, Jugador J)
{
    ListaDeJugador * aux=CrearNodoJugador(J);
    if (Lst==NULL)
    {
        Lst=aux;
    }
    else
    {
        aux->siguiente=Lst;
        Lst=aux;
    }
    return Lst;
}

Listatorneos * NuevoJugador(Listatorneos * Lst)
{
    Jugador J;
    printf("\nIngrese el Nombre del Torneo: ");
    fflush(stdin);
    gets(J.Torne);
    printf("\nIngrese el anio que se realizo el torneo: ");
    scanf("%d", &J.annio);
    printf("\nIngrese el nombre del Jugador: ");
    fflush(stdin);
    scanf("%s", J.Nombre);
    printf("\nIngrese el apellido del jugador: ");
    fflush(stdin);
    scanf("%s", J.Apellido);
    printf("\nIngrese el documento del Jugador: ");
    scanf("%ld", &J.Documento);
    printf("\nIngrese la posicion del Jugador en el torneo: ");
    fflush(stdin);
    scanf("%s", J.Posicion);
    Lst=Insertarjugador(Lst, J);
    printf("Se ha ingresado al jugador con exito!");
    return Lst;
}

Listatorneos * Insertarjugador(Listatorneos * Lst, Jugador J)
{
    if(Lst==NULL)
    {
        Lst=AgregarTorneo(Lst, J);
        Lst->ListadeJugadores=AgregarJugador(Lst->ListadeJugadores, J);
    }
    else
    {
        Listatorneos * aux=Lst;
        int flag=0;
        while (aux!=NULL && flag==0)
        {
            if(strcmp(aux->T.NombreTorneo, J.Torne)==0)
                if(aux->T.Anio==J.annio)
            {
                flag=1;
                aux->ListadeJugadores=AgregarJugador(aux->ListadeJugadores, J);
            }
            if (flag==0)
                aux=aux->Anteriores;
        }
        if (flag==0)
        {
            Lst=AgregarTorneo(Lst, J);
            Lst->ListadeJugadores=AgregarJugador(Lst->ListadeJugadores, J);
        }

    }
    return Lst;
}

Listatorneos * ModificarJugador(Listatorneos * Lst)
{
    char Nombre[40];
    char Apellido[40];
    int opcion;
    int flag=0;
    char control='s';
    Listatorneos * aux=Lst;
    while (flag==0 && control=='s')
    {
        printf("Ingrese el nombre del jugador que desea modificar: ");
        fflush(stdin);
        scanf("%s", Nombre);
        printf("Ingrese el apellido del jugador que desea modificar: ");
        fflush(stdin);
        scanf("%s", Apellido);
        while (aux!=NULL && flag==0)
        {
            while (aux->ListadeJugadores!=NULL && flag==0)
            {
                if (strcmp(aux->ListadeJugadores->Jug.Nombre, Nombre)==0)
                    if(strcmp(aux->ListadeJugadores->Jug.Apellido, Apellido)==0)
                {
                    flag=1;
                }
            if (flag==0)
                aux->ListadeJugadores=aux->ListadeJugadores->siguiente;
            }
        if (flag==0)
            aux=aux->Anteriores;
        }
        if (flag==0)
        {
            printf("\nNo hay registros del jugador ingresado. Desea volver a intentar? s/n\n");
            fflush(stdin);
            scanf("%c", &control);
        }
    }
    if (control=='s')
    {
    printf("\nQue dato desea modificar?");
    printf("\n1-Nombre del Jugador");
    printf("\n2-Apellido del Jugador");
    printf("\n3-Documento del Jugador");
    printf("\n4-Posicion");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        printf("Ingrese el nuevo nombre del jugador:");
        fflush(stdin);
        scanf("%s", aux->ListadeJugadores->Jug.Nombre);
        break;
    case 2:
        printf("Ingrese el nuevo apellido del jugador:");
        fflush(stdin);
        scanf("%s", aux->ListadeJugadores->Jug.Apellido);
        break;
    case 3:
        printf("Ingrese el nuevo documento del jugador:");
        scanf("%ld", &aux->ListadeJugadores->Jug.Documento);
        break;
    case 4:
        printf("Ingrese la posicion del jugador:");
        fflush(stdin);
        scanf("%s", aux->ListadeJugadores->Jug.Posicion);
        break;

    }
    }
    return Lst;
}

void PasarListaJugadoresAArchi(Listatorneos * Lst)
{
    FILE *archi;
    Jugador J;
    archi=fopen(NombrearchiJUGADORES, "wb");
    if (archi!=NULL)
    {
        while (Lst!=NULL)
        {
            while (Lst->ListadeJugadores!=NULL)
            {
                J=Lst->ListadeJugadores->Jug;
                fwrite(&J, sizeof(Jugador), 1,archi);
                Lst->ListadeJugadores=Lst->ListadeJugadores->siguiente;
            }
            Lst=Lst->Anteriores;
        }
        fclose(archi);
    }

}

Listatorneos * PasarArchiALista(Listatorneos * Lst)
{
    FILE *archi;
    Jugador J;
    archi=fopen(NombrearchiJUGADORES, "rb");
    if (archi!=NULL)
    {
        while (fread(&J, sizeof(Jugador), 1, archi)>0)
        {
            Lst=Insertarjugador(Lst, J);
        }
        fclose(archi);
    }
    return Lst;
}

void MostrarJugadores(Listatorneos * Lst)
{
    ListaDeJugador * aux;
    while(Lst!=NULL)
    {
        printf("\n/----------------------/");
        printf("\n|Torneo: %s %d|", Lst->T.NombreTorneo, Lst->T.Anio);
        aux=Lst->ListadeJugadores;
        while (aux!=NULL)
        {
            printf("\n/----------------------/");
            printf("\nJugador: %s %s", aux->Jug.Nombre, aux->Jug.Apellido);
            printf("\nDocumento: %ld", aux->Jug.Documento);
            printf("\nPosicion: %s", aux->Jug.Posicion);
            aux=aux->siguiente;
        }
        Lst=Lst->Anteriores;
    }
}



















