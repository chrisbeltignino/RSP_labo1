#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Pokemon.h"
#include "parser.h"
#include "Menus.h"
#include "Utn.h"

/** \brief Leer archivo de texto
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPokemons)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListPokemons!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!=NULL)
		{
			if(!parser_PokemonsFromText(pArchivo, pArrayListPokemons))
			{
				printf("Se cargo con exito\n");
				retorno = 0;
			}
		}else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}
	return retorno;
}

/** \brief Baja de pokemones
 *
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePokemons(LinkedList* pArrayListPokemons)
{
	int retorno = -1;
	int opcion;
	int i=0;

	if(pArrayListPokemons!=NULL)
	{
		printf("BAJA DE POKEMONES\n");
		utn_getInt("\n¿Cuantos Pokemones desea dar de baja?: ","\nError, reingrese: ",1,10,3,&opcion);

		do
		{
			if(!Pokemons_remove(pArrayListPokemons))
			{
				retorno=0;
			}
			i++;
		}while(opcion!=i);
	}

    return retorno;
}

/** \brief Listar Pokemones
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPokemons(LinkedList* pArrayListPokemons)
{
	int retorno = -1;

	if(pArrayListPokemons!=NULL)
	{
		printf("LISTA DE POKEMONES\n");
		if(Pokemons_printList(pArrayListPokemons)!=0)
		{
			printf("No hay Pokemones para mostrar");
			retorno=0;
		}
	}

	return retorno;
}

/**
 * @fn int controller_filterAgua(LinkedList*)
 * @brief Filtrar pokemones por agua
 *
 * @param pArrayListPokemons
 * @return int
 */int controller_filterAgua(LinkedList* pArrayListPokemons)
{
    LinkedList* listaAux = ll_newLinkedList();
    int retorno = -1;

    if(pArrayListPokemons != NULL)
    {
    	printf("FILTRO DE POKEMONES DE AGUA\n");
    	listaAux = ll_filter(pArrayListPokemons, Pokemons_filterAgua);
    	controller_ListPokemons(listaAux);
    	retorno = 0;
    }

    return retorno;
}
/**
 * @fn int controller_mapeo(LinkedList*)
 * @brief Mapear valor de ataque en pokemones
 *
 * @param pArrayListPokemons
 * @return int
 */
int controller_mapeo(LinkedList* pArrayListPokemons)
{
    LinkedList* listaAux = ll_newLinkedList();
    int retorno = -1;

    if(pArrayListPokemons != NULL)
    {
    	printf("MAPEO DE POKEMONES\n");

		listaAux = ll_map(pArrayListPokemons, Pokemons_mapeoPokemones);
		controller_ListPokemons(listaAux);
		retorno = 0;
    }

    return retorno;
}

int controller_mapeoEventoKanto(LinkedList* pArrayListPokemons)
{
    LinkedList* listaAux = ll_newLinkedList();
    int retorno = -1;

    if(pArrayListPokemons != NULL)
    {
    	listaAux = ll_map(pArrayListPokemons, Pokemons_mapeoPokemonesEventoKanto);
		controller_ListPokemons(listaAux);
		retorno = 0;
    }

    return retorno;
}

int controller_batallaPokemon(LinkedList* pArrayListPokemons)
{
    int retorno;

    if(pArrayListPokemons != NULL)
    {
    	retorno = ll_count(pArrayListPokemons, Pokemons_Batalla);

    	printf("La cantidad de Pokemones que cumplen para batallar a Lugia, son: %d\n", retorno);

		if(retorno > 2)
		{
			printf("Muy bien!!!! Has ganado la batalla\n");
		}else{
			printf("Has perdido la batalla, la proxima sera mi rey\n");
		}
    }

    return retorno;
}
