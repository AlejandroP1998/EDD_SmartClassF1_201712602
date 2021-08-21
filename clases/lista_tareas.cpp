#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int numero = 0;
int numero2 = 0;

class ListaD
{
public:
    struct nodo
    {

        int id = 0;
        int posicion;
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
    void grafico();
    void busquedaFecha();
    void buscarPosicion();
    void salida();
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
    //Considerando un arreglo [9][30][5]
    //Array[hora][dia][mes]
    int month = atoi(mes.c_str());
    int day = atoi(dia.c_str());
    int hour = atoi(hora.c_str());
    switch (hour)
    {
    case 8:
        hour = 0;
        break;
    case 9:
        hour = 1;
        break;
    case 10:
        hour = 2;
        break;
    case 11:
        hour = 3;
        break;
    case 12:
        hour = 4;
        break;
    case 13:
        hour = 5;
        break;
    case 14:
        hour = 6;
        break;
    case 15:
        hour = 7;
        break;
    case 16:
        hour = 8;
        break;
    default:
        break;
    }

    switch (month)
    {
    case 7:
        month = 0;
        break;
    case 8:
        month = 1;
        break;
    case 9:
        month = 2;
        break;
    case 10:
        month = 3;
        break;
    case 11:
        month = 4;
        break;
    default:
        break;
    }

    //ROW MAJOR
    //month+5(day+30(hour*9))
    nuevo->posicion = month+5*(day+30*(hour*9));

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
        cout << "\n La lista se encuentra Vacia\n\n";
    }
}

void ListaD::modificarNodo(int nodoBuscado)
{
    int opcion;
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
                cout << "1. Mes\n";
                cout << "2. Dia\n";
                cout << "3. Hora\n";
                cout << "4. Carne\n";
                cout << "5. Nombre\n";
                cout << "6. Descripcion\n";
                cout << "7. Materia\n";
                cout << "8. Fecha\n";
                cout << "9. Estado\n";
                cout << "Ingrese el numero de lo que desea modificar:\n";
                cin >> opcion;
                switch (opcion)
                {
                case 1:
                    cout << "\n Ingrese el nuevo mes para esta Tarea: ";
                    cin >> actual->mes;
                    break;
                case 2:
                    cout << "\n Ingrese el nuevo dia para esta Tarea: ";
                    cin >> actual->dia;
                    break;
                case 3:
                    cout << "\n Ingrese la nueva hora para esta Tarea: ";
                    cin >> actual->hora;
                    break;
                case 4:
                    cout << "\n Ingrese el nuevo carne para esta Tarea: ";
                    cin >> actual->carnet;
                    break;
                case 5:
                    cout << "\n Ingrese el nuevo nombre para esta Tarea: ";
                    cin >> actual->nombre;
                    break;
                case 6:
                    cout << "\n Ingrese la nueva descripcion para esta Tarea: ";
                    cin >> actual->descripcion;
                    break;
                case 7:
                    cout << "\n Ingrese la nuevo materia para esta Tarea: ";
                    cin >> actual->materia;
                    break;
                case 8:
                    cout << "\n Ingrese la nuevo fecha para esta Tarea: ";
                    cin >> actual->fecha;
                    break;
                case 9:
                    cout << "\n Ingrese el nuevo estado para esta Tarea: ";
                    cin >> actual->estado;
                    break;
                default:
                    break;
                }

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

void ListaD::grafico()
{
    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL)
    {
        int contador = 0;
        ofstream archivo;
        archivo.open("tareas.dot", ios::out); //Abriendo el archivo
        archivo << "digraph G {\n";
        archivo << "rankdir=LR;\n";
        archivo << "node[shape = record];\n ";
        archivo << "edge[dir=\"both\"];\n";

        while (actual != NULL)
        {
            string str1 = std::to_string(contador);
            string str2 = std::to_string(contador + 1);
            string ide = std::to_string(actual->id);

            archivo << "nodo" + str1 << "[label=\" id:" + ide + "\n |carnet:" + actual->carnet + "\n |nombre:" + actual->nombre + "\n |descripcion" + actual->descripcion + "\n |materia" + actual->materia + "\n |fecha:" + actual->fecha + "\n |hora:" + actual->hora + "\n |estado:" + actual->estado + "\"" + "]";
            if (actual->siguiente == NULL)
            {
                archivo << "\n nodo" + str1 + "\n";
            }
            else
            {
                archivo << "\n nodo" + str1 + "->" + "nodo" + str2 + "\n";
            }
            contador++;

            actual = actual->siguiente;
        }
        archivo << "}\n";
        archivo.close();
        string cmd = "dot -Tpng tareas.dot -o tarea";
        string str = std::to_string(numero2);
        cmd += str;
        cmd += ".png";
        system(cmd.c_str());
        numero2++;
    }
    else
    {
        cout << "\n La listas se encuentra Vacia\n\n";
    }
}

void ListaD::busquedaFecha()
{
    nodo *actual = new nodo();
    actual = primero;
    bool encontrado = false;
    string m, d, h;
    cout << " Ingrese el mes de la tarea a buscar: ";
    cin >> m;
    cout << " Ingrese el dia de la tarea a buscar: ";
    cin >> d;
    cout << " Ingrese el hora de la tarea a buscar: ";
    cin >> h;

    if (primero != NULL)
    {

        while (actual != NULL && encontrado != true)
        {

            if (actual->mes == m && actual->dia == d && actual->hora == h)
            {
                cout << "carne:" << actual->carnet + "\n";
                cout << "nombre:" << actual->nombre + "\n";
                cout << "descripcion:" << actual->descripcion + "\n";
                cout << "materia:" << actual->materia + "\n";
                cout << "fecha:" << actual->fecha + "\n";
                cout << "estado:" << actual->estado + "\n";
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
        cout << "\n La lista se encuentra Vacia\n\n";
    }
}

void ListaD::buscarPosicion()
{
    int mes,dia,hora;
    int posicion;
    cout<<"Ingrese el mes de la tarea\n";
    cin>>mes;
    cout<<"Ingrese el dia de la tarea\n";
    cin>>dia;
    cout<<"Ingrese la hora de la tarea\n";
    cin>>hora;
    //Considerando un arreglo [9][30][5]
    //Array[hora][dia][mes]
    switch (hora)
    {
    case 8:
        hora = 0;
        break;
    case 9:
        hora = 1;
        break;
    case 10:
        hora = 2;
        break;
    case 11:
        hora = 3;
        break;
    case 12:
        hora = 4;
        break;
    case 13:
        hora = 5;
        break;
    case 14:
        hora = 6;
        break;
    case 15:
        hora = 7;
        break;
    case 16:
        hora = 8;
        break;
    default:
        break;
    }

    switch (mes)
    {
    case 7:
        mes = 0;
        break;
    case 8:
        mes = 1;
        break;
    case 9:
        mes = 2;
        break;
    case 10:
        mes = 3;
        break;
    case 11:
        mes = 4;
        break;
    default:
        break;
    }

    //ROW MAJOR
    //month+5(day+30(hour*9))
    posicion = mes+5*(dia+30*(hora*9));

    nodo *actual = new nodo();
    actual = primero;
    bool encontrado = false;

    if (primero != NULL)
    {

        while (actual != NULL && encontrado != true)
        {

            if (actual->posicion == posicion)
            {
                cout << "\n Tarea con id ( " << actual->id << " ) Encontrada\n\n";
                cout<<actual->carnet+"\n";
                cout<<actual->nombre+"\n";
                cout<<actual->descripcion+"\n";
                cout<<actual->materia+"\n";
                cout<<actual->fecha+"\n";
                cout<<actual->hora+"\n";
                cout<<actual->estado+"\n";
                cout<<"Utilizando ROW MAJOR su posicion es: "+posicion<<"\n";
                encontrado = true;
            }

            actual = actual->siguiente;
        }

        if (!encontrado)
        {
            cout << "\n La tarea no existe\n\n";
        }
    }
    else
    {
        cout << "\n La lista se encuentra Vacia\n\n";
    }

}

void ListaD::salida()
{

    ofstream documento;
    //para añadir texto se usa app
    documento.open("salida.txt", ios::app);

    nodo *actual = new nodo();
    actual = primero;
    if (primero != NULL)
    {

        while (actual != NULL)
        {
            string id = std::to_string(actual->id);
            documento<<"    ¿element type=\"task\"?\n";
            documento<<"        ¿item Id = \""+id+"\" $?\n";
            documento<<"        ¿item Carnet = \""+actual->carnet+"\" $?\n";
            documento<<"        ¿item Nombre = \""+actual->nombre+"\" $?\n";
            documento<<"        ¿item Descripcion = \""+actual->descripcion+"\" $?\n";
            documento<<"        ¿item Materia = \""+actual->materia+"\" $?\n";
            documento<<"        ¿item Fecha = \""+actual->fecha+"\" $?\n";
            documento<<"        ¿item Hora = \""+actual->hora+"\" $?\n";
            documento<<"        ¿item Estado = \""+actual->estado+"\" $?\n";
            documento<<"    ¿$element?\n";
            actual = actual->siguiente;
        }
    }else{}
    documento.close();
}
