# Visualizador de Movimientos de Ajedrez ♟️

## Descripción del Proyecto

Este es un programa desarrollado en **C** que funciona como una herramienta de línea de comandos (CLI) para calcular y visualizar todos los movimientos válidos de una pieza de ajedrez en un tablero vacío. El usuario puede seleccionar una pieza, especificar su posición inicial y el programa mostrará un tablero de 8x8 con la pieza y todos sus posibles destinos marcados.

-----

## Características Principales

  * **Selección de Pieza**: Permite al usuario elegir entre Alfil, Caballo, Reina, Rey y Torre.
  * **Posicionamiento Dinámico**: El usuario puede colocar la pieza en cualquier coordenada (fila, columna) del tablero.
  * **Visualización Clara**: Muestra una representación textual del tablero, marcando la posición de la pieza y todas las casillas a las que se puede mover con una 'X'.
  * **Gestión de Memoria**: El tablero se crea dinámicamente en memoria, demostrando el uso de `malloc` y `free` en C.

-----

## ⚙️ Compilación y Ejecución

Para compilar y correr este proyecto, necesitarás un compilador de C como **GCC**.

1.  **Clona o descarga el repositorio.**

2.  **Abre una terminal** en el directorio del proyecto.

3.  **Compila el código** con el siguiente comando:

    ```bash
    gcc nombre_del_archivo.c -o ajedrez
    ```

    *(Reemplaza `nombre_del_archivo.c` con el nombre de tu archivo C)*.

4.  **Ejecuta el programa**:

      * En Windows:
        ```bash
        ajedrez.exe
        ```
      * En Linux o macOS:
        ```bash
        ./ajedrez
        ```

-----

## 🎮 Cómo Usar

Una vez que el programa esté en ejecución:

1.  Se mostrará un menú para que elijas la pieza que deseas visualizar.
2.  Ingresa el número correspondiente a tu elección.
3.  Introduce las coordenadas de la pieza, que van de **0 a 7** tanto para la fila (`x`) como para la columna (`y`).
4.  El programa imprimirá el tablero con los movimientos calculados. El ciclo se repetirá hasta que selecciones la opción "Salir".
