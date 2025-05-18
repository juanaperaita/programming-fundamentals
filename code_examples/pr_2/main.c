/*
* File: main.c
* Author: UOC
* Course: 20242
* Description: PR3
*/

/* System header files */
#include "forecast.h"

/* main */
int main(int argc, char **argv)
{
	tSkiResortsTable resorts;
	tTemperature scale;
	
	tSkiResortsTable resortsResultsTable;
	
	float minTemp;
	float maxTemp;
	
	int i;
	char filename[MAX_FILE_NAME];
	bool isRead = false;
	
	
	/* Data input */		
	/* Input the temperature scale */
	printf("INPUT DATA\n");
	
	do {
		printf ("SELECT TEMPERATURE SCALE (1-CELSIUS, 2-FAHRENHEIT) >>\n");
		scanf("%u", &scale);
		getchar();

		/* Data validation */
		if (scale < CELSIUS || scale > FAHRENHEIT) {
			printf("INVALID DATA, TRY AGAIN!\n");
		}
	} while (scale < CELSIUS || scale > FAHRENHEIT);
		
	
	/* load data from file */ 
    printf("LOAD DATA FROM FILE. ENTER FILE NAME >>\n");
    scanf("%s", filename);
	loadSkiResortsDataFromFile(filename, scale, &resorts, &isRead);	
	
	if (isRead) { /* Data successfully loaded */
		printf("\n");
		printf ("RESULTS:\n");
		printf("SKI_STATION MIN_TEMP MAX_TEMP\n");
		printf("=============================\n");
        /* Exercise 5 */
		/* Retrieve and display extreme temperatures forecast */
		for(i=0; i<resorts.nResorts; i++){
			// como los paraemtros de la accion son punteros, debemos pasarle la direccion
			// en memoria,y esto se hace con &
			getExtremeTempForecast(&resorts.resorts[i], &minTemp, &maxTemp);
			printf("%s %.2f %.2f\n", resorts.resorts[i].resortName, minTemp, maxTemp);
		}
		
		/* Exercise 6 */
		/* Retrieve and display snowy ski resorts. */
		printf("\n");
		printf("SNOWY SKI RESORTS\n");
		printf("=================\n");
		
		getResortsWithSnowPrediction(&resorts, scale, &resortsResultsTable);
		// comprobamos si existen resorts con snowy weeks, y si es asi los devolvemos.
		// si no, devolvemos el string
		if(resortsResultsTable.nResorts==0){
			printf("NO SNOW FORECAST\n");
		} else {
			for(i=0; i< resortsResultsTable.nResorts; i++){
				printf("%s\n", resortsResultsTable.resorts[i].resortName);
			}
		}
	}
	else {
		/* No data recovered */
		printf("NO RESORTS RECOVERED\n");
	}
		
	return 0;
}






