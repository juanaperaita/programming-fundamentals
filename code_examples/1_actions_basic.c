// Difference between action and function:
// 1. actions don't return a value 
// 2. Can change parameters from parent algorithm(the one that calls the action)

// in parameters (same as functions). Example:

#include <stdio.h>

void printParameters(int p, int q){

    print("%d %d\n", p, q)
    // since its an action and not a function, it has no returned value
}

int main(){
    int a = 3;
    int b= 4;

    printParameters(a,b);

    return 0;
}

// in/out and out parameters. Here, we use pointers. The variables inside
// the action will have the memory address of the variables defined in the
// main program (this is only for in/out and out parameters). 
// We pass the parameters by REFERENCE, instead of by COPY.
// Example:

#include <stdio.h>

#define MAX_DISCOUNT 0.20
#define MIN_DISCOUNT 0.10
#define LIMIT1 1000
#define LIMIT2 500

void computeCost(int num, float *pDiscount, float *pPrice){
    *pDiscount = 0.0; //now we know this is an out parameter, because we do
    // not depend on the value passed as a parameter in the action

    if(num>=LIMIT1){
        *pDiscount = MAX_DISCOUNT;
    } else {
        if (num >=LIMIT2){
            *pDiscount = MIN_DISCOUNT;
        } else {
            if (num <= LIMIT2){
                *pDiscount=0.0;
            }
        }
    }

    *pPrice = (float) num * (*pPrice) *(1.0-*pDiscount);
    // pPrice is an in/out value because we recalculate the value
    // that has been sent as a parameter in the action
}

int main(){
    int num;
    float price;
    float discount;

    num = 1000;
    price = 10.0;

    computeCost(num, &discount, &price) // we use the variable "num" and
    // the pointers to "price" and "discount" (their memory addresses).
    // What this will do is that pDiscount and pPrice will have the
    // memory addresses, so, in the action, we're working with the same 
    // variables, since we have copied their memory address. If we 
    // change the address content in the action, this will also be seen
    // in the main program.

    printf("Price: %f , Discount: %f", price, discount);
    return 0;
}
    
