/*
 * File: hashtable.h
 * Author: Miguel Nunes Goncalves   
 * IST Number: 94238
 * Description: Header file that contains declaractions of 
                structure "Link", and also prototypes of functions 
                used, which are related to that structure and also 
                the structure "Contacto", defined in "lista.h".
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "lista.h"

/* Definition of a "Link" structure, which contains a pointer to a
   structure "Contacto", and a pointer to the next "Link". This will
   be a node of an hashtable, */
typedef struct link{
	
	Contacto * contacto;
	struct link * next;
}Link;


/* Declaration of functions used with this structure, aswell as the structure "Contacto.*/

void cria_tabela();
void liberta_conjunto_links(Link * head);
void liberta_tabela();
void adiciona_link(Contacto * cont);
int hash(const char* name);
Contacto* procura_nome(const char* name);
void procura_contacto(const char* name);
void apaga_link(Contacto * cont);
void altera_email(char* n);

#endif