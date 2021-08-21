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
void errores();

void archivoSalida();

Queue q(150);

Lista li;
ListaD ld;

int salir = 0;

int main()
{
    if (salir == 0)
    {
        ofstream documento;
        documento.open("salida.txt", ios::out);
        documento << "¿Elements?\n";
        documento.close();
        salir = 1;
    }

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
        cout << "*          5. Errores                *" << endl;
        cout << "*          6. Salir                  *" << endl;
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
        case 5:
            errores();
            break;
        case 6:
            if (q.size() != 0)
            {
                cout << "La cola de errores no esta vacia\n";
            }
            else{}
        default:
            break;
        }
    } while (q.size() != 0);
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
            }
            else if (answer == 0)
            {
                cout << "Error: El correo del estudiante con dpi: " + dpi + " no es valido" << endl;
                cout << "Error: revisar cola de errores" << endl;
                q.enqueue("Estudiante", "El correo del estudiante con dpi: " + dpi + " no es valido");
                li.ingresar(carne, dpi, nom, carr, passw, cre, age, mail);
            }
            else
            {
                cout << "Estudiante" + nom + "\n";
                cout << "carne valido\n";
                cout << "dpi valido\n";
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
            int mes_bueno, dia_bueno, hora_bueno;
            mes_bueno = atoi(mes.c_str());
            dia_bueno = atoi(dia.c_str());
            hora_bueno = atoi(hora.c_str());
            if (mes_bueno < 11 && mes_bueno > 6)
            {
            }
            else
            {
                cout << "Error: Fecha invalida \n";
                cout << "Error: revisar cola de errores\n";
                q.enqueue("Tarea carne:" + carne, "Mes invalido");
            }
            if (dia_bueno < 31 && dia_bueno > 0)
            {
            }
            else
            {
                cout << "Error: Fecha invalida \n";
                cout << "Error: revisar cola de errores\n";
                q.enqueue("Tarea carne:" + carne, "Dia invalido");
            }
            if (hora_bueno < 17 && hora_bueno > 7)
            {
            }
            else
            {
                cout << "Error: Fecha invalida \n";
                cout << "Error: revisar cola de errores\n";
                q.enqueue("Tarea carne:" + carne, "Hora invalida");
            }

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
            ld.busquedaFecha();
            break;
        case 4:
            ld.buscarPosicion();
            break;
        case 5:
            q.grafico();
            break;
        case 6:
            archivoSalida();
            break;
        default:
            break;
        }
    } while (opcion != 7);
    main();
}

void carga_estudiantes(string documento)
{
    bool answer = "";
    ifstream archivo(documento);
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        stringstream stream(linea); // Convertir la cadena a un stream
        string carnet = "", dpi = "", nombre = "", carrera = "", password = "", creditos = "", edad = "", correo = "";
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
        }
        else if (answer == 0)
        {
            cout << "Error: El correo del estudiante con dpi: " + dpi + " no es valido" << endl;
            cout << "Error: revisar cola de errores" << endl;
            q.enqueue("Estudiante", "El correo del estudiante con dpi: " + dpi + " no es valido");
            li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
        }
        else
        {
            cout << "Estudiante:      " + nombre + "\n";
            cout << "carne valido:    " + carnet + "\n";
            cout << "dpi valido:      " + dpi + "\n";
            cout << "\n";
            li.ingresar(carnet, dpi, nombre, carrera, password, credit, age, correo);
        }
    }
    archivo.close();
    main();
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

        int mes_bueno, dia_bueno, hora_bueno;
        mes_bueno = atoi(mes.c_str());
        dia_bueno = atoi(dia.c_str());
        hora_bueno = atoi(hora.c_str());
        if (mes_bueno < 11 && mes_bueno > 6)
        {
        }
        else
        {
            cout << "Error: Fecha invalida \n";
            cout << "Error: revisar cola de errores\n";
            q.enqueue("Tarea carne:" + carnet, "Mes invalido");
        }
        if (dia_bueno < 31 && dia_bueno > 0)
        {
        }
        else
        {
            cout << "Error: Fecha invalida \n";
            cout << "Error: revisar cola de errores\n";
            q.enqueue("Tarea carne:" + carnet, "Dia invalido");
        }
        if (hora_bueno < 17 && hora_bueno > 7)
        {
        }
        else
        {
            cout << "Error: Fecha invalida \n";
            cout << "Error: revisar cola de errores\n";
            q.enqueue("Tarea carne:" + carnet, "Hora invalida");
        }

        ld.insertarNodo(mes, dia, hora, carnet, nombre, descripcion, materia, fecha, estado);
    }
    archivo.close();
    main();
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

void errores()
{
    int opcion;
    do
    {
        string dpi;
        int id;
        cout << "1. Lista de errores\n";
        cout << "2. Eliminar error\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Modificar tarea\n";
        cout << "5. Errores restantes\n";
        cout << "6. Regresar\n";
        cout << "\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            q.imprimir();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "Ingrese el dpi del estudiante\n";
            cin >> dpi;
            li.modificar(dpi);
            break;
        case 4:
            cout << "Ingrese el id de la tarea\n";
            cin >> id;
            ld.modificarNodo(id);
            break;
        case 5:
            cout << "Faltan:\n";
            cout << q.size() + "errores\n";
            break;
        default:
            break;
        }
    } while (opcion != 6);
    main();
}

void archivoSalida()
{
    li.salida();
    ld.salida();

    ofstream documento;
    //para añadir texto se usa app
    documento.open("salida.txt", ios::app);
    documento << "\n¿$Elements?";
    documento.close();
}
