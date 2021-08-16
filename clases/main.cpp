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
bool revisarCorreo(string palabra, string tipo, string id);

Queue q(150);

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
            cout << "Bienvenido a la carga de usuarios \n";
            cout << "Por favor ingrese la ruta del archivo de usuarios\n";
            cin >> documento;
            carga_estudiantes(documento);
            //li.mostrar();
            break;

        case 2:
            // Lista de instrucciones de la opción 2
            cout << "Bienvenido a la carga de tareas \n";
            cout << "Por favor ingrese la ruta del archivo de tareas\n";
            cin >> documento;
            carga_tareas(documento);
            ld.desplegarListaPU();
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
        cout << "*          3. Regresar               *" << endl;
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
        bool answer;
        string carne;
        int carne_bueno;
        string dpi;
        int dpi_bueno;
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
            answer = revisarCorreo(mail, "Estudiante", dpi);
            carne_bueno = carne.size();
            dpi_bueno = dpi.size();
            if (carne_bueno != 9 && dpi_bueno != 13 && answer == 0)
            {
                cout << "Error: El carnet, dpi y correo del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet, correo y dpi del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            else if (carne_bueno != 9 && dpi_bueno != 13)
            {
                cout << "Error: El carnet y dpi del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet y dpi del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            else if (dpi_bueno != 13 && answer == 0)
            {
                cout << "Error: El dpi y correo del estudiante: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El dpi y correo del estudiante: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            else if (carne_bueno != 9 && answer == 0)
            {
                cout << "Error: El carnet y correo del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet y correo del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            else if (carne_bueno != 9)
            {
                cout << "Error: El carnet del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            else if (dpi_bueno != 13)
            {
                cout << "Error: El dpi del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El dpi del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }else if(answer == 0)
            {
                cout << "Error: El correo del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El correo del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            else
            {
                cout<<"Estudiante"+nom+"\n";
                cout<<"carne valido\n";
                cout<<"dpi valido\n";
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            //li.mostrar();

            break;
        case 2:

            cout << "Ingrese el DPI del estudiante a modificar\n";
            cin >> buscar;
            li.modificar(buscar);

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
    bool answer;
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

            answer = li.buscarCarne(carne);
            if (answer == 0)
            {
                cout << "Error: No se encontro en carne \n";
                cout << "Error: revisar cola de errores\n";
                q.enqueue("Tarea", "El carne del estudiante no se encontro en la lista");
                cout << "La tarea respectiva al carne: " + carne + " no se encontro\n";
                ld.insertarNodo(mes, dia, hora, carne, nombre, descripcion, materia, fecha, estado);
            }
            else if (answer == 1)
            {
                ld.insertarNodo(mes, dia, hora, carne, nombre, descripcion, materia, fecha, estado);
            }

            ld.desplegarListaPU();
            break;
        case 2:
            system("cls");
            ld.insertarNodo("mes1", "dia1", "hora1", "carne1", "nombre1", "descripcion1", "materia1", "fecha1", "estado1");
            ld.insertarNodo("mes2", "dia2", "hora2", "carne2", "nombre2", "descripcion2", "materia2", "fecha2", "estado2");
            ld.insertarNodo("mes3", "dia3", "hora3", "carne3", "nombre3", "descripcion3", "materia3", "fecha3", "estado3");
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
    int opcion;
    system("cls");
    do
    {
        cout << "\n\n************* Menu de reportes ************" << endl;
        cout << "*                                          *" << endl;
        cout << "* 1. Lista de estudiantes                  *" << endl;
        cout << "* 2. Lista de tareas linealizada           *" << endl;
        cout << "* 3. Busqueda en estructura linealizada    *" << endl;
        cout << "* 4. Busqueda de posicion linealizada      *" << endl;
        cout << "* 5. Cola de errores                       *" << endl;
        cout << "* 6. Codigo generado de salida             *" << endl;
        cout << "* 7. Regresar                              *" << endl;
        cout << "********************************************" << endl;
        cout << "Escriba el numero de la opcion que desee: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            li.grafico();
            break;
        case 2:
            ld.grafico();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            q.enqueue("Estudiante","DPI,CARNE");
            q.enqueue("Estudiante","CORREO");
            q.enqueue("Tarea","CARNE");
            q.enqueue("Estudiante","DPI,CARNE");
            q.enqueue("Tarea","FECHA");
            q.grafico();
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (opcion != 7);
}

void carga_estudiantes(string documento)
{
    bool answer="";
    ifstream archivo(documento);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string carnet="", dpi="", nombre="", carrera="", password="", creditos="", edad="", correo="";
        // Extraer todos los valores de esa fila
        getline(stream, carnet, delimitador);
        getline(stream, dpi, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, carrera, delimitador);
        getline(stream, password, delimitador);
        getline(stream, creditos, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, correo, delimitador);
        int credit, age;
        credit = atoi(creditos.c_str());
        age = atoi(edad.c_str());
        answer = revisarCorreo(correo, "Estudiante", dpi);
        if (carnet.size() != 9 && dpi.size() != 13 && answer == 0)
            {
                cout << "Error: El carnet, dpi y correo del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet, correo y dpi del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }
            else if (carnet.size() != 9 && dpi.size() != 13)
            {
                cout << "Error: El carnet y dpi del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet y dpi del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }
            else if (dpi.size() != 13 && answer == 0)
            {
                cout << "Error: El dpi y correo del estudiante: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El dpi y correo del estudiante: " + dpi + " no es valido");
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }
            else if (carnet.size() != 9 && answer == 0)
            {
                cout << "Error: El carnet y correo del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet y correo del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }
            else if (carnet.size() != 9)
            {
                cout << "Error: El carnet del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El carnet del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }
            else if (dpi.size() != 13)
            {
                cout << "Error: El dpi del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El dpi del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }else if(answer == 0)
            {
                cout << "Error: El correo del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El correo del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }
            else
            {
                cout<<"Estudiante:      "+nombre+"\n";
                cout<<"carne valido:    "+carnet+"\n";
                cout<<"dpi valido:      "+dpi+"\n";
                cout<<"\n";
                li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
            }
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
        string mes, dia, hora, carnet, nombre, descripcion, materia, fecha, estado;
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

        ld.insertarNodo(mes, dia, hora, carnet, nombre, descripcion, materia, fecha, estado);
    }
    archivo.close();
}

bool revisarCorreo(string palabra, string tipo, string id)
{
    bool well = false;
    bool well1 = false;
    bool well2 = false;

    string word = "";
    for (auto x : palabra)
    {
        if (x == '@')
        {
            well = true;
            //cout << word + "\n";
            //cout << word << endl;
            word = "";
        }
        else if (x == '.')
        {
            well1 = true;
            //cout << word + "\n";
            //cout << word << endl;
            word = "";
        }
        else
        {
            word = word + x;
        }
        if (word == "es" || word == "com" || word == "org")
        {
            //cout << word + "\n";
            well2 = true;
        }
        else
        {
            well2 = false;
        }
    }
    if (well == false || well1 == false || well2 == false)
    {
        cout << "Error: El correo no es valido \n";
        cout << "Error: revisar cola de errores\n";
        q.enqueue(tipo, "El correo del estudiante con dpi: " + id + " no es valido");
        cout << "El correo del estudiante con dpi: " + id + " no es valido\n";
        return 0;
    }
    else
    {
        cout << "Correo valido \n";
        return 1;
    }
}
