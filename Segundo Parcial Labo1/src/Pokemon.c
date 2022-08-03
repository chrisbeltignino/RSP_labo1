#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Pokemon.h"
#include "Utn.h"


Pokemons* Pokemons_new()
{
	Pokemons* this = (Pokemons*) malloc(sizeof(Pokemons)*1);

    if(this != NULL)
    {
        this->numero = 0;
        strcpy(this->nombre, "");
        strcpy(this->tipo, "");
        strcpy(this->tamanio, "");
        strcpy(this->ataqueCargado, "");
        this->valorAtaque = 0;
        this->esVariocolor = 0;
    }
    return this;
}

Pokemons* Pokemons_newParametros(char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,char* valorAtaqueStr,char* esVariocolorStr)
{
	Pokemons* PokemonsParam = NULL;

	if(numeroStr!=NULL && nombreStr!=NULL && tipoStr!=NULL && tamanioStr!=NULL && ataqueCargadoStr!=NULL && valorAtaqueStr!=NULL && esVariocolorStr!=NULL)
	{
		PokemonsParam = Pokemons_new();

		if(PokemonsParam!=NULL)
		{
			if((Pokemons_setVerifyChar(PokemonsParam,numeroStr,nombreStr,tipoStr,tamanioStr,ataqueCargadoStr,valorAtaqueStr,esVariocolorStr))!=0)
			{
				Pokemons_delete(PokemonsParam);
			}
		}
	}

	return PokemonsParam;
}

int Pokemons_remove(LinkedList* listaPokemons)
{
	int retorno = -1;
	int id;
	int len;
	int index = -1;
	char respuesta[4];
	Pokemons* aux = NULL;

	if(listaPokemons!=NULL)
	{
		len = ll_len(listaPokemons);
		Pokemons_printList(listaPokemons);
		utn_getInt("Ingrese el Numero para dar de baja: \n","Error, Numero invalido\n",1,len,3,&id);
		index = Pokemons_findNumero(listaPokemons,id);

		if(index!=-1)
		{
			aux = ll_get(listaPokemons,index);
			Pokemons_printOnePokemons(aux);
			utn_getString("\n¿Esta seguro que desea eliminar este pokemon?[si/no]\n","\nRespuesta invalida, ingrese [si/no]\n",4,3,respuesta);

			if(!(stricmp(respuesta,"si")))
			{
				ll_remove(listaPokemons,index);
				printf("Baja realizada con exito\n");
			}else
			{
				printf("Baja cancelada\n");
			}
		}else
		{
			printf("No se pudo encontrar el Numero\n");
		}
	}

	return retorno;
}

int Pokemons_findNumero(LinkedList* listaPokemons, int numero)
{
	int i;
	int len;
	int index;
	Pokemons* auxiliar;

	if(listaPokemons!=NULL)
	{
		len = ll_len(listaPokemons);

		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (Pokemons*)ll_get(listaPokemons,i);
				if(auxiliar->numero==numero)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}

int Pokemons_printOnePokemons(Pokemons* this)
{
	int retorno = -1;
	int auxNumero;
	char auxNombre[128];
	char auxTipo[128];
	char auxTamanio[128];
	char auxAtaqueCargado[128];
	int auxValorAtaque;
	int auxEsVariocolor;

	if(this!=NULL)
	{
		if(!Pokemons_getVerify(this,&auxNumero,auxNombre,auxTipo,auxTamanio,auxAtaqueCargado,&auxValorAtaque,&auxEsVariocolor))
		{
			printf("%-10d %-15s %-15s %-15s %-20s %-15d %d\n",auxNumero
															,auxNombre
															,auxTipo
															,auxTamanio
															,auxAtaqueCargado
															,auxValorAtaque
															,auxEsVariocolor);
			retorno = 0;
		}else
		{
			printf("Error para mostrar el Pokemones");
		}
	}
	return retorno;
}

int Pokemons_printList(LinkedList* listaPokemons)
{
	int retorno = -1;
	int len;
	Pokemons* aux;

	if(listaPokemons!=NULL)
	{
		len = ll_len(listaPokemons);

		if(len>0)
		{
			printf("%-10s %-15s %-15s %-15s %-15s %-10s %-10s\n",
				      "Numero",    "Nombre",      "Tipo",     "Tamanio",  "Ataque Cargado"  ,  "Valor de Ataque"  ,  "esVariocolor");

			for(int i=0; i<len ;i++)
			{
				aux = (Pokemons*) ll_get(listaPokemons,i);

				if(aux != NULL)
				{
					Pokemons_printOnePokemons(aux);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

int Pokemons_getVerify(Pokemons* this, int* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,int* valorAtaqueStr,int* esVariocolorStr)
{
	int retorno = -1;

	if(this!=NULL && numeroStr!=NULL && nombreStr!=NULL && tipoStr!=NULL && tamanioStr!=NULL && ataqueCargadoStr!=NULL && valorAtaqueStr!=NULL && esVariocolorStr!=NULL)
	{
		if((!(Pokemons_getNumero(this,numeroStr)) &&
			!(Pokemons_getNombre(this,nombreStr)) &&
			!(Pokemons_getTipo(this,tipoStr)) &&
			!(Pokemons_getTamanio(this,tamanioStr)) &&
			!(Pokemons_getAtaqueCargado(this,ataqueCargadoStr)) &&
			!(Pokemons_getValorAtaque(this,valorAtaqueStr)) &&
			!(Pokemons_getEsVariocolor(this,esVariocolorStr))))
		{
			retorno = 0;
		}
	}

	return retorno;
}
/*
int Pokemons_setVerifyInt(Pokemons* this, int numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,int valorAtaqueStr,int esVariocolorStr)
{
	int retorno = -1;

	if(this!=NULL && numeroStr!=NULL && nombreStr!=NULL && tipoStr!=NULL && tamanioStr!=NULL && ataqueCargadoStr!=NULL && valorAtaqueStr!=NULL && esVariocolorStr!=NULL)
	{
		if((!(Pokemons_setNumero(this,numeroStr)) &&
			!(Pokemons_setNombre(this,nombreStr)) &&
			!(Pokemons_setTipo(this,tipoStr)) &&
			!(Pokemons_setTamanio(this,tamanioStr)) &&
			!(Pokemons_setAtaqueCargado(this,ataqueCargadoStr)) &&
			!(Pokemons_setValorAtaque(this,valorAtaqueStr))  &&
			!(Pokemons_setEsVariocolor(this,esVariocolorStr))))
		{

			retorno = 0;
		}
	}

	return retorno;
}
*/
int Pokemons_getNumero(Pokemons* this,int* numero)
{
	int isOk = -1;

	if(this!=NULL && numero!=NULL)
	{
		*numero = this->numero;
		isOk=0;
	}

	return isOk;
}

int Pokemons_getNombre(Pokemons* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		isOk=0;
	}

	return isOk;
}

int Pokemons_getTipo(Pokemons* this, char* tipo)
{
	int isOk = -1;

	if(this!=NULL && tipo!=NULL)
	{
		strcpy(tipo,this->tipo);
		isOk=0;
	}

	return isOk;
}

int Pokemons_getTamanio(Pokemons* this, char* tamanio)
{
	int isOk = -1;

	if(this!=NULL && tamanio!=NULL)
	{
		strcpy(tamanio,this->tamanio);
		isOk=0;
	}

	return isOk;
}

int Pokemons_getAtaqueCargado(Pokemons* this, char* ataqueCargado)
{
	int isOk = -1;

	if(this!=NULL && ataqueCargado!=NULL)
	{
		strcpy(ataqueCargado,this->ataqueCargado);
		isOk=0;
	}

	return isOk;
}

int Pokemons_getValorAtaque(Pokemons* this, int* valorAtaque)
{
	int isOk = -1;

	if(this!=NULL && valorAtaque>0)
	{
		*valorAtaque = this->valorAtaque;
		isOk=0;
	}

	return isOk;
}

int Pokemons_getEsVariocolor(Pokemons* this, int* esVariocolor)
{
	int isOk = -1;

	if(this!=NULL && esVariocolor>=0)
	{
		*esVariocolor = this->esVariocolor;
		isOk=0;
	}

	return isOk;
}

int Pokemons_setVerifyChar(Pokemons* this, char* numeroStr,char* nombreStr,char* tipoStr,char* tamanioStr,char* ataqueCargadoStr,char* valorAtaqueStr,char* esVariocolorStr)
{
	int retorno = -1;

	if((!(Pokemons_setNumero(this,atoi(numeroStr))) &&
		!(Pokemons_setNombre(this,nombreStr)) &&
		!(Pokemons_setTipo(this,tipoStr)) &&
		!(Pokemons_setTamanio(this,tamanioStr)) &&
		!(Pokemons_setAtaqueCargado(this,ataqueCargadoStr)) &&
		!(Pokemons_setValorAtaque(this,atoi(valorAtaqueStr)))  &&
		!(Pokemons_setEsVariocolor(this,atoi(esVariocolorStr)))))
	{

		retorno = 0;
	}

	return retorno;
}

int Pokemons_setNumero(Pokemons* this, int numero)
{
	int isOk = -1;

	if(this!=NULL && numero > 0)
	{
		this->numero = numero;
		isOk=0;
	}

	return isOk;
}

int Pokemons_setNombre(Pokemons* this, char* nombre)
{
	int isOk = -1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		isOk=0;
	}

	return isOk;
}

int Pokemons_setTipo(Pokemons* this, char* tipo)
{
	int isOk = -1;

	if(this!=NULL && tipo!=NULL)
	{
		strcpy(this->tipo,tipo);
		isOk=0;
	}

	return isOk;
}

int Pokemons_setTamanio(Pokemons* this, char* tamanio)
{
	int isOk = -1;

	if(this!=NULL && tamanio!=NULL)
	{
		strcpy(this->tamanio,tamanio);
		isOk=0;
	}

	return isOk;
}

int Pokemons_setAtaqueCargado(Pokemons* this, char* ataqueCargado)
{
	int isOk = -1;

	if(this!=NULL && ataqueCargado!=NULL)
	{
		strcpy(this->ataqueCargado,ataqueCargado);
		isOk=0;
	}

	return isOk;
}

int Pokemons_setValorAtaque(Pokemons* this, int valorAtaque)
{
	int isOk = -1;

	if(this!=NULL && valorAtaque > 0)
	{
		this->valorAtaque = valorAtaque;
		isOk=0;
	}

	return isOk;
}

int Pokemons_setEsVariocolor(Pokemons* this, int esVariocolor)
{
	int isOk = -1;

	if(this!=NULL && esVariocolor >= 0)
	{
		this->esVariocolor = esVariocolor;
		isOk=0;
	}

	return isOk;
}

void Pokemons_delete(Pokemons* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int Pokemons_filterAgua(void* Pokemon)
{
    int retorno = 0;
    int esVariocolor;
    char tipo[100];

    Pokemons_getEsVariocolor(Pokemon, &esVariocolor);
    Pokemons_getTipo(Pokemon, tipo);

    if(strcmp(tipo, "Water") == 0 && esVariocolor == 1)
    {
    	retorno = 1;
    }

    return retorno;
}

void* Pokemons_mapeoPokemones(void* Pokemon)
{
	Pokemons* pElement = NULL;
	int auxAtaqueCargado;
	char auxTipo[50];
	int bufeo;

	if(Pokemon != NULL)
	{
		pElement = (Pokemons*) Pokemon;

		Pokemons_getValorAtaque(pElement, &auxAtaqueCargado);
		Pokemons_getTipo(pElement, auxTipo);

		if((strcmp(auxTipo, "Ground") == 0) || (strcmp(auxTipo, "Grass") == 0) || (strcmp(auxTipo, "Fire") == 0))
		{
			bufeo = auxAtaqueCargado * 0.10;
			auxAtaqueCargado = auxAtaqueCargado + bufeo;
			Pokemons_setValorAtaque(Pokemon, auxAtaqueCargado);
		}
	}
	return pElement;
}

/*
 *6) Mapear ataque cargado: Con motivo del evento Kanto, los pokemenos que
cumplan con las siguientes características incrementaron su poder:
Los pokemones de tipo Bug, Fire y Grass aumentarán su poder un 20%
siempre y cuando el tamaño sea XL, un 10% si es L y sino un 5 para cualquier otro
tamaño.
 **/
void* Pokemons_mapeoPokemonesEventoKanto(void* Pokemon)
{
	Pokemons* pElement = NULL;
	int auxAtaqueCargado;
	char auxTipo[50];
	char auxTamanio[50];
	int bufeo;

	if(Pokemon != NULL)
	{
		pElement = (Pokemons*) Pokemon;

		Pokemons_getValorAtaque(pElement, &auxAtaqueCargado);
		Pokemons_getTipo(pElement, auxTipo);
		Pokemons_getTamanio(pElement, auxTamanio);

		if(((strcmp(auxTipo, "Bug") == 0) || (strcmp(auxTipo, "Grass") == 0) || (strcmp(auxTipo, "Fire") == 0)) && (strcmp(auxTamanio, "XL") == 0))
		{
			bufeo = auxAtaqueCargado * 0.20;
			auxAtaqueCargado = auxAtaqueCargado + bufeo;
			Pokemons_setValorAtaque(Pokemon, auxAtaqueCargado);

			if((strcmp(auxTamanio, "L") == 0))
			{
				bufeo = auxAtaqueCargado * 0.10;
				auxAtaqueCargado = auxAtaqueCargado + bufeo;
				Pokemons_setValorAtaque(Pokemon, auxAtaqueCargado);
			}else{
				bufeo = auxAtaqueCargado * 0.5;
				auxAtaqueCargado = auxAtaqueCargado + bufeo;
				Pokemons_setValorAtaque(Pokemon, auxAtaqueCargado);
			}
		}
	}
	return pElement;
}

int Pokemons_Batalla(void* Pokemon)
{
	int retorno = -1;

	Pokemons* pElement = NULL;
	int auxValorCargado;
	char auxAtaqueCargado[50];
	char auxTipo[50];
	char auxTamanio[50];

	if(Pokemon != NULL)
	{
		pElement = (Pokemons*) Pokemon;

		Pokemons_getValorAtaque(pElement, &auxValorCargado);
		Pokemons_getAtaqueCargado(pElement, auxAtaqueCargado);
		Pokemons_getTipo(pElement, auxTipo);
		Pokemons_getTamanio(pElement, auxTamanio);

		if(((strcmp(auxTipo, "Fire") == 0) && (strcmp(auxAtaqueCargado, "Lanzallamas") == 0) && (strcmp(auxTamanio, "XL") == 0) && auxValorCargado > 80)
		|| ((strcmp(auxTipo, "Water") == 0) && (strcmp(auxAtaqueCargado, "Hidrobomba") == 0) && (strcmp(auxTamanio, "L") == 0) && auxValorCargado > 80))
		{
			retorno = 1;
		}else{
			retorno = 0;
		}

	}
	return retorno;
}
