#include <iostream>
using namespace std;//
bool    juego_terminado; //Mantiene el juego en funcionamiento
const int ancho = 20;//Define el ancho del mapa del juego, se utiliza const para mantener el valor siempre igual
const int alto = 20;//Define el alto del mapa del juego
//variables para posicionamiento// 
int x;//Posicion en x
int y;//Posicion en y
int frutaX;
int frutaY;
int Puntaje;
enum eDireccion { STOP = 0, IZQ, DER, ARR, ABAJ };
eDireccion dir;
string palabra;
string division;
void config() {
    juego_terminado = false;
    dir = STOP;
    x = ancho / 2;
    y = alto / 2;
    frutaX = rand() % ancho;
    frutaY = rand() % alto;
    Puntaje = 0;
    

}
string pedir() {
    cout << "\n Ingrese una palabra: ";
    cin >> palabra;
    return palabra;
}
void personalizacion_muro(string z) {
    int a = 0;
    int longitud = 0;
    int dif = 0;
    while (a < ancho / z.size()) {
        for (int i = 0; i < z.size(); i++) {
            cout <<z[i];
            longitud++;
        }
        a++;
    }
    if (z.size() != ancho) {
        dif = ancho - longitud;
        for (int i = 0; i <= dif; i++) {
            cout << z[i];
        }
    }
    else {

    }
}

void graficas(string z) {
    system("cls");
    personalizacion_muro(z);
    cout << endl;
    for (int al = 0; al < alto; al++) {
        for (int j = 0; j < ancho; j++) {
            if (j == 0) {
                cout << "#";
            }if (al == y) {
                if (j == x) {
                    cout << "O";
                }
                else {
                   //out << " ";
                }
            }
            else {
                cout << " ";
                if (j == ancho - 1) {
                    cout << "#";
                }
            }
        }
        cout << endl;
    }
    personalizacion_muro(z);
}
void teclas() {

}
void logica() {

}
int main() {
    string z = pedir();
    config();
    while (juego_terminado != true) {
        graficas(z);
        teclas();
        logica();
    }
}