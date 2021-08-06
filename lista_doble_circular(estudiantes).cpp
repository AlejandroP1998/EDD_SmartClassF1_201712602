#include <iostream>

using namespace std;

class Lista
{

    struct nodo
    {
        int dato;
        nodo *siguiente;
        nodo *anterior;
    };

    nodo *primero = NULL;
    nodo *ultimo = NULL;

public:
    void ingresar();
    void mostrar();
};

void Lista::ingresar()
{

    nodo *nuevo_nodo = new nodo();
    cout << "digite el dato que desea guardar";
    cin >> nuevo_nodo->dato;

    if (primero == NULL)
    {
        primero = nuevo_nodo;
        primero->siguiente = primero;
        primero->anterior = primero;
        ultimo = primero;
    }
    else
    {
        ultimo->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = primero;
        nuevo_nodo->anterior = ultimo;
        ultimo = nuevo_nodo;
        primero->anterior = ultimo;
    }
}

void Lista::mostrar()
{
    nodo *aux = new nodo();
    aux = primero;
    if (primero != NULL)
    {
        do
        {
            cout << "[" << aux->dato << "]";
            aux = aux->siguiente;
        } while (aux != primero);
    }
    else
    {
        cout << "La lista esta vaci a !!!\n";
    }
}
