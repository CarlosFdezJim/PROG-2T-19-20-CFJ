# PROG-2T-19-20-CFJ
Páctica 2º Trimestre

Tarjeta 0: Creación del Menú de Opciones
Tarjeta 1: Crear Tabla Usuarios: en este apartado se creará una tabla de usuarios con algunos ejemplos en su interior y que esté totalmente preparada para interactuar. Evidentemente ninguna otra acción podrá realizarse hasta que la tabla de usuarios esté creada en el sistema, y una vez creada la misma, no podrá volver a crearse. Mínimo 7 usuarios creados automáticamente y todos con un número de ficheros en su interior distintos.
Tarjeta 2: Eliminar Tabla Usuarios: en este apartado se eliminará la tabla de usuarios adecuadamente, liberando la memoria dinámica en el orden apropiado para evitar errores de segmentación.
Tarjeta 3: Imprimir Tabla Usuarios: en este apartado el administrador podrá visualizar el contenido de la tabla de usuarios, de tal manera que se imprima cada usuario y, optativamente si así se desea, los nombres de los ficheros que son de su propiedad. En este apartado se valora mucho la presentación y se deben usar colores.
Tarjeta 4: Insertar Usuario en tabla Usuarios: en este apartado el administrador podrá crear un nuevo usuario en la tabla de usuarios. Aquí se creará su burbuja y se captarán los datos básicos del mismo, se reservará memoria para almacenar ficheros, pero de momento no se agregará ninguno. Se debe controlar el crecimiento y en cada inserción redimensionar el vector de punteros a usuario, es decir, la dimensión del vector de punteros a usuario, crece de una unidad en una unidad.
Tarjeta 5: Eliminar Usuario en tabla Usuarios: en este apartado se eliminará un usuario de la lista de usuarios adecuadamente, liberando la memoria dinámica en el orden apropiado para evitar errores de segmentación. Para ello se deberá mostrar la tabla de usuarios actual previamente y a través del login, que es único en el sistema, se escogerá el que se quiere eliminar. Se debe controlar cómo decrece dinámicamente la tabla, eliminando una posición en cada eliminación, es decir, la dimensión del vector de punteros a usuario, decrece de una unidad en una unidad.
Tarjeta 6: Buscar Usuario por Atributo Login en tabla Usuarios (utilizar la búsqueda secuencial)
Tarjeta 7: Ordenar tabla Usuarios por Atributo totalFotosUsuario y por atributo login
Tarjeta 8: Añadir Foto a Usuario: en este apartado se creará una nueva burbuja de tipo Foto que se copiará al vector de Fotos dinámico del usuario al que se quiera añadir. Si no hubiese espacio en dicho vector, hay que controlar su redimensión.
Tarjeta 9: Eliminar Foto de un Usuario: este apartado se eliminará una Foto del usuario, bastará con emplear las útiles y reordenar.
Tarjeta 10: Imprimir las Fotos de un Usuario: en este apartado se imprimirán en detalle todos las Fotos de un usuario que previamente se escoja mediante el login.
Tarjeta 11 (EXTRA): Resolver la siguiente consulta sobre la tabla: “Devolver el conjunto de usuarios que posean un determinado fichero. Para ello, se le pedirá al usuario una cadena de texto, y se deberá buscar en todas los ficheros de todos los usuarios del sistema si esa cadena coincide total o parcialmente con nombres de ficheros que sean de su propiedad”
Tarjeta 12: Salir: en este apartado se terminará la ejecución del programa y se liberará toda la memoria dinámica previamente antes de despedirse del administrador.
"Tarjeta 13: FLIPADAS: 1) Uso del comando execl para ejecutar scripts propios y abrir un programa que permita visualizar una foto real en el sistema operativo.
2) MÓDULO TESTING INVOCADO DESDE OTRA OPCIÓN
3) Cualquier otra flipada o mejora.
