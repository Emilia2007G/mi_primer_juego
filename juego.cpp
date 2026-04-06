#include <iostream>
using namespace std;
int main() {
    int tablero[3][3] = {0}; // todo inicia en 0
    int fila, col;
    int jugador = 1;
    bool juegoTerminado = false;
   while (!juegoTerminado) {
    // IMpresion del tablero con los ceros
        cout << "TABLERO: "<< endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
        ///turno del jugador 1
        cout << "Turno del jugador " << jugador << endl;
        cout << "Ingrese fila (0-2): ";
        cin >> fila;
        cout << "Ingrese columna (0-2): ";
        cin >> col;
        //ver que no este fuera de rango
        if (fila < 0 or fila > 2 or col < 0 or col > 2) {
            cout << "Posicion fuera de rango. Intente de nuevo."<< endl;
        }
        //que la casilla no este ocupada si es diferente de cero esta ocupada
        else if (tablero[fila][col] != 0) {
            cout << "Casilla ocupada. Intentalo de nuevo."<< endl;
        }
        else{
            //marcar la casilla con el numero del jugador
            tablero[fila][col] = jugador;
        }
        //verificar si hizo 3 en raya
        //verificar las filas
        for (int i=0;i<3;i++){
            if (tablero[i][0] == jugador and 
                tablero[i][1] == jugador and 
                tablero[i][2] == jugador){
                cout << "Jugador " << jugador << " gana!"<< endl;
                juegoTerminado = true;
            }
        }
        //verfificar las columnas
        for (int j=0;j<3;j++){
            if (tablero[0][j] == jugador and 
                tablero[1][j] == jugador and 
                tablero[2][j] == jugador){
                cout << "Jugador " << jugador << " gana!"<< endl;
                juegoTerminado = true;
            }
        }
        //verificar las diagonales
        if (tablero[0][0] == jugador and 
            tablero[1][1] == jugador and 
            tablero[2][2] == jugador){
            cout << "Jugador " << jugador << " gana!"<< endl;
            juegoTerminado = true;
        }
        //verificar la diagonal inversa
        if (tablero[0][2] == jugador and 
            tablero[1][1] == jugador and 
            tablero[2][0] == jugador){
            cout << "Jugador " << jugador << " gana!"<< endl;
            juegoTerminado = true;
        }
        //si juego terminado es verdadero el if menciona el ganador y rompe el ciclo
        if (juegoTerminado) {
            cout << "Gana el jugador " << jugador << endl;
            break;
        }
        //verifica cada una de las casillas si alguna es ogual a 0 sig que no esta llena y sigue
        bool lleno = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i][j] == 0) {
                    lleno = false;
                }
            }
        }
        //si esta lleno y nadie gano es empate y rompe el ciclo
        if (lleno) {
            cout << "Empate!" << endl;
            break;
        }
        //cambiar de jugador
        if (jugador == 1) { 
            jugador = 2;
        }
        else {
            jugador = 1;
        }

}//FINAL del while
    return 0;
}//FINAL del main
