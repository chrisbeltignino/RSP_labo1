/*
 * Pokemon.h
 *
 *  Created on: 1 jul. 2022
 *      Author: 54115
 */

#ifndef POKEMON_H_
#define POKEMON_H_

typedef struct
{
	int numero;
	char nombre[128];
	char tipo[128];
	char tamanio[128];
	char ataqueCargado[128];
	int valorAtaque;
	int esVariocolor;
}Pokemons;

Pokemons* Pokemons_new();
Pokemons* Pokemons_newParametros(char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,char* valorAtaqueStr,char* esVariocolorStr);

int Pokemons_setVerifyChar(Pokemons* this, char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,char* valorAtaqueStr,char* esVariocolorStr);
int Pokemons_getVerify(Pokemons* this, int* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,int* valorAtaqueStr,int* esVariocolorStr);
int Pokemons_findNumero(LinkedList* listaPokemons, int numero);
int Pokemons_remove(LinkedList* listaPokemons);
int Pokemons_printOnePokemons(Pokemons* this);
int Pokemons_printList(LinkedList* listaPokemons);
void Pokemons_delete(Pokemons* this);
int Pokemons_filterAgua(void* Pokemon);
void* Pokemons_mapeoPokemones(void* Pokemon);
void* Pokemons_mapeoPokemonesEventoKanto(void* Pokemon);
int Pokemons_Batalla(void* Pokemon);

int Pokemons_getNumero(Pokemons* this,int* numero);
int Pokemons_getNombre(Pokemons* this, char* nombre);
int Pokemons_getTipo(Pokemons* this, char* tipo);
int Pokemons_getTamanio(Pokemons* this, char* tamanio);
int Pokemons_getAtaqueCargado(Pokemons* this, char* ataqueCargado);
int Pokemons_getValorAtaque(Pokemons* this, int* valorAtaque);
int Pokemons_getEsVariocolor(Pokemons* this, int* esVariocolor);

int Pokemons_setNumero(Pokemons* this, int numero);
int Pokemons_setNombre(Pokemons* this, char* nombre);
int Pokemons_setTipo(Pokemons* this, char* tipo);
int Pokemons_setTamanio(Pokemons* this, char* tamanio);
int Pokemons_setAtaqueCargado(Pokemons* this, char* ataqueCargado);
int Pokemons_setValorAtaque(Pokemons* this, int valorAtaque);
int Pokemons_setEsVariocolor(Pokemons* this, int esVariocolor);

#endif /* POKEMON_H_ */
