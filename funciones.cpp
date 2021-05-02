#ifndef FUNCIONES_CPP   
#define FUNCIONES_CPP

#include "funciones.h"
#include "manipulacion_datos.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void mayuscula(string &cadena){
	for(size_t i=0;i<cadena.length();i++)
		cadena[i] = (cadena[i]>='a'&&cadena[i]<='z')?'A'+(cadena[i]-'a'):cadena[i];
}
/*
Pre: Un nombre del fichero a abrir
Post: Devuelve la informacion del fichero en formato string
*/
string obtener_texto(string nombre_fichero){
	
	fstream archivo(nombre_fichero.c_str(), fstream::in );
	if(!archivo){
		cout<<"No se pudo abrir el archivo "<<nombre_fichero<<endl;
		return NULL;
	}
  	string datos_texto;
  	getline(archivo,datos_texto,'\0');
  	archivo.close();
  	return datos_texto;
}
/*
Pre: una cadena de texto con la informacion y un delimitador a usar
Post: separa la cadena con el delimitador y cuenta cuantas cadenas existen.
*/
size_t obtener_cant_division(const char info[],const char *delim){
	char copia[strlen(info)];
	strcpy(copia,info);
	size_t cantidad=0;
	char *palabra=strtok(copia,delim);
	while(palabra&&++cantidad)
		palabra=strtok(NULL,delim);
	
	return cantidad;
}
/*
Pre: una cadena de texto con la informacion, un delimitador, la cantidad de divisiones y el vector de cadenas a guardar la informacion
Post: guarda en el vector de cadenas cada division realizada del texto con el delimitador la cantidad solicitada por parametro
*/
void dividir(const char texto[],const char *delim,const size_t cantidad,char divisiones[][MAX_DATOS]){
	char copia[strlen(texto)];
	strcpy(copia,texto);
	strcpy(divisiones[0],strtok(copia,delim));
	for(int i=1;i<cantidad;i++)
		strcpy(divisiones[i],strtok(NULL,delim));
}
/*
Pre: datos previamente cargados, una cadena con el cuadrante a buscar y la opcion del menu
Post: devuelve verdadero si encuentra el objeto con el cuadrante y falso en caso contrario
*/
bool buscar(datos_t datos,string cuadrante,int opcion){
	mayuscula(cuadrante);
	switch(opcion){
    	case AGUA: 				return buscar_agua(datos,cuadrante);
    	case BALA: 				return buscar_bala(datos,cuadrante);
    	case CRUZ: 				return buscar_cruz(datos,cuadrante);
    	case ESTACA: 			return buscar_estaca(datos,cuadrante);
    	case ESCOPETA: 			return buscar_escopeta(datos,cuadrante);
    	case HUMANO: 			return buscar_humano(datos,cuadrante,"humano");
    	case HUMANO_CAZADOR: 	return buscar_humano(datos,cuadrante,"cazador");
    	case VANESA: 			return buscar_humano(datos,cuadrante,"Vanesa");
    	case VAMPIRO: 			return buscar_vampiro(datos,cuadrante,"Vampiro");
    	case VAMPIRELLA:		return buscar_vampiro(datos,cuadrante,"Vampirella");
    	case NOSFERATU:			return buscar_vampiro(datos,cuadrante,"Nosferatu");
    	case ZOMBIE:			return buscar_zombie(datos,cuadrante);
	}
}
/*
Pre:
Post: interfaz del usuario, encargada de recoger la informacion del cuadrante
*/
void mostrar_menu(const datos_t datos){
    string respuesta="Si";
    while(strstr(RESPUESTAS,respuesta.c_str())){
		string cuadrante="NADA";    
		cout<<"\t-----MENU-----"<<endl;
	    while(cuadrante.length()>2||!strstr(CUADRANTES,cuadrante.c_str())){
	        cout<<"\nIngrese el cuadrante donde quiere preguntar:\n";
	        cout<<"\tNO : Norte Oeste \n";
	        cout<<"\tNE : Norte Este \n";
	        cout<<"\tSO : Sur Oeste \n";
	        cout<<"\tSE : Sur Este \n\n";
	        cin>>cuadrante;
	        cin.ignore();
	    }
	    string elemento="NINGUNO";
	    while(elemento.length()>2||atoi(elemento.c_str())>12||atoi(elemento.c_str())<1){
	        cout<<"Ingrese el digito por el elemento que desea consultar:\n";
	        cout<<"\t01) Agua \n";
	        cout<<"\t02) Bala \n";
	        cout<<"\t03) Cruz \n";
	        cout<<"\t04) Estaca \n";
	        cout<<"\t05) Escopeta \n";
	        cout<<"\t06) Humano \n";
	        cout<<"\t07) Humano Cazador \n";
	        cout<<"\t08) Humano Vanesa \n";
	        cout<<"\t09) Vampiro \n";
	        cout<<"\t10) Vampiro Vampirella \n";
	        cout<<"\t11) Vampiro Nosferatu \n";
	        cout<<"\t12) Zombi \n\n";
	        cin>>elemento;
	        cin.ignore();
	    }
	    cout<<(buscar(datos,cuadrante,atoi(elemento.c_str()))?"\tSE ENCONTRO":"\tNO SE ENCONTRO")<<endl;
	    cout<<"Desea repetir la operacion? (S/N): "<<endl;
		cin>>respuesta;
		cin.ignore();
	}
}
/*
Pre: una coordenada cargada
Post: muestra las coordenadas en un formato especifico
*/
void mostrar_coordenada(coord_t coordenada){
	cout<<"("<<coordenada.x<<","<<coordenada.y<<")"<<endl;
}
/*
Pre:
Post: muestra la informacion de los datos con un formato especifico
*/
void mostrar_resumen(const datos_t datos){
    int suma_agua = obtener_total_agua(datos);
    int suma_balas = obtener_total_balas(datos);
    int suma_personaje = datos.cantidad_humanos+datos.cantidad_vampiros+datos.cantidad_zombies;
    int suma_objetos = suma_agua+datos.cantidad_cruces+datos.cantidad_estacas;
    
    cout<<"ELEMENTO\tCANTIDAD\t\tPORCENTAJE"<<endl;
    cout<<"HUMANOS\t\t"<<datos.cantidad_humanos<<"\t\t\t"<<(suma_personaje!=0?100*(float)datos.cantidad_humanos/(float)suma_personaje:0)<<endl;
    cout<<"ZOMBIS\t\t"<<datos.cantidad_zombies<<"\t\t\t"<<(suma_personaje!=0?100*(float)datos.cantidad_zombies/(float)suma_personaje:0)<<endl;
    cout<<"VAMPIROS\t"<<datos.cantidad_vampiros<<"\t\t\t"<<(suma_personaje!=0?100*(float)datos.cantidad_vampiros/(float)suma_personaje:0)<<endl;
    cout<<"AGUA BENDITA\t"<<suma_agua<<"\t\t\t"<<(suma_objetos!=0?100*(float)suma_agua/(float)suma_objetos:0)<<endl;
    cout<<"CRUCES\t\t"<<datos.cantidad_cruces<<"\t\t\t"<<(suma_objetos!=0?100*(float)datos.cantidad_cruces/(float)suma_objetos:0)<<endl;
    cout<<"ESTACAS\t\t"<<datos.cantidad_estacas<<"\t\t\t"<<(suma_objetos!=0?100*(float)datos.cantidad_estacas/(float)suma_objetos:0)<<endl;
    cout<<"ESCOPETAS\t"<<datos.cantidad_escopetas<<"\t\t\t"<<(suma_balas!=0?100*(float)datos.cantidad_escopetas/(float)suma_balas:0)<<endl;
    cout<<"BALAS\t\t"<<suma_balas<<"\t\t\t"<<(datos.cantidad_escopetas!=0?100*(float)suma_balas/(float)datos.cantidad_escopetas:0)<<endl;
}
/*
Pre:
Post: muestra la informacion de los datos con un formato especifico
*/
void mostrar_datos(const datos_t datos){
	
	cout<<"AGUAS: "<<endl;
	for(int i=0;i<datos.cantidad_aguas;i++){
		cout<<" ("<<datos.aguas[i].cuadrante<<")";
		cout<<"DOSIS: "<<datos.aguas[i].dosis<<" ";
		mostrar_coordenada(datos.aguas[i].coordenada);
	}
	cout<<"BALAS: "<<endl;
	for(int i=0;i<datos.cantidad_balas;i++){
		cout<<" ("<<datos.balas[i].cuadrante<<")";
		cout<<"CANTIDAD: "<<datos.balas[i].cantidad<<" ";
		mostrar_coordenada(datos.balas[i].coordenada);
	}
	cout<<"CRUCES: "<<endl;
	for(int i=0;i<datos.cantidad_cruces;i++){
		cout<<" ("<<datos.cruces[i].cuadrante<<")";
		mostrar_coordenada(datos.cruces[i].coordenada);
	}
	cout<<"ESCOPETAS: "<<endl;
	for(int i=0;i<datos.cantidad_escopetas;i++){
		cout<<" ("<<datos.escopetas[i].cuadrante<<")";
		mostrar_coordenada(datos.escopetas[i].coordenada);
	}
	cout<<"HUMANOS: "<<endl;
	for(int i=0;i<datos.cantidad_humanos;i++){
		cout<<" ("<<datos.humanos[i].cuadrante<<")";
		cout<<datos.humanos[i].nombre;
		cout<<(datos.humanos[i].cazador?" (Cazador) ":" ");
		mostrar_coordenada(datos.humanos[i].coordenada);
	}
	cout<<"VAMPIROS: "<<endl;
	for(int i=0;i<datos.cantidad_vampiros;i++){
		cout<<" ("<<datos.vampiros[i].cuadrante<<")";
		cout<<datos.vampiros[i].nombre<<" ";
		mostrar_coordenada(datos.vampiros[i].coordenada);
	}
	cout<<"ZOMBIES: "<<endl;
	for(int i=0;i<datos.cantidad_zombies;i++){
		cout<<" ("<<datos.zombis[i].cuadrante<<")";
		mostrar_coordenada(datos.zombis[i].coordenada);
	}
}

#endif
