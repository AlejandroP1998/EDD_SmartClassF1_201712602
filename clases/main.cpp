#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "cola_errores.cpp"
#include "circular_estudiantes.cpp"
#include "lista_tareas.cpp"


/*
á –> \xA0; 
é –> \x82; 
í –> \xA1; 
ó –> \xA2; 
ú –> \xA3; 
ñ –> \xA4; 
Ñ –> \xA5;
*/

using namespace std;

void I_manual();
void reportes();
void m_usuarios();
void m_tareas();
void carga_estudiantes(string documento);
void carga_tareas(string documento);

Queue q;
Lista li;
ListaD ld;


int main()
{
    system("cls");
    int opcion;
    string documento;
    do
    {

        // Texto del menú que se verá cada vez
        cout << "\n\n********** Men\xA3 de Opciones**********" << endl;
        cout << "*                                    *" << endl;
        cout << "*          1. Carga de usuarios      *" << endl;
        cout << "*          2. Carga de tareas        *" << endl;
        cout << "*          3. Ingreso manual         *" << endl;
        cout << "*          4. Reportes               *" << endl;
        cout << "*          5. Salir                  *" << endl;
        cout << "*                                    *" << endl;
        cout << "**************************************" << endl;

        cout << "\nIngrese una opci\xA2n: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // Lista de instrucciones de la opción 1
            cout<<"Bienvenido a la carga de usuarios \n";
            cout<<"Por favor ingrese la ruta del archivo de usuarios\n";
            cin>>documento;
            carga_estudiantes(documento);
            li.mostrar();
            break;

        case 2:
            // Lista de instrucciones de la opción 2
            printf("Bienvenido a la carga de tareas \n");
            printf("Por favor ingrese la ruta del archivo de tareas\n");

            break;

        case 3:
            // Lista de instrucciones de la opción 3
            I_manual();
            break;

        case 4:
            // Lista de instrucciones de la opción 4
            reportes();
            break;
        default:
            printf("Caracter invalido\n");
            break;
        }
    } while (opcion != 5);
    return 0;
}

void I_manual()
{
    system("cls");
    int opcion;
    do
    {
        cout << "\n\n******** Menu de carga manual ********" << endl;
        cout << "*                                    *" << endl;
        cout << "*          1. Usuarios               *" << endl;
        cout << "*          2. Tareas                 *" << endl;
        cout << "*          3. Regresar                  *" << endl;
        cout << "*                                    *" << endl;
        cout << "**************************************" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            m_usuarios();
            break;
        case 2:
            m_tareas();
            break;
        case 3:
            main();
            break;
        default:
            break;
        }
    } while (opcion != 3);
}

void m_usuarios()
{
    system("cls");
    int opcion;
    do
    {
        string buscar;

        string carne;
        string dpi;
        string nom;
        string carr;
        string mail;
        string passw;
        int cre;
        int age;

        cout << "\n\n******** Menu de usuarios ********" << endl;
        cout << "*                                    *" << endl;
        cout << "*          1. Ingresar               *" << endl;
        cout << "*          2. Modificar              *" << endl;
        cout << "*          3. Eliminar               *" << endl;
        cout << "*          4. Regresar               *" << endl;
        cout << "*                                    *" << endl;
        cout << "**************************************" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            //li.ingresar("carne", "dpi", "nom", "carr", "mail", "1234", 120, 22);
            cout << "Ingrese el carne del estuante\n";
            cin >> carne;
            cout << "Ingrese el dpi del estuante\n";
            cin >> dpi;
            cout << "Ingrese el nombre del estuante\n";
            cin >> nom;
            cout << "Ingrese la carrera del estuante\n";
            cin >> carr;
            cout << "Ingrese el correo del estuante\n";
            cin >> mail;
            cout << "Ingrese la password del estuante\n";
            cin >> passw;
            cout << "Ingrese los creditos del estuante\n";
            cin >> cre;
            cout << "Ingrese la edad del estuante\n";
            cin >> age;

            li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            //li.mostrar();

            break;
        case 2:

            cout << "Ingrese el DPI del estudiante a modificar\n";
            cin >> buscar;
            li.buscar(buscar);

            break;
        case 3:
            //li.ingresar("carne", "dpi1", "nom1", "carr", "mail", "1234", 120, 22);
            //li.ingresar("carne", "dpi2", "nom2", "carr", "mail", "1234", 120, 22);
            //li.ingresar("carne", "dpi3", "nom3", "carr", "mail", "1234", 120, 22);
            //li.mostrar();
            cout << "Ingrese el DPI del estudiante a eliminar\n";
            cin >> buscar;
            li.eliminar(buscar);
            //li.mostrar();
            break;
        default:
            cout << "Caracter invalido" << endl;
            break;
        }
    } while (opcion != 4);
}

void m_tareas()
{
    system("cls");
    int buscar;

    int opcion;
    string mes;
    string dia;
    string hora;
    string carne;
    string nombre;
    string descripcion;
    string materia;
    string fecha;
    string estado;
    do
    {

        cout << "\n\n******** Menu de tareas **********" << endl;
        cout << "*                                    *" << endl;
        cout << "*          1. Ingresar               *" << endl;
        cout << "*          2. Modificar              *" << endl;
        cout << "*          3. Eliminar               *" << endl;
        cout << "*          4. Salir                  *" << endl;
        cout << "*                                    *" << endl;
        cout << "**************************************" << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Ingrese el mes\n";
            cin >> mes;
            cout << "Ingrese el dia\n";
            cin >> dia;
            cout << "Ingrese la hora\n";
            cin >> hora;
            cout << "Ingrese el carne\n";
            cin >> carne;
            cout << "Ingrese el nombre\n";
            cin >> nombre;
            cout << "Ingrese la descripcion\n";
            cin >> descripcion;
            cout << "Ingrese la materia\n";
            cin >> materia;
            cout << "Ingrese la fecha\n";
            cin >> fecha;
            cout << "Ingrese el estado\n";
            cin >> estado;
            ld.insertarNodo(mes,dia,hora,carne,nombre,descripcion,materia,fecha,estado);
            break;
        case 2:
            system("cls");
            ld.insertarNodo("mes1","dia1","hora1","carne1", "nombre1", "descripcion1", "materia1", "fecha1",  "estado1");
            ld.insertarNodo("mes2","dia2","hora2","carne2", "nombre2", "descripcion2", "materia2", "fecha2",  "estado2");
            ld.insertarNodo("mes3","dia3","hora3","carne3", "nombre3", "descripcion3", "materia3", "fecha3",  "estado3");
            ld.desplegarListaPU();
            cout << "Ingrese el id de la tarea";
            cin >> buscar;
            ld.modificarNodo(buscar);
            ld.desplegarListaPU();
            break;
        case 3:
            system("cls");
            ld.desplegarListaPU();
            cout << "Ingrese el id de la tarea";
            cin >> buscar;
            ld.eliminarNodo(buscar);
            ld.desplegarListaPU();
            break;
        default:
            break;
        }

    } while (opcion != 4);
}

void reportes()
{
    system("cls");
    cout << "\n\n********** Menu de reportes *********" << endl;
    cout << "*                                    *" << endl;
    cout << "*         1. Lista de usuarios       *" << endl;
    cout << "*         2. Linealizacion de tareas *" << endl;
    cout << "*         5. Salir                   *" << endl;
    cout << "*                                    *" << endl;
    cout << "**************************************" << endl;
}

void carga_estudiantes(string documento)
{
    ifstream archivo(documento);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string carnet,dpi,nombre,carrera,password,creditos,edad,correo;
        // Extraer todos los valores de esa fila
        getline(stream, carnet, delimitador);
        getline(stream, dpi, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, carrera, delimitador);
        getline(stream, password, delimitador);
        getline(stream, creditos, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, correo, delimitador);
        int credit,age;
        credit =  atoi(creditos.c_str());
        age =  atoi(edad.c_str());
        li.ingresar(carnet,dpi,nombre,carrera,password,credit,age,correo);
    }
    archivo.close();
}

void carga_tareas(string documento)
{
    ifstream archivo(documento);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado;
        // Extraer todos los valores de esa fila
        getline(stream, mes, delimitador);
        getline(stream, dia, delimitador);
        getline(stream, hora, delimitador);
        getline(stream, carnet, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, descripcion, delimitador);
        getline(stream, materia, delimitador);
        getline(stream, fecha, delimitador);
        getline(stream, estado, delimitador);

        ld.insertarNodo(mes,dia,hora,carnet,nombre,descripcion,materia,fecha,estado);
    }
    archivo.close();
}
