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
//********************************************************************************************************//
#include <iostream>
#include <string.h>
using namespace std;

/**************************************
** Definición del TIPO DE DATO Foto **
**************************************/

struct Foto{
	string ruta;			//ruta del archivo en el SO.
	string tipo;			//Tipo de la foto(jpg, png).
	unsigned long int tamanio;	//Se va a guardar en bytes.
}

/****************************************
** Definición del TIPO DE DATO Usuario **
****************************************/
struct Usuario{

	string login;		//Debe ser único.
	string nombre;
	string apellido;
	string perfil_usuario;
	Foto* v_fotos;		//Vector Dinámico de Burbujas.
	int dim_fotos;		//Dimensión del vector.
	int totalFotosUsuario;	//utiles del vector
}

//set,get,crearUsuario,eliminarUsuario, insertarFotoenUsuario,eliminarFotoUsuario,etc

/**********************************************
** Definición del TIPO DE DATO TablaUsuarios **
**********************************************/

struct TablaUsuarios{
	Usuario** punteroapuntero;	//Vector Dinámico de Punteros a Burbuja.
	int totaltuplas;		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.
}

//set, get, crearTabla,eliminarTabla,InsertaUsuarioenTabla,eliminarUsuarioenTabla,etc

/**************************************************************
 **  Implementación de los Prototipos del Tipo de Dato Foto  **
 *************************************************************/
Foto* crearFoto();
void borrarFoto(Foto *f);
//-----------------------------//
void setRuta(Foto *f, string ruta);
void setTipo(Foto *f, string tipo);
void setTamanio (Foto *f, unsigned long int tamanio);
//-----------------------------//
string getRuta(Foto *f);
string getTipo(Foto *f);
int long unsigned getTamanio (Foto *f);

/*****************************************************************
 **  Implementación de los Prototipos del Tipo de Dato Usuario  **
 ****************************************************************/

/*********************************************************************
 ** Implementación de los Prototipos del Tipo de Dato TablaUsuarios **
 ********************************************************************/



//********************************************************************************************************//

/**
 * @brief Se reservará un espacio de memoria para crear una estructura Foto, siempre y cuando haya memoria suficiente.
 * @post Se reservará un espacio de memoria para la Foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
Foto* crearFoto(){

	Foto *f = new Foto;

	if (p == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}
	return f;
}
/**
 * @brief Módulo que borrará el espacio de memoria reservado a Foto, borrando primero los datos de la persona que queremos borrar y después borramos los punteros.
 * @param Foto *f		//Puntero de tipo foto.
 * @post Se reservará un espacio de memoria.
 * @version 1.0
 * @author Carlos Fdez.
 */
void borrarFoto(Foto *f){

    //formateo a cero/nulo todos los datos que tiene una persona
    p->ruta = "";
    p->tipo = "";
    p->tamanio = -1;

    //borro el fragmento de memoria
    delete f;

    //elimino la dirección que referenciaba al fragmento de memoria
    f = 0;
}
					/*******************
					****	SET	****
					********** *********/
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto en una variable string llamada ruta.
 * @param Foto *f		//Puntero de tipo foto.
 * @param string ruta		//Nombre de la ruta donde se va a almacenar la foto.
 * @post Se almacenará en la variable estructurada Foto la ruta de dónde está almacenada.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setRuta(Foto *f, string ruta){
	f->ruta = ruta;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto una variable string llamada tipo.
 * @param Foto *f		//Puntero de tipo foto.
 * @param string tipo		//Formato de la foto.
 * @post Se almacenará en la variable estructurada Foto el formato de la foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setTipo(Foto *f, string tipo){
	f->tipo = tipo;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto una variable de tipo long int llamada tamanio.
 * @param Foto *f		//Puntero de tipo foto.
 * @param unsigned long int tamanio.	//Tamaño de la foto, esto dependerá de el tipo del formato que tenga la foto.
 * @pre El tamanio no puede ser números negativos.
 * @post Nos devuelve la variable tamanio de un tipo estructurado de Foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setTamanio (Foto *f, unsigned long int tamanio){
    f->tamanio = tamanio;
}
//----------------------------------------------------------//
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto una variable string llamada tipo.
 * @param Foto *f		//Puntero de tipo foto.
 * @param string tipo		//Formato de la foto.
 * @post Se almacenará en la variable estructurada Foto el formato de la foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setLogin(Usuario *u, string login){
	
	u->login = login;
}

					/*******************
					****	GET	****
					********************/
/**
 * @brief Devuelve el puntero Ruta de una variable estructurada de tipo Persona.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getRuta(Foto *f){
    return f->ruta;
}
/**
 * @brief Devuelve el puntero Tipo de una variable estructurada de tipo Persona.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getTipo(Foto *f){
    return f->tipo;
}
/**
 * @brief Devuelve el Tamanio Ruta de una variable estructurada de tipo Persona.
 * @param Foto *f		//Puntero de tipo foto.
 * @pre Está filtrada al usar unsigned int para no introducir números negativos.
 * @post Nos devuelve la variable edad de un tipo estructurado de alumno.
 * @version 1.0
 * @author Carlos Fdez.
 */
int long unsigned getTamanio (Foto *f){
    return p->tamanio;
}

//----------------------------------------------------------//

//********************************************************************************************************//
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
		cout << "\n[7]  Ordenar tabla Usuarios por Atributo totalFotosUsuario y por atributo login. ";	//Doble ordenación
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
					CrearTablaUsuarios();
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
//********************************************************************************************************//
int main(){
 
	//Declaración de variables.
 
 
 
 
 
	MenuInicio();
 
 
 
 
}
