#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Doble_tareas.cpp"
#include "cola_errores.cpp"
#include "circular_estudiantes.cpp"


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

LinkedList ll;
Queue q;
Lista li;

int main()
{
    system("cls");
    int opcion;
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
            printf("Bienvenido a la carga de usuarios \n");
            printf("Por favor ingrese la ruta del archivo de usuarios\n");

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

        case 5:
            printf("Ha salido del programa\n");
            system("exit");
            break;
        
        default:
            printf("Caracter invalido\n");
            break;
        }
    } while (opcion !=5);
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
        cout << "*          1. Carga de usuarios      *" << endl;
        cout << "*          2. Carga de tareas        *" << endl;
        cout << "*          3. Salir                  *" << endl;
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
            ll.addFront(5);
            ll.addFront(25);
            ll.addFront(3);
            ll.addFront(80);
            ll.addBack(21);
            ll.addBack(34);
            ll.removeBack();
            ll.removeFront();

            ll.printForward();

            break;
        case 3:
            main();
            break;
        default:
            break;
        }
    }while(opcion != 3);
 
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
        cout << "*          4. Salir                  *" << endl;
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

            li.ingresar(carne, dpi, nom, carr, mail, passw, cre, age);
            //li.mostrar();

            break;
        case 2:
            /* li.ingresar("carne", "dpi1", "nom1", "carr", "mail", "1234", 120, 22);
            li.ingresar("carne", "dpi2", "nom2", "carr", "mail", "1234", 120, 22);
            li.ingresar("carne", "dpi3", "nom3", "carr", "mail", "1234", 120, 22);
            li.mostrar(); */
            cout << "Ingrese el DPI del estudiante a modificar\n";
            cin >> buscar;
            li.buscar(buscar);
            //li.mostrar();

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
        case 4:
            cout << "Ha salido de este menu" << endl;
            I_manual();
            break;
        default:
            cout << "Caracter invalido" << endl;
            break;
        }
    }while(opcion != 4);

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
