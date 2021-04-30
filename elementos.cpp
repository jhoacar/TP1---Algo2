#ifndef ELEMENTOS_CPP
#define ELEMENTOS_CPP

#include "elementos.h"
#include <cstdlib>
#include <cstring>

coord_t obtener_coordenadas(char cadena[],const char *delim){
	char copia[strlen(cadena)];
	strcpy(copia,cadena);	
	coord_t coord = {atoi(strtok(copia,delim)),atoi(strtok(NULL,delim))};
	return coord;
}

bool es_humano(const char *nombre){
	return strstr(HUMANOS,nombre);
}
bool es_zombi(const char *nombre){
	return strstr(ZOMBIES,nombre);
}
bool es_vampiro(const char *nombre){
	return strstr(VAMPIROS,nombre);
}
bool es_agua(const char *nombre){
	return !strcmpi(nombre,"agua");
}
bool es_bala(const char *nombre){
	return !strcmpi(nombre,"bala");
}
bool es_estaca(const char *nombre){
    return !strcmpi(nombre,"estaca");
}
bool es_escopeta(const char *nombre){
	return !strcmpi(nombre,"escopeta");
}
bool es_cruz(const char *nombre){
	return !strcmpi(nombre,"cruz");
}
bool es_cazador(const char *nombre){
	return !strcmpi(nombre,CAZADOR);
}

bool esta_Norte(coord_t coordenada){
    return coordenada.y>=LIMITES_NORTE[0] && coordenada.y<=LIMITES_NORTE[1];
}
bool esta_Sur(coord_t coordenada){
    return coordenada.y>=LIMITES_SUR[0] && coordenada.y<=LIMITES_SUR[1];
}
bool esta_Oeste(coord_t coordenada){
    return coordenada.x>=LIMITES_OESTE[0] && coordenada.x<=LIMITES_OESTE[1];
}
bool esta_Este(coord_t coordenada){
    return coordenada.x>=LIMITES_ESTE[0] && coordenada.x<=LIMITES_ESTE[1];
}

void cargar_cuadrante(char cuadrante[],coord_t coordenada){
	const char *info=" \0";
    info = esta_Norte(coordenada) && esta_Oeste(coordenada)? "NO":info;
    info = esta_Norte(coordenada) && esta_Este(coordenada) ? "NE":info;
    info = esta_Sur(coordenada)   && esta_Oeste(coordenada)? "SO":info;
    info = esta_Sur(coordenada)   && esta_Este(coordenada) ? "SE":info;
    strcpy(cuadrante,info);
}

void cargar_coordenada(coord_t &destino,coord_t origen){
	destino.x=origen.x;
	destino.y=origen.y;
}

void cargar_posicion(coord_t &destino,char cuadrante_destino[],coord_t origen,char cuadrante_origen[]){
	cargar_coordenada(destino,origen);
	strcpy(cuadrante_destino,cuadrante_origen);
}

void cargar_humano(const char info[],objeto_t objeto,humano_t &humano){
	humano.cazador=es_cazador(info);
	strcpy(humano.nombre,objeto.nombre);
	cargar_posicion(humano.coordenada,humano.cuadrante,objeto.coordenada,objeto.cuadrante);	
}
void cargar_zombie(objeto_t objeto,zombi_t &zombie){
	cargar_posicion(zombie.coordenada,zombie.cuadrante,objeto.coordenada,objeto.cuadrante);
}
void cargar_vampiro(objeto_t objeto,vampiro_t &vampiro){
	strcpy(vampiro.nombre,objeto.nombre);
	cargar_posicion(vampiro.coordenada,vampiro.cuadrante,objeto.coordenada,objeto.cuadrante);
}
void cargar_agua(const char info[],objeto_t objeto,agua_t &agua){
	agua.dosis=atoi(info);
	cargar_posicion(agua.coordenada,agua.cuadrante,objeto.coordenada,objeto.cuadrante);
}
void cargar_bala(const char info[],objeto_t objeto,bala_t &bala){
	bala.cantidad=atoi(info);
	cargar_posicion(bala.coordenada,bala.cuadrante,objeto.coordenada,objeto.cuadrante);
}
void cargar_estaca(objeto_t objeto,estaca_t &estaca){
	cargar_posicion(estaca.coordenada,estaca.cuadrante,objeto.coordenada,objeto.cuadrante);
}
void cargar_escopeta(objeto_t objeto,escopeta_t &escopeta){
	cargar_posicion(escopeta.coordenada,escopeta.cuadrante,objeto.coordenada,objeto.cuadrante);
}
void cargar_cruz(objeto_t objeto,cruz_t &cruz){
	cargar_posicion(cruz.coordenada,cruz.cuadrante,objeto.coordenada,objeto.cuadrante);
}

#endif
