#ifndef MANIPULACION_DATOS_H
#define MANIPULACION_DATOS_H

#include "elementos.h"

const int MAX_DATOS = 100;

typedef struct datos{
	humano_t *humanos;
	zombi_t *zombis;
	vampiro_t *vampiros;
	agua_t *aguas;
	cruz_t *cruces;
	estaca_t *estacas;
	escopeta_t *escopetas;
	bala_t *balas;
	int cantidad_humanos;
	int cantidad_vampiros;
	int cantidad_zombies;
	int cantidad_aguas;
	int cantidad_cruces;
	int cantidad_estacas;
	int cantidad_escopetas;
	int cantidad_balas;
}datos_t;


void inicializar_datos(datos_t *datos);
void eliminar_arrays(datos_t *datos);
bool cargar_datos_fichero(datos_t *datos,char *nombre_fichero);
int obtener_total_agua(datos_t datos);
int obtener_total_balas(datos_t datos);

bool buscar_agua(datos_t datos,string cuadrante);
bool buscar_bala(datos_t datos,string cuadrante);
bool buscar_cruz(datos_t datos,string cuadrante);
bool buscar_estaca(datos_t datos,string cuadrante);
bool buscar_escopeta(datos_t datos,string cuadrante);
bool buscar_zombie(datos_t datos,string cuadrante);
bool buscar_humano(datos_t datos,string cuadrante,const char *humano);
bool buscar_vampiro(datos_t datos,string cuadrante,const char *vampiro);


#endif

