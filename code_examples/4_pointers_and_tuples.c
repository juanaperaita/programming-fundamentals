// When defining a tuple's pointer, we're 
// asigning the memory address of the first
// element of the tuple

#include <stdio.h>

typedef struct {
    float x;
    float y;
} tPoint;

int main(){
    tPoint a;
    tPoint *pPoint;

    a.x =3;
    a.y = 5;
    pPoint = NULL;

    pPoint = &a;

    return 0;
}

// Remember that a pointer variable has always the
// same size, since it just points to another variable.


// We can also access variables x and y from the
// pointer pPoint:

#include <stdio.h>

typedef struct {
    float x;
    float y;
} tPoint;

int main(){
    tPoint a;
    tPoint *pPoint;

    a.x = 3;
    a.y = 5;
    pPoint = NULL;

    pPoint = &a;
    // We're accessing the values through indirection
    printf("%f %f\n", (*pPoint).x, (*pPoint).y);

    return 0;
}

// The "->" operator lets us access the internal
// fields of a variable in a simpler way.

// We could change this: 
printf("%f %f\n", (*pPoint).x, (*pPoint).y);
// for this:
printf("%f %f\n", pPoint->x, pPoint->y);