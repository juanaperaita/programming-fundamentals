## Ski Resort Forecast ⛷️

Partiendo del algoritmo desarrollado en la PR2 (predicción meteorológica en estaciones de esquí), en este ejercicio actualizamos y ampliamos la funcionalidad para:

1. **Carga de datos**  
   - Leer desde el teclado:
     - La escala de temperatura de trabajo (`Celsius` o `Fahrenheit`).  
     - El nombre del archivo que contiene los datos meteorológicos semanales de varias estaciones de esquí.  
   - Invocar la acción `loadSkiResortsDataFromFile` para:
     - Inicializar una tabla de salida.  
     - Leer cada línea del fichero (formato: nombre_estación, 7 pares de valores temperatura/precipitación).  
     - Convertir temperaturas según la escala elegida (usando las funciones `celsiusToFahrenheit` y `fahrenheitToCelsius`).  
     - Almacenar los registros en la tabla junto con un indicador de éxito/fracaso al leer el archivo.

2. **Procesamiento por estación**  
   Para cada estación cargada en la tabla:
   - **[Ejercicio 2]** Extender `isSnowyWeek` para que funcione con datos en Celsius o Fahrenheit.  
   - **[Ejercicio 3]** Diseñar `getExtremeTempForecast` que devuelva la temperatura mínima y máxima de la semana.  

3. **Filtrado de estaciones con nieve**  
   - **[Ejercicio 4]** Implementar `getResortsWithSnowPrediction` que, usando `isSnowyWeek`, genere una tabla con las estaciones que tendrán nevadas.

4. **Salida de resultados**  
   Tras una carga exitosa:
   - **[Ejercicio 5]** Mostrar un listado de todas las estaciones con sus temperaturas mínimas y máximas previstas.  
   - **[Ejercicio 6]** Listar las estaciones con previsión de nevadas. Si no hay ninguna, mostrar el mensaje:
     ```
     NO SNOW FORECAST
     ```
   Si la carga de datos falla, mostrar:
    ```
    NO RESORTS RECOVERED
    ```

### Formato del fichero de entrada

Cada línea del archivo sigue este formato:
    ```
    <ESTACIÓN> t1 p1 t2 p2 t3 p3 t4 p4 t5 p5 t6 p6 t7 p7
    ```

- `tX`: temperatura media diaria en °C  
- `pX`: precipitación diaria en mm  

**Ejemplo** (Formigal Panticosa):
    ```
    FORMIGAL_PANTICOSA -1.5 7.2 0.3 8.5 2.1 6.9 4.4 5.2 2.3 6.7 1.1 9.3 3.2 8.1
    ```
- Lunes: –1.5 °C, 7.2 mm  
- Martes: 0.3 °C, 8.5 mm  
- …hasta el domingo.

---

## Punto de partida

Se proporciona el pseudocódigo inicial con:
- Declaración de la estructura de datos.  
- Esqueleto de `loadSkiResortsDataFromFile`.  
- Funciones auxiliares de conversión de temperatura.  
- Firma de `isSnowyWeek`.  

Partid de este código y completad los **Ejercicios 1–6** para cumplir los requisitos descritos. ¡Manos a la obra!  
