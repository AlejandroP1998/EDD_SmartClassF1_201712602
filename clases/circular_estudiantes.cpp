#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
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
    void modificar(string dato);

    void eliminar(string dato);

    bool buscarCarne(string carne);

    void mostrar();

    void grafico();
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
void Lista::modificar(string dato)
{

    bool encontrado = false;
    nodo *buscar = new nodo();
    buscar = primero;
    string carne_bueno;
    string dpi_bueno;
    string correo_bueno;
    string respuesta;

    if (primero != NULL)
    {
        do
        {
            if (buscar->dpi == dato)
            {
                cout << "Estudiante encontrado\n"
                     << endl;
                int opcion;
                cout << "1. Carne \n";
                cout << "2. DPI \n";
                cout << "3. Nombre\n";
                cout << "4. Carrera\n";
                cout << "5. Correo\n";
                cout << "6. Password\n";
                cout << "7. Creditos\n";
                cout << "8. Edad\n";
                cout << "Ingrese el numero de lo que desea modificar\n";
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    cout << "Escriba el nuevo carne:\n";
                    cin >> carne_bueno;
                    buscar->carne = carne_bueno;
                    break;
                case 2:
                    cout << "Escriba el nuevo dpi:\n";
                    cin >> dpi_bueno;
                    buscar->dpi = dpi_bueno;
                    break;
                case 3:
                    cout << "Escriba el nuevo nombre:\n";
                    cin >> buscar->nombre;
                    break;
                case 4:
                    cout << "Escriba la nueva carrera:\n";
                    cin >> buscar->carrera;
                    break;
                case 5:
                    cout << "Escriba el nuevo correo:\n";
                    cin >> buscar->correo;
                    break;
                case 6:
                    cout << "Escriba el nuevo password:\n";
                    cin >> buscar->password;
                    break;
                case 7:
                    cout << "Escriba los nuevos creditos:\n";
                    cin >> buscar->creditos;
                    break;
                case 8:
                    cout << "Escriba la nueva edad:\n";
                    cin >> buscar->edad;
                    break;
                default:
                    break;
                }

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

bool Lista::buscarCarne(string carne)
{
    bool encontrado = false;
    nodo *buscar = new nodo();
    buscar = primero;
    if (primero != NULL)
    {
        do
        {
            if (buscar->carne == carne)
            {
                cout << "Estudiante encontrado\n"
                     << endl;
                encontrado = true;
                return 1;
            }
            buscar = buscar->siguiente;
        } while (buscar != primero && encontrado == false);

        if (encontrado == false)
        {
            cout << "No se encontro al estudiante\n"
                 << endl;
            return 0;
        }
    }
    else
    {
        cout << "La lista esta vacia" << endl;
        return 0;
    }
}

void Lista::grafico()
{
    int contador = 0;
    ofstream archivo;
    archivo.open("estudiantes.dot", ios::out); //Abriendo el archivo
    archivo << "digraph G {\n";
    archivo << "rankdir=LR;\n";
    archivo << "node[shape = record];\n ";
    nodo *aux = new nodo();
    aux = primero;
    if (primero != NULL)
    {
        do
        {
            string str1 = std::to_string(contador);
            string str2 = std::to_string(contador + 1);
            string cre = std::to_string(aux->creditos);
            string ed = std::to_string(aux->edad);

            archivo << "nodo" + str1 << "[label=\" carne:" + aux->carne + "\n |dpi:" + aux->dpi + "\n |nombre:" + aux->nombre + "\n |carrera" + aux->carrera + "\n |correo" + aux->correo + "\n |password:" + aux->password + "\n |creditos:" + cre + "\n |edad:" + ed + '\"' + "]";
            if (aux->siguiente == primero)
            {
                archivo << "\n nodo" + str1 + "-> nodo0\n";
            }
            else
            {
                archivo << "\n nodo" + str1 + "->" + "nodo" + str2 + "\n";
            }
            contador++;
            aux = aux->siguiente;
        } while (aux != primero);
        archivo << "}\n";
        archivo.close();
        system("dot -Tpng estudiantes.dot -o estudiantes.png");
    }
    else
    {
        cout << "La lista esta vacia !!!\n";
    }
}
