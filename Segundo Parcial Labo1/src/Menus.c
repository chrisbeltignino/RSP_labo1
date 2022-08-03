#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
#include "Utn.h"

int Menu()
{
	int opciones;
	pedirEntero(&opciones,
				"------------------------------------>-MENU-<------------------------------------\n"
				"1. Cargar los datos de los Pokemones desde el archivo data.csv (modo texto).\n"
				"2. Baja de Pokemones\n"
				"3. Listar Pokemones\n"
				"4. Filtrar de tipo Agua variocolor\n"
				"5. Mapear con dia despejado\n"
				"6. Mapear evento Kanto\n"
				"7. Batalla Pokemon\n"
				"8. Salir\n"
				"--------------------------------------------------------------------------------\n"
				"Ingrese una opcion: ",
				"--------------------------------------------------------------------------------\n"
				"1. Cargar los datos de los Pokemones desde el archivo data.csv (modo texto).\n"
				"2. Baja de Pokemones\n"
				"3. Listar Pokemones\n"
				"4. Filtrar de tipo Agua variocolor\n"
				"5. Mapear con dia despejado\n"
				"6. Mapear evento Kanto\n"
				"7. Batalla Pokemon\n"
				"8. Salir\n"
				"--------------------------------------------------------------------------------\n"
				"Error, opcion invalida: ",1,8);

	return opciones;
}
