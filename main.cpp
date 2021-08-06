#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "lista_doble_circular(estudiantes).cpp"
#include "lista_doble(tareas).cpp"

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
void leer();
Lista li;
LinkedList ll;


int main()
{
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");

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

            system("pause>nul"); // Pausa
            break;

        case 2:
            // Lista de instrucciones de la opción 2
            printf("Bienvenido a la carga de tareas \n");
            printf("Por favor ingrese la ruta del archivo de tareas\n");
            leer();
            system("pause>nul"); // Pausa
            break;

        case 3:
            // Lista de instrucciones de la opción 3
            I_manual();
            system("pause>nul"); // Pausa
            break;

        case 4:
            // Lista de instrucciones de la opción 4
            reportes();
            system("pause>nul"); // Pausa
            break;

        case 5:
            repetir = false;
            break;
        }
    } while (repetir);

    return 0;
}

void I_manual()
{
    int opcion;
    cout << "\n\n******** Menu de carga manual ********" << endl;
    cout << "*                                    *" << endl;
    cout << "*          1. Carga de usuarios      *" << endl;
    cout << "*          2. Carga de tareas        *" << endl;
    cout << "*          5. Salir                  *" << endl;
    cout << "*                                    *" << endl;
    cout << "**************************************" << endl;
    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        li.ingresar();
        li.ingresar();
        li.ingresar();
        li.mostrar();
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

    }
}

void reportes()
{
    cout << "\n\n********** Menu de reportes *********" << endl;
    cout << "*                                    *" << endl;
    cout << "*         1. Lista de usuarios       *" << endl;
    cout << "*         2. Linealizacion de tareas *" << endl;
    cout << "*         5. Salir                   *" << endl;
    cout << "*                                    *" << endl;
    cout << "**************************************" << endl;
}

