/*
 * procesar_archivos.h
 *
 *  Created on: 28 ago. 2021
 *      Author: utnso
 */

#ifndef PROCESAR_ARCHIVOS_H_
#define PROCESAR_ARCHIVOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/collections/list.h>
#include <commons/string.h>
#include "persona.h"
#include "string_utils.h"

void procesar_archivos(FILE* archivoEntrada, FILE* archivoSalida);

t_list* leer_archivo_entrada(FILE* archivo);

#endif /* PROCESAR_ARCHIVOS_H_ */
