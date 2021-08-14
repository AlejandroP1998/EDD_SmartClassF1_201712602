#include <iostream>
using namespace std;

class Lista
{

    struct nodo
    {
        string carne;
        string dpi;
        string nombre;
        string carrera;
        string correo;
        string password;
        int creditos;
        int edad;

        nodo *siguiente;
        nodo *anterior;
    };

    nodo *primero = NULL;
    nodo *ultimo = NULL;

public:
    void ingresar(string carne, string dpi,
                     string nom, string carr, string passw, int cre, int age, string mail);
    void buscar(string dato);

    void eliminar(string dato);

    void mostrar();
};

void Lista::ingresar(string carne, string dpi,
                     string nom, string carr, string passw, int cre, int age, string mail)
{

    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->carne = carne;
    nuevo_nodo->dpi = dpi;
    nuevo_nodo->nombre = nom;
    nuevo_nodo->carrera = carr;
    nuevo_nodo->correo = mail;
    nuevo_nodo->password = passw;
    nuevo_nodo->creditos = cre;
    nuevo_nodo->edad = age;

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
        cout << "La lista de estudiantes actualmente es:\n";
        do
        {
            cout << aux->nombre << endl;
            aux = aux->siguiente;
        } while (aux != primero);
    }
    else
    {
        cout << "La lista esta vacia !!!\n";
    }
}
//METODO MODIFICAR
void Lista::buscar(string dato)
{

    bool encontrado = false;
    nodo *buscar = new nodo();
    buscar = primero;
    if (primero != NULL)
    {
        do
        {
            if (buscar->dpi == dato)
            {
                cout << "Estudiante encontrado\n"
                     << endl;
                cout << "Escriba el nuevo dpi:\n";
                cin >> buscar->dpi;
                cout << "Escriba el nuevo nombre:\n";
                cin >> buscar->nombre;
                cout << "Escriba la nueva carrera:\n";
                cin >> buscar->carrera;
                cout << "Escriba el nuevo correo:\n";
                cin >> buscar->correo;
                cout << "Escriba el nuevo password:\n";
                cin >> buscar->password;
                cout << "Escriba los nuevos creditos:\n";
                cin >> buscar->creditos;
                cout << "Escriba la nueva edad:\n";
                cin >> buscar->edad;

                encontrado = true;
            }
            buscar = buscar->siguiente;
        } while (buscar != primero && encontrado == false);

        if (encontrado == false)
        {
            cout << "No se encontro al estudiante\n"
                 << endl;
        }
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
}

void Lista::eliminar(string dato)
{
    nodo *buscar = new nodo();
    nodo *eliminar = new nodo();
    buscar = primero;
    eliminar = NULL;
    bool encontrado = false;
    if (primero != NULL)
    {
        do
        {
            if (buscar->dpi == dato)
            {
                cout << "Estudiante " << buscar->nombre << " ha sido eliminado\n";
                if (buscar == buscar->siguiente)
                {
                    primero = NULL;
                    ultimo = NULL;
                    eliminar = NULL;
                    buscar = NULL;
                    encontrado = true;
                }
                else if (buscar == primero)
                {
                    primero = primero->siguiente;
                    primero->anterior = ultimo;
                    ultimo->siguiente = primero;
                }
                else if (buscar == ultimo)
                {
                    ultimo = ultimo->anterior;
                    primero->anterior = ultimo;
                    ultimo->siguiente = primero;
                }
                else
                {
                    eliminar->siguiente = buscar->siguiente;
                    buscar->siguiente->anterior = eliminar;
                }
                encontrado = true;
            }
            else
            {
                eliminar = buscar;
                buscar = buscar->siguiente;
            }

        } while (buscar != primero && encontrado == false);

        if (encontrado == false)
        {
            cout << "No se encontro al estudiante\n"
                 << endl;
        }
        else
        {
            free(eliminar);
        }
    }
    else
    {
        cout << "La lista esta vacia" << endl;
    }
}
