
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Uncomment the line below once you've completed the exercise 1*/
//#define TYPEDEF_COMPLETED

/*Constants for file reading */
#define MAX_FILE_NAME 100+1
#define MAX_LINE 514

#define MAX_NAME_LENGTH 25+1
#define DAYS_IN_WEEK 7    /* Number of days of the week */

#define MAX_RESORTS 20   /* Max. number of ski resorts */

/* Temperature scale conversion constants (CELSIUS/FAHRENHEIT) */
#define CELSIUS_FACTOR 0.555f   /* Round to three decimal places to maintain precision */
#define FAHRENHEIT_FACTOR 1.8f   
#define FAHRENHEIT_OFFSET 32.0f

#define HEAVY_RAIN_THRESHOLD 50.0f        /* Heavy rain threshold in millimeters */
#define SNOW_TEMP_CELSIUS_THRESHOLD 0.0f  /* Temperature below for snow in Celsius degrees */
#define SNOW_RAIN_THRESHOLD 10.0f         /* Minimum rain in millimeters for snow */
/* ... */


/* User defined types */
typedef enum {CELSIUS = 1, FAHRENHEIT} tTemperature; /* Type of temperature scale */

typedef struct {
	tTemperature scale;     /* Temperature scale */
    float temperature;      /* Temperature degree */
    float rainAccumulation; /* Accumulated rainfall in millimeters */
/* Exercise 1.1 */


/**************/
} tWeatherData;

typedef struct {
    char resortName[MAX_NAME_LENGTH];    /* Name of the ski resort */
    tWeatherData weekData[DAYS_IN_WEEK];  /* Vector to store weather data */
/* Exercise 1.2 */



/**************/
} tSkiResort;

typedef struct {
    tSkiResort resorts[MAX_RESORTS]; /* Ski resorts */
    int nResorts;                    /* Number of ski resorts */ 
} tSkiResortsTable;


/* Functions/actions prototypes declaration for auxiliary functions */
/* Function that converts Celsius degrees to Fahrenheit */
float celsiusToFahrenheit(float celsius);
/* Function that converts Fahrenheit degrees to Celsius*/
float fahrenheitToCelsius(float fahrenheit);
/* Action that reads resorts data from file */
void loadSkiResortsDataFromFile(const char* filename, tTemperature scale, tSkiResortsTable *resortsTable, bool* isRead);

/* Functions/actions prototypes declaration for exercises */
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
