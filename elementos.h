#ifndef ELEMENTOS_H
#define ELEMENTOS_H

#include <string>
using namespace std;

const int MAX_NOMBRE = 50;
const int LIMITES_NORTE[2]  = {1,300};
const int LIMITES_SUR[2]    = {301,600};
const int LIMITES_ESTE[2]   = {501,1000};
const int LIMITES_OESTE[2]  = {1,500};
const char* CAZADOR 	= "CV";
const char* VAMPIROS 	= "Nosferatu Vampirella vampiro";
const char* HUMANOS 	= "humano Vanesa";
const char* ZOMBIES 	= "zombi zombies";

typedef struct coord{
	int x;
	int y;
}coord_t;

typedef struct Personaje{
	string nombre;
	coord_t coordenada;
	string cuadrante;
	string extra;
}personaje_t;

typedef struct objeto{
	char nombre[MAX_NOMBRE];
	coord_t coordenada;
	char cuadrante[3];
	char extra[MAX_NOMBRE];
}objeto_t;

typedef struct humano {
	char nombre[MAX_NOMBRE];
	coord_t coordenada;
	char cuadrante[3];
	bool cazador;
}humano_t;

typedef struct vampiro{
	char nombre[MAX_NOMBRE];
	coord_t coordenada;
	char cuadrante[3];
}vampiro_t;

typedef struct zombi{
	coord_t coordenada;
	char cuadrante[3];
}zombi_t;

typedef struct agua{
	coord_t coordenada;
	char cuadrante[3];
	int dosis;
}agua_t;

typedef struct cruz{
	coord_t coordenada;
	char cuadrante[3];
}cruz_t;

typedef struct estaca{
	coord_t coordenada;
	char cuadrante[3];
}estaca_t;

typedef struct escopeta{
	coord_t coordenada;
	char cuadrante[3];
}escopeta_t;

typedef struct bala{
	coord_t coordenada;
	char cuadrante[3];
	int cantidad;
}bala_t;

coord_t obtener_coordenadas(char cadena[],const char *delim);

void cargar_coordenada(coord_t &destino,coord_t origen);
void cargar_posicion(coord_t &destino,char cuadrante_destino[],coord_t origen,char cuadrante_origen[]);
void cargar_cuadrante(const char cuadrante[],coord_t coordenada);

bool es_humano(const char nombre[]);
bool es_zombi(const char nombre[]);
bool es_vampiro(const char nombre[]);
bool es_agua(const char nombre[]);
bool es_bala(const char nombre[]);
bool es_estaca(const char nombre[]);
bool es_escopeta(const char nombre[]);
bool es_cruz(const char nombre[]);
bool es_cazador(const char nombre[]);

bool esta_Norte(coord_t coordenada);
bool esta_Sur(coord_t coordenada);
bool esta_Oeste(coord_t coordenada);
bool esta_Este(coord_t coordenada);

void cargar_humano(const char info[],objeto_t objeto,humano_t &humano);
void cargar_zombie(objeto_t objeto,zombi_t &zombie);
void cargar_vampiro(objeto_t objeto,vampiro_t &vampiro);
void cargar_agua(const char info[],objeto_t objeto,agua_t &agua);
void cargar_bala(const char info[],objeto_t objeto,bala_t &bala);
void cargar_estaca(objeto_t objeto,estaca_t &estaca);
void cargar_escopeta(objeto_t objeto,escopeta_t &escopeta);
void cargar_cruz(objeto_t objeto,cruz_t &cruz);


#endif

