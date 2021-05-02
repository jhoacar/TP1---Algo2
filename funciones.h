#ifndef FUNCIONES_H   
#define FUNCIONES_H

#include <string>

#include "manipulacion_datos.h"

const char* CUADRANTES = "NO no NE ne SO so SE se";
const char* RESPUESTAS = "Y YES Yes yes SI Si si";
enum {AGUA=1,BALA,CRUZ,ESTACA,ESCOPETA,HUMANO,HUMANO_CAZADOR,VANESA,VAMPIRO,VAMPIRELLA,NOSFERATU,ZOMBIE};

string obtener_texto(string nombre_fichero);
size_t obtener_cant_division(const char info[],const char *delim);
void dividir(const char texto[],const char *delim,const size_t cantidad,char divisiones[][MAX_DATOS]);


void mostrar_menu(const datos_t datos);
void mostrar_coordenada(coord_t coordenada);
void mostrar_resumen(const datos_t datos);
void mostrar_datos(const datos_t datos);


#endif
