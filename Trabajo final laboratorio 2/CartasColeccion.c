#include "Estructuras.c"
#include "Estructuras.h"
#include "CartasColeccion.h"
#include "string.h"
#define ANCHOCARTA 28
#define AlTOIMAGEN 7

arbol * IniciarArbol()
{
    return NULL;
}

arbol * crearNodoArbol(carta card)
{
arbol * aux = (arbol *)malloc(sizeof(arbol));
aux->der=NULL;
aux->izq=NULL;
aux->cartas=card;
return aux;
}

arbol * insertar(arbol * arb, carta card)
{
    if(arb==NULL)
        arb = crearNodoArbol(card);
    else
    {
        if(card.costemana>arb->cartas.costemana)
            arb->der = insertar(arb->der, card);
        else
            arb->izq = insertar(arb->izq, card);
    }
    return arb;
}

arbol * PasararchiAarbol(arbol * arb)
{
    FILE *archi;
    carta card;
    archi= fopen(NombrearchiCARTAS, "rb");
    if (archi!=NULL)
    {
        while (fread(&card, sizeof(carta),1,archi)>0)
        {
            arb=insertar(arb, card);
        }
        fclose(archi);
    }
    return arb;
}

void PasarArbolaArchi(arbol * arb)
{
    FILE *archi;
    archi= fopen(NombrearchiCARTAS, "wb");
    if (archi!=NULL)
    {
        recorreryescribir(arb, archi);
        fclose(archi);
    }

}

void recorreryescribir(arbol * arb, FILE * archi)
{
    carta A;
    if (arb!=NULL)
    {

        A=arb->cartas;
        fwrite(&A, sizeof(A), 1, archi);
        recorreryescribir(arb->izq, archi);
        recorreryescribir(arb->der, archi);
    }
}

void Vercoleccion(arbol * arb)
{
    if (arb!=NULL)
    {

        Vercoleccion(arb->izq);
        printf("\n");
        MostrarCarta(arb);
        printf("\n");
        Vercoleccion(arb->der);
    }
}

void MostrarCarta(arbol * arb)
{
    int i=0;
    int j=0;
    printf("\n");
    //ESTA ES LA PARTE DE ARRIBA DE LA CARTA
    for (i=0; i<ANCHOCARTA; i++)
        printf("-");
    //Renglon de nombre carta y mana
    printf("\n|%s", arb->cartas.nombre);
    for (i=0; i<ANCHOCARTA-(strlen(arb->cartas.nombre)+3); i++)
        printf("-");
    printf("%d|", arb->cartas.costemana);
    //Arte de carta
    printf("\n|");
    for (i=0; i<ANCHOCARTA-2; i++)
        printf("-");
    printf("|");
    for(j=0; j<AlTOIMAGEN; j++)
    {
        printf("\n||");
        for (i=0; i<ANCHOCARTA-4; i++)
            printf(" ");
        printf("||");
    }
    printf("\n|");
    for (i=0; i<ANCHOCARTA-2; i++)
        printf("-");
    printf("|");
    //Imprimimos el tipo
    printf("\n|");

    switch (arb->cartas.tipo)
    {
    case 1:
        printf("Criatura-----");
        break;
    case 2:
        printf("Tierra-------");
        break;
    case 3:
        printf("Conjuro------");
        break;
    case 4:
        printf("Instantaneo--");
        break;
    case 5:
        printf("Encantamiento");
        break;
    }
    for (i=0; i<ANCHOCARTA-21; i++)
        printf("-");
    switch (arb->cartas.color)
    {
    case 1:
        printf("--Azul");
        break;
    case 2:
        printf("Blanco");
        break;
    case 3:
        printf("-Negro");
        break;
    case 4:
        printf("--Rojo");
        break;
    case 5:
        printf("-Verde");
        break;
    }
    printf("|");
    //Es una linea separadora
    printf("\n|");
    for (i=0; i<ANCHOCARTA-2; i++)
        printf("-");
    printf("|");
    //Texto de la carta
    mostrarefecto(arb->cartas.efecto);
    printf("\n|");
    if (arb->cartas.tipo==1)
    {
        for (i=0; i<ANCHOCARTA-5; i++)
            printf("-");
        printf("%d/%d", arb->cartas.fuerza, arb->cartas.resistencia);
    }
    else for (i=0; i<ANCHOCARTA-2; i++)
            printf("-");
    printf("|\n");
    for (i=0; i<ANCHOCARTA; i++)
        printf("-");
}

void mostrarefecto(char Ef[])
{
    int i=0;
    printf("\n|");
    for (i=0; i<ANCHOCARTA-5 && i<strlen(Ef); i++)
        printf("%c", Ef[i]);
    if(i<ANCHOCARTA-5)
    {
        for (i; i<ANCHOCARTA-2; i++)
            printf(" ");
         printf("|");
    }
    else printf("...|");

}

void BuscarCarta(arbol * arb)
{
    int opcion=0;
    int i=0;
    char nombre[30];
    int Coste=0;
    int Color=0;
    int Tipo=0;
    int Fuerza=0;
    int Resistencia=0;
    printf("\nPor que criterio desea ver la coleccion?");
    printf("\n1-Nombre de la carta");
    printf("\n2-Coste de mana");
    printf("\n3-Color");
    printf("\n4-Tipo de carta");
    printf("\n5-Fuerza");
    printf("\n6-Resistencia\n");
    scanf("%d", &opcion);
    system("cls");
    switch(opcion)
    {
    case 1:
    {

        printf("Ingrese el nombre de la carta que desea buscar: ");
        fflush(stdin);
        gets(nombre);
        MostrarCarta(BuscarxNombre(arb, nombre));
        break;
    }
    case 2:
    {


        printf("Ingrese el coste de mana de la carta que desea buscar: ");
        scanf("%d", &Coste);
        BuscarxCostemana(arb, Coste);
        break;
    }
    case 3:
    {


        printf("Ingrese el numero correspondiente al color que desea buscar: ");
        scanf("%d", &Color);
        BuscarxColor(arb, Color);
        break;
    }
    case 4:
    {


        printf("Ingrese el numero correspondiente al tipo que desea buscar");
        printf("\n1-Criatura 2-Tierra 3-Conjuro 4-Instantaneo 5-Encantamiento\n");
        scanf("%d", &Tipo);
        Buscarxtipo(arb, Tipo);
        break;
    }
    case 5:
    {


        printf("Ingrese la fuerza de la criatura que desea buscar: ");
        scanf("%d", &Fuerza);
        i=BuscarxFuerza(arb, Fuerza);
        if (i==0)
            printf("\nNo hay ninguna carta que coincida con los datos ingresados");
        break;
    }
    case 6:
    {

        printf("Ingrese la resistencia de la criatura que desea buscar: ");
        scanf("%d", &Resistencia);
        BuscarxResistencia(arb, Resistencia);
        break;
    }
    }
    printf("\n\n");
    system("pause");
    system("cls");
}

arbol * BuscarxNombre(arbol * arb, char nombre[])
{
    arbol * aux=NULL;
    if (arb!=NULL)
    {
        if (strcmp(arb->cartas.nombre, nombre)==0)
        {
            aux=arb;
        }
        else
        {
            aux=BuscarxNombre(arb->izq, nombre);
            if (aux==NULL)
                aux=BuscarxNombre(arb->der, nombre);
        }
    }
    return aux;
}

void BuscarxCostemana(arbol * arb, int Coste)
{
    if(arb!=NULL)
    {
        if (arb->cartas.costemana==Coste)
            MostrarCarta(arb);
            BuscarxCostemana(arb->izq, Coste);
            BuscarxCostemana(arb->der, Coste);
        }
}

void Buscarxtipo(arbol * arb, int Tipo)
{
    if (arb!=NULL)
    {
        if (arb->cartas.tipo==Tipo)
            MostrarCarta(arb);
        Buscarxtipo(arb->izq, Tipo);
        Buscarxtipo(arb->der, Tipo);
    }
}

int BuscarxFuerza(arbol * arb, int Fuerza)
{
    int i=0;
    if (arb!=NULL)
    {
        if(arb->cartas.fuerza==Fuerza)
        {
            MostrarCarta(arb);
            i++;
        }
        i=i+BuscarxFuerza(arb->izq, Fuerza);
        i=i+BuscarxFuerza(arb->der, Fuerza);
    }
    return i;
}

void BuscarxResistencia(arbol * arb, int Resistencia)
{
    if (arb!=NULL)
    {
        if(arb->cartas.fuerza==Resistencia)
            MostrarCarta(arb);
        BuscarxResistencia(arb->izq, Resistencia);
        BuscarxResistencia(arb->der, Resistencia);
    }
}

void BuscarxColor(arbol*arb, int Color)
{
    if(arb!=NULL)
    {
        if(arb->cartas.color==Color)
            MostrarCarta(arb);
            BuscarxColor(arb->izq, Color);
            BuscarxColor(arb->der, Color);
    }
}


arbol * AgregarCartas(arbol * arbolcarta)
{
    carta card;
    printf("Ingrese el nombre de la carta\n");
    fflush(stdin);
    gets(card.nombre);
    printf("\nIngrese el coste de mana\n");
    scanf("%d", &card.costemana);
    printf("\nIndique el color de la carta\n");
    printf("1-Azul 2-Blanco 3-Negro 4-Rojo 5-Verde\n");
    scanf("%d", &card.color);
    printf("\nIndique el tipo de carta\n");
    printf("1-Criatura 2-Tierra 3-Conjuro 4-Instantaneo 5-Encantamiento\n");
    scanf("%d", &card.tipo);
    if (card.tipo==1)
    {
        printf("\nIngrese la fuerza de la criatura\n");
        scanf("%d", &card.fuerza);
        printf("\nIngrese la resistencia de la criatura\n");
        scanf("%d", &card.resistencia);
    }
    printf("\nIngrese el texto de la carta\n");
    fflush(stdin);
    gets(card.efecto);
    arbolcarta=insertar(arbolcarta, card);
    return arbolcarta;
}

arbol * ModificarCarta(arbol * arbolcarta)
{
    VernombresCartas(arbolcarta);
    char card[30];
    int opcion=0;
    printf("Ingrese el nombre de la carta que desea buscar: ");
    fflush(stdin);
    gets(card);
    arbol * aux=BuscarxNombre(arbolcarta, card);
    printf("\nQue dato desea modificar?");
    printf("\n1-Nombre de la carta");
    printf("\n2-Coste de mana");
    printf("\n3-Color de la carta");
    printf("\n4-Texto de la carta");
    printf("\n5-Tipo de carta");
    printf("\n6-Fuerza de la criatura");
    printf("\n7-Resistencia de la criatura\n");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:
        printf("Ingrese el nuevo nombre de la carta: ");
        fflush(stdin);
        gets(aux->cartas.nombre);
        break;
    case 2:
        printf("Ingrese el nuevo coste de mana: ");
        scanf("%d", &aux->cartas.costemana);
        break;
    case 3:
        printf("Ingrese el nuevo color de la carta");
        printf("1-Azul 2-Blanco 3-Negro 4-Rojo 5-Verde\n");
        scanf("%d", &aux->cartas.color);
        break;
    case 4:
        printf("Ingrese el nuevo texto de la carta");
        fflush(stdin);
        gets(aux->cartas.efecto);
        break;
    case 5:
        printf("Ingrese el nuevo tipo de carta");
        printf("1-Criatura 2-Tierra 3-Conjuro 4-Instantaneo 5-Encantamiento\n");
        scanf("%d", &aux->cartas.tipo);
        break;
    case 6:
        if (aux->cartas.fuerza==1)
        {
            printf("Ingrese la nueva fuerza de la criatura: ");
            scanf("%d", &aux->cartas.fuerza);
        }
        else
            printf("La carta elegida no es una criatura\n");
        break;
    case 7:
        if (aux->cartas.resistencia)
        {
            printf("Ingrese la nueva resistencia de la criatura: ");
            scanf("%d", &aux->cartas.resistencia);
        }
        else
            printf("La carta elegida no es una criatura");
        break;
    }
    printf("La carta ha sido modificada con exito!");
    return arbolcarta;
}

void VernombresCartas(arbol * arb)
{
    if (arb!=NULL)
    {
        VernombresCartas(arb->izq);
        printf("\n%s", arb->cartas.nombre);
        VernombresCartas(arb->der);
    }
}



