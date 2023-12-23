//Librerías necesarios
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
//Teclas para el menú
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;

/*Esta estructura senta la base de datos dinamica en la que se alojaran todos los 
datos necesarios para el funcionamiento del programa*/

struct prestamo 
{// Para poder concretar un presatamo, Los datos que deben existir son:

	string libroprestado; 		// Un libro tiene su nombre
	string codigoISBNprestado;	// El codigo del libro solicitado
	string nombredelposeedor;	// Nombre del usuario que pasará a poseerlo
	int ceduladelposeedor;		// Documento del usuario que pasará a poseerlo
	int fechadeprestamo;		// Fechá en la que el libro fue prestado o en la que se presta.
	int mesdeprestamo;			// Mes en el que el libro fue prestado o en la que se presta.
	int aniodeprestamo;			// Año en el que el libro fue prestado o en la que se presta.
	int fechalimite;			// Fechá en la cual el libro debe ser devuelto.
	int meslimite;				// Mes en el cual el libro debe ser devuelto.
	int aniolimite;				// Año en el cual el libro debe ser devuelto.
	int estadodeprestamo;		// Estado en el que es devuelto
	prestamo *sig;				// Puntero con funcionalidad de reanudar al siguiente espacio de memoria que posee todos los datos anteiores.
};

struct usuario
{	// Para que un usuario exista, Los datos que deben existir son:
	
	string nombrecompleto;		// Un nombre (Preferilemente completo)
	string nombredeusuario;		// El nombre publico que utilizará en el sistema (muy importante cual ya que será el cual será solicitado cuando le sea bloqueado o desbloqueado)
	string contrasenia;			// Una cadena de texto que le permitir'a al usuario acceder a su cuenta
	int documento;				// Documento de identificación con el que se dirigirá la biblioteca al dueño de la cuenta
	int edad;					// Edad del propietario de la cuenta
	bool ban;					// Este dato es una instancia que verifica si al usuario se le permite el acceso o se le niega. 
	bool admin;					// Este dato es una instancia que verifica si el usuario tiene o no permisos de administrador.
	string email;				// Dirección de correo electronico mediante a la cual la biblioteca se comunicara con el usuario
	long long int telefono;		// Codigo de telefonía que utilizará la biblioteca en caso de necesitar comunicarse directamente con el usuario
	string direccion;			// Direccion de vivienda del usuario
	char sexo;					// Dato que distingue el genero del usuario
	int numerodelibrosprestados;// Indice de bibliografia prestada al usuario
	usuario *sig;				// Puntero con funcionalidad de reanudar al siguiente espacio de memoria que posee todos los datos anteiores.

};

struct libro
{// Para que un Libro exista, Los datos que deben existir son:
	
	string nombre; 			// Un libro tiene su nombre
	string autor; 			// Un libro debe estar informado sobre su autor (en caso de no tener se debe denotar que el mismo es anonimo). 
	string editorial; 		// La editorial que le imprimio
	int edicion; 			// Su Edición 
	int npag; 				// El numero que expresa la cantidad de paginas que lleva
	string genero;			// El tipo de lectura que ofrece al consumidor
	int aniodepublicacion;  // El año en el que fue publicado
	string codigoISBN;		// Cada libro lleva su codigo ISBN que le distingue entre cualquier par. Tal codigo contiene 13 digitos. Ej :"xxx-xx-xxx-xxx-x"
	int estadolibro; 		// El estado se define como un entero, ya que el rango estará entre tres numeros designados como categorias (1 = Excelente, 2 Aceptable, 3=Poco apreciable).
	string estanteria; 		// Codigo que distingue la estanteria en la que se encuentra el ejemplar. 
	int fila;				// Designa que en que fila puede encontrarse
	int existencia;			// Define cuantos ejemplares hay de un mismo libro
	libro *sig;				// Puntero con funcionalidad de reanudar al siguiente espacio de memoria que posee todos los datos anteiores.
};

//Aquí se declaran todas las funciones y procesos que utiliza el programa
	//Apartado: Visual e Interactivo
int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi); // Este Proceso es imprescindible, pues está encargado de gestionar TODOS los menús de eleccion
void cuadro (int x1,int y1,int x2,int y2);   //Estos dos Procedimientos son fundametales para la correcta 
void gotoxy (int x, int y);  				// impresión del apartado visual del programa
void Animation(); //Animación de cambio de pantalla
		//Menúes
int	I_sesion (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos); //Menú de inicio de sesión
void iniciodesesion(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos); //Proceso de inicio de sesión
void U_menu_principal (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos); //Menú de Usuarios
void A_menu_principal (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos); //Menú de Administradores
void A1_menu_principal(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos); //Menú de Administración de Usuarios
void A2_menu_principal(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos); //Menú de Administración de Libros
void A3_menu_principal(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos); //Menú de Administración de Préstamos
		//Fin Menúes
	//Fin Apartado: Visual e Interactivo

	//Apartado Funcionalidad de la Biblioteca
void constructor (libro *&listalibros, usuario *&listausuarios); //Constructor inicial de listas
void registrarusuario (usuario *&listausuarios); 
void mostrarusuarios (usuario *&listausuarios);
void verlistadeusuarios (usuario *&listausuarios);
void eliminarusuarios (usuario *&listausuarios);
void buscarusuarios (usuario *&listausuarios);
void desbloquearusuario (usuario *&listausuarios);
void insertarlibro (libro *&listalibros);
void mostrarlibros (libro *&listalibros);
void verlistadelibros (libro *&listalibros);
void buscarlibro (libro *&listalibros);
void eliminarlibro (libro *&listalibros);
void registrarprestamo (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos);
void registrardevolucion (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos);
void verlistadeprestamos (prestamo *&listaprestamos);
void mostrarprestamos (prestamo *&listaprestamos);
void eliminarprestamo (prestamo *&listaprestamos, usuario *&listausuarios);
//Fin Procesos de biblioteca
void cierreF ();
	//Fin Apartado Funcionalidad de la Biblioteca

//FUNCIONES ESTETICAS PARA LOS MENÚS
void gotoxy (int x, int y){ //Proceso que permite escribir(ó dibujar) libremente en cualquier parte de la consola

	/*Recibe como parametro dos valores que designan el punto exacto que se solicita alcanzar*/
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; // Usa el valor señalado para describir donde debe situarse el cursor horizontalmente. 
	dwPos.Y = y; // Usa el valor señalado para describir donde debe situarse el cursor Verticalmente.
	SetConsoleCursorPosition(hcon,dwPos); // Posiciona el cursor basado en los datos proporcionados.
	
}

void cuadro ( int x1,int y1,int x2,int y2) { 
	
	/*Recibe como parametro cuatro valores enteros que designaran las caracterisiticas del cuadro que se 
	requiere para la situación que fue solicitado*/
	
	int i;
	for (i = x1; i < x2;i++){ //Lineas Horizontales
		gotoxy(i,y1);cout << "-"; // Dibuja la Linea Superior 
		gotoxy(i,y2);cout << "-"; // Dibuja la Linea Inferior
	}
	
	gotoxy(x1,y1); printf("<"); // Dibuja el simbolo de la Esquinas Arriba Izquierda
	gotoxy(x1,y2); printf("<"); // Dibuja el simbolo de la Esquina Abajo Izquierda
	gotoxy(x2,y1); printf(">"); // Dibuja el simbolo de la Esquina Arriba Derecha
	gotoxy(x2,y2); printf(">");	// Dibuja el simbolo de la Esquina Abajo Derecha
}
//FIN FUNCIONES ESTETICAS PARA LOS MENÚS 

void animation() {
	
	for (int i =0;i<1;i++){ // Este For se encarga de delimitar los limites de la animación
		// Estas cuatro lineas crean las cuatro puntas del cuadro de la animación de carga.
		gotoxy (1,5); cout << "*";		// Punta de Superior Izquierda
		gotoxy (78,5); cout << "*";		// Punta de Superior Derercha
		gotoxy (1,22); cout << "*";		// Punta de Inferiror Izquierda
		gotoxy (78,22); cout << "*";	// Punta de Inferiror Derecha
		
		for (int i =0;i<3;i++)  // "Este for crea y gestiona la animación de carga menú. 
		{//la duración de carga dependerá del valor que necesario para i
			gotoxy (1,7-1+i); cout << "|"; // Arriba Izquierda
			gotoxy (3-1+i,5); cout << "-"; // Arriba de derecha a izquierda
			
			gotoxy (78,7-1+i); cout << "|"; // Arriba Derecha
			gotoxy (77-i,5); cout << "-"; // Arriba de izquierda a derecha
			
			gotoxy (1,22-1-i); cout << "|"; // Abajo Izquierda
			gotoxy (3-1+i,22); cout << "-"; // Abajo de Derecha a Izquierda
			
			gotoxy (78,22-1-i); cout << "|"; // Abajo Derecha
			gotoxy (77-i,22); cout << "-";  //Abajo de Izquierda a Derecha 
			
			cout << "\a"; // Esta linea reeimprime el caracter "alarma" para concatenar el pitido de la consola
			Sleep (350);  // Y esta de controlar el intevalo entre pitidos
		}			
	}
}
	
int I_sesion (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) {
	//Menú para iniciar sesión
	
	int ini;
	const char *titulo = "BIENVENIDO A LA BIBLIOTECA UNIVERSITARIA";	// Dirigase a la funcion:
	const char *mensaje = "\t\t¿Qué desea hacer?";						// int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi)
	const char *opciones[] = {"INICIAR SESIÓN","CERRAR PROGRAMA"};		// Para Recibir información sobre el funcionamiento 
	int posi = 2;														// de estas cuatro lineas

	ini = menu(titulo,mensaje,opciones,posi); //Retorno del valor de la seleccion de la función menu
	animation(); //animación

	switch (ini) // Switch ordinario de un menú, dirigirá al usuario a la función que quiera realizar
	{
		case 1: 
			system ("cls");
			iniciodesesion(listalibros, listausuarios, listaprestamos); // Lleva al inico de sesión
		break;
							
		case 2:	
			system ("cls");
			cierreF (); // Lleva al usuario al cierre del programa.
		break;
	}	
}

void iniciodesesion(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos)
{
	char charaux;					// Este variable extra ayudará al funcionamiento del programa
	string stringaux;				// Será un comparador de lo que ponga el usuario con lo registrado dentro del programa
	usuario *buscadordeusuarios = listausuarios; // La información requerida para el registro del usuario se resguarda dentro del Struct usuario, ergo, se le hace llama
	bool encontrado = false;		// Será aquella variable que le advertira al progrma si exite una coincidencia dentro del Struct Usuario
	
	int y, x;						// Estas dos variables son Cuestiones Visuales particulares de esta interfaz
	do
	{
		system ("cls"); 
		system ("Title ¡Estas Iniciando Sesión!"); // El titulo cambia
		buscadordeusuarios = listausuarios; // el buscador de usuarios se iguala continuamente en caso de un nuevo intento
		
		y = 6; x = 14;  // Cuestiones Visuales
		cuadro (1,0,78,4);
		gotoxy (26,2); cout << "...INICIANDO SESIÓN..."; // Cuestiones Visuales
		
		fflush(stdin); // El buffer es limpiado para prevenir errores de compilación
		gotoxy(x, y++);cout << "Ingrese nombre de usuario: "; getline(cin, stringaux);
		
		while (buscadordeusuarios != NULL) //Bucle buscador de usuarios cuya condición consiste en enviar los datos a evaluar de forma continua
		{
			if (buscadordeusuarios -> nombredeusuario == stringaux) //Esta linea verifica si existe una coincidencia entre el nombre de usuario propuesto y los almacenados
			{
				encontrado = true; // en caso de existir la coincidencia
				break;
			}
		
			buscadordeusuarios = buscadordeusuarios -> sig;
		}
	
		if (encontrado == false) //Si el usuario no es encontrado
		{
			y++; // Y se incrementa por Cuestion Visuales
			gotoxy(x, y++);cout << "Usuario no encontrado.";
			gotoxy(x, y++);cout << "Desea intentarlo de nuevo? (n=no , s=si): ";
			cin >> charaux; // Se lee el caracter indicará el reintento.
			
			if (charaux=='n') // Se Verifica el reintento, en caso de ser n (negativo) volverá al primer menú
				break;
		}
		
		else //Si sí es encontrado
		{
			if (buscadordeusuarios -> ban == true) //Check de ban
			{
				y++; // Y se incrementa por Cuestion Visuales
				gotoxy(x, y++);cout << "usuario bloqueado, acceso restringido.";
				break;
			}
			
			encontrado = false;
			fflush(stdin);
			gotoxy(x, y++);cout << "Ingrese contraseña: "; getline(cin, stringaux);
			
			if (buscadordeusuarios -> contrasenia == stringaux) //Esta linea verifica si existe una coincidencia entre la conttraseña propuesta y la correspondiente
			{
				encontrado = true;
			}

			if (encontrado == false) //Si la contraseña es incorrecta
			{
				y++; // Y se incrementa por Cuestion Visuales
				gotoxy(x, y++);cout << "Contraseña incorrecta.";
				gotoxy(x, y++);cout << "Desea intentarlo de nuevo? (n=no , s=si)";
				cin >> charaux; // Se lee el caracter indicará el reintento.
			
				if (charaux=='n') // Se Verifica el reintento, en caso de ser n (negativo) volverá al primer menú
					break;
			}
			
			else //Si encontrado permanece siendo true, significa que los datos introducidos son corrctos y que el programa puede proseguir
			{
				animation();
				if (buscadordeusuarios -> admin == true) //Verifica si el usuario tiene permisos de admnistrador
				{
					A_menu_principal (listalibros, listausuarios, listaprestamos); // Si los tiene irá al menú de administrador
				}
				
				else 
				{
					U_menu_principal (listalibros, listausuarios, listaprestamos); //Sino ira al menú de usuario 
				}
			}
		}
	} while (true);
}

void U_menu_principal (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) { //Menú de usuarios
	
	int eleccion;
	
	do{ 
	
	const char *titulo = "\t    MENÚ PRINCIPAL";										// Dirigase a la funcion:
	const char *mensaje = "Bienvenido, estimado usuario ¿en qué podemos servirle?";		// int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi)
	const char *opciones[] = {															// Para Recibir información sobre el funcionamiento
	"MOSTRAR LIBROS","VER LISTA DE LIBROS","BUSCAR LIBRO","CERRAR SESIÓN"};	
	int posi = 4;																		// de estas cuatro lineas
	
	eleccion = menu(titulo,mensaje,opciones,posi); //Retorno del valor de la seleccion de la función menu
	animation();
	
	switch (eleccion) // Switch ordinario de un menú, dirigirá al usuario a la función que quiera realizar
		{
			case 1: 
				system ("cls");
				mostrarlibros(listalibros); // Lleva al usuario a los detalles de cada libro
			break;
					
			case 2: 
				system ("cls");
				verlistadelibros (listalibros); // Lleva al usuario a la lista de libros
			break;
										
			case 3:	
				system ("cls");
				buscarlibro (listalibros); 	// Lleva al usuario al buscardor de libros
			break;
					
			case 4: 
				system ("cls");
				eleccion = false;
				I_sesion(listalibros, listausuarios, listaprestamos); // Lleva al usuario al inicio de sesión
			break;
		} 	
	} while (eleccion);
}

void A_menu_principal (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) { // Menú de Administradores ~~~
	
	int eleccion;
	
	do{
	const char *titulo = "\t    MENÚ PRINCIPAL"; 										// Dirigase a la funcion:
	const char *mensaje = "Bienvenido, administrador ¿que acción desea realizar?";		// int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi)
	const char *opciones[] = { 															// Para Recibir información sobre el funcionamiento
	"ADMINISTRACIÓN DE USUARIOS","ADMINISTRACIÓN DE LA BIBLIOTECA", "CERRAR SESIÓN"}; 
	int posi = 3;																		// de estas cuatro lineas
	
	eleccion = menu(titulo,mensaje,opciones,posi); //Retorno del valor de la seleccion de la función menu
	animation();
	
	switch (eleccion) // Switch ordinario de un menú, dirigirá al usuario a la función que quiera realizar
		{
			case 1: 
				system ("cls");
				A1_menu_principal(listalibros, listausuarios, listaprestamos); // Lleva al usuario al menú de administracion de usuarios
			break;
					
			case 2: 
				system ("cls");
				A2_menu_principal(listalibros, listausuarios, listaprestamos); // Lleva al usuario al menú de administracion de libros
			break;
										
			case 3:	 
				system ("cls");
				I_sesion (listalibros, listausuarios, listaprestamos); // Lleva al usuario inicio de sesión
			break; 
		} 	
	} while (eleccion);
}

void A1_menu_principal(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) { // Menú de Administración de Usuarios ~~~
	
	int eleccion;
	bool repetir = true;
	do
	{	
	const char *titulo = "\tADMINISTRACIÓN DE USUARIOS"; 							// Dirigase a la funcion:
	const char *mensaje = "Muy bien, administrador, estás en el menú de usuarios";  //int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi)
	const char *opciones[] = { 														// Para Recibir información sobre el funcionamiento
	"REGISTRAR USUARIO","MOSTRAR USUARIOS", "VER LISTA DE USUARIOS","ELIMINAR USUARIO","BUSCAR USUARIOS","DESBLOQUEAR USUARIOS","VOLVER"};
	int posi = 7;																	// de estas cuatro lineas
	
	eleccion = menu(titulo,mensaje,opciones,posi); //Retorno del valor de la seleccion de la función menu
	animation();
	
		switch (eleccion) // Switch ordinario de un menú, dirigirá al usuario a la función que quiera realizar
		{
			case 1: 
				system ("cls");
				registrarusuario(listausuarios); // Lleva la ventana de registro de usuarios
			break;
					
			case 2: 
				system ("cls");
				mostrarusuarios(listausuarios); // Lleva la ventana de muestrade usuarios
			break;
										
			case 3:	 
				system ("cls");
				verlistadeusuarios(listausuarios); // Lleva la ventana de la lista de usuarios
			break; 

			case 4:	 
				system ("cls");
				eliminarusuarios(listausuarios); // Lleva la ventana de iliminación de usuarios
			break; 

			
			case 5:	 
				system ("cls");
				buscarusuarios(listausuarios); // Lleva la ventana de buscador de usuarios
			break; 

			
			case 6:	 
				system ("cls");
				desbloquearusuario(listausuarios); // Lleva la ventana de desbloqueo de usuarios
			break; 

			
			case 7:
				system ("cls");
				repetir=false;  // Regresa al menún anterior
			 break;
		}
	} while(repetir);
}

void A2_menu_principal(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) { // Menú de Administración de la Biblioteca ~~~
	
	int eleccion;
	bool repetir = true;
	
	do
	{	
	const char *titulo = "\tADMINISTRACIÓN DE LIBROS";								// Dirigase a la funcion:
	const char *mensaje = "Muy bien, administrador, estás en el menú de libros";	//int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi)
	const char *opciones[] = {"INSERTAR LIBRO","MOSTRAR LIBRO", 					// Para Recibir información sobre el funcionamiento
	"ELIMINAR LIBRO","BUSCAR LIBRO","VER LISTA DE LIBROS","SISTEMA DE PRÉSTAMOS","SALIR"};
	int posi = 7;																	// de estas cuatro lineas
	
	eleccion = menu(titulo,mensaje,opciones,posi); //Retorno del valor de la seleccion de la función menu
	animation();
	
		switch (eleccion) // Switch ordinario de un menú, dirigirá al usuario a la función que quiera realizar
		{
			case 1: 
				system ("cls");
				insertarlibro (listalibros); // Lleva la ventana de insersión de libros
			break;
					
			case 2: 
				system ("cls");
				mostrarlibros(listalibros);	// Lleva la ventana de muestra de libros		
			break;
					
			case 3:	 
				system ("cls");
				eliminarlibro (listalibros); // Lleva la ventana de eliminación de libros
			break; 
			
			case 4:	 
				system ("cls");
				buscarlibro (listalibros); // Lleva la ventana del buscador de libros
			break; 

			case 5:	 
				system ("cls");
				verlistadelibros (listalibros); // Lleva la ventana de la lista de libros
			break; 

			case 6:	 
				system ("cls");
				A3_menu_principal (listalibros, listausuarios, listaprestamos); // Lleva al menú de prestramos
			break; 

			case 7:
				system ("cls");
				repetir=false; // Regresa al menú anterior.
			 break;
		}
	} while(repetir);
}

void A3_menu_principal(libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) { // Menú de Administración de Préstamos ~~~
	
	int eleccion;
	bool repetir = true;
	do
	{
	const char *titulo = "\tSISTEMAS DE PRÉSTRAMOS";									// Dirigase a la funcion:
	const char *mensaje = "Muy bien, administrador, estás en el menú de préstamos";	//int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi)
	const char *opciones[] = {"REGISTRAR PRÉSTAMO",									// Para Recibir información sobre el funcionamiento
	"REGISTRAR DEVOLUCIÓN","MOSTRAR PRÉSTAMOS","VER LISTA DE PRÉSTAMOS","ELIMINAR PRÉSTAMOS","VOLVER","SALIR"};
	int posi = 6;																	// de estas cuatro lineas
	
	eleccion = menu(titulo,mensaje,opciones,posi);
	animation();
	
		switch (eleccion) // Switch clasico de un menú
		{
			case 1: 
				system ("cls");
				registrarprestamo (listalibros, listausuarios, listaprestamos); // Lleva la ventana de registro de prestramos
			break;
			case 2: 
				system ("cls");
				registrardevolucion (listalibros, listausuarios, listaprestamos); // Lleva la ventana de registro de devolución
			break;
					
			case 3:	 
				system ("cls");
				mostrarprestamos (listaprestamos); // Lleva la ventana de muestra de prestramos
			break; 
			
			case 4:	 
				system ("cls");
				verlistadeprestamos (listaprestamos); // Lleva la ventana de lista de prestramos
			break; 

			case 5:	 
				system ("cls");
				eliminarprestamo (listaprestamos, listausuarios);// Lleva la ventana de eliminacion de prestramos
			break; 
			
			case 6:
				system ("cls");// Regresa al menú anterior
				return;
			break;
		}
	} while(repetir);
}

void registrarusuario (usuario *&listausuarios) // Método que permite registrar usuarios ~~~!
{
	usuario *nuevo_usuario = new usuario(); // La información requerida para el registro de libros se resguarda dentro del Struct libro, ergo, se le hace un llamado.
	
	// Variables Auxiliares que almacenan información como guardado provisonal ó para hacer comparaciones 
	string stringaux;
	long long int intaux;
	char sexo;
	char num[11];
	bool aux2;
	// Fin Variables Auxiliares
	int x, y; // Se declaran con fines Visuales
	
	nuevo_usuario -> ban = false; 					//Se declaran valores constantes de un nuevo usuario
	nuevo_usuario -> admin = false;					//Se declaran valores constantes de un nuevo usuario
	nuevo_usuario -> numerodelibrosprestados = 0;	//Se declaran valores constantes de un nuevo usuario
	
	
	do
	{
		system ("cls");
		// Cuestiones Visuales
		y = 6;
		x = 14;
		cuadro (1,0,78,4);
		gotoxy (25,2); cout << "...REGISTRANDO USUARIO..."; // ENCABEZADO CENTRADO
		// Fin Cuestiones Visuales
		
		aux2=true;
		fflush(stdin);															// Con ayuda de esta función, Se limpia el buffer para evitar errores de calculo
		gotoxy(x,y++);cout << "Nombre completo: "; getline(cin, stringaux);		// Se le solicita Informacion al usuario y se hace uso de la funcion "getline() para guardar detalladamente dicha información
		nuevo_usuario -> nombrecompleto = stringaux;							// Con ayuda de del puntero "nuevo usuario", la informacion recolectada se va al Struc Usuario 
	
		fflush(stdin); 															// Con ayuda de esta función, Se limpia el buffer para evitar errores de calculo
		gotoxy(x,y++);cout << "Nombre de usuario: "; getline(cin, stringaux);	// Se le solicita Informacion al usuario y se hace uso de la funcion "getline() para guardar detalladamente dicha información
		nuevo_usuario -> nombredeusuario = stringaux;							// Con ayuda de del puntero "nuevo usuario", la información recolectada se va al Struc Usuario
	
		fflush(stdin); 															// Con ayuda de esta función, Se limpia el buffer para evitar errores de calculo
		gotoxy(x,y++);cout << "Contraseña: "; getline(cin, stringaux); 			// Se le solicita Informacion al usuario y se hace uso de la funcion "getline() para guardar detalladamente dicha información
		nuevo_usuario -> contrasenia = stringaux; 								// Con ayuda de del puntero "nuevo usuario", la información recolectada se va al Struc Usuario
	
		gotoxy(x,y++);cout << "Documento de identidad: "; cin >> num;			// Se solicita al usuario el codigo de su documento de identificacón, para ser leido posteriormente
		
		for (int i=0;i<7;i++)					// Este pequeño bucle recorre todo el arreglo "num" 
		{										
			if (!isdigit(num[i])) 				// Este condicional evalua el contenido del arreglo. 
			{									// Consiste en que si con la ayuda de la función "isdigit()" es negada, significa que en alguna parte del codigo existe un caracter no numerico.
				aux2=false; 					// Si eso ocurre, como se puede apreciar en la linea anterior, el booleano "aux2" pasa a ser falso.
			}									
		}
		
		if (aux2==true)							// Esta condicional opera en función de la anteior, que está dentro del bucle for.
		{										// Si "aux2" prevalece siendo verdadera, el contenido del arreglo de caracteres "num" se convierten en caracteres numericos 
			intaux = atoll(num);				// y es refugiado en otra variable de tipo int para evitar errores.
		}										
		
		else									// De ser el caso en que el valor aux2 llegó siendo falso
		{
			gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo. [Contraseña]"; // Se le informa al usuario de la problematica
			system ("pause>null"); 
			continue;							// y la sentencia "continue" lo reenvia al inicio del llenado de información
		}
		nuevo_usuario -> documento = intaux;	// Una vez verificada la seguridad del dato, se resguarda en el Struct Usuario

		aux2=true; 								// Para evitar el mal funcionamiento del resto de la estructura, aux2 se iguala a verdadero
		gotoxy(x,y++);cout << "Edad: "; cin >> num;		// Se solicita al usuario la cifra de su edad, para ser guardada.	
		for (int i=0;i<2;i++)					// Este pequeño bucle recorre solo los dos primeros espacios del arreglo "num"
		{
			if (!isdigit(num[i])) 				// Este condicional evalua el contenido del arreglo. 
			{									// Consiste en que si con la ayuda de la función "isdigit()" es negada, significa que en alguna parte del codigo existe un caracter no numerico.
				aux2=false; 					// Si eso ocurre, como se puede apreciar en la linea anterior, el booleano "aux2" pasa a ser falso.
			}									
		}
		
		if (aux2==true)							// Esta condicional opera en función de la anteior, que está dentro del bucle for.
		{										// Si "aux2" prevalece siendo verdadera, el contenido del arreglo de caracteres "num" se convierten en caracteres numericos 
			intaux = atoll(num);				// y es refugiado en otra variable de tipo int para evitar errores.
		}										
		
		else									// De ser el caso en que el valor aux2 llegó siendo falso
		{
			gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo. [Edad]"; // Se le informa al usuario de la problematica
			system ("pause>null"); 
			continue;							// y la sentencia "continue" lo reenvia al inicio del llenado de información
		}
		nuevo_usuario -> edad = intaux; 		// Una vez verificada la seguridad del dato, se resguarda en el Struct Usuario
	
		gotoxy(x,y++);cout << "Sexo legal (m=Masculino/f=Femenino): "; cin >> sexo; // Se lee el sexo del usuario
		if (sexo != 'm' && sexo != 'f') 		//Se evalua para evitar errores.
		{
			gotoxy(x-5,y+2); cout << "Ingresó un caracter inválido, Inténtelo de nuevo.[Sexo]"; // Se le informa al usuario de la problematica
			system ("pause>null");
			continue;							// y la sentencia continue lo reenvia al inicio del llenado de información
		}
		nuevo_usuario -> sexo = sexo; 			// Una vez mas, es verificada la seguridad del dato, se resguarda en el Struct Usuario

		fflush(stdin);																			// Con ayuda de esta función, Se limpia el buffer para evitar errores de calculo
		gotoxy(x,y++);cout << "Dirección de correo electrónico: "; getline(cin, stringaux); 	//Se le solicita Informacion al usuario y se hace uso de la funcion "getline() para guardar detalladamente dicha información
		nuevo_usuario -> email = stringaux; 													// Con ayuda de del puntero "nuevo usuario", la información recolectada se va al Struc Usuario
	
		fflush(stdin);																			// Con ayuda de esta función, Se limpia el buffer para evitar errores de calculo
		gotoxy(x,y++);cout << "Dirección de vivienda: "; getline(cin, stringaux);				// Se le solicita Informacion al usuario y se hace uso de la funcion "getline() para guardar detalladamente dicha información
		nuevo_usuario -> direccion = stringaux;													// Con ayuda de del puntero "nuevo usuario", la información recolectada se va al Struc Usuario
		
		aux2=true; 								// Para evitar el mal funcionamiento del resto de la estructura, aux2 se iguala a verdadero
		gotoxy(x,y++);cout << "Teléfono (Recuerde poner 0 al inicio): "; cin >> num;
		for (int i=0;i<11;i++)					// Este pequeño bucle recorre solo los dos primeros espacios del arreglo "num"
		{
			if (!isdigit(num[i])) 				// Este condicional evalua el contenido del arreglo. 
			{									// Consiste en que si con la ayuda de la función "isdigit()" es negada, significa que en alguna parte del codigo existe un caracter no numerico.
				aux2=false; 					// Si eso ocurre, como se puede apreciar en la linea anterior, el booleano "aux2" pasa a ser falso.
			}									
		}
		
		if (aux2==true)							// Esta condicional opera en función de la anteior, que está dentro del bucle for.
		{										// Si "aux2" prevalece siendo verdadera, el contenido del arreglo de caracteres "num" se convierten en caracteres numericos 
			intaux = atoll(num);				// y es refugiado en otra variable de tipo int para evitar errores.
		}	
		
		else									// De ser el caso en que el valor aux2 llegó siendo falso
		{
			gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo. [Teléfono]";	// Se le informa al usuario de la problematica
			system ("pause>null"); 
			continue;							// y la sentencia "continue" lo reenvia al inicio del llenado de información
		}
		nuevo_usuario -> telefono = intaux; 	// y una vez mas verificada la seguridad del dato, se resguarda en el Struct Usuario
		break;
	} while (true); 
	//Este bucle do-while tiene como condición true(verdadero) es decir, el bucle se ejectará siempre y cuando el mismo bucle no sea interrumpido desde su interior
	//Notese el break justo en la linea anterior a la del condicional del bucle do-while
	
	usuario *aux = listausuarios; 	// Se define un puntero
	listausuarios = nuevo_usuario; 	// Se le otorga valor al puntero
	nuevo_usuario -> sig = aux;		// Se le ordena al computador "pasar pagina' y depositar los datos recolectados en nuevo espacio.
	gotoxy(x-5,y+2); cout << "EL USUARIO A SIDO REGISTRADO CORRECTAMENTE!!"; //Informe de estado.

	system ("pause>null");
}

void mostrarusuarios (usuario *&listausuarios) // Método que permite mostrar los datos de los usuarios! ~~~
{
	usuario *mostrar = listausuarios; // Es necesario información de la lsita Usuario para esta Tarea, por esa razón, se le hace referncia con un puntero.
	int contador=1;					  // Ayuda a preservar el orden logico dentro de esta opción, es inicializada en uno puesto que la biblioteca necesita almenos un usuario.				
	
	int y, x; // Se declara con fines Visuales
	while(mostrar != NULL) // Este bucle consiste en que funcionara hasta que mostrar pase a ser NULL (vacio), ergo, no hay mas usuarios que mnstrar
	{
		system ("cls");
		y = 9;
		x = 16;
		cuadro (1,0,78,4); gotoxy (27,2); cout << "LIBRETA DE USUARIOS";
	
		// El compilador accede al Struct Usuario y muestra en pantalla todos los datos sobre cada usuario. 
		gotoxy(29,6);cout << "USUARIO " << contador; // Se añade la variable contador para enumerar a los usuarios.
		gotoxy(20,7);cout << "-------------------------------" ;
		gotoxy(x,y++);cout << "Nombre completo: " << mostrar -> nombrecompleto ;
		gotoxy(x,y++);cout << "Nombre de usuario: " << mostrar -> nombredeusuario ;
		gotoxy(x,y++);cout << "Documento de identificación: " << mostrar -> documento ;
		gotoxy(x,y++);cout << "Edad: " << mostrar -> edad ;
		gotoxy(x,y++);cout << "Sexo: " << mostrar -> sexo ;
		gotoxy(x,y++);cout << "Dirección de correo electrónico: " << mostrar -> email ;
		gotoxy(x,y++);cout << "Teléfono: " << mostrar -> telefono ;
		gotoxy(x,y++);cout << "Dirección de vivienda: " << mostrar -> direccion ;
		gotoxy(x,y++);cout << "Numero de libros prestados: " << mostrar -> numerodelibrosprestados ;
		// Todo estas lineas son mapeadas con ayuda de la Función Gotoxy para otorgar mayor comodidad visual.
		
		//Una pequeña comprobación lógica para indicar que tipo de usuario debe mostrarse
		if (mostrar -> admin == true){ gotoxy(x,y++);cout << "Usuario administrador";}	
		else {gotoxy(x,y++);cout << "Usuario general";}
		
		// Una pequeña comprobación lógica para indicar el estado de accesos que debe mostrarse
		if (mostrar -> ban == true) {gotoxy(x,y++);cout << "Usuario vetado";}		
		else{gotoxy(x,y++);cout << "Usuario autorizado";}
		
		contador++; // Contador incrementa cada que un usuario es mostrado.
		mostrar = mostrar -> sig; // Mediante a "mostrar" hace accede a la siguiente locacion de memoria en la lista Usuario 
		gotoxy(x-5,y+2);cout << "Presione cualquier tecla para continuar...";
		system ("pause>null");
	} 
	gotoxy(x-5,y+3);cout << "No hay más usuarios registrados.";
	system ("pause>null");
}

void verlistadeusuarios (usuario *&listausuarios) // Método permite ver la lista general de usuarios!
{
	int contador=1; // Fines de orden
	usuario *mostrar = listausuarios; // La informacion necesaria viene de Struct Usuario
	int x = 8; // Se declaran con fines esteticos
	int y = 8; // Se declaran con fines esteticos
	int pag=6;
	while (mostrar != NULL)
	{
	
		cuadro (1,0,78,4); gotoxy (27,2); cout << "LISTA DE USUARIOS"; //Fines esteticos
	
		gotoxy(x,y++);cout << contador << ") Nombre completo: " << mostrar -> nombrecompleto; //Esta linea sitúa,enumera, y muestra el nombre completo del usuario
		gotoxy(x,y++);cout << "Documento de identificación: " << mostrar -> documento; //Esta linea sitúa,enumera, y muestra el documento del usuario
		y++; // Se incrementa para que el gotoxy marque un breve salto de linea. 
		
		mostrar = mostrar -> sig; // Mediante a "mostrar" hace accede a la siguiente locacion de memoria en la lista Usuario 
		contador++; // Contador incrementa cada que un usuario es mostrado.
		if (contador==pag) // Si contador es igual, significa que hay mas usuarios de los posibles de mostrar en pantalla.
		{
			gotoxy (x, y++);cout << "Pulse una tecla para continuar...";
			y=8; x=8; // Fines Visuales
			system ("pause>null");
			pag += 6; // Se incrementa la capacidad del mostrador.
			system ("cls");
		}
	}
	system ("pause>null");
}

void eliminarusuarios (usuario *&listausuarios)  // Método que permite ELIMINAR usuarios!
{	
	usuario *eliminar = listausuarios;	// La informacion necesaria viene de Struct Usuario
	usuario *anteliminar = NULL;		// Dos variable que ayudarán 
	int eliminando;						// a la hora de borrar al usuario	
	char documento[8];					// Una variable que guardará el documento del usuario para identificarlo
	bool encontrado = false, aux2=true; // Booleanos que serviran de herramientas para manejar las condicionales.

	do
	{
		aux2=true; // Se reinicia continuamente para mantener el orden
		system ("cls");
		
		cuadro (1,0,78,4); gotoxy (27,2); cout << "ELIMINAR UN USUARIO"; //Fines Visuales
		gotoxy(9,10);cout << "Ingrese documento de identificación del usuario a eliminar: "; cin >> documento;
		
		for (int i=0;i<7;i++) // Este pequeño bucle recorre todo el arreglo "documento" 
		{
			if (!isdigit(documento[i])) 		// Este condicional evalua el contenido del arreglo. 
			{									// Consiste en que si con la ayuda de la función "isdigit()" es negada, significa que en alguna parte del codigo existe un caracter no numerico.
				aux2=false; 					// Si eso ocurre, como se puede apreciar en la linea anterior, el booleano "aux2" pasa a ser falso.
			}									
		}
		
		if (aux2==true)							// Esta condicional opera en función de la anteior, que está dentro del bucle for.
		{										// Si "aux2" prevalece siendo verdadera, el contenido del arreglo de caracteres "documento" se convierten en caracteres numericos 
			eliminando = atoi(documento);		// y es refugiado en otra variable de tipo int para evitar errores.
		}		
		
		else
		{
			gotoxy(9,11); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo."; // Se le informa al usuario de la problematica
			system ("pause>null");
			continue; // y la sentencia "continue" lo reenvia al inicio del llenado de información
		}
		break;
	} while (true);
	
	animation();
		
	while (eliminar != NULL) // Mientras "eliminar" (que es nuestro puntero hacia a la lista Usuario) sea distinto a vacio
	{
		if (anteliminar == NULL && listausuarios -> documento == eliminando)
		{	//Mientras la coincidencia se encuentre en el primer nodo de la lista
			encontrado = true;
			listausuarios = listausuarios -> sig;	// Se inicializa la lista en el siguiente a lista
			delete eliminar;						// y con ayudas de la función "delete", se elimina la coincidencia
			break;									// Saca al ordenador de todos los bucles
		}
		
		else if (eliminar -> documento == eliminando && anteliminar != NULL)
		{	//Cuando se encuentra una coincidencia en un nodo que no sea el primero
			encontrado = true;
			anteliminar -> sig = eliminar -> sig; //Al nodo anterior al que se va a eliminar se le asigna de siguiente el siguiente del siguiente XDDDDD
			delete eliminar; //Se elimina la coincidencia
			break;
		}
		
		anteliminar = eliminar;
		eliminar = eliminar -> sig;
	}
	
	if (encontrado == false) {gotoxy(14,12);cout << "Usuario no encontrado.";} // en caso de que no haya podido encontrar al usuario, se informa la problematica
	
	else {gotoxy(14,12);cout << "Usuario eliminado satisfactoriamente.";} // En cambio, si pudo encontrarlo, significa que el usuario ya se ha eliminado
	
	system ("pause>null");
}

void buscarusuarios (usuario *&listausuarios) 
{
	int x = 9; // fines visuales
	int y = 12; // fines visuales
	usuario *buscar = listausuarios; // La informacion necesaria viene de la lista Usuario
	
	//Variables auxiliares
	char documento[8];
	int buscador;
	bool buscando = false, aux2=true;
	//Fin de variables auxiliares
	
	do
	{
		aux2=true;
		system("cls");
		cuadro (1,0,78,4); gotoxy (27,2); cout << "BUSCAR UN USUARIO"; //Estética
		gotoxy(6,6);cout << "Ingrese el documento de identidad del usuario que desea buscar: ";cin >> documento;
		for (int i=0;i<7;i++) //El bucle recorre todo el arreglo documento 
		{
			if (!isdigit(documento[i])) //Ingresa si se detecta algún caracter no dígito
			{
				aux2=false;
			}
		}
		
		if (aux2==true) //Si no encuentra caracteres alfabéticos o simbólicos
		{
			buscador = atoi(documento); //Se almacena el arreglo en una variable entero.
		}
		
		else //Si encuentra caracteres de tipo dígito
		{
			gotoxy(6,7); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo."; //Se notifica del problema
			system ("pause>null");
			continue; //Se repite el bucle 
		}
		break; //Se cierra el bucle
	} while (true);
	
	while (buscar!=NULL) //Se recorre toda la lista de usuarios
	{
		if (buscar -> documento == buscador) //Si se encuentra una coincidencia
		{
			buscando = true; //Se expresa en un booleano
			break;
		}
		
		else
			buscar = buscar -> sig; //Si no se encuentra coincidencia se sigue el recorrido de la lista
	}
	
	if (buscando == true) //Si encuentra coincidencia, muestra todos los datos en pantalla
	{
		gotoxy(x,10);cout << "USUARIO ENCONTRADO"  ;
		gotoxy(x,11);cout << "-------------------------------"  ;
		gotoxy(x,y++);cout << "Nombre completo: " << buscar -> nombrecompleto  ;
		gotoxy(x,y++);cout << "Nombre de usuario: " << buscar -> nombredeusuario  ;
		gotoxy(x,y++);cout << "Documento de identificación: " << buscar -> documento  ;
		gotoxy(x,y++);cout << "Edad: " << buscar -> edad  ;
		gotoxy(x,y++);cout << "Sexo: ";
		switch (buscar -> sexo)
		{
			case 'm':
				cout << "Masculino"; break;
				
			case 'f':
				cout << "Femenino"; break;
			
			default: cout << ""; break;
		}
		gotoxy(x,y++);cout << "Dirección de correo electrónico: " << buscar -> email  ;
		gotoxy(x,y++);cout << "Teléfono: 0" << buscar -> telefono  ;
		gotoxy(x,y++);cout << "Dirección de residencia: " << buscar -> direccion  ;
		gotoxy(x,y++);cout << "Número de libros prestados: " << buscar -> numerodelibrosprestados;
	}
		
	else
	{
		gotoxy(10,14);cout << "Usuario no encontrado "; //Si el booleado encontrado no es verdadero se expresa.
	}
	
	system ("pause>null");
}

void desbloquearusuario (usuario *&listausuarios) //Método que permite el desbloqueo de un usuario
{
	int x, y; //Estéticas de menú
	
	usuario *buscar = listausuarios; //Nodo buscador de la lista usuario
	bool encontrado = false, aux2=true; //Booleanos auxiliares
	int buscador; 
	char documento[8];
	
	do
	{
		aux2=true;
		system("cls");
		cuadro (1,0,78,4); gotoxy (27,2); cout << "DESBLOQUEAR UN USUARIO";
		gotoxy(6,10);cout << "Ingrese el documento de identidad del usuario que desea buscar: "; cin >> documento;
		for (int i=0;i<7;i++) //Bucle que recorre el arreglo documento
		{
			if (!isdigit(documento[i])) //En busca de algpun caracter que no sea de tipo dígito
			{
				aux2=false;
			}
		}
		
		if (aux2==true) //Si nolo encuentra, se reescribe ese arreglo en una variable entero.
		{
			buscador = atoi(documento);
		}
		
		else //Si encuentra un caracter alfabético
		{
			gotoxy(6,11); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		break;
	} while (true);
	
	while (buscar != NULL) //Al salir del bucle, el nodo buscador recorre la lista de usuarios en busca de coincidencias con el número de documento.
	{
		if (buscar -> documento == buscador)
		{
			encontrado = true;
			break;
		}
		
		buscar = buscar -> sig;
	}

	animation();

	if (encontrado == true && buscar -> ban == true) //Si lo encuentra y está vetado, lo desbloquea
	{
		buscar -> ban = false;
		gotoxy(14,12);cout << "Usuario desbloqueado.";
	}

	else if (encontrado == true && buscar -> ban == false) //Si lo encuentra y no está vetado
	{
		gotoxy(14,12);cout << "Usuario no bloqueado.";
	}

	else //Si no encuentra al usuario en la lista
	{
		gotoxy(14,12);cout << "Usuario no encontrado.";
	}
	
	system("pause>null");
}

void insertarlibro (libro *&listalibros) //Método que permite el registro de un nodo en la lista de libros
{
	libro *nuevo_libro = new libro(); //Primero se crea un nuevo nodo
	string stringaux;				//Se declaran las variables necesarias:
	char arrayaux[4];
	bool aux2=true;
	int intaux, y, x;
	
	do
	{
		aux2=true;
		system ("cls");
		y = 6;
		x = 14;
		cuadro (1,0,78,4); gotoxy (30,2); cout << "\t\t...REGISTRANDO LIBRO..."; //Encabezado del menú
	
		//Se ingresan y leen todos los datos del nuevo libro a regustrar en la biblioteca
		fflush(stdin);
		gotoxy(x,y++);cout << "Nombre: "; getline(cin, stringaux);
		nuevo_libro -> nombre = stringaux; 
	
		fflush(stdin);
		gotoxy(x,y++);cout << "Autor: "; getline(cin, stringaux);
		nuevo_libro -> autor = stringaux;
	
		fflush(stdin);
		gotoxy(x,y++);cout << "Editorial: "; getline(cin, stringaux);
		nuevo_libro -> editorial = stringaux;
	
		gotoxy(x,y++);cout << "Edición número: "; cin >> arrayaux;
		for (int i=0;i<1;i++)
		{
			if (!isdigit(arrayaux[i])) //Verificacion de entrada para evitar caracteres alfabéticos
			{
				aux2=false;
			}
		}
		
		if (aux2==true)
		{
			intaux = atoi(arrayaux);
		}
		
		else
		{
			gotoxy(x,y++); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}		
		
		if (intaux<=0)
		{
			gotoxy(x,y++);cout << "No puede ser la edición 0. Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		nuevo_libro -> edicion = intaux;
	
		gotoxy(x,y++);cout << "Número de páginas: "; cin >> arrayaux;
		for (int i=0;i<2;i++)
		{
			if (!isdigit(arrayaux[i])) //Verificacion de entrada para evitar caracteres alfabéticos
			{
				aux2=false;
			}
		}
		
		if (aux2==true)
		{
			intaux = atoi(arrayaux);
		}
		
		else
		{
			gotoxy(x,y++); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		
		if (intaux<=0)
		{
			gotoxy(x,y++);cout << "No puede tener 0 páginas. Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		nuevo_libro -> npag = intaux;
	
		fflush(stdin);
		gotoxy(x,y++);cout << "Género del libro: "; getline(cin, stringaux);
		nuevo_libro -> genero = stringaux;
	
		gotoxy(x,y++);cout << "Año de publicación: "; cin >> arrayaux;
		for (int i=0;i<4;i++)
		{
			if (!isdigit(arrayaux[i])) //Verificacion de entrada para evitar caracteres alfabéticos
			{
				aux2=false;
			}
		}
		
		if (aux2==true)
		{
			intaux = atoi(arrayaux);
		}
		
		else
		{
			gotoxy(x,y++); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		nuevo_libro -> aniodepublicacion = intaux;

		gotoxy(x,y++);cout << "Estado físico del libro (0 al 9. (mayor es peor)): "; cin >> arrayaux;
		for (int i=0;i<1;i++)
		{
			if (!isdigit(arrayaux[i])) //Verificacion de entrada para evitar caracteres alfabéticos
			{
				aux2=false;
			}
		}
		
		if (aux2==true)
		{
			intaux = atoi(arrayaux);
		}
		
		else
		{
			gotoxy(x,y++); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		
		if (intaux < 0 || intaux > 9)
		{
			gotoxy(x,y++); cout << "Estado físico erróneo, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		nuevo_libro -> estadolibro = intaux;
	
		fflush(stdin);
		gotoxy(x,y++);cout << "Código ISBN del libro: "; getline(cin, stringaux);
		nuevo_libro -> codigoISBN = stringaux;
	
		fflush(stdin);
		gotoxy(x,y++);cout << "Código de estantería donde se encuentra el ejemplar: "; getline(cin, stringaux);
		nuevo_libro -> estanteria = stringaux;
	
		gotoxy(x,y++);cout << "Fila de la estantería donde se encuentra el ejemplar: "; cin >> arrayaux;
		for (int i=0;i<1;i++)
		{
			if (!isdigit(arrayaux[i])) //Verificacion de entrada para evitar caracteres alfabéticos
			{
				aux2=false;
			}
		}
		
		if (aux2==true)
		{
			intaux = atoi(arrayaux);
		}
		
		else
		{
			gotoxy(x,y++); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		
		if (intaux<=0)
		{
			gotoxy(x,y++);cout << "No puede ser fila 0. Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		nuevo_libro -> fila = intaux;
	
		gotoxy(x,y++);cout << "Numero de copias del libro en existencia: "; cin >> arrayaux;
		for (int i=0;i<1;i++)
		{
			if (!isdigit(arrayaux[i])) //Verificacion de entrada para evitar caracteres alfabéticos
			{ 
				aux2=false;
			}
		}
		
		if (aux2==true)
		{
			intaux = atoi(arrayaux);
		}
		
		else
		{
			gotoxy(x,y++); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		
		if (intaux<=0)
		{
			gotoxy(x,y++);cout << "No pueden registrarse 0 copias. Inténtelo de nuevo.";
			system ("pause>null");
			continue;
		}
		nuevo_libro -> existencia = intaux;
		//Fin de ingreso de datos del libro
		
		break;
	} while (true);
	
	gotoxy(x-5,y+2); cout << "¡¡EL LIBRO A SIDO REGISTRADO CORRECTAMENTE!!";	
	
	//proceso de inserción del nodo creado en la lista:
	libro *aux = listalibros;
	listalibros = nuevo_libro;
	nuevo_libro -> sig = aux;
	
	system ("pause>null");
}

void mostrarlibros (libro *&listalibros) //Proceso que imprime uno por uno los datos de los nodos en la lista libros
{
	libro *mostrar = listalibros; //Se inicializa el nodo que recorrerá toda la lista.
	int contador=1, x, y;
	
	while (mostrar != NULL) //Se recorre la lista hasta el final
	{
		system ("cls");
		y = 9;
		x = 15;
		cuadro (1,0,78,4); gotoxy (30,2); cout << "MOSTRAR LIBROS"; //Encabezado
		
		//Se muestran los libros:
		gotoxy(29,6);cout << "LIBRO " << contador ;
		gotoxy(20,7);cout << "-------------------------------";
		gotoxy(x,y++);cout << "Título: " << mostrar -> nombre;
		gotoxy(x,y++);cout << "Autor: " << mostrar -> autor;
		gotoxy(x,y++);cout << "Editorial: " << mostrar -> editorial;
		gotoxy(x,y++);cout << "Edición: " << mostrar -> edicion;
		gotoxy(x,y++);cout << "Número de páginas: " << mostrar -> npag;
		gotoxy(x,y++);cout << "Género literario: " << mostrar -> genero;
		gotoxy(x,y++);cout << "Año de publicación: " << mostrar -> aniodepublicacion;
		gotoxy(x,y++);cout << "Código ISBN: " << mostrar -> codigoISBN;
		
		gotoxy(x,y++);cout << "Estado físico de las copias: ";
		switch (mostrar -> estadolibro)
		{
			case 0:
				cout << "Excelente.";
				break;
				
			case 1:
				cout << "Casi excelente.";
				break;
				
			case 2:
				cout << "Muy bueno.";
				break;
				
			case 3:
				cout << "Bueno.";
				break;
				
			case 4:
				cout << "No tan bueno.";
				break;
				
			case 5:
				cout << "Intermedio.";
				break;
				
			case 6:
				cout << "No tan horrible.";
				break;
				
			case 7:
				cout << "Horrible.";
				break;
				
			case 8:
				cout << "Muy horrible.";
				break;
				
			case 9:
				cout << "Deplorable.";
				break;
				
			default:
				cout << "Desconocido.";
				break;
		}
		
		cout  ;
		gotoxy(x,y++);cout << "Código de estantería: " << mostrar -> estanteria;
		gotoxy(x,y++);cout << "Fila de la estantería: " << mostrar -> fila;
		gotoxy(x,y++);cout << "Numero de copias disponibles: " << mostrar -> existencia;
		//Fin de muestra de libros
		
		contador++; 
		gotoxy(x-5,y+2);cout << "Presione cualquier tecla para continuar...";
		
		system ("pause>null");
		mostrar = mostrar -> sig; //Se señala al siguiente nodo de la lista
	}
	gotoxy(x-5,y+3);cout << "No hay más libros registrados."; //Al llegar al final de la lista
	system ("pause>null");
}

void eliminarlibro (libro *&listalibros) //método que permite la eliminación de un libro
{
	libro *eliminar = listalibros; //Nodo que recorrerá la lista de libros en busca de coincidencias
	libro *anteliminar = NULL; //Nodo que precederá al que será eliminado
	//Variables auxiliares
	string eliminando;
	int estadoeliminando;
	bool encontrado = false;
	char aux;
	
	do
	{
		system("cls");
		cuadro (1,0,78,4); gotoxy (30,2); cout << "ELIMINAR UN LIBRO"; //Encabezado
		fflush(stdin);
		gotoxy(9,10);cout << "Ingrese código ISBN del libro a eliminar: "; getline(cin, eliminando);
		gotoxy(9,12);cout << "Ingrese estado fìsico del libro a eliminar: "; cin >> aux;
		if (!isdigit(aux)) //Verificación de entrada para evitar caracteres alfabéticos
		{
			gotoxy(9,13);cout << "Ingresó una letra inválida. Inténtelo de nuevo.";
			system("pause>null");
			continue;
		}
	
		else
		{
			estadoeliminando = atoi(&aux);
			break;
		}
	} while (true);
	
	while (eliminar != NULL) //Bucle que recorrerá la lista de libros en busca de coincidencias
	{
		if (anteliminar == NULL && listalibros -> codigoISBN == eliminando && listalibros -> estadolibro == estadoeliminando) //Si encuentra coincidencia al principio de la lista
		{
			encontrado = true;
			
			if (eliminar -> existencia <= 1) //Si esa coincidencia tiene 1 o menos en existencia
			{
				listalibros = listalibros -> sig;
				delete eliminar;
				break;
			}
			
			else
			{
				eliminar -> existencia = eliminar -> existencia-1; //Si esa coincidencia tiene más de 1 en existencia
				break;
			}
		}
		
		else if (anteliminar != NULL && eliminar -> codigoISBN == eliminando && eliminar -> estadolibro == estadoeliminando) //Si encuentra coincidencia en algún nodo diferente al primero
		{
			encontrado = true;

			if (eliminar -> existencia <= 1) //Si tiene 1 o menos en existencia
			{
				anteliminar -> sig = eliminar -> sig;
				delete eliminar;
				break;
			}
			
			else
			{
				eliminar -> existencia = eliminar -> existencia-1; //Si tiene más de 1 en existencia
				break;
			}
		}
		
		else
		{
			anteliminar = eliminar;
			eliminar = eliminar -> sig;
		}
	}
	
	animation();
	
	if (encontrado == false){
		gotoxy(14,14);cout << "Código no encontrado.";
	}
		
	else {
		gotoxy(14,14);cout << "Libro eliminado satisfactoriamente.";
	}
		
	system ("pause>null");
}

void buscarlibro (libro *&listalibros) //Método que permite buscar un libro en la lista
{
	libro *buscar = listalibros; //Nodo buscador de tipo libro
	//Variables auxiliares
	string buscador;
	bool buscando = false;
	char auxopc;
	
	int y = 13;
	int x = 18;
	cuadro (1,0,78,4); gotoxy (30,2); cout << "BUSCAR UN LIBRO"; //Encabezado
	
	gotoxy(9,6);cout << "Desea buscar por título o por código ISBN? (c=isbn, t=título): "; cin >> auxopc; 
		
	switch (auxopc) //Switch de modo de búsqueda
	{
		case 't': //Si el usuario desea buscar por título
			fflush (stdin);
			gotoxy(9,8);cout << "Ingrese el título de lo que desea buscar: "; getline(cin, buscador);
			while (buscar!=NULL) //Bucle que recorrerá la lista
			{
				if (buscar -> nombre == buscador) //Si encuentra coincidencias
				{
					buscando = true;
					break;
				}
				
				else
					buscar = buscar -> sig;
			}
			break;
		
		case 'c': //Si el usuario desea buscar por código ISBN
			fflush (stdin);
			gotoxy(9,8);cout << "Ingrese el código isbn de lo que desea buscar: "; getline(cin, buscador);
			while (buscar!=NULL) //Bucle que recorrerá la lista
			{
				if (buscar -> codigoISBN == buscador)  //Si encuentra coincidencias
				{
					buscando = true;
					break;
				}
			
				else
					buscar = buscar -> sig;
			}	
			break;
		
		default: //Si el usuario ingresa un caracter inválido
			gotoxy(9,9);cout << "Opción inválida.";
			system ("pause>null");
			return;
			break;
	}
	
	if (buscando == true) //Si encuentra coincidencia en la lista
	{
		if (buscar -> existencia != 0){
			gotoxy(9,10);cout << "Sí está en existencia el libro " << buscador; //Si el libro tiene copias no prestadas
		}
		else{
			gotoxy(9,10);cout << "No está en existencia el libro " << buscador; //Si el libro tiene todas las copias prestadas
		} 
			
		//Se imprimen los datos del libro
		gotoxy(x,y++);cout << "LIBRO ENCONTRADO" ;
		gotoxy(x,y++);cout << "-------------------------------" ;
		gotoxy(x,y++);cout << "Título: " << buscar -> nombre ;
		gotoxy(x,y++);cout << "Autor: " << buscar -> autor ;
		gotoxy(x,y++);cout << "Editorial: " << buscar -> editorial ;
		gotoxy(x,y++);cout << "Edición: " << buscar -> edicion ;
		gotoxy(x,y++);cout << "Número de páginas: " << buscar -> npag ;
		gotoxy(x,y++);cout << "Género literario: " << buscar -> genero ;
		gotoxy(x,y++);cout << "Año de publicación: " << buscar -> aniodepublicacion ;
		gotoxy(x,y++);cout << "Código ISBN: " << buscar -> codigoISBN ;
		gotoxy(x,y++);cout << "Código de estantería: " << buscar -> estanteria ;
		gotoxy(x,y++);cout << "Fila de la estantería: " << buscar -> fila ;
		
	}
		
	else{ //Si no encuentra el libro en la lista
		gotoxy(9,16);cout << "No está registrado el libro en la biblioteca.";
	}
	
	system ("pause>null");
}

void verlistadelibros (libro *&listalibros) //Método que permite la vizualización de la lista de libros
{
	int contador=1, pag=15;
	libro *mostrar = listalibros; //nodo que recorrerá la lista
	
	int x = 8;
	int y = 8;
	while (mostrar != NULL) //Bucle que mostrará los datos en la lista
	{
		cuadro (1,0,78,4); gotoxy (30,2); cout << "LISTA DE LIBROS"; //Encabezado
		gotoxy(x,y++);cout << contador << ") " << mostrar -> nombre ; //Mostrará el título del libro
		mostrar = mostrar -> sig;
		contador++;
		if (contador == pag) //Si excede el límite por pantalla se limpia y se imprime otra página
		{
			gotoxy (x, y++);cout << "Pulse una tecla para continuar...";
			system ("pause>null");
			x = 8;
			y = 8;
			pag += 15;
			system ("cls");
		}
	}
	system ("pause>null");
}

void registrarprestamo (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) //Método que permite el registro de un préstamo
{
	//Variables necesarias
	string stringaux;
	char charaux;
	int intaux, x, y;
	int libroaprestar;
	int anio;
	char num, documento[8];
	
	do //Bucle para evitar ingreso de caracteres inválidos
	{
		libro *buscarlibro = listalibros; //nodo buscador de la lista de libros
		usuario *buscarusuario = listausuarios; //nodo buscador de la lista de usuarios
		
		//Booleanos auxiliares
		bool buscandolibro = false;
		bool buscandousuario = false;
		bool aux2=true;
		//Booleanos auxiliares
		
		system ("cls");
		y = 6;
		x = 10;
		cuadro (1,0,78,4); gotoxy (28,2); cout << "\t\t...REGISTRANDO PRÉSTAMO..."; //Encabezado
		fflush(stdin);
		gotoxy(x,y++);cout << "Ingrese el código ISBN del libro a tomar prestado: "; getline(cin, stringaux);
		gotoxy(x,y++);cout << "Ingrese estado físico del libro a tomar prestado: "; cin >> num;
		if (!isdigit(num)) //Verificación de entrada para evitar ingreso de caracteres alfabéticos
		{
			gotoxy(x,y++);cout << "Ingresó una letra invalida. Intentelo de nuevo.";
			system("pause>null");
			continue;
		}
	
		else
		{
			intaux = atoi(&num);
		}
		
		while (buscarlibro!=NULL) //Bucle que recorrerá la lista de libros
		{
			if (buscarlibro -> codigoISBN == stringaux && buscarlibro -> estadolibro == intaux) //Si encuentra el libro en cuestión
			{
				buscandolibro = true;
				break;
			}
				
			else //Sino, sigue recorriendo la lista
				buscarlibro = buscarlibro -> sig;
		}	
		
		if (buscarlibro != NULL && buscarlibro -> existencia == 0) //Si encuentra el libro en existencia 0 no se puede prestar y retorna
		{
			gotoxy(x,y++);cout << "Libro no disponible.";
			system ("pause>null");
			return;
		}
		
		if (buscandolibro == false) //Si no encuentra el libro
		{
			gotoxy(x,y++);cout << "Libro no encontrado, desea intentarlo de nuevo? (s/n): ";
			cin >> charaux;
			
			if (charaux == 'n')
				return;
		}
		
		else //Si encuentra el libro
		{
			gotoxy(x,y++);cout << "Ingrese el documento de identidad del prestatario "; cin >> documento;
			for (int i=0;i<7;i++)
			{
				if (!isdigit(documento[i])) //Verificacion de entrada de caracter por caracter para evitar caracteres alfabéticos
				{
					aux2=false;
				}
			}
		
			if (aux2==true)
			{
				intaux = atoi(documento);
			}
		
			else
			{
				gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
				system ("pause>null");
				continue;
			}
						
			while (buscarusuario!=NULL) //Bucle que recorrerá la lista de usuarios
			{
				if (buscarusuario -> documento == intaux) //Si encuentra coincidencia
				{
					buscandousuario = true;
					break;
				}
					
				else //sino, sigue recorriendo
					buscarusuario = buscarusuario -> sig;
			}	
			
			if (buscandousuario == false) //Si no encuentra el usuario
			{
				gotoxy(x,y++);cout << "Usuario no encontrado, desea intentarlo de nuevo? (s/n): ";
				cin >> charaux;
			
				if (charaux == 'n')
					return;
			}
			
			else //Si encuentra el usuario
			{
				if (buscarusuario -> ban == true) //Si el usuario está bloqueadom se imposibilita el préstamo
				{
					gotoxy(x,y+2);cout << "Usuario bloqueado, no se puede tramitar el préstamo.";
					system ("pause>null");
					return;
				}
				
				prestamo *nuevo_prestamo = new prestamo(); //Se crea el nuevo nodo y se empieza a rellenar:
				nuevo_prestamo -> libroprestado = buscarlibro -> nombre;
				nuevo_prestamo -> codigoISBNprestado = buscarlibro -> codigoISBN;
				nuevo_prestamo -> nombredelposeedor = buscarusuario -> nombrecompleto;
				nuevo_prestamo -> ceduladelposeedor = buscarusuario -> documento; 
				
				gotoxy(x,y++);cout << "Ingrese año de préstamo: "; cin >> documento;
				aux2=true;
				for (int i=0;i<4;i++)
				{
					if (!isdigit(documento[i])) //Verificación de entrada para evitar ingreso de caracteres alfabéticos
					{
						aux2=false;
					}
				}
		
				if (aux2==true)
				{
					anio = atoi(documento);
					if (anio < 2023)
					{
						gotoxy(x,y++);cout << "Año Inválido, inténtelo de nuevo.";
						system ("pause>null");
						delete nuevo_prestamo;
						continue;
					}
				}
		
				else
				{
					gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
					system ("pause>null");
					delete nuevo_prestamo;
					continue;
				}
				nuevo_prestamo -> aniodeprestamo = anio;
				
				gotoxy(x,y++);cout << "Ingrese mes de préstamo: "; cin >> documento;
				aux2=true;
				for (int i=0;i<1;i++)
				{
					if (!isdigit(documento[i]))//Verificación de entrada para evitar ingreso de caracteres alfabéticos
					{
						aux2=false;
					}
				}
		
				if (aux2==true)
				{
					intaux = atoi(documento);
				}
		
				else
				{
					gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
					system ("pause>null");
					delete nuevo_prestamo;
					continue;
				}
				nuevo_prestamo -> mesdeprestamo = intaux;
				
				gotoxy(x,y++);cout << "Ingrese fecha de préstamo: "; cin >> documento;
				aux2=true;
				for (int i=0;i<1;i++)
				{
					if (!isdigit(documento[i]))//Verificación de entrada para evitar ingreso de caracteres alfabéticos
					{
						aux2=false;
					}
				}
		
				if (aux2==true)
				{
					intaux = atoi(documento);
				}
		
				else
				{
					gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
					system ("pause>null");
					delete nuevo_prestamo;
					continue;
				}
				nuevo_prestamo -> fechadeprestamo = intaux;
				
				gotoxy(x,y++);cout << "Ingrese año límite de devolución: "; cin >> documento;
				aux2=true;
				for (int i=0;i<4;i++)
				{
					if (!isdigit(documento[i]))//Verificación de entrada para evitar ingreso de caracteres alfabéticos
					{
						aux2=false;
					}
				}
		
				if (aux2==true)
				{
					intaux = atoi(documento);
					if (intaux < anio)
					{
						gotoxy(x,y++);cout << "Año Inválido, inténtelo de nuevo.";
						system ("pause>null");
						delete nuevo_prestamo;
						continue;
					}
				}
		
				else
				{
					gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
					system ("pause>null");
					delete nuevo_prestamo;
					continue;
				}
				nuevo_prestamo -> aniolimite = intaux;
				
				gotoxy(x,y++);cout << "Ingrese mes límite de devolución: "; cin >> documento;
				aux2=true;
				for (int i=0;i<1;i++)
				{
					if (!isdigit(documento[i]))//Verificación de entrada para evitar ingreso de caracteres alfabéticos
					{
						aux2=false;
					}
				}
		
				if (aux2==true)
				{
					intaux = atoi(documento);
				}
		
				else
				{
					gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
					system ("pause>null");
					delete nuevo_prestamo;
					continue;
				}
				nuevo_prestamo -> meslimite = intaux;
				
				gotoxy(x,y++);cout << "Ingrese fecha límite de devolución: "; cin >> documento;
				aux2=true;
				for (int i=0;i<1;i++)
				{
					if (!isdigit(documento[i]))//Verificación de entrada para evitar ingreso de caracteres alfabéticos
					{
						aux2=false;
					}
				}
		
				if (aux2==true)
				{
					intaux = atoi(documento);
				}
		
				else
				{
					gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
					system ("pause>null");
					delete nuevo_prestamo;
					continue;
				}
				nuevo_prestamo -> fechalimite = intaux;
				nuevo_prestamo -> estadodeprestamo = buscarlibro -> estadolibro;
				//Fin de llenado de datos del nodo
				
				//procesos de libro y usaurio
				buscarusuario -> numerodelibrosprestados = buscarusuario -> numerodelibrosprestados + 1;
				buscarlibro -> existencia--;
				
				//Se inserta el nodo en la lista
				prestamo *aux = listaprestamos;
				listaprestamos = nuevo_prestamo;
				nuevo_prestamo -> sig = aux;
				
				break;
			}
		}
	} while (true);
	
	cout ;
	gotoxy(x-5,y+2);cout << "Préstamo registrado exitosamente!";
	system ("pause>null");
}

void registrardevolucion (libro *&listalibros, usuario *&listausuarios, prestamo *&listaprestamos) //está bugeadísimo
{
	string ISBN; //para almacenar códigos ISBN
	int fecha, mes, anio, estadodevolucion, estadoprestamo; //Para fechas y estados de préstamo
	bool encontrado = false; //Para el buscador de préstamo
	bool encontradoaux = false; //Para un segundo buscador
	prestamo *buscadorprestamo = listaprestamos; //buscador prestamo para saber si existe
	prestamo *antbuscadorprestamo = NULL; //anterior al buscador para eliminarlo después
	prestamo *buscadorprestamoaux = listaprestamos; //Para buscar si hay préstamos similares
	usuario *usuarioprestamo = listausuarios; //Para señalar el usuario deudor
	libro *libroprestamo = listalibros; //Para señalar el libro prestado
	libro *buscadorlibroaux = listalibros; //Para buscadr un libro en el mismo estado de devolución
	libro *antbuscadorlibro = NULL; //Para poder eliminar el libro
	char num, aux[4], aux3[2], aux4;
	bool aux2=true;
	int y, x;
	
	do
	{
		aux2=true;
		system ("cls");
		y = 6;
		x = 11;
		cuadro (1,0,78,4); gotoxy (28,2); cout << "\t\t...REGISTRANDO DEVOLUCIÓN..."; //Encabezado
		fflush(stdin);
		gotoxy(x,y++);cout << "Ingrese código ISBN del libro a devolver: "; getline (cin, ISBN);
		gotoxy(x,y++);cout << "Ingrese estado físico del libro prestado (0 al 9. (mayor es peor)): "; cin >> num;
		if (!isdigit(num)) //Verificación de entrada para evitar ingreso de caracteres alfabéticos
		{
			gotoxy(x,y++);cout << "Ingresó una letra inválida. Inténtelo de nuevo.";
			system("pause>null");
			continue;
		}
	
		else
		{
			estadoprestamo = atoi(&num);
		}
	
	while (buscadorprestamo != NULL) //Se busca el préstamo para saber si existe
	{
		if (buscadorprestamo -> codigoISBNprestado == ISBN && buscadorprestamo -> estadodeprestamo == estadoprestamo)
		{
			encontrado = true;
			break;
		}
		
		antbuscadorprestamo = buscadorprestamo;
		buscadorprestamo = buscadorprestamo -> sig;
	}
	
	if (encontrado == true) //si el préstamo existe:
	{
		while (usuarioprestamo -> documento != buscadorprestamo -> ceduladelposeedor) //Se señala al usuario que pidió el libro originalmente
		{
			usuarioprestamo = usuarioprestamo -> sig;
		}
		//A su vez, se señala al libro que fue prestado
		while (libroprestamo != NULL)
		{
			if (libroprestamo -> codigoISBN == buscadorprestamo -> codigoISBNprestado && libroprestamo -> estadolibro == buscadorprestamo -> estadodeprestamo)
			{
				break;
			}
			libroprestamo = libroprestamo -> sig;
		}
		
		gotoxy(x,y++);cout << "Estado físico del libro devuelto (0 al 9. (mayor es peor)): "; cin >> num;
		if (!isdigit(num)) //Verificación de entrada para evitar ingreso de caracteres alfabéticos
		{
			gotoxy(x,y++);cout << "Ingresó una letra inválida. Inténtelo de nuevo.";
			system("pause>null");
			continue;
		}
	
		else
		{
			estadodevolucion = atoi(&num);
		}
		
		if (estadodevolucion > buscadorprestamo -> estadodeprestamo) //Primer check de ban
		{
			usuarioprestamo -> ban = true;
			gotoxy(x,y++);cout << "Libro devuelto en muy mal estado, usuario bloqueado.";
		}
		
		else //Sigue
		{
			gotoxy(x,y++);cout << "Ingrese año de devolución: "; cin >> aux;
			for (int i=0;i<4;i++)
			{
				if (!isdigit(aux[i])) //Verificación de entrada para evitar ingreso de caracteres alfabéticos
				{
					aux2=false;
				}
			}
		
			if (aux2==true)
			{
				anio = atoi(aux);
			}
		
			else
			{
				gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
				system ("pause>null");
				continue;
			}
			
			if (anio > buscadorprestamo -> aniolimite) //Segunda comprobación de ban
			{
				usuarioprestamo -> ban = true;
				gotoxy(x,y++);cout << "Libro devuelto después de tiempo, usuario bloqueado.";
			}
			
			else //Sigue
			{
				aux2=true;
				gotoxy(x,y++);cout << "Ingrese mes de devolución: "; cin >> aux3;
				for (int i=0;i<1;i++)
				{
					if (!isdigit(aux3[i])) //Verificación de entrada para evitar ingreso de caracteres alfabéticos
					{
						aux2=false;
					}
				}
		
				if (aux2==true)
				{
					mes = atoi(aux3);
				}
		
				else
				{
					gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
					system ("pause>null");
					continue;
				}
				
				if (anio == buscadorprestamo -> aniolimite && mes > buscadorprestamo -> meslimite) //Tercera comprobación de ban
				{
					usuarioprestamo -> ban = true;
					gotoxy(x,y++);cout << "Libro devuelto después de tiempo, usuario bloqueado.";
				}
				
				else //Sigue
				{
					aux2=true;
					gotoxy(x,y++);cout << "Ingrese fecha de devolución: "; cin >> aux3; 
					for (int i=0;i<1;i++)
					{
						if (!isdigit(aux3[i])) //Verificación de entrada para evitar ingreso de caracteres alfabéticos
						{
							aux2=false;
						}
					}
		
					if (aux2==true)
					{
						fecha = atoi(aux3);
					}
		
					else
					{
						gotoxy(x-5,y+2); cout << "Hay una letra o espacio en blanco, Inténtelo de nuevo.";
						system ("pause>null");
						continue;
					}
					
					if (anio == buscadorprestamo -> aniolimite && mes == buscadorprestamo -> meslimite && fecha > buscadorprestamo -> fechalimite) //Cuarta comprobación de ban
					{
						usuarioprestamo -> ban = true;
						gotoxy(x,y++);cout << "Libro devuelto después de tiempo, usuario bloqueado.";
					}
				}
			}
		}
		
		usuarioprestamo -> numerodelibrosprestados--; //Se elimina el registro de libro prestado
		
		if (estadodevolucion == buscadorprestamo -> estadodeprestamo) //En caso de que se devuelva en el mismo estado y todo bien
		{
			libroprestamo -> existencia++; //Se agrega existencia
		}
		
		else //Si no se devueelven el mismo estado en el que se prestó. aquí empieza lo complejo.
		{
			while (buscadorlibroaux != NULL) //Se busca un libro con estado similar con el auxiliar
			{
				if (buscadorlibroaux -> codigoISBN == buscadorprestamo -> codigoISBNprestado && buscadorlibroaux -> estadolibro == estadodevolucion)
				{
					encontradoaux = true;
					break;
				}
				buscadorlibroaux = buscadorlibroaux -> sig;
			}
			
			if (encontradoaux == true) //Si sí existe otro libro en estado similar al de devolución
			{			
				buscadorlibroaux -> existencia++; //Se agrega 1 a la existencia
			}
			
			else //Sino, se crea un nodo nuevo
			{
				libro *nuevo_libro = new libro();
				
				//Se rellena
				nuevo_libro -> nombre = libroprestamo -> nombre; 
				nuevo_libro -> autor = libroprestamo -> autor; 
				nuevo_libro -> editorial = libroprestamo -> editorial;
				nuevo_libro -> edicion = libroprestamo -> edicion;
				nuevo_libro -> npag = libroprestamo -> npag;
				nuevo_libro -> genero = libroprestamo -> genero;
				nuevo_libro -> aniodepublicacion = libroprestamo -> aniodepublicacion;
				nuevo_libro -> estadolibro = estadodevolucion;
				nuevo_libro -> codigoISBN = libroprestamo -> codigoISBN;
				nuevo_libro -> estanteria = libroprestamo -> estanteria;
				nuevo_libro -> fila = libroprestamo -> fila;
				nuevo_libro -> existencia = 1;
				
				//y se inserta en la lista
				libro *aux = listalibros;
				listalibros = nuevo_libro;
				nuevo_libro -> sig = aux;
			}
		} 
		
		//Se elimina el préstamo, porque fue devuleto el libro
		
		//Si el préstamo es el primero de la lista
		if (antbuscadorprestamo == NULL)
		{
			listaprestamos = listaprestamos -> sig;
			delete buscadorprestamo;
		}
		
		else //Si no es el primero de la lista
		{
			antbuscadorprestamo -> sig = buscadorprestamo -> sig;
			delete buscadorprestamo;
		}
		
		//Una vez eliminado el prestamo se chekea si existe otro.
		
		if (libroprestamo -> existencia == 0) //Para borrar la instancia de libro original si no le queda nada.
		{
			//entra acá
			encontradoaux = false; //Se recicla la variable auxiliar
			
			while (buscadorprestamoaux != NULL) //Una vez borrado el prestamo devuelto, se comprueba si existe otro idéntico
			{
				if (buscadorprestamoaux -> codigoISBNprestado == ISBN && buscadorprestamoaux -> estadodeprestamo == estadoprestamo)
				{
					encontradoaux = true;
					break;
				}
				
				buscadorprestamoaux = buscadorprestamoaux -> sig;
			}
			
			if (encontradoaux == false) //Si no encontró otro préstamo idéntico, se borra el nodo del libro
			{
				buscadorlibroaux = listalibros;
				antbuscadorlibro = listalibros;
				while (buscadorlibroaux != NULL) //Busca al libro del prestamo
				{
					if (buscadorlibroaux -> codigoISBN == libroprestamo -> codigoISBN && buscadorlibroaux -> estadolibro == libroprestamo -> estadolibro)
					{
						break;
					}
					
					antbuscadorlibro = buscadorlibroaux;
					buscadorlibroaux = buscadorlibroaux -> sig;
				}

				//Una vez encontrado, se elimina
				
				antbuscadorlibro -> sig = buscadorlibroaux -> sig;
				delete buscadorlibroaux;
			}
			break;
		}
		
		else
		{
			break;
		}
	}
	
	else //Si nunca se encuntra dicho préstamo para empezar
 	{
		break;
	}
	
	} while (true);	//Bucle para evitar errores de entrada

	if (encontrado==true) //Imprime si el proceso fue correcto
	{
		gotoxy(x-3,y+2);cout << "Libro registrado como devuelto!";
	}
	
	else //Imprime si no encontró el registro
	{
		gotoxy(x-3,y+2);cout << "Libro no registrado como prestado.";
	}
	
	system ("pause>null");
}

void mostrarprestamos (prestamo *&listaprestamos) //Método que mostrará todos los préstamos de la lista
{
	prestamo *mostrar = listaprestamos; //Nodo buscador
	int contador=1;
	int x, y;
	y = 9;
	x = 16;
	while (mostrar != NULL) //Bucle buscador
	{
		system ("cls");
		y = 9;
		x = 16;
		cuadro (1,0,78,4); gotoxy (28,2); cout << "PRÉSTAMOS"; //Encabezado
		//Datos del préstamo
		gotoxy(29,6);cout << "PRESTAMO " << contador ;
		gotoxy(20,7);cout << "-------------------------------" ;
		gotoxy(x,y++);cout << "Libro prestado: " << mostrar -> libroprestado ;
		gotoxy(x,y++);cout << "Código ISBN del libro prestado: " << mostrar -> codigoISBNprestado ;
		gotoxy(x,y++);cout << "Nombre del poseedor: " << mostrar -> nombredelposeedor ;
		gotoxy(x,y++);cout << "Documento de identidad del poseedor: " << mostrar -> ceduladelposeedor ;
		gotoxy(x,y++);cout << "Fecha de préstamo: " << mostrar -> fechadeprestamo << "/" << mostrar -> mesdeprestamo << "/" << mostrar -> aniodeprestamo ;
		gotoxy(x,y++);cout << "Fecha límite de devolución: " << mostrar -> fechalimite << "/" << mostrar -> meslimite << "/" << mostrar -> aniolimite ;
		gotoxy(x,y++);cout << "Estado físico del libro al momento del préstamo: ";
		
		switch (mostrar -> estadodeprestamo)
		{
			case 0:
				cout << "Excelente.";
				break;
				
			case 1:
				cout << "Casi excelente.";
				break;
				
			case 2:
				cout << "Muy bueno.";
				break;
				
			case 3:
				cout << "Bueno.";
				break;
				
			case 4:
				cout << "No tan bueno.";
				break;
				
			case 5:
				cout << "Intermedio.";
				break;
				
			case 6:
				cout << "No tan horrible.";
				break;
				
			case 7:
				cout << "Horrible.";
				break;
				
			case 8:
				cout << "Muy horrible.";
				break;
				
			case 9:
				cout << "Deplorable.";
				break;
				
			default:
				cout << "Desconocido.";
				break;
		}
		//Fin de datos del prestamo
		
		contador++;
		mostrar = mostrar -> sig;
		gotoxy(x-5,y+2);cout << "Presione cualquier tecla para continuar...";
		
		system ("pause>null");
	}
		gotoxy(x-5,y+3);cout << "No hay más préstamos registrados."; //En caso de finalizar el recorrido de la lista
		system ("pause>null");
}

void verlistadeprestamos (prestamo *&listaprestamos) //Método que mostrará toda la lista de préstamos hasta un límite
{
	int contador=1;
	prestamo *mostrar = listaprestamos;	//Nodo que recorrerá la lista
	int x = 8;
	int y = 8;
	int pag=4;
	
	while (mostrar != NULL) //Bucle que mostrará uno por uno los datos de cada nodo de la lista
	{
		system ("cls");
		cuadro (1,0,78,4); gotoxy (28,2); cout << "LISTA DE PRÉSTAMOS"; //Encabezado
		//Datos en forma de lista
		gotoxy(x,y++);cout << contador << ") Nombre del libro: " << mostrar -> libroprestado ;
		gotoxy(x,y++);cout << "   nombre del poseedor: " << mostrar -> nombredelposeedor ;
		gotoxy(x,y++);cout << "Fecha límite de devolución: " << mostrar -> fechalimite << "/" << mostrar -> meslimite << "/" << mostrar -> aniolimite ;
		//Fin de datos
		
		y++;
		mostrar = mostrar -> sig;
		contador++;
		if (contador==pag) //Si llega a un límite
		{
			gotoxy (x, y++);cout << "Pulse una tecla para continuar...";
			y=8;
			x=8;
			system ("pause>null");
			pag += 4;
		}
	}
	system ("pause>null");
}

void eliminarprestamo (prestamo *&listaprestamos, usuario*&listausuarios) //Proceso de eliminación de un préstamo manualmente
{	
	prestamo *eliminar = listaprestamos; //Nodo buscador de la lsta préstamos
	prestamo *anteliminar = NULL; //Nodo que le antecederá al nodo a eliminar
	usuario *buscadorusuario = listausuarios; //Nodo buscador del usuario
	
	//Variables necesarias
	int eliminando2;
	string aux;
	bool encontrado = false;
	char num;
	//Fin de variables

	do
	{
		system("cls");
		cuadro (1,0,78,4); gotoxy (28,2); cout << "ELIMINAR UN PRÉSTAMO"; //Encabezado
		fflush(stdin);
		gotoxy(9,10);cout << "Ingrese código ISBN del prestamo a eliminar: "; getline(cin, aux); //Se ingresan los datos del préstamo
		gotoxy(9,11);cout << "Ingrese estado físico del libro prestado a eliminar: "; cin >> num;
		if (!isdigit(num)) //Verificación de entrada para evitar caracteres alfabéticos
		{
			gotoxy(9,12);cout << "Ingresó una letra inválida. Inténtelo de nuevo.";
			system("pause>null");
			continue;
		}
	
		else
		{
			eliminando2 = atoi(&num); //Si no se encuentran caracteres alfabéticos se registra en una variable entero
			break;
		}
	} while (true);
	
	while (eliminar != NULL) //Este bucle recorrerá toda la lista de préstamos en busca de coincidencias
	{
		if (anteliminar == NULL && listaprestamos -> codigoISBNprestado == aux && listaprestamos -> estadodeprestamo == eliminando2) //Si la encuentra en el primer nodo de la lista
		{
			encontrado = true;
			if (encontrado == true) //proceso que resta 1 a los libros prestados del usuario del préstamo a eliminar
			{
				while (buscadorusuario != NULL) //Bucle buscador del usuario
				{
					if (buscadorusuario -> nombrecompleto == eliminar -> nombredelposeedor) //Si encuentra la coincidencia
					{
						buscadorusuario -> numerodelibrosprestados--; //Resta uno a sus libros prestados
					}
					buscadorusuario = buscadorusuario -> sig;
				}
			}
	
			listaprestamos = listaprestamos -> sig;
			delete eliminar;
			break;
		}
		
		else if (anteliminar != NULL && eliminar -> codigoISBNprestado == aux && eliminar -> estadodeprestamo == eliminando2) //Si la encuentra no en el primer nodo de la lista
		{
			encontrado = true;
			if (encontrado == true) //proceso que resta 1 a los libros prestados del usuario del préstamo a eliminar
			{
				while (buscadorusuario != NULL) //Bucle buscador del usuario
				{
					if (buscadorusuario -> nombrecompleto == eliminar -> nombredelposeedor) //Si encuentra la coincidencia
					{
						buscadorusuario -> numerodelibrosprestados--; //Resta uno a sus libros prestados
					}
					buscadorusuario = buscadorusuario -> sig;
				}
			}
	
			anteliminar -> sig = eliminar -> sig;
			delete eliminar;
			break;
		}
		
		anteliminar = eliminar;
		eliminar = eliminar -> sig;
	}
	
	animation();
	
	if (encontrado == false) //Si no encuentra coincidencias
	{
		gotoxy(5,14);cout << "préstamo no encontrado.";	
	}
		
	else //Si encuentra coincidencias
	{
		gotoxy(5,14);cout << "préstamo eliminado satisfactoriamente.";
	}
		
	system ("pause>null");
}

void cierreF (){
	//Pequeño mensaje de despedida
	system ("cls");
	cout << "\n\n\n\n\n\n\n\n\t\tMuchas gracias por su visita, vuelva pronto\n\t\t\t¡¡Le estaremos esperando!!\n\n\n\t\t\t";
	exit(1);
}

int menu(const char *titulo,const char *mensaje, const char *opciones[],int posi){

/*
Esta es una función que se encarga de construir cualquier menú 
los parametros que recibe sirven para determinar su funcionamiento.

const char *titulo = Imprimira el Titulo en el encabezado
const char *opciones[] = Este Vector se encargará de almacenar todas las opciones posibles en el menú correspondiente
int posi = Esta variable manipulará el numero de opciones disponible, así como la flechita que la señalará
*/

	int opcionselect = 1;
	int tecla;
	bool bucle = true;

	do 
	{
		system ("cls");
		system ("Title Use las flechas direccionales para desplazarse en el menú");
		cuadro (1,0,78,4); // Dibuja el cuadro del encabezado.
	

		gotoxy(23,7 + (opcionselect+opcionselect)); cout << "-->"; //Configura el comportamiento de la flecha del menú
				
		//esto imprime el titulo
		gotoxy (20,2); cout << titulo;
		gotoxy(15,6);cout << mensaje; 
		
		//imprimiremos las opciones 
		for (int i =0; i < posi; i++) {
			gotoxy (27,9+(i+i)); cout << i+1 << ") " << opciones[i]; 
		}
		
		do {
			tecla = getch();
		} while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER); //Evita teclas ajenas a las 3 funcionales

		
		switch (tecla) //Gestiona el funcionamiento del menú en función de las teclas presionadas
		{
			case TECLA_ARRIBA:
				opcionselect--;
				if (opcionselect < 1) opcionselect = posi; 
				break; 
				
			case TECLA_ABAJO:
				opcionselect++;
				if (opcionselect > posi ) opcionselect = 1;	
				break;
				
			case ENTER:
				bucle = false;
				return opcionselect; //Retorna a la opción sellecionada con ENTER
				break; 
		}
	} while (bucle); 
}

void constructor (libro *&listalibros, usuario *&listausuarios) //Pequeño constructor inicial de listas al iniciar el programa
{
	usuario *nuevo_usuario = new usuario(); //Se crea un nuevo nodo de tipo usuario
	libro *nuevo_libro = new libro(); //Se crea un nuevo nodo de tipo libro
	
	//Se llenan los datos del nodo usuario
	nuevo_usuario -> nombrecompleto = "Aijam Khoudier";
	nuevo_usuario -> nombredeusuario = "Aijam348";
	nuevo_usuario -> contrasenia = "slanesh123";
	nuevo_usuario -> documento = 31513330;
	nuevo_usuario -> edad = 16;
	nuevo_usuario -> ban = false;
	nuevo_usuario -> admin = true;
	nuevo_usuario -> email = "aijamkhoudier@gmail.com";
	nuevo_usuario -> telefono = 4243360846;
	nuevo_usuario -> direccion = "Aragua, Maracay, Urb. La placera";
	nuevo_usuario -> sexo = 'm';
	nuevo_usuario -> numerodelibrosprestados = 0;
	//Fin de llenado de datos del nodo usuario
	
	//Se llenan los datos del nodo libro
	nuevo_libro -> nombre = "Manifiesto comunista";
	nuevo_libro -> autor = "Marx, Karl / Engels, Friedrich";
	nuevo_libro -> editorial = "Alianza Editorial";
	nuevo_libro -> edicion = 1;
	nuevo_libro -> npag = 144;
	nuevo_libro -> genero = "Marxismo y comunismo / Manifiestos políticos";
	nuevo_libro -> aniodepublicacion = 2011;
	nuevo_libro -> codigoISBN = "978-84-206-5500-0";
	nuevo_libro -> estadolibro = 1;
	nuevo_libro -> estanteria = "1A";
	nuevo_libro -> fila = 1;
	nuevo_libro -> existencia = 10;
	//Fin de llenado de datos del nodo libro
	
	//Proceso de inserción en las listas
	usuario *auxusuario = listausuarios;
	libro *auxlibro = listalibros;
	listausuarios = nuevo_usuario;
	listalibros = nuevo_libro;
	nuevo_usuario -> sig = auxusuario;
	nuevo_libro -> sig = auxlibro;
	//Fin de procesos de inserción
	
	nuevo_usuario = new usuario(); //Se crea un nuevo nodo de tipo usuario
	nuevo_libro = new libro(); //Se crea un nuevo nodo de tipo libro
	
	 //Se llenan los datos del nodo usuario
	nuevo_usuario -> nombrecompleto = "Rafael Carreño";
	nuevo_usuario -> nombredeusuario = "drafa";
	nuevo_usuario -> contrasenia = "carreno";
	nuevo_usuario -> documento = 31023109;
	nuevo_usuario -> edad = 18;
	nuevo_usuario -> ban = false;
	nuevo_usuario -> admin = true;
	nuevo_usuario -> email = "rafaelcarrenorec@gmail.com";
	nuevo_usuario -> telefono = 4243356032;
	nuevo_usuario -> direccion = "Aragua, Maracay, San Jacinto";
	nuevo_usuario -> sexo = 'm';
	nuevo_usuario -> numerodelibrosprestados = 0;
	//Fin de llenado del nodo usuario
	
	//Se llenan los datos del nodo libro
	nuevo_libro -> nombre = "Mi lucha";
	nuevo_libro -> autor = "Hitler, Adolf";
	nuevo_libro -> editorial = "T&B Editores";
	nuevo_libro -> edicion = 1;
	nuevo_libro -> npag = 336;
	nuevo_libro -> genero = "Manifiestos políticos";
	nuevo_libro -> aniodepublicacion = 2018;
	nuevo_libro -> codigoISBN = "978-607-8578-08-5";
	nuevo_libro -> estadolibro = 1;
	nuevo_libro -> estanteria = "1A";
	nuevo_libro -> fila = 1;
	nuevo_libro -> existencia = 10;
	//Fin de llenado de datos del nodo libro
	
	//Proceso de inserción en las listas
	auxusuario = listausuarios;
	auxlibro = listalibros;
	listausuarios = nuevo_usuario;
	listalibros = nuevo_libro;
	nuevo_usuario -> sig = auxusuario;
	nuevo_libro -> sig = auxlibro;
	//Fin de procesos de inserción
	
	nuevo_usuario = new usuario(); //Se crea un nuevo nodo de tipo usuario
	nuevo_libro = new libro(); //Se crea un nuevo nodo de tipo libro
	
	 //Se llenan los datos del nodo usuario
	nuevo_usuario -> nombrecompleto = "Leonardo Castillo";
	nuevo_usuario -> nombredeusuario = "leocastillo";
	nuevo_usuario -> contrasenia = "castillo";
	nuevo_usuario -> documento = 31339091;
	nuevo_usuario -> edad = 18;
	nuevo_usuario -> ban = false;
	nuevo_usuario -> admin = false;
	nuevo_usuario -> email = "leonardocastillo@gmail.com";
	nuevo_usuario -> telefono = 4243111281;
	nuevo_usuario -> direccion = "Aragua, Turmero";
	nuevo_usuario -> sexo = 'm';
	nuevo_usuario -> numerodelibrosprestados = 0;
	//Fin de llenado del nodo usuario
	
	//Se llenan los datos del nodo libro
	nuevo_libro -> nombre = "El Corán";
	nuevo_libro -> autor = "Anónimo";
	nuevo_libro -> editorial = "PENGUIN CLASICOS";
	nuevo_libro -> edicion = 1;
	nuevo_libro -> npag = 640;
	nuevo_libro -> genero = "Teología / Historia";
	nuevo_libro -> aniodepublicacion = 2015;
	nuevo_libro -> codigoISBN = "978-84-9105-072-8";
	nuevo_libro -> estadolibro = 1;
	nuevo_libro -> estanteria = "1A";
	nuevo_libro -> fila = 1;
	nuevo_libro -> existencia = 10;
	//Fin de llenado de datos del nodo libro
	
	//Proceso de inserción en las listas
	auxusuario = listausuarios;
	auxlibro = listalibros;
	listausuarios = nuevo_usuario;
	listalibros = nuevo_libro;
	nuevo_usuario -> sig = auxusuario;
	nuevo_libro -> sig = auxlibro;
	//Fin de procesos de inserción
}

int main () {
	//Proceso principal
	system ("mode con cols=81 lines=30"); //Proceso de cambio de dimensiones de la consola
	setlocale (LC_ALL, ""); //Inserción de compatibilidad con carácteres especiales
	system ("color 03"); //Cambio de color de la consola
	
	//Declaracion inicial de las listas
	usuario *listausuarios = NULL;
	libro *listalibros = NULL;
	prestamo *listaprestamos = NULL;
	//Fin de declaración de las listas
	
	constructor(listalibros, listausuarios); //PRoceso de contrucción inicial
	I_sesion (listalibros, listausuarios, listaprestamos); //De este método se desemboca todo el programa

	system ("pause");
	return 0;
}

