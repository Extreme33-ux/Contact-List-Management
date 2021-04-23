/*
 * File: lista.h
 * Author: Miguel Nunes Goncalves
 * IST Number: 94238
 * Description: Header file that contains declaractions of 
                structures "Contacto" and "Lista", and also
                prototypes of functions used, which are related 
                to those structures.
*/


#ifndef LISTA_H
#define LISTA_H


/* Definition of a "Contacto" structure, which contais the information
   about a person's contacts(Name, Email and Number), a pointer to the next "Contacto",
   and a pointer the previous "Contacto". These pointers are used to mantain order in
   the list used. */

typedef struct contacto {
	char *nome;
	char *local;
	char *dominio;
	char *numero;
	char *conjugue;
	struct contacto *seguinte, *anterior;
}Contacto;


/* Definition of a "Lista" structure, which contains pointers to first 
"Contacto" that has been introduced, aswell as the last "Contacto". */

typedef struct lista {
	Contacto *cabeca, *fim;
}Lista;

/* String that contains a character, which choose which operation to perform. */
char *comando;

/* String that contains the info needed to perform a given operation. */
char *EntryData;


/* Declaration of functions used with these structures*/

Lista* cria_lista();
void liberta_lista(Lista* l);
void liberta_contacto(Contacto* n);
Contacto* adiciona_contacto(Lista* l,char *n);
void todos_contactos(Lista * l);
void conta_ocorrencias_dominio(Lista* l, const char* dominio);
Contacto* apaga_contacto_lista(Lista* l, const char* name);
void conta_prefixos_tel(Lista* l, const char *n);
void adiciona_conjugue(char *n);


#endif