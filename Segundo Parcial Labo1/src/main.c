/*
 ============================================================================
 Name        : Segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pokemon.h"
#include "Utn.h"
#include "Menus.h"

#define REALIZADO 1
#define NO_REALIZADO 0

int main(void)
{
	setbuf(stdout,NULL);
	char confirmar[4];
	int flagTxt = NO_REALIZADO;

	LinkedList* listaPokemones = ll_newLinkedList();

	do{
		switch(Menu())
		{
			case 1:
				if(ll_isEmpty(listaPokemones) || (flagTxt==NO_REALIZADO))
				{
					if(!controller_loadFromText("C:\\Users\\Usuario\\Desktop\\Workspace\\Segundo Parcial Labo1\\src\\Data_Pokemones.csv", listaPokemones))
					{
						flagTxt=REALIZADO;
					}else
					{
						flagTxt=NO_REALIZADO;
					}
				}else
				{
					printf("No puedes cargar el archivo dos veces");
				}
				system("pause");
			break;
			case 2:
				if(!ll_isEmpty(listaPokemones))
				{
					controller_removePokemons(listaPokemones);
				}else
				{
					printf("No hay pokemones para dar de baja");
				}
			break;
			case 3:
				if(!ll_isEmpty(listaPokemones))
				{
					controller_ListPokemons(listaPokemones);
				}else
				{
					printf("No hay pokemones para mostrar");
				}
				system("pause");
			break;
			case 4:
				if(!ll_isEmpty(listaPokemones))
				{
					controller_filterAgua(listaPokemones);
				}else
				{
					printf("No hay pokemones para filtrar");
				}
				system("pause");
			break;
			case 5:
				if(!ll_isEmpty(listaPokemones))
				{
					controller_mapeo(listaPokemones);
				}else
				{
					printf("No hay pokemones para mapear");
				}
				system("pause");
			break;
			case 6:
				if(!ll_isEmpty(listaPokemones))
				{
					controller_mapeoEventoKanto(listaPokemones);
				}else
				{
					printf("No hay pokemones para mapear");
				}
				system("pause");
			break;
			case 7:
				if(!ll_isEmpty(listaPokemones))
				{
					controller_batallaPokemon(listaPokemones);
				}else
				{
					printf("No hay pokemones para batallar");
				}
				system("pause");
			break;
		}
	}while(stricmp(confirmar,"si"));
	return 0;
}
