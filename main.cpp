#include "funciones.h"
#include <iostream>
using namespace std;

const char *nombre_archivo = "estado.txt";


int main() {
  	
  	datos_t datos;
  	
  	inicializar_datos(&datos);
  	if(!cargar_datos_fichero(&datos,nombre_archivo)){
  		cout<<"No se pudo cargar datos del "<<nombre_archivo<<endl;
		return 1;	
	}
	mostrar_resumen(datos);
  	cout<<"Presione una tecla para continuar...";
	cin.get();
	system("clear");
	mostrar_menu(datos);
  	
  	eliminar_arrays(&datos);
  	return 0;
}
