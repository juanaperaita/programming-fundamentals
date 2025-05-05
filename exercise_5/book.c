#include <stdio.h>
#include <string.h>
#include "book.h"

// estas acciones tienen como parametros los punteros (las direcciones
// en memoria pasadas en main)
void readBook(tBook *book){
	printf("TITLE?\n");
	// aqui escribimos directamente en book.title. Como es string, 
	// directamente es un la direccion en memoria del primer caracter, por lo que no hace falta anyadir el &
	scanf("%30s", book->title);
	printf("IS SIGNED (0-FALSE, 1-TRUE)?\n");
	// aqui anyadimos el & ya que si no, le pasariamos directamente el integer y no la direccion en memoria
	scanf("%d", &book->isSigned);
	printf("BOOKBINDING (0-MANUSCRIPT, 1-HARDCOVER, 2-PAPERBACK)?\n");
	scanf("%d", &book->bindingType);
}

void compareBooks(const tBook *book1, const tBook *book2, tBook *mostValuable){
	// se comprueba si tienen el mismo titulo
	if (strcmp(book1->title, book2->title) !=0){
		printf("OUTPUT\n");
		printf("NON-COMPARABLE BOOKS\n");
	}
	// se realizan las decisiones para ver cual es mas valioso y se asigna a mostvaluable
	// que es un puntero a la variable best definida en main
	if(book1->isSigned && !book2->isSigned){
		*mostValuable = *book1;
	} else if(book2->isSigned && !book1->isSigned){
		*mostValuable = *book2;
	} else if(book1->bindingType < book1->bindingType){
		*mostValuable = *book1;
	} else if(book2->bindingType < book1->bindingType){
		*mostValuable = *book2;
	} else{
		*mostValuable = *book1;
	}
}

void mostValuableBook(const tBook *book){
	printf("OUTPUT\n");
	printf("THE MOST VALUABLE BOOK IS:\n");
	printf("TITLE: %s\n", book->title);
	printf("IS SIGNED (0-FALSE, 1-TRUE): %d\n", book->isSigned);
	printf("BOOKBINDING (0-MANUSCRIPT, 1-HARDCOVER, 2-PAPERBACK): %d\n", book->bindingType);
}
