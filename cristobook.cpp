//
//	CRISTOBOOK.cpp
//
//  Created by Carlos Fdez
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
#include <stdlib.h>
#include <string.h>
using namespace std;

/**************************************
** Definición del TIPO DE DATO Foto **
**************************************/

struct Foto{
	string ruta;			//ruta del archivo en el SO.
	string tipo;			//Tipo de la foto(jpg, png).
	unsigned long int tamanio;	//Se va a guardar en bytes.
};

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
};

//set,get,crearUsuario,eliminarUsuario, insertarFotoenUsuario,eliminarFotoUsuario,etc

/**********************************************
** Definición del TIPO DE DATO TablaUsuarios **
**********************************************/

struct TablaUsuarios{
	Usuario** punteroapuntero;	//Vector Dinámico de Punteros a Burbuja.
	int totaltuplas;		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.
};

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
void setLogin(Usuario *u, string login);
void setNombre(Usuario *u, string nombre);
void setApellido(Usuario *u, string apellido);
void setPerfilUsuario(Usuario *u, string perfil_usuario);
//-----------------------------//
string getLogin(Foto *u);
string getNombre(Usuario *u);
string getApellido(Usuario *u);
string getPerfilUsuario(Usuario *u);
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

	Foto *f=0;
	f = new Foto;

	if (f == 0){
		cerr << "Error. No hay memoria suficiente para crear una foto nueva. Se abortará la ejecución" << endl;
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
    f->ruta = "";
    f->tipo = "";
    f->tamanio = -1;

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
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada login.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string tipo		//Formato de la foto.
 * @post Se almacenará en la variable estructurada Foto el login del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setLogin(Usuario *u, string login){
	u->login = login;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada nombre.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string nombre		//Formato de la foto.
 * @post Se almacenará en la variable estructurada Foto el nombre del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setNombre(Usuario *u, string nombre){
    u->nombre = nombre;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada apellido.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string apellido		//Formato de la foto.
 * @post Se almacenará en la variable estructurada Foto el apellido del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setApellido(Usuario *u, string apellido){
    u->apellido = apellido;   
}
/**
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada login.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string tipo		//Formato de la foto.
 * @post Se almacenará en la variable estructurada Foto el login del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setPerfilUsuario(Usuario *u, string perfil_usuario){ 
    u->perfil_usuario = perfil_usuario;
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
    return f->tamanio;
}
/**
 * @brief Devuelve el puntero Login de una variable estructurada de tipo Usuario.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getLogin(Usuario *u){
    return u->login;
}
/**
 * @brief Devuelve el puntero Nombre de una variable estructurada de tipo Usuario.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getNombre(Usuario *u){
    return u->nombre;
}
/**
 * @brief Devuelve el puntero Apellido de una variable estructurada de tipo Usuario.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getApellido(Usuario *u){
    return u->apellido;
}
/**
 * @brief Devuelve el puntero Perfil_Usuario de una variable estructurada de tipo Usuario.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getPerfilUsuario(Usuario *u){
    return u->perfil_usuario;
}
//----------------------------------------------------------//
/**
 * @brief 
 * @param 
 * @param 
 * @pre 
 * @post 
 * @version
 * @author Carlos Fdez.
 */
Usuario* crearUsuario(){

	Usuario *u=0;
	u = new Usuario;
	u->v_fotos = new Foto[u->dim_fotos];

	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";
	u->v_fotos=0;	
	u->dim_fotos=0;
	u->totalFotosUsuario=0;

		if (u == 0){
			cerr << "Error. No hay memoria suficiente para crear una foto nueva. Se abortará la ejecución" << endl;
			exit(-1);
		}

		if (u->v_fotos == 0){
			cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
			exit(-1);
		}

	return u;

}
/**
 * @brief Módulo que borrará el espacio de memoria reservado a Foto, borrando primero los datos de la persona que queremos borrar y después borramos los punteros.
 * @param Foto *f		//Puntero de tipo foto.
 * @post Se reservará un espacio de memoria.
 * @version 1.0
 * @author Carlos Fdez.
 */
void eliminarUsuario(Usuario *u){

	//formateo a cero/nulo todos los datos que tiene una persona
	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";	
	
	for(int i=0; i < u->totalFotosUsuario; i++){
		borrarFoto(&u->v_fotos[i]);
	}
	
	u->dim_fotos=-1;
	u->totalFotosUsuario=-1;

	//borro el fragmento de memoria
	delete [] u->v_fotos;
	delete u;

	//elimino la dirección que referenciaba al fragmento de memoria
	u = 0;
}
void CrearTablaUsuarios(Usuario *u){

	//Usuarios predefinidos.
	Usuario Carlos;
	Usuario Jaime;
	Usuario Cristian;
	Usuario Adrian;
	Usuario Jesus;
	Usuario Pablo;
	Usuario Ana;
	
	/***************************************
	**************	CARLOS	****************
	****************************************/
	setLogin(Carlos*, "CarlosCristoRey");
	setNombre(Carlos*, "Carlos");
	setApellido(Carlos*, "Fernández");
	//setPerfilUsuario(Carlos, string perfil_usuario);
	
	/***************************************
	**************	JAIME	****************
	****************************************/	
	setLogin(Jaime, "JaimeCristoRey");
	setNombre(Jaime, "Jaime");
	setApellido(Jaime, "Cabezas");
	//setPerfilUsuario(Jaime, string perfil_usuario);
	
	/***************************************
	********	CRISTIAN	********
	****************************************/	
	setLogin(Cristian, "CristianCristoRey");
	setNombre(Cristian, "Cristian");
	setApellido(Cristian, "Campos");
	//setPerfilUsuario(Cristian, string perfil_usuario);
	
	/***************************************
	**************	ADRIAN	****************
	****************************************/	
	setLogin(Adrian, "AdrianCristoRey");
	setNombre(Adrian, "Adrián");
	setApellido(Adrian, "Castillo");
	//setPerfilUsuario(Adrian, string perfil_usuario);
	
	/***************************************
	**************	JESUS	****************
	****************************************/	
	setLogin(Jesus, "JesusCristoRey");
	setNombre(Jesus, "Jesús");
	setApellido(Jesus, "Rey");
	//setPerfilUsuario(Jesus, string perfil_usuario);
	
	/***************************************
	**************	PABLO	****************
	****************************************/	
	setLogin(Pablo, "PabloCristoRey");
	setNombre(Pablo, "Pablo");
	setApellido(Pablo, "García");
	//setPerfilUsuario(Pablo, string perfil_usuario);
	
	/***************************************
	**************	  ANA	****************
	****************************************/	
	setLogin(Ana, "AnaCristoRey");
	setNombre(Ana, "Ana");
	setApellido(Ana, "Tallón");
	//setPerfilUsuario(Ana, string perfil_usuario);
}
//********************************************************************************************************//






/**
 * @brief Imprime por pantalla el nombre completo de la foto.
 * @param const Fecha F(E/S)
 * @pre Los módulos getDia, getMes y getAnio deben de tener ya algún valor introducido.
 * @post Imprimiremos la fecha por pantalla.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printNombreFoto(Foto *f){
	cout << getRuta(f) << "." << getTipo(f) << "-" << getTamanio(f) << endl;
}
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
					//CrearTablaUsuarios();
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
