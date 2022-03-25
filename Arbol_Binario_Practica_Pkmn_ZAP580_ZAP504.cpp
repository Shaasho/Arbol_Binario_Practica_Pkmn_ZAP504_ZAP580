/*
* C++ - Arboles Binaros de busqueda -Recorridos por amplitud
*
* Description: Recorrdos por Orden, Pre-Orden y Post-Orden
* ZAP504 & ZAP580
*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo {
    int nivel;
    char tipo;
    struct nodo* izq, * der;
};

typedef struct nodo* ABB;
/* es un puntero de tipo nodo que hemos llamado ABB(Arbol binario de busqueda), que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodo(int x, char y)
{
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nivel = x;
    nuevoNodo->tipo = y;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(ABB& arbol, int x, char y)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(x,y);
    }
    else {
        if (arbol->tipo == 'F') {
            if (y == 'P') {
                insertar(arbol->izq, x, y);
            }
            if (y == 'A') {
                insertar(arbol->der, x, y);
            }
            if (y == arbol->tipo) {
                if (x < arbol->nivel) {
                    insertar(arbol->izq, x, y);
                }
                else {
                    insertar(arbol->der, x, y);
                }
            }
        }
        if (arbol->tipo == 'A') {
            if (y == 'F') {
                insertar(arbol->izq, x, y);
            }
            if (y == 'P') {
                insertar(arbol->der, x, y);
            }
            if (y == arbol->tipo) {
                if (x < arbol->nivel) {
                    insertar(arbol->izq, x, y);
                }
                else {
                    insertar(arbol->der, x, y);
                }
            }
        }
        if (arbol->tipo == 'P') {
            if (y == 'A') {
                insertar(arbol->izq, x, y);
            }
            if (y == 'F') {
                insertar(arbol->der, x, y);
            }
            if (y == arbol->tipo) {
                if (x < arbol->nivel) {
                    insertar(arbol->izq, x, y);
                }
                else {
                    insertar(arbol->der, x, y);
                }
            }
        }
    }
}

void preOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        cout <<"| Tipo: " << arbol->tipo << " Nivel: " << arbol->nivel << " |";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void enOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        enOrden(arbol->izq);
        cout << "| Tipo: " << arbol->tipo << " Nivel: " << arbol->nivel << " |";
        enOrden(arbol->der);
    }
}

void postOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << "| Tipo: " << arbol->tipo << " Nivel: " << arbol->nivel << " |";
    }
}

void verArbol(ABB arbol, int n)
{
    if (arbol == NULL)
        return;
    verArbol(arbol->der, n + 1);

    for (int i = 0; i < n; i++)
        cout << "   ";

    cout << arbol->tipo << arbol->nivel << endl;

    verArbol(arbol->izq, n + 1);
}

int main()
{
    ABB arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo, nivel
    char y; //elemento a insertar del tipo

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA POKEMON ]..  \n\n";

    cout << " Numero de nodos del arbol ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << " Nivel del Pokemon " << i + 1 << ": ";
        cin >> x;
        cout << " Tipo del Pokemon (F-Fuego, A-Agua, P-Planta)" << i + 1 << ": ";
        cin >> y;
        insertar(arbol, x, y);
    }

    cout << "\n Mostrando ABB \n\n";
    verArbol(arbol, 0);

    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;

    system("pause");
    return 0;
}