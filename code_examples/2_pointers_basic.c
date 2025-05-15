#include <stdio.h>

int main(){
    int a;
    int *p;

    a = 3;
    p = NULL;

    p = &a; // Asigns variable address

    printf("Content of vairable a: %d", a);
    printf("Content of vairable a: %d", *p); // Access the variable value of "p" through indirection

    printf("memory address of variable a: %p", &a); // Access memory address of "a"
    printf("memory address of variable a: %p", p); // The pointer already contains the memory address of "a"
}

