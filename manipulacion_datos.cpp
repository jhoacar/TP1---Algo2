#ifndef MANIPULACION_DATOS_CPP
#define MANIPULACION_DATOS_CPP

#include "manipulacion_datos.h"
#include "funciones.h"
#include "funciones.cpp"
#include "elementos.h"
#include "elementos.cpp"
#include <iostream>
#include <cstring>
using namespace std;


/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_agua(datos_t datos,string cuadrante){
	int i=0;bool encontrado=false;
	while(!encontrado&&i<datos.cantidad_aguas)
		encontrado=!strcmpi(datos.aguas[i++].cuadrante,cuadrante.c_str());
	
	return encontrado;
}
/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_bala(datos_t datos,string cuadrante){
	int i=0;bool encontrado=false;
	while(!encontrado&&i<datos.cantidad_balas)
		encontrado=!strcmpi(datos.balas[i++].cuadrante,cuadrante.c_str());
	
	return encontrado;
}
/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_cruz(datos_t datos,string cuadrante){
	int i=0;bool encontrado=false;
	while(!encontrado&&i<datos.cantidad_cruces)
		encontrado=!strcmpi(datos.cruces[i++].cuadrante,cuadrante.c_str());
	
	return encontrado;
}
/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_estaca(datos_t datos,string cuadrante){
	int i=0;bool encontrado=false;
	while(!encontrado&&i<datos.cantidad_estacas)
		encontrado=!strcmpi(datos.estacas[i++].cuadrante,cuadrante.c_str());
	
	return encontrado;
}
/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_escopeta(datos_t datos,string cuadrante){
	int i=0;bool encontrado=false;
	while(!encontrado&&i<datos.cantidad_escopetas)
		encontrado=!strcmpi(datos.escopetas[i++].cuadrante,cuadrante.c_str());
	
	return encontrado;
}
/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_zombie(datos_t datos,string cuadrante){
	int i=0;bool encontrado=false;
	while(!encontrado&&i<datos.cantidad_zombies)
		encontrado=!strcmpi(datos.zombis[i++].cuadrante,cuadrante.c_str());
	
	return encontrado;
}
/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_humano(datos_t datos,string cuadrante,const char *nombre_humano){
	int i=0;bool encontrado=false;
	while(!encontrado&&i++<datos.cantidad_humanos)
		encontrado=!strcmpi(datos.humanos[i].cuadrante,cuadrante.c_str())&&!strcmpi(datos.humanos[i].nombre,nombre_humano);
	
	return encontrado;
}
/*
Pre: una estructura de datos cargadas con cuadrante a buscar
Post: devuelve si encontro el objeto con ese cuadrante en los datos
*/
bool buscar_vampiro(datos_t datos,string cuadrante,const char *nombre_vampiro){
	int i=0;bool encontrado=false;
	while(!encontrado&&i++<datos.cantidad_vampiros)
		encontrado=!strcmpi(datos.vampiros[i].cuadrante,cuadrante.c_str())&&!strcmpi(datos.vampiros[i].nombre,nombre_vampiro);
	
	return encontrado;
}
/*
Pre: 
Post: inicializa todos los punteros y las cantidades a 0
*/
void inicializar_datos(datos_t *datos){
	datos->aguas=NULL;
	datos->balas=NULL;
	datos->cruces=NULL;
	datos->escopetas=NULL;
	datos->estacas=NULL;
	datos->humanos=NULL;
	datos->vampiros=NULL;
	datos->zombis=NULL;
	datos->cantidad_humanos=0;
	datos->cantidad_zombies=0;
	datos->cantidad_vampiros=0;
	datos->cantidad_aguas=0;
	datos->cantidad_balas=0;
	datos->cantidad_escopetas=0;
	datos->cantidad_cruces=0;
	datos->cantidad_estacas=0;
}
/*
Pre:
Post: inicializa pidiendo memoria en el heap los vectores de cada objeto
*/
void inicializar_arrays(datos_t *datos){
	
	datos->humanos	=new humano_t	[datos->cantidad_humanos];
	datos->vampiros	=new vampiro_t	[datos->cantidad_vampiros];
	datos->zombis	=new zombi_t	[datos->cantidad_zombies];
	datos->aguas	=new agua_t		[datos->cantidad_aguas];
	datos->balas	=new bala_t		[datos->cantidad_balas];
	datos->escopetas=new escopeta_t	[datos->cantidad_escopetas];
	datos->cruces	=new cruz_t		[datos->cantidad_cruces];
	
}
/*
Pre: un puntero con la informacion de los arrays previamente cargados
Post: libera la memoria y posiciona los punteros a una direccion nula
*/
void eliminar_arrays(datos_t *datos){
	delete datos->humanos;
	delete datos->vampiros;
	delete datos->zombis;
	delete datos->aguas;
	delete datos->balas;
	delete datos->escopetas;
	delete datos->cruces;
	
	datos->aguas=NULL;
	datos->balas=NULL;
	datos->cruces=NULL;
	datos->escopetas=NULL;
	datos->estacas=NULL;
	datos->humanos=NULL;
	datos->vampiros=NULL;
	datos->zombis=NULL;
}
/*
Pre: una estructura datos previamente cargada
Post: devuelve la cantidad de agua que se encuentra en los datos
*/
int obtener_total_agua(datos_t datos){
    int suma=0;
    for(int i=0;i<datos.cantidad_aguas;i++)
        suma+=datos.aguas[i].dosis;
    return suma;
}
/*
Pre: una estructura datos previamente cargada
Post: devuelve la cantidad de balas que se encuentra en los datos
*/
int obtener_total_balas(datos_t datos){
    int suma=0;
    for(int i=0;i<datos.cantidad_balas;i++)
        suma+=datos.balas[i].cantidad;
    return suma;
}
/*
Pre: un objeto a guardar con la informacion para separarlas en tokens
Post: guarda la informacion decodificada de la info en el objeto
*/
void guardar_objeto(objeto_t &objeto,char info[]){
	
	char copia_info[strlen(info)];
	strcpy(copia_info,info);
	
	strcpy(objeto.nombre,strtok(copia_info,"("));
	
	coord_t coordenada = obtener_coordenadas(strtok(NULL,")"),",");
	cargar_coordenada(objeto.coordenada,coordenada);
	cargar_cuadrante(objeto.cuadrante,objeto.coordenada);	
}
/*
Pre: un vector de objetos del mismo tamano de la cantidad pasada por parametro y la estructura de los datos a cargar
Post: carga en los vectores de los datos la informacion de cada uno.
*/
void cargar_objetos_a_datos(objeto_t objetos[],size_t cantidad,datos_t *datos){
	
	int pos_agua=0;
	int pos_humano=0;
	int pos_vampiro=0;
	int pos_zombie=0;
	int pos_cruz=0;
	int pos_bala=0;
	int pos_estaca=0;
	int pos_escopeta=0;
	
	for(int i=0;i<cantidad;i++){
		
		char *nombre = strtok(objetos[i].nombre," ");
		const char *extra = strtok(NULL," ");
		extra=extra?extra:"NO_HAY";
		
		if(es_humano(nombre))
			cargar_humano(extra,objetos[i],datos->humanos[pos_humano++]);
			
		if(es_zombi(nombre))
			cargar_zombie(objetos[i],datos->zombis[pos_zombie++]);
			
		if(es_vampiro(nombre))
			cargar_vampiro(objetos[i],datos->vampiros[pos_vampiro++]);
			
		if(es_agua(nombre))
			cargar_agua(extra,objetos[i],datos->aguas[pos_agua++]);
			
		if(es_bala(nombre))
			cargar_bala(extra,objetos[i],datos->balas[pos_bala++]);
		
		if(es_estaca(nombre))
			cargar_estaca(objetos[i],datos->estacas[pos_estaca++]);
		
		if(es_escopeta(nombre))
			cargar_escopeta(objetos[i],datos->escopetas[pos_escopeta++]);
			
		if(es_cruz(nombre))
			cargar_cruz(objetos[i],datos->cruces[pos_cruz++]);
		
	}
}
/*
Pre: un vector de objetos del mismo tamano de la cantidad pasada por parametro con la informacion a procesar y la estructura de los datos a guardar
Post: cuenta la cantidad de objetos que hay con dicha informacion y guarda cada informacion en los objetos y procesa la cantidad que hay en los datos
*/
void contar_objetos(objeto_t objetos[],size_t cantidad_info,char info[][MAX_DATOS],datos_t *datos){
	
	for(int i=0;i<cantidad_info;i++){
		
		guardar_objeto(objetos[i],info[i]);
		
		char *nombre = strtok(info[i]," ");
		
		if(es_humano(nombre))
			datos->cantidad_humanos+=1;	
			
		if(es_zombi(nombre))
			datos->cantidad_zombies+=1;
			
		if(es_vampiro(nombre))
			datos->cantidad_vampiros+=1;
			
		if(es_agua(nombre))
			datos->cantidad_aguas+=1;
			
		if(es_bala(nombre))
			datos->cantidad_balas+=1;
		
		if(es_estaca(nombre))
			datos->cantidad_estacas+=1;
			
		if(es_escopeta(nombre))
			datos->cantidad_escopetas+=1;
			
		if(es_cruz(nombre))
			datos->cantidad_cruces+=1;
			
	}
}
/*
Pre: un puntero con la estructura de los datos a guardar y el nombre del fichero a buscar la informacion
Post: procesa la informacion del fichero y la carga a la estructura de datos.
*/
bool cargar_datos_fichero(datos_t *datos,const char *nombre_fichero){

	cout<<"Cargando datos..."<<endl;
	
	string texto = obtener_texto(nombre_fichero);
	
	if(!texto.c_str()){
		cout<<"Error al obtener el texto del fichero: "<<nombre_fichero<<endl;
		return false;
	}
	
	size_t cantidad_datos = obtener_cant_division(texto.c_str(),"\n");
	char info[cantidad_datos][MAX_DATOS];
	dividir(texto.c_str(),"\n",cantidad_datos,info);
	
	objeto_t objetos[cantidad_datos];

	contar_objetos(objetos,cantidad_datos,info,datos);
	
	inicializar_arrays(datos);
	
	cargar_objetos_a_datos(objetos,cantidad_datos,datos);
	
	cout<<"Datos cargados!"<<endl;
	
	return true;
}

#endif

