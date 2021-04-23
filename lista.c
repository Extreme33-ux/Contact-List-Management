/*
 * File: lista.c
 * Author: Miguel Nunes Goncalves   
 * IST Number: 94238
 * Description: Code file that contains the definition of
 				functions declared previously in "lista.h".

*/

#include "lista.h"
#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Function that creates an initialized structure "Lista", and returns it. */

Lista* cria_lista(){

	Lista * l = malloc(sizeof(Lista));
	l->cabeca = l->fim = NULL;
	return l;
}

/* Function that adds a contact to the list of contacts. If the name is already present
   in the list, then it will display a message error, and won't add it to the list.
   Otherwise, it will create a structure "Contacto" with the given info, and "add" it to
   the list. Returns the "Contacto" structure. */

Contacto* adiciona_contacto(Lista* l,char* n){

	char *name;
	char *loc;
	char *domain;
	char *num;
	Contacto * novo = malloc(sizeof(Contacto));

	name = strtok(n," ");
	loc = strtok(NULL,"@");
	domain = strtok(NULL," ");
	num = strtok(NULL,"\n");

	if (procura_nome(name)){
		printf("Nome existente.\n");
		free(novo);
		return NULL;
	}

	novo->anterior = l->fim;
	novo->seguinte = NULL;
	novo->nome = malloc(sizeof(char)*(strlen(name)+1));
	novo->local = malloc(sizeof(char)*(strlen(loc)+1));
	novo->dominio = malloc(sizeof(char)*(strlen(domain)+1));
	novo->numero = malloc(sizeof(char)*(strlen(num)+1));
	novo->conjugue = malloc(sizeof(char));
	strcpy(novo->nome, name);
	strcpy(novo->local, loc);
	strcpy(novo->dominio, domain);
	strcpy(novo->numero, num);
	if(l->fim) l->fim->seguinte=novo;
	l->fim = novo;
	if (!(l->cabeca)) l->cabeca = novo;
	return novo;
}


/* Function that erases a "Contacto", given its name. If the name isn't present
 on any contact, it will display a message error, and won't erase anything.
   Otherwise, the "Contacto" will dissapear from the list. Returns the "Contacto". */

Contacto* apaga_contacto_lista(Lista * l,const char* name){

	if (!(procura_nome(name))){
		printf("Nome inexistente.\n");
		return NULL;
	}

	else{

		Contacto * t = procura_nome(name);

		if (t->anterior == NULL)
			l->cabeca = t->seguinte;
		else
			t->anterior->seguinte=t->seguinte;

		if(t->seguinte==NULL)
			l->fim = t->anterior;
		else
			t->seguinte->anterior = t->anterior;

	return t;
	}		
}

/* Function that frees the entire memory of "Lista", including the "Contactos"
   inside of it */

void liberta_lista(Lista* l){

	while(l->cabeca)  {
		Contacto* tmp = l->cabeca->seguinte;
		liberta_contacto(l->cabeca);
		l->cabeca = tmp;
	}
	free(l);
	return;
}

/* Function that frees the memory occupied by  a "Contacto". */
void liberta_contacto(Contacto* n){

	free(n->nome);
	free(n->local);
	free(n->dominio);
	free(n->numero);
	free(n->conjugue);
	free(n);
	return;
}

/*Function  that prints every "Contacto" in the list, in the order that they were
 introduced to it. */

void todos_contactos(Lista * l){

	Contacto * n;

	for (n = l->cabeca; n; n=n->seguinte)
		printf("%s %s@%s %s %s\n", n->nome, n->local, n->dominio, n->numero, n->conjugue);

	return;
}

/* Function that counts the number of occurrences of a given domain in the list. */
void conta_ocorrencias_dominio(Lista* l, const https://discord.gg/Wpn5ACchar* dominio){

	int x = 0;
	Contacto * n;

	for(n = l->cabeca; n; n=n->seguinte)
		if (strcmp(n->dominio,dominio)==0)
			x++;
	printf("%s:%d\n",dominio,x);
	return;
}


void conta_prefixos_tel(Lista* l,const char *n){

	Contacto * var;
	int x=0;
	int y = strlen(n);
	int k;

	for(var= l->cabeca; var; var=var->seguinte){
		for (k=0;k<y;k++){
			if (var->numero[k]==n[k])
				if(var->numero)
				x++;	
			}
		}
	printf("%d\n", x);
}

void adiciona_conjugue(char *n){

	char *n1;
	char *n2;
	Contacto * n11;
	Contacto * n22;

	n1 = strtok(n," ");
	n2 = strtok(NULL,"\n");

	n11 = procura_nome(n1);
	n22 = procura_nome(n2);

	n22->conjugue = realloc(n22->conjugue,sizeof(char)*(strlen(n1)+1));
	n11->conjugue = realloc(n11->conjugue,sizeof(char)*(strlen(n2)+1));
	strcpy(n22->conjugue,n1);
	strcpy(n11->conjugue,n2);

	return;

}

