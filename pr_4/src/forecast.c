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


/* Function to load ski resort data from file */
void loadSkiResortsDataFromFile(const char* filename, tTemperature scale, tSkiResortsTable *resortsTable, bool* isRead) {
#ifdef TYPEDEF_COMPLETED
    FILE* fin = NULL;
    char line[MAX_LINE];
	char buffer[MAX_LINE];
    tSkiResort newResort;
    int i;
	
	float temperature;
	tWeatherData weatherDataTmp;

    /* Open the input file */
    if ((fin = fopen(filename, "r")) != NULL) {
		
		/* Initialize resort table */
		resortsTable -> nResorts = 0;
				
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
				for (i = 0; i < DAYS_IN_WEEK; i++) {
					sscanf(buffer, "%f %f %f %d %[^\n]s", &temperature, &weatherDataTmp.rainAccumulation, 
                           &weatherDataTmp.windSpeed, &weatherDataTmp.snowAccumulation, buffer);
	

					weatherDataTmp.scale = scale;
					/* If Fahrenheit is needed, convert the temperature */					
					if (weatherDataTmp.scale == FAHRENHEIT) {
						weatherDataTmp.temperature = celsiusToFahrenheit(temperature);
					}	
					else {
						weatherDataTmp.temperature = temperature;
					}
					
					newResort.weekData[i] = weatherDataTmp;
				}	
				
				
				/* Add new resort to resorts vector */
				resortsTable->resorts[resortsTable->nResorts] = newResort;
                /* Increment the resorts counter. */
				resortsTable->nResorts++ ;
                	
            }
        }
        /* Close the file */
        fclose(fin);
        *isRead = true;
    } else {
        *isRead = false;
    }
#endif
}

/* Exercise 2 */
/* Action to get resorts with some emergency */
/* ... */


/* Exercise 2.1 */
/* Action to modify resort with emergencies */
/* ... */


/* Exercise 2.2 */
/* Function that test if snow levels is recommended */
/* ... */


/* Exercise 2.3 */
/* Action to insert resort in table sorted by name */
/* ... */


/* Exercise 3 */
/* Action to print resort data */
/* ... */


/* Exercise 4 */
/* Function that test if resort is in emergencies resort list */
/* ... */

