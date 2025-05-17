// iterating through a table

// once we have a filled table, now we want to add a 20% to each element of the table

#include <stdio.h>

#define MAX_THEATERS 20 
#define END_SEQ -1.0

typedef struct {
    float collect[MAX_THEATERS];
    int numTheaters;
} tTheater;

void update(tTheater *movieTheater){
    int i;
    // we use a for instead of a while because we know the exact number of elements
    for(i=0; i<movieTheater->numTheaters; i++){
        movieTheater->collect[i] = movieTheater->collect[i]*1.20;
    }
}

// we can now update the algorithm:

#include <stdio.h>

#define MAX_THEATERS 20 
#define END_SEQ -1.0

typedef struct {
    float collect[MAX_THEATERS];
    int numTheaters;
} tTheater;

void fillTable(tTheater *movieTheater){
    float temp;
    movieTheater->numTheaters =0;
    scanf("%f", &temp);
    while (temp != END_SEQ){
        movieTheater->collect[movieTheater->numTheaters]=temp;
        movieTheater->numTheaters = movieTheater->numTheaters+1;
        scanf("%f", &temp);
    }
}

void update(tTheater *movieTheater){
    int i;
    for(i=0; i<movieTheater->numTheaters; i++){
        movieTheater->collect[i] = movieTheater->collect[i]*1.20;
    }
}

void printTable(tTheater movieTheater){
    int i;

    for(i=0; i<movieTheater.numTheaters; i++){
        print("%f", movieTheater.collect[i]);
    }
}

int main(){
    tTheater santalo;
    fillTable(&santalo);
    printTable(santalo);
    update(&santalo);
    printTable(santalo);

    return 0;
}

//////////////////////

// search for a specific value

// we search in the table if there has been 
// an action > to a specific value

#include <stdio.h>
#include <stdbool.h>

#define MAX_THEATERS 20
#define END_SEQ -1.0

typedef struct {
    float collect[MAX_THEATERS];
    int numTheaters;
} tTheater;

void fillTable(tTheater *movieTheater){
    float temp;
    movieTheater->numTheaters = 0;

    scanf("%f", &temp);
    while (temp != END_SEQ){
        movieTheater->collect[movieTheater->numTheaters];
        movieTheater->numTheaters = movieTheater->numTheaters+1:
        scanf("%f", &temp);
    }
}

void searchValue(tTheater movieTheater, float value, int *position){
    int i;
    bool found;

    //variable initialization
    i = 0;
    found = false;
    *position = -1;
    // while there are still elements in the table and
    // the value has not been found
    while(i<movieTheater.numTheaters && !found){
        if(movieTheater.collect[i] >=value){
            found=true;
        } else{
            i++;
        }
    }
    if(found){
        *position = i;
    }
}

int main(){
    tTheater movieTheater;
    float value;
    int position;

    fillTable(&movieTheater);
    scanf("%f", &value);
    searchValue(movieTheater, value, &position);
    print("%d", position);

    return 0;
}