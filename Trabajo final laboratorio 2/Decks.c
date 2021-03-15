#include "Estructuras.c"
#include "Estructuras.h"
#include "Decks.h"
#include "CartasColeccion.h"

ListaDecks * InicDeck()
{
    return NULL;
}

ListaDecks * CrearNodoDeck()
{
    ListaDecks * aux =(ListaDecks*)malloc(sizeof(ListaDecks));
    aux->Siguiente=NULL;
    aux->Cant=0;
    return aux;
}

ListaDecks * AgregarDeck(ListaDecks * Lista, ListaDecks * aux)
{
    if (Lista==NULL)
        Lista=aux;
    else
    {
        aux->Siguiente=Lista;
        Lista=aux;
    }
    return Lista;
}

void Verdecks(ListaDecks * Lista)
{
    ListaDecks * aux=Lista;
    while(aux!=NULL)
    {
        printf("\n-----------------");
        printf("\nNombre del mazo: %s", aux->nombredeck);
        aux=aux->Siguiente;
    }
    printf("\n-----------------");
}
ListaDecks * IngresarNuevoDeck(ListaDecks * Lst)
{
    ListaDecks * nn=CrearNodoDeck();
    printf("\nIngrese el nombre del mazo: ");
    fflush(stdin);
    gets(nn->nombredeck);
    arbol * arb=NULL;
    arb=PasararchiAarbol(arb);
    char carta[30];
    printf("\nIngrese las cartas que contiene el deck, deben estar almacenadas en la base de datos");
    printf("\n|Cartas Disponibles|");
    VernombresCartas(arb);
    printf("\n------------------");
    char control='s';
    arbol * aux=NULL;
    int i=0;
    while(control=='s')
    {
        printf("\nIngrese la carta que desea ingresar al mazo: ");
        fflush(stdin);
        gets(carta);
        aux=BuscarxNombre(arb, carta);
        printf("Buscando la carta %s ...", carta);
        if (aux!=NULL)
        {
            printf("\nLa carta se ha encontrado y se ha guardado");
            nn->card[i].card=aux->cartas;
            printf("\nCuantas copias desea ingresar?: ");
            scanf("%d", &nn->card[i].Cantidad);
            i++;
            nn->Cant++;
            printf("Desea seguir ingresando? s/n\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        else
        {
            printf("La carta no se ha encontrado, desea intentar nuevamente? s/n\n");
            fflush(stdin);
            scanf("%c", &control);
        }
    }
    Lst=AgregarDeck(Lst, nn);
    return Lst;
}

void BuscarMazo(ListaDecks * Lst)
{
    char D[30];
    Verdecks(Lst);
    char control='s';
    while (control=='s')
    {
        printf("\nIngrese el nombre del mazo que desea ver: ");
        fflush(stdin);
        gets(D);
        ListaDecks * aux=Lst;
        while (aux!=NULL && control=='s')
        {
            if (strcmp(D, aux->nombredeck)==0)
            {
                Vermazo(aux);
                aux=NULL;
                control='n';
            }
            else
                aux=aux->Siguiente;
        }
        if (control=='s')
        {
            printf("El mazo introducido no se encuentra en los archivos, desea intentar nuevamente? s/n");
            fflush(stdin);
            scanf("%c", &control);
        }
    }

}

void Vermazo(ListaDecks * D)
{
    int i=0;
    while(i<D->Cant)
    {
        printf("\n|%d x %s|", D->card[i].Cantidad, D->card[i].card.nombre);
        i++;
    }
    printf("\n\n");
}
void Guardardeck(ListaDecks * lista)
{
    FILE * archideck=fopen(NombrearchiDECK,"wb");
    RegistroDeck aux;
    ListaDecks * borrado;
    if(archideck!=NULL)
    {
        while(lista!=NULL)
        {
            int i=0;
            while(i<lista->Cant)
            {
                aux.card[i]=lista->card[i];

                i++;
            }
            aux.Cant=lista->Cant;
            strcpy(aux.nombredeck,lista->nombredeck);
            fwrite(&aux,sizeof(RegistroDeck),1,archideck);

            borrado=lista;
            lista=lista->Siguiente;
            free(borrado);
        }
        fclose(archideck);
    }
}
ListaDecks * ArchivodeckAstruct(ListaDecks * lista)
{
    FILE * archideck=fopen(NombrearchiDECK,"rb");
    RegistroDeck aux;
    ListaDecks * nuevo;

    if(archideck!=NULL)
    {
        while(fread(&aux,sizeof(RegistroDeck),1,archideck)>0)
        {
            int i=0;
            nuevo=CrearNodoDeck();
            nuevo->Cant=aux.Cant;
            while(i<nuevo->Cant)
            {
                nuevo->card[i]=aux.card[i];
                i++;
            }
            strcpy(nuevo->nombredeck,aux.nombredeck);
            lista=AgregarDeck(lista,nuevo);
        }
        fclose(archideck);
    }
    return lista;
}
void verarchi()
{
    FILE * archideck=fopen(NombrearchiDECK,"rb");
    RegistroDeck regis;
    if(archideck!=NULL)
    {
        while(fread(&regis,sizeof(RegistroDeck),1,archideck)>0)
        {
            printf("%s  %d",regis.nombredeck,regis.Cant);
        }
        fclose(archideck);
    }
}
void Modificardeck(ListaDecks * lista)
{
    char nombre[30];
    arbol * arb=IniciarArbol();
    arb=PasararchiAarbol(arb);
    arbol * aux=IniciarArbol();
    char control='s';
    char carta[20];

    printf("\ningrese nombre del deck a modificar: ");
    fflush(stdin);
    scanf("%s",nombre);

    while(lista!=NULL && strcmp(lista->nombredeck,nombre)!=0)
    {
        lista=lista->Siguiente;
    }

    if(lista!=NULL)
    {
        printf("\nIngrese nuevo nombre del mazo: ");
        fflush(stdin);
        gets(lista->nombredeck);
        lista->Cant=0;
        while(control=='s')
        {
            int i=0;
            printf("\n|Cartas Disponibles|");
            VernombresCartas(arb);
            printf("\nIngrese la carta que desea ingresar al mazo: ");
            fflush(stdin);
            gets(carta);

            aux=BuscarxNombre(arb, carta);
            printf("Buscando la carta %s ...", carta);
            if (aux!=NULL)
            {
                lista->card[i].card=aux->cartas;
                printf("\nLa carta se ha encontrado y se ha guardado");
                printf("\nCuantas copias desea ingresar?: ");
                scanf("%d", &lista->card[i].Cantidad);
                i++;
                lista->Cant++;

                printf("Desea seguir ingresando? s/n\n");
                fflush(stdin);
                scanf("%c", &control);
            }
            else
            {
                printf("La carta no se ha encontrado, desea intentar nuevamente? s/n\n");
                fflush(stdin);
                scanf("%c", &control);
            }
        }
    }
    else
    {
        printf("\n Deck no encontrado..");
    }
}


