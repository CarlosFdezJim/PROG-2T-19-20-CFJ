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
** Definición del TIPO DE DATO Foto  **
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
	string nombre;		//Nombre del usuario
	string apellido;	//Apellido del usuario
	string perfil_usuario;	// Nombre de videojuego
	Foto* v_fotos;		//Vector Dinámico de Burbujas.
	int dim_vfotos;		//Dimensión del vector.
	int totalFotosUsuario;	//utiles del vector
};

//set,get,crearUsuario,eliminarUsuario, insertarFotoenUsuario,eliminarFotoUsuario,etc

/**********************************************
** Definición del TIPO DE DATO TablaUsuarios **
**********************************************/

struct TablaUsuarios{

	Usuario** punteroapuntero;	//Vector Dinámico de Punteros a Burbuja.
	int TotalTuplas;		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.
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
Usuario* crearUsuario();
void borrarUsuario(Usuario *u);
//-----------------------------//
void setLogin(Usuario *u, string login);
void setNombre(Usuario *u, string nombre);
void setApellido(Usuario *u, string apellido);
void setPerfilUsuario(Usuario *u, string perfil_usuario);
//-----------------------------//
string getLogin(Usuario *u);
string getNombre(Usuario *u);
string getApellido(Usuario *u);
string getPerfilUsuario(Usuario *u);
/*********************************************************************
 ** Implementación de los Prototipos del Tipo de Dato TablaUsuarios **
 ********************************************************************/
void setTotalTuplas(TablaUsuarios &tu, int TotalTuplas);
int getTotalTupla(TablaUsuarios &tu);


//********************************************************************************************************//

/**
 * @brief Se reservará un espacio de memoria para crear una estructura de tipo Foto, siempre y cuando haya memoria suficiente.
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
 * @brief Módulo que borrará el espacio de memoria reservado a Foto, borrando primero los miembros y después borramos el punteros.
 * @param Foto *f		//Puntero de tipo foto.
 * @post Se reservará un espacio de memoria.
 * @version 1.0
 * @author Carlos Fdez.
 */
void borrarFoto(Foto *f){

	//Ponemos a cero/null todos los datos que tiene la Foto
	f->ruta = "";
	f->tipo = "";
	f->tamanio = -1;

	//borro el fragmento de memoria
	delete f;

	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	f = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Se reservará un espacio de memoria para crear un nuevo Usuario y sus miembros, siempre y cuando haya memoria suficiente.
 * @post Se reservará un espacio de memoria para la Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
Usuario* crearUsuario(){

	//Reservamos un nuevo espacio de memoria para el usuario y lo inicializamos.
	Usuario *u = 0;
	u = new Usuario;
	//Inicializamos el contenido del Usuario.
	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";

	u->v_fotos=0;	
	u->dim_vfotos=0;
	u->totalFotosUsuario=0;
	//Reservamos un nuevo espacio de memoria para el vector de fotos que lleva dentro el usuario.
	u->v_fotos = new Foto[u->dim_vfotos];

	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (u == 0){
		cerr << "Error. No hay memoria suficiente para crear un nuevo Usuario. Se abortará la ejecución" << endl;
		exit(-1);
	}

	if (u->v_fotos == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}

	return u;

}
/**
 * @brief Módulo que borrará el espacio de memoria reservado a un Usuario, borrando primero los datos del usuario y después borramos los punteros.
 * @param Usuario *u		//Puntero de tipo foto.
 * @post Se liberará un espacio de memoria al borrar a un usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void eliminarUsuario(Usuario *u){

	//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";	
	//borramos una por una las fotos del vector de fotos.
	for(int i=0; i < u->totalFotosUsuario; i++){
		borrarFoto(&u->v_fotos[i]);
	}
	u->dim_vfotos=0;
	u->totalFotosUsuario=0;

	//borro el fragmento de memoria
	delete [] u->v_fotos;
	delete u;

	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	u = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Se reservará un espacio de memoria para crear una nueva TablaUsuarios y sus miembros, siempre y cuando haya memoria suficiente.
 * @post Se reservará un espacio de memoria para la Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
/*TablaUsuarios* crearTablaUsuarios(){

	//Reservamos un nuevo espacio de memoria para el usuario y lo inicializamos.
	TablaUsuarios *tu=0;
	tu = new TablaUsuarios;
	int TotalTuplas=0;
	
	//Reservamos un nuevo espacio de memoria para el vector de fotos que lleva dentro el usuario.
	//tu-> = new PunteroAPunteros[TotalTuplas];

	//Inicializamos el contenido del Usuario.
	tu->TotalTuplas=0;

		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (tu == 0){
			cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
			exit(-1);
		}

	return tu;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 * @pre El tamanio no puede ser números negativos, por eso usamos "unsigned".
 * @post Nos devuelve la variable tamanio de un tipo estructurado de Foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setTamanio (Foto *f, unsigned long int tamanio){
    f->tamanio = tamanio;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada login.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string login		//Login del usuario.
 * @post Se almacenará en la variable estructurada Usuario el login del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setLogin(Usuario *u, string login){
	u->login = login;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada nombre.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string nombre		//nombre del usuario.
 * @post Se almacenará en la variable estructurada Usuario el nombre del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setNombre(Usuario *u, string nombre){
    u->nombre = nombre;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada apellido.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string apellido	//Apellido del usuario.
 * @post Se almacenará en la variable estructurada Usuario el apellido del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setApellido(Usuario *u, string apellido){
    u->apellido = apellido;   
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada perfil_usuario que almacenará el nombre del juego al que el usuario quiere jugar.
 * @param Usuario *u			//Puntero de tipo Usuario.
 * @param string perfil_usuario		//Nombre del juego al que juega el usuario.
 * @post Se almacenará en la variable estructurada Usuario el juego favorito del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setPerfilUsuario(Usuario *u, string perfil_usuario){ 
    u->perfil_usuario = perfil_usuario;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada dim_vfotos.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param int dim_vfotos	//Dimensión de fotos que puede almacenar el usuario.
 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setV_Fotos(Usuario *u, Foto *f){
    u->v_fotos = f;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada dim_vfotos.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param int dim_vfotos	//Dimensión de fotos que puede almacenar el usuario.
 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setDIM_vFotos(Usuario *u, int dim_vfotos){
    u->dim_vfotos = dim_vfotos;   
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada totalFotosUsuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param int totalFotosUsuario	//Total de fotos que almacena actualmente el usuario.
 * @post Se almacenará en la variable estructurada Usuario el total de fotos que tiene actualmente el usuario del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setTotalFotosUsuario(Usuario *u, int totalFotosUsuario){
    u->totalFotosUsuario = totalFotosUsuario;   
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo TablaUsuario una variable int llamada TotalTuplas.
 * @param TablaUsuarios &tu
 * @param int TotalTuplas
 * @pre Debemos haber creado eln struct Tabla Usuario correctamente. 
 * @post Se alamacenará en la variable estructurada TablaUsuarios el tota de tuplas que tiene la tabla.(Las útiles del vector de usuarios llamado PunteroAPuntero).
 * @version 1.0
 * @author Carlos Fdez.
 */
void setTotalTuplas(TablaUsuarios &tu, int TotalTuplas){
	tu.TotalTuplas=TotalTuplas;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


					/*******************
					****	GET	****
					********************/
/**
 * @brief Devuelve el puntero Ruta de una variable estructurada de tipo Foto.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getRuta(Foto *f){
    return f->ruta;
}
/**
 * @brief Devuelve el puntero Tipo de una variable estructurada de tipo Foto.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getTipo(Foto *f){
    return f->tipo;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Devuelve el Tamanio Ruta de una variable estructurada de tipo Foto.
 * @param Foto *f		//Puntero de tipo foto.
 * @pre Está filtrada al usar unsigned int para no introducir números negativos.
 * @post Nos devuelve la variable edad de un tipo estructurado de alumno.
 * @version 1.0
 * @author Carlos Fdez.
 */
int long unsigned getTamanio (Foto *f){
    return f->tamanio;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Devuelve el puntero Login de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getLogin(Usuario *u){
    return u->login;
}
/**
 * @brief Devuelve el puntero Nombre de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getNombre(Usuario *u){
    return u->nombre;
}
/**
 * @brief Devuelve el puntero Apellido de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getApellido(Usuario *u){
    return u->apellido;
}
/**
 * @brief Devuelve el puntero Perfil_Usuario de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getPerfilUsuario(Usuario *u){
    return u->perfil_usuario;
}
/**
 * @brief Devuelve el puntero Perfil_Usuario de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
/*string getv_Fotos(Usuario *u){


    return u->perfil_usuario;
}*/
/**
 * @brief Devuelve el puntero dim_vfotos de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
int getDIM_vfotos(Usuario *u){
    return u->dim_vfotos;
}
/**
 * @brief Devuelve el puntero totalFotosUsuario de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
int getTotalFotosUsuario(Usuario *u){
    return u->totalFotosUsuario;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Devuelve el puntero totalFotosUsuario de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
int getTotalTupla(TablaUsuarios &tu){
	return tu.TotalTuplas;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------//
void insertarUsuarioTablaUsuarios(Usuario *u,TablaUsuarios tu){

	if (totalTuplas <= 20){
		tu.punteroapuntero[tu.totalTuplas] = u;
		cout << "El usuario se ha insertado correctamente. " << endl;
	}else
		cout <<"No hay más espacio." << endl;
		
		
}
/**
 * @brief Módulo que se encarga de almacenar en la Tabla de Usuarios algunos usuarios predefinidos.
 * @pre Deberemos tener bien hechos los Set para que no fallen al insertar los usuarios predefinidos.
 * @post Los usuarios serán introducidos en la Tabla de Usuarios.
 * @version 2.2
 * @author Carlos Fdez.
 */
void UsuariosPredefinidos(TablaUsuarios tu){

	//Usuarios predefinidos.
	Usuario *Carlos=0;
	Usuario *Jaime=0;
	Usuario *Cristian=0;
	Usuario *Adrian=0;
	Usuario *Jesus=0;
	Usuario *Pablo=0;
	Usuario *Ana=0;
	
	
	/***************************************
	**************	CARLOS	****************
	****************************************/
	Carlos =  crearUsuario();
	setLogin(Carlos, "@CarlosCristoRey");
	setNombre(Carlos, "Carlos");
	setApellido(Carlos, "Fernández");
	setPerfilUsuario(Carlos, "FIFA");
	insertarUsuarioTablaUsuarios(Carlos,tu);
	
	
	/***************************************
	**************	JAIME	****************
	****************************************/	
	Jaime = crearUsuario();
	setLogin(Jaime, "@JaimeCristoRey");
	setNombre(Jaime, "Jaime");
	setApellido(Jaime, "Cabezas");
	setPerfilUsuario(Jaime, "Minecraft");
	insertarUsuarioTablaUsuarios(Jaime,tu);
	/***************************************
	********	CRISTIAN	********
	****************************************/
	Cristian =  crearUsuario();
	setLogin(Cristian, "@CristianCristoRey");
	setNombre(Cristian, "Cristian");
	setApellido(Cristian, "Campos");
	setPerfilUsuario(Cristian, "Footbal Manager");
	insertarUsuarioTablaUsuarios(Cristian,tu);
	/***************************************
	**************	ADRIAN	****************
	****************************************/
	Adrian =  crearUsuario();
	setLogin(Adrian, "@AdrianCristoRey");
	setNombre(Adrian, "Adrián");
	setApellido(Adrian, "Castillo");
	setPerfilUsuario(Adrian, "Counter Strike");
	insertarUsuarioTablaUsuarios(Adrian,tu);
	/***************************************
	**************	JESUS	****************
	****************************************/
	Jesus = crearUsuario();
	setLogin(Jesus, "@JesusCristoRey");
	setNombre(Jesus, "Jesús");
	setApellido(Jesus, "Rey");
	setPerfilUsuario(Jesus, "GTA V");
	
	/***************************************
	**************	PABLO	****************
	****************************************/
	Pablo =  crearUsuario();
	setLogin(Pablo, "@PabloCristoRey");
	setNombre(Pablo, "Pablo");
	setApellido(Pablo, "García");
	setPerfilUsuario(Pablo, "Counter Strike");
	
	/***************************************
	**************	  ANA	****************
	****************************************/
	Ana =  crearUsuario();
	setLogin(Ana, "@AnaCristoRey");
	setNombre(Ana, "Ana");
	setApellido(Ana, "Tallón");
	setPerfilUsuario(Ana, "Animal Crossing");


	
}
/**
 * @brief En éste módulo insertaremos los usuarios predefinidos en una TablaUsuarios que hemos creado previamente.
 * @param TablaUsuarios &tu	//
 * @pre Deberemos haber creado la tabla de usuarios previamente.
 * @post Insertaremos en la tabla de usuarios los usuarios que querámos.
 * @version
 * @author Carlos Fdez.
 */
 void insertarUsuariosTabla(TablaUsuarios &tu, Usuario *u){

	 
 
 
 }
//********************************************************************************************************/
/**
 * @brief Imprime por pantalla el contenido de una variable estructurada de tipo Usuario.
 * @param Usuario *u
 * @pre El nombre, la edad y los nombres de las asignaturas deberán contener carácteres válidos.
 * @post Imprimir por pantalla la información del contenido del tipo Alumno seleccionado.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printUsuario(Usuario *u){

	cout << YELLOW << "****************************************" << endl;
	cout << YELLOW <<  "Login: " << DEFAULT << getLogin(u) << endl;
	cout << YELLOW << "Nombre: " << DEFAULT <<  getNombre(u) << endl;
	cout << YELLOW << "Apellido: " << DEFAULT <<  getNombre(u) << endl;
	cout << YELLOW << "Este usuario tiene: " << DEFAULT << getTotalFotosUsuario(u) << endl;
	cout << YELLOW << "--------------------------" << DEFAULT << endl;

}
/**
 * @brief Imprime por pantalla el vector de Usuarios.
 * @param Usuario *PunterosAPunteros	//Vector de punteros de usuarios.
 * @param int TotalTuplas		//Útiles del vector.
 * @pre Las utiles deberán de estar filtradas para no superar la dimensión del vector.
 * @post Se mostará por pantalla el vector de usuarios
 * @version
 * @author Carlos Fdez.
 */
void printVectorUsuario(Usuario *PunterosAPunteros, int TotalTuplas){
    for(int i=0; i < TotalTuplas; i++)
        printUsuario(&PunterosAPunteros[i]);
}
/**
 * @brief Imprime por pantalla la ruta de la foto junto a su tipo y el tamaño que ocupa la foto.
 * @param Foto *f
 * @pre Los módulos getRuta, getTipo y getTamanio deben de tener ya algún valor introducido.
 * @post Imprimiremos la ruta de la foto por pantalla.
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
					cout << YELLOW << "\nLo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
			}
	}
}
//********************************************************************************************************//
int main(){


	//Carlos = CrearUsuario();
	//Cristobook.PunteroAPuntero[Cristobook.TotalTuplas] = &Carlos;	//getTotalTuplas.
	//Cristobook.TotalTuplas++;
	
	//InsertarTabla
	//Paso &Carlos y Cristobok.PunteroAPuntero = Usuario &u;
	//Llamar Resize aumentar.

	
		
	//UsuariosPredefinidos();
	//MenuInicio(); 
}
