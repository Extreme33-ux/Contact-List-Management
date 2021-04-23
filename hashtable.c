/*
 * File: hashtable.c
 * Author: Miguel NUnes Goncalves   
 *IST Number: 94238
 * Description: Code file that contains the definition of
 				functions declared previously in "hashtable.h".
*/


#include "hashtable.h"
#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* The size for the hashtable */
static int M=997;

/* Declaration of an Array of "Links" */
static Link ** tabela;


/* Function that allows the creation of an hashtable, initialized. */
void cria_tabela(){

	int x;

	tabela = malloc(M*sizeof(Link));
	for(x=0; x<M; x++)
		tabela[x] = NULL;

}

/* Function that receives a name of a person, and hashes it. Returns an integer,
   corresponding to the hash of the name. */
int hash(const char* name){

	int h=0, a = 107;

	for(; *name !='\0';name++)
		h = (a*h + *name) % M;
	return h;
}

/* Function that receives a contact, and adds it to the Hashtable. */
void adiciona_link(Contacto * cont){

	if (cont == NULL){
		return;
	}
	else{
		int h = hash(cont->nome);
		Link * head= tabela[h];
		Link * novo1 = malloc(sizeof(Link));

		novo1->contacto = cont;
		novo1->next = head;
		tabela[h] = novo1;
	}
}

/* Function that frees all the links on a given index of the hashtable. */
void liberta_conjunto_links(Link * head){

	while(head){
		Link * tmp = head->next;
		free(head);
		head = tmp;
	}
}

/* Function that frees the hashtable. Before freeing itself, it frees all the links. */

void liberta_tabela(){

	int i;

	for (i=0; i<M; i++){

		liberta_conjunto_links(tabela[i]);
	}
	free(tabela);
	return;
}

/* Function that receives a name of a person, and searches the contact in the
   hashtable, If it is found, the contact is returned. Otherwise, returns NULL.*/

Contacto* procura_nome(const char* name){

	Link *tmp = tabela[hash(name)];

	for (;tmp !=NULL; tmp=tmp->next)
		if (strcmp(tmp->contacto->nome, name)==0)
			return tmp->contacto;
	return NULL;
}

/* Function that receives a name of a person, and checks for its existance. 
   If it exists, it prints the info about the person. Otherwise, returns an
   error message. */

void procura_contacto(const char* name){

	if (!(procura_nome(name))){
		printf("Nome inexistente.\n");
		return;
	}

	else{
		Contacto * t = procura_nome(name);
		printf("%s %s@%s %s\n", t->nome, t->local, t->dominio, t->numero);
		return;
	}
}

/* Function that receives a contact, and frees the Link with the pointer
   to that contact on the hashtable. Also frees the contact. */
void apaga_link(Contacto * cont){

	if (cont == NULL){
		return;
		}
https://discord.gg/Wpn5AC
	else{

		Link *tmp, *prev;
		Link *head = tabela[hash(cont->nome)];
		Contacto * conjug = procura_nome(cont->conjugue);

		for(tmp = head, prev= NULL; tmp != NULL;prev= tmp, tmp = tmp->next) {
			if(strcmp(tmp->contacto->nome, cont->nome) == 0) {
				if(tmp == head){
					tabela[hash(cont->nome)] = tmp->next;
					liberta_contacto(cont);
					free(tmp);
					conjug->conjugue = realloc(conjug->conjugue,sizeof(char)*(strlen("")+1));
					strcpy(conjug->conjugue, "");
					return;
					}
				else{
					prev->next = tmp->next;
					liberta_contacto(cont);
					free(tmp);
					conjug->conjugue = realloc(conjug->conjugue,sizeof(char)*(strlen("")+1));
					strcpy(conjug->conjugue, "");
					return;
					}
				}
			}
		}		
}

/* Function that receives a name of a person and the email to be changed to.
   Checks if the person is on the Hashtable. If so, changes the email.
   Otherwise, returns a message error. */
void altera_email(char* n){

	char *name;
	char *loc;
	char *domain;

	name = strtok(n," ");
	loc = strtok(NULL,"@");
	domain = strtok(NULL,"\n");

	if (!(procura_nome(name))){
		printf("Nome inexistente.\n");
		return;
	}
	else{
		Contacto* t= procura_nome(name);

		t->local = realloc(t->local,sizeof(char)*(strlen(loc)+1));
		t->dominio = realloc(t->dominio,sizeof(char)*(strlen(domain)+1));
		strcpy(t->local, loc);
		strcpy(t->dominio, domain);

		return;
	}
}