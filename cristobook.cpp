//
//
// Created by Carlos Fdez
//
//

//**********COLOR**********//

#define DEFAULT "\033[1;0m"
#define GREY "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define ERROR "\033[1;41m"
//************************//

#include <iostream>
using namespace std;

//-------------------------------------------------------------//






/**
 * @brief Este módulo sólo muestra por pantalla el menú de opciones que tenemos disponibles.
 * @post El usuario seleccionará la opción que el desee.
 * @version 1.0
 * @author Carlos Fdez.
 */
void MostrarMenu(){

	cout << BLUE <<"/***************************************"<< endl;
	cout << "****	BIENVENIDOS A CRISTOBOOK   *****" << endl;
	cout << "****************************************/ ";
	cout << "\nPulse la tecla que desee para realizar una de las siguientes acciones: ";
	cout << "\n[1]  Crear tabla Usuarios. ";
	cout << "\n[2]  Eliminar tabla Usuarios. ";
	cout << "\n[3]  Imprimir tabla Usuarios. ";
	cout << "\n[4]  Insertar Usuario en tabla Usuarios. ";
	cout << "\n[5]  Eliminar Usuario en tabla Usuarios. ";
	cout << "\n[6]  Buscar Usuario por Atributo Login en tabla Usuarios. "; //(utilizar la búsqueda secuencial)
	cout << "\n[7]  Ordenar tabla Usuarios por Atributo totalFotosUsuario y por atributo login. ";
	cout << "\n[8]  Añadir Fotografía a Usuario. ";
	cout << "\n[9]  Eliminar Fotografía de un Usuario. ";
	cout << "\n[10] Imprimir las Fotografías de un Usuario. ";
	cout << "\n[11] Salir. " << DEFAULT << endl;
	
}
/**
 * @brief Este módulo sirve para acceder a la opción del menu mostrado previamente.
 * @param 
 * @param 
 * @param 
 * @pre El menú deberá de estar hecho inicialmente.
 * @post Mostramos el menú y vamos a la opción seleccionada por el usuario.
 * @version 2.5
 * @author Carlos Fdez.
 */
void MenuInicio(){

	//Declaración de variables.
	int opcion=0;
	
	while(opcion!=11){
		MostrarMenu();
		cout << "\nEliga usted el programa que desea ejecutar: " << endl;		
		cin >> opcion;
	
			switch (opcion){
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:		
					break;
				case 5:		
					break;
				case 6:		
					break;
				case 7:		
					break;
				case 8:		
					break;
				case 9:		
					break;
				case 10:		
					break;
				case 11:
					cout << BLUE << "----------SALIENDO----------\n" << DEFAULT << endl;
					break;
				default:
					cout << YELLOW << "\nLa opción seleccionada no es correcta. " << DEFAULT << endl;
			}
		
	}
}

int main(){
 
	//Declaración de variables.
 
 
 
 
 
	MenuInicio();
 
 
 
 
}
