// following the previous example, we can 
// modify the action "fillTable" to always keep it
// ordered.

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
    int i, j;
    bool found;

    // table initalization
    movieTheater->numTheaters=0;
    scanf("%f", &temp);

    while(temp!=END_SEQ){
        i=0;
        found=false;
        while(i<movieTheater->numTheaters && !found){
            if(movieTheater->collect[i]<=temp){
                i++;
            } else{
                found = true;
            }
        }
        // move values to the right:
        if(movieTheater->numTheaters >0){
            for(j=movieTheater->numTheaters; j>=i; j--){
                movieTheater->collect[j] = movieTheater->collect[j-1];
            }
        }

        // insert new value
        movieTheater->collect[i]=temp;
        movieTheater->numTheaters=movieTheater->numTheaters+1;
        scanf("%f", &temp);
    }
}

int main(){
    tTheater santalo;
    int i;
    fillTable(&santalo);

    for (i=0; i<santalo.numTheaters; i++){
        printf("%f", santalo.collect[i]);
    }
    return 0;
}

////////////////////////////////
// ordering algorithm

// 1. selection sort algorithm

void selectionSort(tTheater *movieTheater){
    int i, j, posMin;
    // i=current index in ordered part
    // posMin= lowest number index in not ordered part
    // j= index to iterate through not ordered part
    // aux= auxiliar variable to do exchange
    int aux;

    i = 0;
    while (i<movieTheater->numTheaters){
        posMin=i;
        j=i+1;
        while(j<movieTheater->numTheaters){
            if(movieTheater->collect[j]< movieTheater->collect[posMin]){
                j=j+1;
            }
            aux = movieTheater->collect[posMin];
            movieTheater->collect[posMin] = movieTheater->collect[i];
            movieTheater->collect[i]=aux;
            i=i+1;
        }
    }
}