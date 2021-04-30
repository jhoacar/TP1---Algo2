#include "funciones.h"
#include "funciones.cpp"
#include "manipulacion_datos.h"
#include "manipulacion_datos.cpp"
#include <iostream>
#include <cstring>
using namespace std;

const char *nombre_archivo = "estado.txt";


int main() {
  	
  	datos_t datos;
  	
  	inicializar_datos(&datos);
  	if(!cargar_datos_fichero(&datos,nombre_archivo)){
  		cout<<"No se pudo cargar datos del "<<nombre_archivo<<endl;
		return 1;	
	}
	mostrar_datos(datos);
	mostrar_resumen(datos);
  	mostrar_menu(datos);
  	
  	eliminar_arrays(&datos);
  	return 0;
}
