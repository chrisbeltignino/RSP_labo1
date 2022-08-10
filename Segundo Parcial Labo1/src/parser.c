#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Pokemon.h"

/** \brief Parsea los datos los datos de los pokemones desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PokemonsFromText(FILE* pFile , LinkedList* pArrayListPokemons)
{
	int retorno = -1;
	char numero[128] = "";
	char nombre[128] = "";
	char tipo[128] = "";
	char tamanio[128] = "";
	char ataqueCargado[128] = "";
	char valorAtaque[128] = "";
	char esVariocolor[128] = "";
	int cantidad = 0;
	Pokemons* auxiliar = NULL;

	if(pFile!=NULL && pArrayListPokemons!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);

			if((cantidad == 7))
			{
				auxiliar = Pokemons_newParametros(numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVariocolor);
				if(auxiliar!=NULL)
				{
					ll_add(pArrayListPokemons, auxiliar);
					retorno = 0;
				}else
				{
					Pokemons_delete(auxiliar);
				}
			}
		}
		while(!feof(pFile));
	}

	return retorno;
}

