#include <stdio.h>

int main(){

    int a[4];

    a[0] = 1;
    a[1] = 4;
    a[2] = -1;
    a[3] = 1023;

    return 0;
}

// When defining "a", the program defines an "a" pointer
// of type integer, for whom it saves its first value's memory address.
// The program saves this memory address for the frist value of "a",
// and it also saves the following 3 memory addresses for the rest
// of the vector's values.

// When doing the following:
a[0] = 1;

// we're accessing the memory position saved in the
// pointer "a" by indirection, and updating its content.

// We can deduce then that, if "a" is a pointer:
*a = 1

// Another example:

#include <stdio.h>

int main(){
    int a[4]; // defining the vector

    a[0] =1;
    a[1] = 4;
    a[2] = -1;
    a[3] = 1023;

    printf("The first element of the vector is: %d\n", a[0]);
    printf("The first element of the vector is: %d\n", *a);
    printf("The memory address of the first element of the vector is: %p\n", &a[0]);
    printf("The memory address of the first element of the vector is: %p\n", a);

    return 0;
}