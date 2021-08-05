#include <iostream>
#include <cstdlib>

using namespace std;

void I_manual();
void reportes();

int main()
{
    int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        // Texto del menú que se verá cada vez
        cout << "\n\n********** Menu de Opciones **********" << endl;
        cout << "*                                    *" << endl;
        cout << "*          1. Carga de usuarios      *" << endl;
        cout << "*          2. Carga de tareas        *" << endl;
        cout << "*          3. Ingreso manual         *" << endl;
        cout << "*          4. Reportes               *" << endl;
        cout << "*          5. Salir                  *" << endl;
        cout << "*                                    *" << endl;
        cout << "**************************************" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
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
    cout << "\n\n******** Menu de carga manual ********" << endl;
    cout << "*                                    *" << endl;
    cout << "*          1. Carga de usuarios      *" << endl;
    cout << "*          2. Carga de tareas        *" << endl;
    cout << "*          5. Salir                  *" << endl;
    cout << "*                                    *" << endl;
    cout << "**************************************" << endl;
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