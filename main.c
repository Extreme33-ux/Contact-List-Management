/*
 * File: main.c
 * Author: Miguel Nunes Goncalves   
 * IST Number: 94238
 * Description: Code file that contains the main function, which
 				allows the management of a list of contacts.

*/

#include <stdio.h>
#include <string.h>
#include "lista.h" 
#include "hashtable.h"

/* Creates a list and an hashtable.Then, reads input from stdin,
   and decides which operation to do according to the first character 
   of the input. Input will still be asked until it receives an 'x' 
   to terminate the program. When the program is terminated, the list
    and the hashtable are freed. */

int main(){

char frase[1650];

	Lista * ls = cria_lista();
	cria_tabela();
	fgets(frase,1650,stdin);
	comando = strtok(frase, " ");
	EntryData = strtok(NULL,"\n");

	while (*comando){

		switch(*comando){

			case 'a':
				adiciona_link(adiciona_contacto(ls, EntryData));
				break;
			case 'l':
				todos_contactos(ls);
				break;
			case 'p':
				procura_contacto(EntryData);
				break; 
			case 'r':
				apaga_link(apaga_contacto_lista(ls, EntryData));
				break;
			case 'e':
				altera_email(EntryData);
				break;
			case 'c':
				conta_ocorrencias_dominio(ls, EntryData);
				break;
			case'P':
				conta_prefixos_tel(ls,EntryData);
				break;
			case 'C':
				adiciona_conjugue(EntryData);
				break;
			case 'x':
				liberta_lista(ls);
				liberta_tabela();
				return 0;
			}

		fgets(frase,1650,stdin);
		comando = strtok(frase, " ");
		EntryData = strtok(NULL,"\n");
	}
	return 0;
}