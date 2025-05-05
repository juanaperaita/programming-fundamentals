# 5. Comparación de Libros 📚

Implementad un programa en lenguaje C que compare dos libros de una biblioteca e indique cuál de ellos es más valioso.

## Datos del libro

Cada libro se representa mediante una tupla con:

* Título (30 caracteres alfanuméricos, sin espacios; usar '\_' en su lugar)
* Si está firmado por el autor (0 = FALSE, 1 = TRUE)
* Tipo de encuadernación:

  * 0 = MANUSCRIPT (más valiosa)
  * 1 = HARDCOVER
  * 2 = PAPERBACK (menos valiosa)

## Comparación de libros

* Solo se comparan libros con el mismo título. Si no coinciden, mostrar:

  * `NON-COMPARABLE BOOKS`
* Si los títulos coinciden:

  1. Gana el firmado por el autor.
  2. Si empatan, gana el de encuadernación más valiosa.
  3. Si siguen empatados, gana el primero introducido.

## Entrada

El programa debe leer por teclado los datos de dos libros. La lectura debe hacerse mediante una acción con una tupla libro como parámetro de salida.

## Salida

El programa debe mostrar los datos del libro más valioso usando una acción con una tupla libro como parámetro de entrada.

## Acciones obligatorias

* Lectura de un libro: acción con parámetro de salida tipo libro.
* Escritura de un libro: acción con parámetro de entrada tipo libro.
* Comparación de dos libros: acción con tres parámetros (dos de entrada y uno de salida, todos tipo libro).

## Requisitos

* Usar estructuras para los libros.
* Modular el programa en tres archivos: `main.c`, `book.c` y `book.h`.

## Ejemplo de ejecución

### Caso 1

```
INPUT
TITLE? The_Lord_Of_The_Rings
IS SIGNED (0-FALSE, 1-TRUE)? 0
BOOKBINDING (0-..., 2-...)? 1
TITLE? The_Lord_Of_The_Rings
IS SIGNED (0-FALSE, 1-TRUE)? 1
BOOKBINDING (0-..., 2-...)? 2

OUTPUT
THE MOST VALUABLE BOOK IS:
TITLE: The_Lord_Of_The_Rings
IS SIGNED (0-FALSE, 1-TRUE): 1
BOOKBINDING (0-..., 2-...): 2
```

### Caso 2

```
INPUT
TITLE? The_Lord_Of_The_Rings
...
TITLE? Lord_Of_The_Flies
...

OUTPUT
NON-COMPARABLE BOOKS
```
