#include <stdio.h>
// max num of values that a table can have
#define MAX_ELEMENTS 10

// we define a special tuple, since it has the structure of a table: +
// 1. vector with data, 2. variable that indicates the vector's occupation
typedef struct {
    // vector of 10 integers
    int elements[MAX_ELEMENTS];
    // integer that specifies the num of elements
    int numElements
} tExampleTable;

int main(){
    tExampleTable aTable;
}

///////////////////////////////////
#include <stdio.h>
#include <stdio.bool>

#define K 10
#define MAX_GATES 40

typedef struct {
    bool stateGates[MAX_GATES];
    int numGates;
} tGates;

// we define an action which uploads the data into a table of tGates type:
void fillTable(tGates *Building);

int main(){
    tGates building1;
    int p;
    bool b;
    bool c;

    c = true;

    fillTable(&building1);
    // we assign the third element of the table building1 to the variable b:
    b = building1.stateGates[2];

    // assings the value of c to the Kth gate of building1:
    building1.stateGates[K-1] =c;

    //assigns the value of the first gate of building1 to the gate 2*p +5 as long as 1 ≤ 2*p+5 ≤ 40
    
    building1.stateGates[2*p+5-1]=building1.stateGates[0];

    return 0;

}

////////////////////

// we initalize a table assigning 0 to the integer that shows the number of elements that are occupied in the table.

// example cinema:

#include <stdio.h>

#define MAX_THEATERS 20

typedef struct {
    float collect[MAX_THEATERS];
    int numTheaters;
} tTheater;

int main(){
    tTheater santalo;
    tTheater sants;
    // we initialize the table setting the number of theater to 0:
    santalo.numTheaters = 0;
    sants.numTheaters = 0;

    return 0;
}

//////////////////////////

// upload data to table reading the standard input channel

#include <stdio.h>

#define MAX_THEATERS 20
#define END_SEQ -1.0

typedef struct {
    float collect[MAX_THEATERS];
    int numTheaters;
} tTheater;

//this action does the following: given a theater
void fillTable(tTheater *movieTheater){
    float temp;
    // sets counter to 0
    movieTheater->numTheaters =0;
    // reads value of temp
    scanf("%f", &temp);
    // while value isn't last one
    while (temp != END_SEQ){
        // saves the value
        movieTheater->collect[movieTheater->numTheaters]=temp;
        // increments counter
        movieTheater->numTheaters = movieTheater->numTheaters+1;
        // reads the next value
        scanf("%f", &temp);
    }
}