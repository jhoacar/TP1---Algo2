#ifndef ELEMENTOS_CPP
#define ELEMENTOS_CPP

#include "elementos.h"
#include <cstdlib>
#include <cstring>
const int LIMITES_NORTE[2]  = {1,300};
const int LIMITES_SUR[2]    = {301,600};
const int LIMITES_ESTE[2]   = {501,1000};
const int LIMITES_OESTE[2]  = {1,500};
const char *NORTE_OESTE = "NO";
const char *SUR_OESTE 	= "SO";
const char *NORTE_ESTE	= "NE";
const char *SUR_ESTE 	= "SE";
const char* CAZADOR 	= "CV";
const char* VAMPIROS 	= "Nosferatu Vampirella vampiro";
const char* HUMANOS 	= "humano HUMANO Vanesa";
const char* ZOMBIES 	= "zombi zombies";
const char* AGUA = "Agua AGUA agua";
const char* BALA = "Bala BALA bala";
const char* ESCOPETA = "Escopeta ESCOPETA escopeta";
const char* ESTACA = "Estaca ESTACA estaca";
const char* CRUZ = "Cruz CRUZ cruz";

/*
Pre: una cadena con la informacion a extraer y su delimitador
Post: devuelve las coordenadas de la informacion extraida con su delimitador 
*/
coord_t obtener_coordenadas(char cadena[],const char *delim){
	char copia[strlen(cadena)];
	strcpy(copia,cadena);	
	coord_t coord = {atoi(strtok(copia,delim)),atoi(strtok(NULL,delim))};
	return coord;
}
/*
Pre: una cadena a comparar
Post: verdadero si esta entre las constantes de humanos
*/
bool es_humano(const char *nombre){
	return strstr(HUMANOS,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si esta entre las constantes de zombies
*/
bool es_zombi(const char *nombre){
	return strstr(ZOMBIES,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si esta entre las constantes de vampiros
*/
bool es_vampiro(const char *nombre){
	return strstr(VAMPIROS,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si coincide con la cadena agua
*/
bool es_agua(const char *nombre){
	return strstr(AGUA,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si coincide con la cadena bala
*/
bool es_bala(const char *nombre){
	return strstr(BALA,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si coincide con la cadena estaca
*/
bool es_estaca(const char *nombre){
    return strstr(ESTACA,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si coincide con la cadena escopeta
*/
bool es_escopeta(const char *nombre){
	return strstr(ESCOPETA,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si coincide con la cadena cruz
*/
bool es_cruz(const char *nombre){
	return strstr(CRUZ,nombre);
}
/*
Pre: una cadena a comparar
Post: verdadero si coincide con la cadena cazador
*/
bool es_cazador(const char *nombre){
	return strstr(CAZADOR,nombre);
}
/*
Pre: una coordenada cargada
Post: devuelve verdadero si pertenece a los limites del norte 
*/
bool esta_Norte(coord_t coordenada){
    return coordenada.y>=LIMITES_NORTE[0] && coordenada.y<=LIMITES_NORTE[1];
}
/*
Pre: una coordenada cargada
Post: devuelve verdadero si pertenece a los limites del sur 
*/
bool esta_Sur(coord_t coordenada){
    return coordenada.y>=LIMITES_SUR[0] && coordenada.y<=LIMITES_SUR[1];
}
/*
Pre: una coordenada cargada
Post: devuelve verdadero si pertenece a los limites del oeste 
*/
bool esta_Oeste(coord_t coordenada){
    return coordenada.x>=LIMITES_OESTE[0] && coordenada.x<=LIMITES_OESTE[1];
}
/*
Pre: una coordenada cargada
Post: devuelve verdadero si pertenece a los limites del este 
*/
bool esta_Este(coord_t coordenada){
    return coordenada.x>=LIMITES_ESTE[0] && coordenada.x<=LIMITES_ESTE[1];
}
/*
Pre: una cadena donde guardar la informacion de una coordenada cargada
Post: carga en la cadena la informacion del cuadrante que corresponde
*/
void cargar_cuadrante(char cuadrante[],coord_t coordenada){
	const char *info=" \0";
    info = esta_Norte(coordenada) && esta_Oeste(coordenada)? NORTE_OESTE:info;
    info = esta_Norte(coordenada) && esta_Este(coordenada) ? NORTE_ESTE:info;
    info = esta_Sur(coordenada)   && esta_Oeste(coordenada)? SUR_OESTE:info;
    info = esta_Sur(coordenada)   && esta_Este(coordenada) ? SUR_ESTE:info;
    strcpy(cuadrante,info);
}
/*
Pre: una coordenada destino y una coordenada origen cargada
Post: carga en la coordenada destino la informacion del origen
*/
void cargar_coordenada(coord_t &destino,coord_t origen){
	destino.x=origen.x;
	destino.y=origen.y;
}
/*
Pre: una coordenada y un cuadrante a guardar la informacion del cuadrante y coordenada de origen previamente cargados
Post: guarda la informacion de la coordenada y el cuadrante respectivamente
*/
void cargar_posicion(coord_t &destino,char cuadrante_destino[],coord_t origen,char cuadrante_origen[]){
	cargar_coordenada(destino,origen);
	strcpy(cuadrante_destino,cuadrante_origen);
}
/*
Pre: una cadena con la informacion a evaluar, un objeto cargado con la info y el humano a cargar
Post: carga la informacion del objeto al humano agregando la informacion extra si tiene.
*/
void cargar_humano(const char info[],objeto_t objeto,humano_t &humano){
	humano.cazador=es_cazador(info);
	strcpy(humano.nombre,objeto.nombre);
	cargar_posicion(humano.coordenada,humano.cuadrante,objeto.coordenada,objeto.cuadrante);	
}
/*
Pre: un objeto cargado y un zombie a cargar 
Post: carga la informacion del objeto al zombie
*/
void cargar_zombie(objeto_t objeto,zombi_t &zombie){
	cargar_posicion(zombie.coordenada,zombie.cuadrante,objeto.coordenada,objeto.cuadrante);
}
/*
Pre: un objeto cargado y un vampiro a cargar
Post: carga la informacion del objeto al vampiro
*/
void cargar_vampiro(objeto_t objeto,vampiro_t &vampiro){
	strcpy(vampiro.nombre,objeto.nombre);
	cargar_posicion(vampiro.coordenada,vampiro.cuadrante,objeto.coordenada,objeto.cuadrante);
}
/*
Pre: una cadena con la informacion a extraer, un objeto cargado y una estructura de agua a cargar
Post: carga la informacion del objeto al agua con la informacion extra de la cadena
*/
void cargar_agua(const char info[],objeto_t objeto,agua_t &agua){
	agua.dosis=atoi(info);
	cargar_posicion(agua.coordenada,agua.cuadrante,objeto.coordenada,objeto.cuadrante);
}
/*
Pre: una cadena con la informacion a extraer, un objeto cargado y una estructura de bala a cargar
Post: carga la informacion del objeto a la bala con la informacion extra de la cadena
*/
void cargar_bala(const char info[],objeto_t objeto,bala_t &bala){
	bala.cantidad=atoi(info);
	cargar_posicion(bala.coordenada,bala.cuadrante,objeto.coordenada,objeto.cuadrante);
}
/*
Pre: un objeto cargado y una estaca a cargar
Post: carga a la estaca la informacion del objeto
*/
void cargar_estaca(objeto_t objeto,estaca_t &estaca){
	cargar_posicion(estaca.coordenada,estaca.cuadrante,objeto.coordenada,objeto.cuadrante);
}
/*
Pre: un objeto cargado y una escopeta a cargar
Post: carga a la escopeta la informacion del objeto
*/
void cargar_escopeta(objeto_t objeto,escopeta_t &escopeta){
	cargar_posicion(escopeta.coordenada,escopeta.cuadrante,objeto.coordenada,objeto.cuadrante);
}
/*
Pre: un objeto cargado y una cruz a cargar
Post: carga a la cruz la informacion del objeto
*/
void cargar_cruz(objeto_t objeto,cruz_t &cruz){
	cargar_posicion(cruz.coordenada,cruz.cuadrante,objeto.coordenada,objeto.cuadrante);
}
#endif
