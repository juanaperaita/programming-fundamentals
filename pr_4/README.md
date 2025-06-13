## Gestión de Emergencias en Estaciones de Esquí 🚨🎿

En este ejercicio partimos del algoritmo desarrollado en la `pr_3` y añadimos datos meteorológicos recogidos durante una semana en varias estaciones de esquí. El objetivo es ampliar la funcionalidad para detectar y gestionar emergencias climatológicas.

---

### 1. Carga de configuración y datos

- **Entrada por teclado**:

  - Escala de temperatura de trabajo: `Celsius` o `Fahrenheit`.
  - Nombre del fichero con previsiones semanales (temperatura, lluvia, viento y nieve) de diversas estaciones.

- **Acción proporcionada**: `loadSkiResortsDataFromFile(fileName: String, scale: Char) -> (resorts: tSkiResort[], error: Bool)`

  - Lee cada línea con formato:
    ```text
    <ESTACIÓN> t1 p1 w1 s1 t2 p2 w2 s2 ... t7 p7 w7 s7
    ```
    donde para cada día: `t`: temperatura, `p`: precipitación, `w`: viento (km/h), `s`: nieve acumulada (cm).
  - Convierte temperaturas según la escala elegida.
  - Devuelve una tabla de `tSkiResort` y un booleano de éxito/fracaso.

---

### 2. Estructuras de datos a ampliar

#### 2.1 `tWeatherData`

Añadir campos para cada estación y cada día:

- `windSpeed: Float` (km/h)
- `snowAccumulation: Float` (cm)

#### 2.2 `tSkiResort`

Extender para incluir indicadores de emergencia:

- `hasRainEmergency: Bool`
- `hasWindEmergency: Bool`
- `hasSnowEmergency: Bool`

---

### 3. Detección de emergencias climatológicas

#### 3.1 Acción principal: `getResortsWithEmergency`

- **Entrada**: tabla completa de `tSkiResort`.
- **Salida**: nueva tabla con las estaciones que presentan alguna emergencia, ordenada ascendentemente por `name`.
- Internamente llama a:
  
  1. 
     - Marca las emergencias según:
       - **Lluvia**: más de 50 ml dos o más días consecutivos.
       - **Viento**: más de 41 km/h dos o más días consecutivos.
       - **Nieve**: usar la función `isSnowRecommended`.
  2. 
     - Devuelve `false` si en al menos 3 días la nieve acumulada es < 80 cm o > 100 cm, indicando condición insegura.
  3. 
     - Inserta una estación en la lista, manteniendo orden lexicográfico por nombre.

---

### 4. Salida de resultados

- Tras obtener la lista de emergencias:
  1. Si la lista está vacía, mostrar:
     ```text
     NO EMERGENCY SITUATIONS
     ```
  2. En caso contrario, usar `writeResorts(emergencies: tSkiResort[])` para:
     - Mostrar el nombre de cada estación.
     - Indicar qué tipo(s) de emergencias (`Rain`, `Wind`, `Snow`).

---

### 5. Consulta de emergencia individual

- **Entrada por teclado**: nombre de una estación.
- Usar la función:
  ```pascal
  function isResortInEmergency(emergencies: tSkiResort[], name: String): Bool;
  ```
  - Devuelve `true` si la estación aparece en la tabla de emergencias.
- Mensajes según resultado:
  ```text
  RESORT IN EMERGENCY LIST
  ```
  ```text
  RESORT NOT IN EMERGENCY LIST
  ```

---

### 6. Manejo de errores

- Si la lectura del fichero falla (`error = true`):
  ```text
  NO SKI RESORTS RECOVERED
  ```

---

Se deben completar los **ejercicios 1.1–4** para cumplir todos los requisitos. ¡A programar! 🎯

