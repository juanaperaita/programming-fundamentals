#define MAX_TITLE 31
// definimos la tupla
typedef struct {
    char title[MAX_TITLE];
    int isSigned;
    int bindingType;
} tBook;
// hacemos las importaciones de las acciones
void readBook(tBook *book);
void compareBooks(const tBook *book1, const tBook *book2, tBook *mostValuable);
void mostValuableBook(const tBook *book);
