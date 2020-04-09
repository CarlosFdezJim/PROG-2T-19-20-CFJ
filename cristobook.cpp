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

	//Reservamos un nuevo espacio de memoria para la Foto y lo inicializamos.
	Foto *f=0;
	f = new Foto;
	
	//Inicializamos el contenido del Usuario.	
	f->ruta = "";
	f->tipo = "";
	f->tamanio = 0;
	
	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (f == 0){
		cerr << "Error. No hay memoria suficiente para crear una foto nueva. Se abortará la ejecución" << endl;
		exit(-1);
	}
	return f;
}
/**
 * @brief Módulo que borrará el espacio de memoria reservado a Foto, borrando primero los miembros y después borramos el punteros.
 * @param Foto *f		//Puntero de tipo foto.
 * @post Se eliminará un espacio de memoria de Foto.
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
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @post Se liberará un espacio de memoria al borrar a un usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void borrarUsuario(Usuario *u){

	//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";	
	
	//borramos una por una las fotos del vector de fotos.
	for(int i=0; i < u->totalFotosUsuario; i++){
		borrarFoto(&u->v_fotos[i]);
	}
	
	u->dim_vfotos = -1;
	u->totalFotosUsuario = -1;

	//borro el fragmento de memoria
	delete [] u->v_fotos;
	delete u;

	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	u = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Se reservará un espacio de memoria para crear una nueva TablaUsuarios y sus miembros, siempre y cuando haya memoria suficiente.
 * @post Se reservará un espacio de memoria para la TablaUsuarios.
 * @version 1.0
 * @author Carlos Fdez.
 */
TablaUsuarios crearTablaUsuarios(){

	//Reservamos un nuevo espacio de memoria para el usuario y lo inicializamos.
	TablaUsuarios tu;
	
	//Inicializamos el contenido de la TablaUsuarios.
	tu.TotalTuplas=0;
	tu.punteroapuntero=0;
	
	//Reservamos un nuevo espacio para el vector de punteros que tiene dentro la variable estructurada TablaUsuario
	tu.punteroapuntero = new Usuario*[tu.TotalTuplas];

	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (tu.punteroapuntero == 0){
		cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
		exit(-1);
	}

	return tu;
}
/**
 * @brief Este módulo se encarga de borrar la TablaUsuarios.Eliminando en el siguiente orden :
 		1º Borramos la estructura Foto y los datos introducidos y ponemos a 0 su puntero.
 		2º Borramos la estructura Usuario y los datos introducidos y ponemos a 0 su puntero.
		3º Borramos la estructura TablaUsuarios y los datos introducidos y ponemos a 0 su puntero.
 * @param TablaUsuarios tu
 * @pre Debemos de tener bien hecho el módulo borrarUsuario, sino se nos quedarán cosas en el limbo.
 * @post Se librerará toda la memoria dinámica en el orden adecuado.
 * @version
 * @author Carlos Fdez.
 */
void borrarTablaUsuarios(TablaUsuarios tu, Usuario *u, Foto *f){
	
	//Eliminamos los datos de Foto y todo el contenido de sus punteros.
	borrarFoto(f);
	
	//Eliminamos los datos del Usuario.(Dentro eliminamos el vector de fotos y los puntero).
	borrarUsuario(u);
	
	//borro el fragmento de memoria que pertenecía a punteroapuntero.
	delete [] tu.punteroapuntero;
	
	//Elimino los datos de TotalTuplas.
	tu.TotalTuplas=-1;
}
/**
 * @brief Este módulo borra toda la memoria dinámica que habíamos creado en nuetsro programa.
 * @param TablaUsuarios tu
 * @param Usuario *u
 * @param Foto *f
 * @pre Los módulos de borrarFoto(), borrarUsuario() y borrarTablaUsuarios() deben de estar bien programados.
 * @post Se elimina la memória dinámica para salir del programa.
 * @version 2.5
 * @author Carlos Fdez.
 */
/*void Exit(TablaUsuarios tu, Usuario *u, Foto *f){
	
	//Eliminamos los datos de Foto y todo el contenido de sus punteros.
	borrarFoto(f);
	
	//Eliminamos los datos del Usuario.(Dentro eliminamos el vector de fotos y los puntero).
	borrarUsuario(u);
	
	//Eliminamos los datos de TablaUsuario y todo el contenido de los punteros.
	borrarTablaUsuarios(tu);
}*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
					/*******************
					****	SET		****
					*******************/
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
 * @param string nombre		//Nombre del usuario.
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
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada v_fotos.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param Foto *f		//Puntero de tipo Foto.
 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
/*void setV_Fotos(Usuario *u, Foto *f){
    u->v_fotos = f;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada dim_vfotos.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param int dim_vfotos	//Dimensión de fotos que puede almacenar el usuario.
 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar el usuario.
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
 * @param TablaUsuarios &tu (E/S)
 * @param int TotalTuplas.
 * @post Se alamacenará en la variable estructurada TablaUsuarios el tota de tuplas que tiene la tabla.(Las útiles del vector de usuarios llamado PunteroAPuntero).
 * @version 1.0
 * @author Carlos Fdez.
 */
void setTotalTuplas(TablaUsuarios &tu, int TotalTuplas){
	tu.TotalTuplas=TotalTuplas;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


					/*******************
					****	GET		****
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
 * @param TablaUsuarios tu
 * @version 1.0
 * @author Carlos Fdez.
 */
int getTotalTuplas(TablaUsuarios &tu){
	return tu.TotalTuplas;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Cambia la dimensión del vector a una nueva DIM_nueva
	 *  1) Creo un vector nuevo con la nueva dimension +1
	 *  2) Copio el contenido del vector que me pasan, en el nuevo vector (OJO SI ES MÁS GRANDE)
	 *  3) Libero la memoria del vector que me pasan
	 *  4) Devuelvo el puntero del nuevo vector
 * @param Persona *v
 * @param int util_v
 * @param int DIM_actual(E/S)
 * @post Aumentaremos en uno la dimensión de nuestro vector.
 * @version 1.0
 * @author Carlos Fdez.
 */
Usuario** resizeAumentarPorPunteros(Usuario **v, int &TotalTuplas){
	
	int DIM = TotalTuplas+1;

	Usuario **vectorNuevo = 0;
	
	vectorNuevo = new Usuario*[DIM]; //memoria dinámica: ME HE CREADO "tamanio" PERSONAS DINÁMICAS

	if (vectorNuevo == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}
	for(int i = 0;i < TotalTuplas;i++){
		vectorNuevo[i]=v[i];
	}
	
	delete [] v;
	TotalTuplas = DIM;

	return vectorNuevo;
}
/**
 * @brief Cambia la dimensión del vector a una nueva DIM_nueva
 * @param Persona *v
 * @param int util_v
 * @param int DIM_actual(E/S)
 * @post Aumentaremos en uno la dimensión de nuestro vector.
 * @version 1.0
 * @author Carlos Fdez.
 */
TablaUsuarios* resizeAumentar(TablaUsuarios *tu, int util_actual, int &DIM_actual){
	
	//1) Creo un vector nuevo con la nueva dimension +1
	int DIM_nueva = DIM_actual+1;

	TablaUsuarios *vector_Nuevo = 0;
	//2) Copio el contenido del vector que me pasan, en el nuevo vector (OJO SI ES MÁS GRANDE)
	vector_Nuevo = new TablaUsuarios[DIM_nueva]; //memoria dinámica: ME HE CREADO "tamanio" PERSONAS DINÁMICAS

	if (vector_Nuevo == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}	
	for(int i = 0;i < util_actual;i++)
		vector_Nuevo[i]=tu[i];
	//3) Libero la memoria del vector que me pasan
	delete [] tu;
	tu = 0;

	DIM_actual = DIM_nueva;
	
	//4) Devuelvo el puntero del nuevo vector
	return vector_Nuevo;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief En éste módulo insertaremos los usuarios predefinidos en una TablaUsuarios que hemos creado previamente.
 * @param Usuario *u
 * @param TablaUsuarios &tu
 * @pre Deberemos haber creado la tabla de usuarios previamente.
 * @post Insertaremos en la tabla de usuarios los usuarios que querámos.
 * @version 1.0
 * @author Carlos Fdez.
 */
void insertarUsuarioTablaUsuarios(Usuario *u, TablaUsuarios &tu){

	//RESIZE
	tu.punteroapuntero=resizeAumentarPorPunteros(tu.punteroapuntero,tu.TotalTuplas);
	
	//INSERTAR USUARIO EN EL VECTOR
	tu.punteroapuntero[tu.TotalTuplas] = u;
	//tu.TotalTuplas++;

}
void eliminarUsuarioTablaUsuarios(Usuario *u, TablaUsuarios &tu){
	//eliminar usuario
	borrarUsuario(u);
	//RESIZE
	tu.punteroapuntero = resizeAumentarPorPunteros(tu.punteroapuntero,tu.TotalTuplas);
	//Eliminar USUARIO EN EL VECTOR

}
/*void insertarFoto(Foto* f, int &totalFotosUsuario, int &DIM_vfotos,Usuario *u){ 	
	//aquí dentro se usa la llamada al resize!!!
	u->v_fotos = resizeAumentar(u->v_fotos,tu.totalFotosUsuario,tu.DIM_vfotos);
	u->v_fotos[totalFotosUsuario] = *f;
	setRuta(f,f->ruta);
	setTipo(f,f->Tipo);
	setTamanio(f, f->Tamanio);
	tu.totalFotosUsuario++;
}*/
/**
 * @brief Este módulo se encargade comprobar si el Login ya está introducido o no.
 * @param string login
 * @param Usuario *u
 * @param bool usado (E/S)
 * @pre El usuario debe de haber insertado el login.
 * @post Continuaremos pidiendo datos si el login no está intoducido.
 * @version 1.0
 * @author Carlos Fdez.
 */
void comprobacionLogin(string login,Usuario *u,bool &usado){

	if(login == u->login){
		cout << RED << "El Login introducido ya está en uso." << DEFAULT << endl;
		usado = true;
	}
}
/**
 * @brief Este módulo se encarga de seguir pidiendo al usuario los datos para completar su inscripción.
 * @param Usuario *u
 * @pre El usario debe de haber introducido un login que no esté repetido.
 * @post Dejaremos al usuario seguir introduciendo datos para su ficha.
 * @version 1.0
 * @author Carlos Fdez.
 */
void pedirDatosUsuario(Usuario *u){

	string nombre = "";
	string apellido = "";
	string perfilUsuario = "";
	
	cout << YELLOW << "Dime el nombre: " << DEFAULT << endl;
	cin >> nombre;
	cout << YELLOW << "Apellido: " << DEFAULT << endl;
	cin >> apellido;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT  << endl;
	cin >> perfilUsuario;
	
	setNombre(u,nombre);
	setApellido(u,apellido);
	setPerfilUsuario(u,perfilUsuario);
	
}
/**
 * @brief Este mñódulo ingresa un usuario en la TablaUsuarios
 * @param TablaUsuarios tu (E/S)
 * @pre La tabla ha tenido que ser creada previamente.
 * @post El usuario aparecerá en la TablaUsuarios.
 * @version 1.0
 * @author Carlos Fdez.
 */
void insertarUsuarioNuevo(TablaUsuarios &tu){

	string login = "";
	bool usado = false;	
	
	cout << "Introduce su Login : " << endl;
	cin >> login;
	
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);	
	}
	if(usado != true){
		
		//Reservamos el espacio de memmoria al nuevo Usuario.
		Usuario *u = 0;	
		u = crearUsuario();
	
		setLogin(u,login);
		pedirDatosUsuario(u);
		//tu.punteroapuntero = resizeAumentarPorPunteros(tu.punteroapuntero,tu.TotalTuplas);
		insertarUsuarioTablaUsuarios(u,tu);
		tu.punteroapuntero = resizeAumentarPorPunteros(tu.punteroapuntero,tu.TotalTuplas);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


					/*******************
					****	PRINT	****
					********************/
/**
 * @brief Imprime por pantalla la ruta de la foto junto a su tipo y el tamaño que ocupa la foto.
 * @param Foto *f
 * @pre Los módulos getRuta, getTipo y getTamanio deben de tener ya algún valor introducido.
 * @post Imprimiremos la ruta de la foto por pantalla.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printFoto(Foto *f){

	cout << "Ruta : " << getRuta(f) << endl;
	cout << "Tipo : " << getTipo(f) << endl;
	cout << "Tamaño : " << getTamanio(f) << endl;
	
}
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
	cout << YELLOW << "Apellido: " << DEFAULT <<  getApellido(u) << endl;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT <<  getPerfilUsuario(u) << endl;
	cout << YELLOW << "--------------------------" << DEFAULT << endl;
	
	if(getTotalFotosUsuario(u) != 0){
		for(int i= 0; i < getTotalFotosUsuario(u);i++){
			cout << " Foto número : " << i << endl;
			printFoto(&u->v_fotos[i]);
			cout << YELLOW << "****************************************" << DEFAULT << endl;
		}
	}else
		cout << YELLOW << "Este usuario no tiene fotos. " << DEFAULT << endl;

}
/**
 * @brief Éste módulo se encarga de imprimir la TablaUsuarios.
 * @param TablaUsuarios &tu
 * @pre La tabla de Usuarios debe de estar creada.
 * @post Mostrará todos los usuarios insertados en a tabla.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printTablaUsuarios(TablaUsuarios &tu){

	for(int i = 0;i < getTotalTuplas(tu);i++)
		printUsuario(tu.punteroapuntero[i]);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Módulo que se encarga de almacenar en la Tabla de Usuarios algunos usuarios predefinidos.
 * @pre Deberemos tener bien hechos los Set para que no fallen al insertar los usuarios predefinidos.
 * @post Los usuarios serán introducidos en la Tabla de Usuarios.
 * @version 2.2
 * @author Carlos Fdez.
 */
void UsuariosPredefinidos(TablaUsuarios &tu){

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
	//setRuta(f->ruta, "/home/Carlos/Escritorio/Imagenes/foto1.jpg");
	insertarUsuarioTablaUsuarios(Carlos,tu);
	//setTotalTuplas(tu,getTotalTuplas(tu));
	
	/***************************************
	**************	JAIME	****************
	****************************************/	
	Jaime = crearUsuario();
	setLogin(Jaime, "@JaimeCristoRey");
	setNombre(Jaime, "Jaime");
	setApellido(Jaime, "Cabezas");
	setPerfilUsuario(Jaime, "Minecraft");
	insertarUsuarioTablaUsuarios(Jaime,tu);
	//setTotalTuplas(tu,getTotalTuplas(tu)+1);
	
	/***************************************
	********	CRISTIAN	********
	****************************************/
	Cristian =  crearUsuario();
	setLogin(Cristian, "@CristianCristoRey");
	setNombre(Cristian, "Cristian");
	setApellido(Cristian, "Campos");
	setPerfilUsuario(Cristian, "Footbal Manager");
	insertarUsuarioTablaUsuarios(Cristian,tu);
	//setTotalTuplas(tu,getTotalTuplas(tu)+1);
	
	/***************************************
	**************	ADRIAN	****************
	****************************************/
	Adrian =  crearUsuario();
	setLogin(Adrian, "@AdrianCristoRey");
	setNombre(Adrian, "Adrián");
	setApellido(Adrian, "Castillo");
	setPerfilUsuario(Adrian, "Counter Strike");
	insertarUsuarioTablaUsuarios(Adrian,tu);
	//setTotalTuplas(tu,getTotalTuplas(tu)+1);
	
	/***************************************
	**************	JESUS	****************
	****************************************/
	Jesus = crearUsuario();
	setLogin(Jesus, "@JesusCristoRey");
	setNombre(Jesus, "Jesús");
	setApellido(Jesus, "Rey");
	setPerfilUsuario(Jesus, "GTA V");
	insertarUsuarioTablaUsuarios(Jesus,tu);
	//setTotalTuplas(tu,getTotalTuplas(tu)+1);
	
	/***************************************
	**************	PABLO	****************
	****************************************/
	Pablo =  crearUsuario();
	setLogin(Pablo, "@PabloCristoRey");
	setNombre(Pablo, "Pablo");
	setApellido(Pablo, "García");
	setPerfilUsuario(Pablo, "Counter Strike");
	insertarUsuarioTablaUsuarios(Pablo,tu);
	//setTotalTuplas(tu,getTotalTuplas(tu)+1);
	
	/***************************************
	**************	  ANA	****************
	****************************************/
	Ana =  crearUsuario();
	setLogin(Ana, "@AnaCristoRey");
	setNombre(Ana, "Ana");
	setApellido(Ana, "Tallón");
	setPerfilUsuario(Ana, "Animal Crossing");
	insertarUsuarioTablaUsuarios(Ana,tu);
	//setTotalTuplas(tu,getTotalTuplas(tu)+1);
	
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
 * @param TablaUsuarios tu
 * @param Usuario *u
 * @param Foto *f
 * @pre El menú deberá de estar hecho inicialmente.
 * @post Mostramos el menú y vamos a la opción seleccionada por el usuario.
 * @version 2.5
 * @author Carlos Fdez.
 */
void MenuInicio(TablaUsuarios tu, Usuario *u, Foto *f){

	//Declaración de variables.
	int opcion=0;
	bool tabla=false;
	
	while(opcion!=11){
		MostrarMenu();
		cout << "\nEliga usted el programa que desea ejecutar: " << endl;		
		cin >> opcion;
	
			switch (opcion){
			
				case 1:
					if(tabla==false){
						cout  << " ****    CREANDO TABLA DE USUARIOS    **** " << endl;
						tu = crearTablaUsuarios();
						UsuariosPredefinidos(tu);
						cout << GREEN << "La tabla de usuarios se ha creado correctamente." << DEFAULT << endl;
						tabla=true;
					}else{
						cout << RED << "La tabla de usuarios ya está creada, por favor elige otra opción." << DEFAULT << endl;
						}
					
				break;
				
				case 2:
					if(tabla==true){
						tabla=false;
						borrarTablaUsuarios(tu, u, f);
						cout << RED << "La tabla de usuarios se eliminó correctamente." << DEFAULT << endl;
					}else{
						cout << ERROR << "\nRecuerde que si no CREA una tabla de Usuarios no podrá seguir utilizando Cristobook. " << DEFAULT << endl;
						}
				break;
				
				case 3:
					if(tabla==true){
						cout << "\n *****   IMPRIMIENDO USUARIOS	*****" << endl;
						printTablaUsuarios(tu);
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 4:		
					if(tabla==true){
						cout << GREEN << "\n****** PREPARANDO PARA INSERTAR USUARIO ********" << DEFAULT << endl;
						insertarUsuarioNuevo(tu);
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 5:		
					if(tabla==true){
						cout << GREEN << "\n****** PREPARANDO PARA ELIMINAR USUARIO ********" << DEFAULT << endl;
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 6:		
					if(tabla==true){
						cout << GREEN << "\n****** BUSCANDO ********" << DEFAULT << endl;
						
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 7:		
					if(tabla==true){
						cout << GREEN << "\n****** ORDENANDO TABLA ********" << DEFAULT << endl;
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 8:		
					if(tabla==true){
						//Añadir fotografía Usuario
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 9:	
					if(tabla==true){
						//Eliminar fotografía Usuario
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 10:		
					if(tabla==true){
						//Imprimir fotografias del usuario
					}else{
						cout << ERROR << "No podrá usar esta opción hasta que la Tabla de Usuarios no esté creada." << DEFAULT << endl;	
					}
				break;
				
				case 11:
						//Exit(tu,u,f);
						cout << BLUE << "----------SALIENDO----------\n" ;
						cout << "\nMuchas gracias por usar CRISTOBOOK ";
						cout << "\n 	© Carlos Fdez" << DEFAULT << endl;
				break;
				
				default:
					cout << YELLOW << "\nLo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
			}
	}
}
//********************************************************************************************************//
int main(){

	//Declaración de punteros
    Usuario *u = 0;
    u = crearUsuario();
    Foto *f = 0;
    f = crearFoto();
	TablaUsuarios tu;

	MenuInicio(tu, u, f);
	
}
