#include <stdio.h>
#include "book.h"
#include <string.h>

int main(void){
	//definimos las variables de tipo tBook
	tBook book1, book2, best;
	printf("INPUT\n");
	// pasamos a las acciones las direcciones en memoria de las variables
	readBook(&book1);
	readBook(&book2);
	compareBooks(&book1, &book2, &best);
	// si son comparables, imprimimos la mejor (tambien pasando su direccion en memoria)
	if (strcmp(book1.title, book2.title) == 0){
		mostValuableBook(&best);
	}
	return 0;
}
