#include <stdio.h> // Incluye la librería estándar de entrada y salida en C.
#include <stdlib.h> // Incluye la librería estándar de C que proporciona funciones para la gestión de memoria dinámica

struct piezaAjedrez { // Define una estructura llamada "piezaAjedrez" que representa una pieza de ajedrez [tipo de pieza (alfil, caballo, reina, rey, torre) y las coordenadas (x, y) en el tablero].
    char tipo; // Tipo de pieza: 'A' (Alfil), 'C' (Caballo), 'Q' (Reina), 'K' (Rey), 'T' (Torre)
    int x, y;  // Coordenadas de la pieza en el tablero
};

void imprimirTablero(char **tablero); // Declara una función llamada "imprimirTablero" que toma como argumento un apuntador a un apuntador de caracteres
void movimientosValidos(char **tablero, struct piezaAjedrez pieza); // Función para calcular y mostrar los movimientos válidos de una pieza de ajedrez en un tablero
void liberarTablero(char **tablero); // Función para liberar la memoria asignada a un tablero de ajedrez

int main() {
    // Definir el struct para las piezas
    struct piezaAjedrez pieza;

    // Definir apuntador para el arreglo de dos dimensiones para el tablero
    char **tablero = (char **)malloc(8 * sizeof(char *));
    for (int i = 0; i < 8; i++) {
        tablero[i] = (char *)calloc(8, sizeof(char));
    }

    // Iniciar el tablero
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = ' ';
        }
    }

    int opcion;

    do {
        // Mostrar menú de opciones
        printf("\n1.- Alfil\n2.- Caballo\n3.- Reina\n4.- Rey\n5.- Torre\n6.- Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Comprueba la opción seleccionada
        if (opcion >= 1 && opcion <= 5) {
            // Solicitar coordenadas
            printf("Ingresa la coordenada x: ");
            scanf("%d", &pieza.x);
            printf("Ingresa la coordenada y: ");
            scanf("%d", &pieza.y);

            // Actualizar el tipo de pieza
            if (opcion == 1) {
                pieza.tipo = 'A';
            } else if (opcion == 2) {
                pieza.tipo = 'C';
            } else if (opcion == 3) {
                pieza.tipo = 'Q';
            } else if (opcion == 4) {
                pieza.tipo = 'K';
            } else if (opcion == 5) {
                pieza.tipo = 'T';
            }

            // Calcular y mostrar los movimientos válidos
            movimientosValidos(tablero, pieza);
        }
    } while (opcion != 6);

    // Liberar la memoria asignada para el tablero
    free(tablero);

    return 0;
}

void movimientosValidos(char **tablero, struct piezaAjedrez pieza) {
    //  Calculo y muestra los movimientos válidos en el tablero
    printf("\nCoordenadas seleccionadas: (%d, %d)\n", pieza.x, pieza.y);
    printf("Movimientos válidos para la pieza de tipo %c:\n", pieza.tipo);

    // Marcamos la posición actual de la pieza en el tablero
    tablero[pieza.x][pieza.y] = pieza.tipo;

    // Movimientos permitidos para cada tipo de pieza
    if (pieza.tipo == 'A') { // Alfil
        // Movimientos diagonales
        // Comprueba si el movimiento del alfil es válido en una casilla específica y marca esa casilla con 'X' si lo es
        for (int i = 1; pieza.x + i < 8 && pieza.y + i < 8; i++) {
            tablero[pieza.x + i][pieza.y + i] = 'X'; // Movimiento hacia abajo-derecha
        }
        for (int i = 1; pieza.x + i < 8 && pieza.y - i >= 0; i++) {
            tablero[pieza.x + i][pieza.y - i] = 'X'; // Movimiento hacia abajo-izquierda
        }
        for (int i = 1; pieza.x - i >= 0 && pieza.y + i < 8; i++) {
            tablero[pieza.x - i][pieza.y + i] = 'X'; // Movimiento hacia arriba-derecha
        }
        for (int i = 1; pieza.x - i >= 0 && pieza.y - i >= 0; i++) {
            tablero[pieza.x - i][pieza.y - i] = 'X'; // Movimiento hacia arriba-izquierda
        }
    } else if (pieza.tipo == 'C') { // Caballo
        // Movimientos en forma de "L"
        // Comprueba si el movimiento del caballo es válido en una casilla específica y marca esa casilla con 'X' si lo es
        if (pieza.x + 2 < 8 && pieza.y + 1 < 8) tablero[pieza.x + 2][pieza.y + 1] = 'X'; //Comprueba si el movimiento del caballo dos filas hacia abajo y una columna hacia la derecha es válido.
        if (pieza.x + 2 < 8 && pieza.y - 1 >= 0) tablero[pieza.x + 2][pieza.y - 1] = 'X'; //Comprueba si el movimiento del caballo dos filas hacia abajo y una columna hacia la izquierda es válido.
        if (pieza.x - 2 >= 0 && pieza.y + 1 < 8) tablero[pieza.x - 2][pieza.y + 1] = 'X'; //Comprueba si el movimiento del caballo dos filas hacia arriba y una columna hacia la derecha es válido.
        if (pieza.x - 2 >= 0 && pieza.y - 1 >= 0) tablero[pieza.x - 2][pieza.y - 1] = 'X'; //Comprueba si el movimiento del caballo dos filas hacia arriba y una columna hacia la izquierda es válido
        if (pieza.x + 1 < 8 && pieza.y + 2 < 8) tablero[pieza.x + 1][pieza.y + 2] = 'X'; //Comprueba si el movimiento del caballo una fila hacia abajo y dos columnas hacia la derecha es válido
        if (pieza.x + 1 < 8 && pieza.y - 2 >= 0) tablero[pieza.x + 1][pieza.y - 2] = 'X'; //Comprueba si el movimiento del caballo una fila hacia abajo y dos columnas hacia la izquierda es válido
        if (pieza.x - 1 >= 0 && pieza.y + 2 < 8) tablero[pieza.x - 1][pieza.y + 2] = 'X'; //Comprueba si el movimiento del caballo una fila hacia arriba y dos columnas hacia la derecha es válido.
        if (pieza.x - 1 >= 0 && pieza.y - 2 >= 0) tablero[pieza.x - 1][pieza.y - 2] = 'X'; //Comprueba si el movimiento del caballo una fila hacia arriba y dos columnas hacia la izquierda es válido
    } else if (pieza.tipo == 'Q') { // Reina
        // Movimientos en todas las direcciones
        // Comprueba si el movimiento de la reina es válido en una casilla específica y marca esa casilla con 'X' si lo es
        for (int i = 1; pieza.x + i < 8; i++) tablero[pieza.x + i][pieza.y] = 'X'; // Movimiento hacia abajo
        for (int i = 1; pieza.x - i >= 0; i++) tablero[pieza.x - i][pieza.y] = 'X'; // Movimiento hacia arriba
        for (int i = 1; pieza.y + i < 8; i++) tablero[pieza.x][pieza.y + i] = 'X'; // Movimiento hacia la derecha
        for (int i = 1; pieza.y - i >= 0; i++) tablero[pieza.x][pieza.y - i] = 'X'; // Movimiento hacia la izquierda
        // Movimientos diagonales
        for (int i = 1; pieza.x + i < 8 && pieza.y + i < 8; i++) tablero[pieza.x + i][pieza.y + i] = 'X'; // Abajo-derecha
        for (int i = 1; pieza.x + i < 8 && pieza.y - i >= 0; i++) tablero[pieza.x + i][pieza.y - i] = 'X'; // Abajo-izquierda
        for (int i = 1; pieza.x - i >= 0 && pieza.y + i < 8; i++) tablero[pieza.x - i][pieza.y + i] = 'X'; // Arriba-derecha
        for (int i = 1; pieza.x - i >= 0 && pieza.y - i >= 0; i++) tablero[pieza.x - i][pieza.y - i] = 'X'; // Arriba-izquierda
    } else if (pieza.tipo == 'K') { // Rey
        // Movimientos en todas las direcciones, pero solo una casilla
        // Comprueba si el movimiento del rey es válido en una casilla específica y marca esa casilla con 'X' si lo es
        if (pieza.x + 1 < 8) tablero[pieza.x + 1][pieza.y] = 'X'; // Movimiento hacia abajo
        if (pieza.x - 1 >= 0) tablero[pieza.x - 1][pieza.y] = 'X'; // Movimiento hacia arriba
        if (pieza.y + 1 < 8) tablero[pieza.x][pieza.y + 1] = 'X'; // Movimiento hacia la derecha
        if (pieza.y - 1 >= 0) tablero[pieza.x][pieza.y - 1] = 'X'; // Movimiento hacia la izquierda
        if (pieza.x + 1 < 8 && pieza.y + 1 < 8) tablero[pieza.x + 1][pieza.y + 1] = 'X'; // Abajo-derecha
        if (pieza.x + 1 < 8 && pieza.y - 1 >= 0) tablero[pieza.x + 1][pieza.y - 1] = 'X'; // Abajo-izquierda
        if (pieza.x - 1 >= 0 && pieza.y + 1 < 8) tablero[pieza.x - 1][pieza.y + 1] = 'X'; // Arriba-derecha
        if (pieza.x - 1 >= 0 && pieza.y - 1 >= 0) tablero[pieza.x - 1][pieza.y - 1] = 'X'; // Arriba-izquierda
    } else if (pieza.tipo == 'T') { // Torre
        // Movimientos ortogonales
        // Comprueba si el movimiento de la torre es válido en una casilla específica y marca esa casilla con 'X' si lo es
        for (int i = 1; pieza.x + i < 8; i++) tablero[pieza.x + i][pieza.y] = 'X'; // Movimiento hacia abajo
        for (int i = 1; pieza.x - i >= 0; i++) tablero[pieza.x - i][pieza.y] = 'X'; // Movimiento hacia arriba
        for (int i = 1; pieza.y + i < 8; i++) tablero[pieza.x][pieza.y + i] = 'X'; // Movimiento hacia la derecha
        for (int i = 1; pieza.y - i >= 0; i++) tablero[pieza.x][pieza.y - i] = 'X'; // Movimiento hacia la izquierda
    }

    // Mostrar el tablero con los movimientos válidos
    imprimirTablero(tablero);
}

void liberarTablero(char **tablero) {
    // Liberar la memoria asignada para el tablero
    for (int i = 0; i < 8; i++) {
        free(tablero[i]);
    }
    free(tablero);
}

void imprimirTablero(char **tablero) {
    // Mostrar el tablero
    printf("\nTablero:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
    return;
}