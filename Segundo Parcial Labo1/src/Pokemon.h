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

/***
 * @fn Pokemons Pokemons_new*()
 * @brief Setea los valores de los elementos en 0 o "" (vacio)
 *
 * @return
 */
Pokemons* Pokemons_new();
/**
 * @fn Pokemons Pokemons_newParametros*(char*, char*, char*, char*, char*, char*, char*)
 * @brief
 *
 * @param numeroStr
 * @param nombreStr
 * @param tipoStr
 * @param tamanioStr
 * @param ataqueCargadoStr
 * @param valorAtaqueStr
 * @param esVariocolorStr
 * @return
 */
Pokemons* Pokemons_newParametros(char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,char* valorAtaqueStr,char* esVariocolorStr);

/**
 * @fn int Pokemons_setVerifyChar(Pokemons*, char*, char*, char*, char*, char*, char*, char*)
 * @brief
 *
 * @param this
 * @param numeroStr
 * @param nombreStr
 * @param tipoStr
 * @param tamanioStr
 * @param ataqueCargadoStr
 * @param valorAtaqueStr
 * @param esVariocolorStr
 * @return
 */
int Pokemons_setVerifyChar(Pokemons* this, char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,char* valorAtaqueStr,char* esVariocolorStr);
/**
 * @fn int Pokemons_getVerify(Pokemons*, int*, char*, char*, char*, char*, int*, int*)
 * @brief
 *
 * @param this
 * @param numeroStr
 * @param nombreStr
 * @param tipoStr
 * @param tamanioStr
 * @param ataqueCargadoStr
 * @param valorAtaqueStr
 * @param esVariocolorStr
 * @return
 */
int Pokemons_getVerify(Pokemons* this, int* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,int* valorAtaqueStr,int* esVariocolorStr);
/**
 * @fn int Pokemons_findNumero(LinkedList*, int)
 * @brief
 *
 * @param listaPokemons
 * @param numero
 * @return
 */
int Pokemons_findNumero(LinkedList* listaPokemons, int numero);
/**
 * @fn int Pokemons_remove(LinkedList*)
 * @brief
 *
 * @param listaPokemons
 * @return
 */int Pokemons_remove(LinkedList* listaPokemons);
/**
 * @fn int Pokemons_printOnePokemons(Pokemons*)
 * @brief
 *
 * @param this
 * @return
 */int Pokemons_printOnePokemons(Pokemons* this);
/**
 * @fn int Pokemons_printList(LinkedList*)
 * @brief
 *
 * @param listaPokemons
 * @return
 */int Pokemons_printList(LinkedList* listaPokemons);
/**
 * @fn void Pokemons_delete(Pokemons*)
 * @brief
 *
 * @param this
 */void Pokemons_delete(Pokemons* this);
/**
 * @fn int Pokemons_filterAgua(void*)
 * @brief
 *
 * @param Pokemon
 * @return
 */int Pokemons_filterAgua(void* Pokemon);
/**
 * @fn void Pokemons_mapeoPokemones*(void*)
 * @brief
 *
 * @param Pokemon
 */void* Pokemons_mapeoPokemones(void* Pokemon);
/**
 * @fn void Pokemons_mapeoPokemonesEventoKanto*(void*)
 * @brief
 *
 * @param Pokemon
 */void* Pokemons_mapeoPokemonesEventoKanto(void* Pokemon);
/**
 * @fn int Pokemons_Batalla(void*)
 * @brief
 *
 * @param Pokemon
 * @return
 */int Pokemons_Batalla(void* Pokemon);

/**
 * @fn int Pokemons_getNumero(Pokemons*, int*)
 * @brief
 *
 * @param this
 * @param numero
 * @return
 */int Pokemons_getNumero(Pokemons* this,int* numero);
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
