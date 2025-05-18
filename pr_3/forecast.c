#include "forecast.h"

/* Function that converts Celsius degrees to Fahrenheit */
float celsiusToFahrenheit(float celsius) {
	float fahrenheit;
	
	fahrenheit = (celsius * FAHRENHEIT_FACTOR) + FAHRENHEIT_OFFSET;
    return fahrenheit;
}

/* Function that converts Fahrenheit degrees to Celsius */
float fahrenheitToCelsius(float fahrenheit) {
	float celsius;
	
	celsius = (fahrenheit - FAHRENHEIT_OFFSET) * CELSIUS_FACTOR;	
    return celsius;
}


/* Exercise 1 */
/* Function to load ski resort data from file */
/* Exercise 1 */
/* Function to load ski resort data from file */
void loadSkiResortsDataFromFile(const char* filename, tTemperature scale, tSkiResortsTable *resortsTable, bool* isRead) {
    FILE* fin = NULL;
    char line[MAX_LINE];
	char buffer[MAX_LINE];
    tSkiResort newResort;
    int i;
	
	float temp;
	float rain;
	
	tWeatherData weatherDataTmp;

    /* Open the input file */
    if ((fin = fopen(filename, "r")) != NULL) {
		
		/* Exercise 1.1 */
		/* Initialize resort table */
		// usamos -> en vez de . ya que resortsTable es un puntero a la tabla de resorts
		// asi que para acceder a sus campos necesitamos esta sintaxis
		resortsTable->nResorts=0;
		// isRead tambien es un puntero (parametro de salida), por lo que para sobreescribir su valor 
		// hay que utilizar * antes de la variable
		*isRead=true;
		
        /* Read all the resorts */  
        while (!feof(fin) && resortsTable -> nResorts < MAX_RESORTS) {
            /* Remove any content from the line */
            line[0] = '\0';

            /* Read one line (maximum MAX_LINE chars) and store it in "line" variable */
            fgets(line, MAX_LINE - 1, fin);

            /* Ensure that the string is ended by 0 */
            line[MAX_LINE - 1] = '\0';

            if (strlen(line) > 0) {
                /* Obtain the resort name and weather data from the file line */
                sscanf(line, "%s %[^\n]s", newResort.resortName, buffer);
					
				/* Generate wheather data and add them to the vector */
				for (i = 0; i < DAYS_IN_WEEK; i++) {
					
					sscanf(buffer, "%f %f %[^\n]s", &temp, &rain, buffer);
					
					/* Exercise 1.2 */					
					/* If Fahrenheit is needed, convert the temperature */					
					
					if(scale==FAHRENHEIT){
						temp = celsiusToFahrenheit(temp);
					}
					
					weatherDataTmp.temperature = temp;
					/************************************************************/
					weatherDataTmp.rainAccumulation = rain;
					newResort.weekData[i] = weatherDataTmp;
				}	
				
				/* Exercise 1.3 */
				/* Add new resort to resorts vector */
				resortsTable->resorts[resortsTable->nResorts] = newResort;
				resortsTable->nResorts= resortsTable->nResorts+1;
                /**************************************/	
            }
        }
        /* Close the file */
        fclose(fin);
        *isRead = true;
    } 
	else {
        *isRead = false;
    }
}

/* Exercise 2 */
bool isSnowyWeek(tSkiResort resort, tTemperature scale) {
	// definimos las variables
	bool itWillSnow = false;
	float threshold;
	int i;
	float currentTemp;
	float currentRain;
	
	// inicializamos las variables
	threshold = SNOW_TEMP_CELSIUS_THRESHOLD;
	// si la escala es fahrenheit, convertimos a celsius
	if(scale == FAHRENHEIT){
		threshold= celsiusToFahrenheit(threshold);
	}
	
	// iteramos sobre los idas de la semana para asignar la temp y rain 
	// asi podremos operar con esa temp y rain concretas
	for(i=0; i<DAYS_IN_WEEK; i++){
		// como resort no es un puntero, accemos a sus campos usando .
		currentTemp = resort.weekData[i].temperature;
		currentRain = resort.weekData[i].rainAccumulation;
		
		// comprobamos si es heavy snow y si es, modificamos el valor de itwillsnow. No devolvemos,
		// ya que es mala práctica poner varios returns en una funcion
		if(currentTemp<=threshold && currentRain>=SNOW_RAIN_THRESHOLD){
			itWillSnow = true;
		}
	}
	
	return itWillSnow;
}

/* Exercise 3 */
void getExtremeTempForecast(
// pasamos dos parametros de salida (minTemp y maxTemp) que son punteros a variables reales.
// tambien definimos resort como constante, ya que no necesitamos modificar sus datos, sino solo
// leerlos. Además, este parametro es un puntero a tSkiResort para evitarnos copiarlo, lo que mejora
// la eficiencia.
		const tSkiResort *resort,
		float *minTemp,
		float *maxTemp
){
	// definimos las variables
	int i;
	float temp;
	
	// iniciamos minTemp y maxTemp empezando por el dia con el indice 0.
	// aqui, igual que en la funcion anterior, tenemos en cuenta que el indice empieza en
	//0, mientrasque en pseudocodigo empieza en 1.
	*minTemp= resort->weekData[0].temperature;
	*maxTemp=resort->weekData[0].temperature;
	
	// modificamos los parametros de salida dinamicamente, comparando con el resto
	// de dias.

	for(i=1; i<DAYS_IN_WEEK; i++){
		temp = resort->weekData[i].temperature;
		if(temp < *minTemp){
			*minTemp = temp;
		}
		if (temp > *maxTemp){
			*maxTemp = temp;
		}
	}
}

/* Exercise 4 */

void getResortsWithSnowPrediction(
	const tSkiResortsTable *allResorts,
	tTemperature scale,
	tSkiResortsTable *snowyResorts
){
	// definimos las variables
	int i;
	
	// inicializamos la tabla de salida vacia
	snowyResorts->nResorts=0;
	
	// recorremos los resorts iterando desde el primero (indice 0) hasta
	// el numero de resorts-1, para filtrar los nevados
	for(i=0; i<allResorts->nResorts; i++){
		//con la funcion isSnowyWeek, sacamos si el resort i tiene una semana nevada y 
		// si es asi, lo añadimos a nuestra tabla e incrementamos el numero de records
		if(isSnowyWeek(allResorts->resorts[i], scale)){
			snowyResorts->resorts[snowyResorts->nResorts]= allResorts->resorts[i];
			snowyResorts->nResorts= snowyResorts->nResorts+1;
		}
	}
}