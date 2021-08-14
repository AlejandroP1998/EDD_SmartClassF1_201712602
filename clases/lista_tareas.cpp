#include <iostream>

using namespace std;

int numero = 0;

class ListaD
{
public:
    struct nodo
    {

        int id = 0;
        string mes, dia, hora, carnet, nombre, descripcion, materia, fecha, estado;
        nodo *siguiente;
        nodo *atras;
    } * primero, *ultimo;

    void insertarNodo(string mes, string dia, string hora,
                      string carnet, string nombre, string descripcion, string materia,
                      string fecha, string estado);
    void buscarNodo(int nodoBuscado);
    void modificarNodo(int nodoBuscado);
    void eliminarNodo(int nodoBuscado);
    void desplegarListaPU();
    void desplegarListaUP();
};

void ListaD::insertarNodo(string mes, string dia, string hora,
                          string carnet, string nombre, string descripcion, string materia,
                          string fecha, string estado)
{
    nodo *nuevo = new nodo();
    nuevo->id = numero;
    numero++;
    nuevo->mes = mes;
    nuevo->dia = dia;
    nuevo->hora = hora;
    nuevo->carnet = carnet;
    nuevo->nombre = nombre;
    nuevo->descripcion = descripcion;
    nuevo->materia = materia;
    nuevo->fecha = fecha;
    nuevo->estado = estado;

    if (primero == NULL)
    {
        primero = nuevo;
        primero->siguiente = NULL;
        primero->atras = NULL;
        ultimo = primero;
    }
    else
    {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->atras = ultimo;
        ultimo = nuevo;
    }
    cout << "\n Tarea Ingresada\n\n";
}

void ListaD::buscarNodo(int nodoBuscado)
{
    nodo *actual = new nodo();
    actual = primero;
    bool encontrado = false;

    cout << " Ingrese el dato del Nodo a Buscar: ";
    cin >> nodoBuscado;
    if (primero != NULL)
    {

        while (actual != NULL && encontrado != true)
        {

            if (actual->id == nodoBuscado)
            {
                cout << "\n Tarea con id ( " << nodoBuscado << " ) Encontrada\n\n";
                encontrado = true;
            }

            actual = actual->siguiente;
        }

        if (!encontrado)
        {
            cout << "\n Tarea no Encontrada\n\n";
        }
    }
    else
    {
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

void ListaD::modificarNodo(int nodoBuscado)
{
    nodo *actual = new nodo();
    actual = primero;
    bool encontrado = false;
    if (primero != NULL)
    {

        while (actual != NULL && encontrado != true)
        {

            if (actual->id == nodoBuscado)
            {
                cout << "\n Tarea con el id ( " << nodoBuscado << " ) Encontrada";
                cout << "\n Ingrese el nuevo mes para esta Tarea: ";
                cin >> actual->mes;
                cout << "\n Ingrese el nuevo dia para esta Tarea: ";
                cin >> actual->dia;
                cout << "\n Ingrese la nueva hora para esta Tarea: ";
                cin >> actual->hora;
                cout << "\n Ingrese el nuevo carne para esta Tarea: ";
                cin >> actual->carnet;
                cout << "\n Ingrese el nuevo nombre para esta Tarea: ";
                cin >> actual->nombre;
                cout << "\n Ingrese la nueva descripcion para esta Tarea: ";
                cin >> actual->descripcion;
                cout << "\n Ingrese la nuevo materia para esta Tarea: ";
                cin >> actual->materia;
                cout << "\n Ingrese la nuevo fecha para esta Tarea: ";
                cin >> actual->fecha;
                cout << "\n Ingrese el nuevo estado para esta Tarea: ";
                cin >> actual->estado;
                cout << " Nodo Modificado\n\n";
                encontrado = true;
            }

            actual = actual->siguiente;
        }

        if (!encontrado)
        {
            cout << "\n Nodo no Encontrado\n\n";
        }
    }
    else
    {
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

// primero = 23      ultimo  = 78    actual  = 12    anterior =  78      encontrado = false      nodoBuscado = 12;

// lista doble         NULL <- 45 -> <- 23 -> <- 78 -> <- 12 -> NULL

void ListaD::eliminarNodo(int nodoBuscado)
{
    nodo *actual = new nodo();
    actual = primero;
    nodo *anterior = new nodo();
    anterior = NULL;
    bool encontrado = false;

    if (primero != NULL)
    {

        while (actual != NULL && encontrado != true)
        {

            if (actual->id == nodoBuscado)
            {
                string desicion;
                cout << "\n Tarea con el id ( " << nodoBuscado << " ) Encontrada";
                cout << "\n Proceder a eliminar (Y/N)?";
                cin >> desicion;

                if (desicion == "Y" || desicion == "y")
                {
                    if (actual == primero)
                    {
                        primero = primero->siguiente;
                        primero->atras = NULL;
                    }
                    else if (actual == ultimo)
                    {
                        anterior->siguiente = NULL;
                        ultimo = anterior;
                    }
                    else
                    {
                        anterior->siguiente = actual->siguiente;
                        actual->siguiente->atras = anterior;
                    }
                    cout << "\n Tarea Eliminada";
                }
                else if (desicion == "N" || desicion == "n")
                {
                    cout << "\n Tarea NO Eliminada";
                }
                else
                {
                    cout << "\n No se hizo nada por caracter invalido";
                }

                encontrado = true;
            }
            anterior = actual;
            actual = actual->siguiente;
        }

        if (!encontrado)
        {
            cout << "\n Tarea no Encontrada\n\n";
        }
    }
    else
    {
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

void ListaD::desplegarListaPU()
{
    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL)
    {

        while (actual != NULL)
        {
            cout << "\n id: " << actual->id;
            cout << "\n nombre: " << actual->nombre;
            cout << "\n estado:" << actual->estado;

            actual = actual->siguiente;
        }
    }
    else
    {
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

void ListaD::desplegarListaUP()
{
    nodo *actual = new nodo();
    actual = ultimo;
    if (primero != NULL)
    {

        while (actual != NULL)
        {
            cout << "\n id: " << actual->id;
            cout << "\n nombre: " << actual->nombre;
            cout << "\n estado:" << actual->estado;
            cout << "\n";

            actual = actual->atras;
        }
    }
    else
    {
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}