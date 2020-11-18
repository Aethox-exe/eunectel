#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

int puntuacion;
int cuerpo[200][2];
int n;
int tam;
int tam2;
int dir;
int x;
int y;
int xc;
int yc;
int velocidad;
char tecla;
string Nombre;
int Nivel;
int Destello;
char r[1];

void inicializar_variables() {
	puntuacion = 0;
	n = 1;
	tam = 6;
	tam2 = 10;
	dir = 3;
	x = 10;
	y = 12;
	xc = 30;
	yc = 15;
	velocidad = 0;
	Nivel = 1;
}

bool Validar_Numeros() {
	if (r[0] >= '0') {
		if (r[0] <= '5') {
			return false;
		}
	}
}

//Basado en Borland
void Ubicacion_cursor(int x, int y)
{
	HANDLE hCon; //identifica objeto o recurso
	COORD dwPos; //coordenada 
	dwPos.X = x; //.  atributos en X y Y
	dwPos.Y = y; // Y va invertida , Posiciones
	hCon = GetStdHandle/*identificador especificado*/(STD_OUTPUT_HANDLE/*adquirir control de la consola*/);
	SetConsoleCursorPosition/*situa el cursor en alguna posicion de la consola*/(hCon, dwPos);
}

void OcultaCursor() {
	CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void sonido_inicio() {
	Beep(480, 200);//frecuencia(hz) y ms
	Beep(1568, 200);
	Beep(1568, 200);
	Beep(1568, 200);
	Beep(739.99, 200);
	Beep(783.99, 200);
	Beep(783.99, 200);
	Beep(783.99, 200);
	Beep(369.99, 200);
	Beep(392, 200);
	Beep(369.99, 200);
	Beep(392, 200);
	Beep(392, 400);
	Beep(196, 400);
}

void portada()
{
	system("color 0f");
	system("cls");
	int c = 24;//Distancia entre techo y suelo
	int f = 99;
	int r;
	char t = 178;
	for (int i = 20; i < f; i++) {
		Ubicacion_cursor(i, 0);
		cout << t;
		Ubicacion_cursor(i, c);
		cout << t;
	}
	for (int i = 0; i <= c; i++) {
		Ubicacion_cursor(20, i);
		cout << t;
		Ubicacion_cursor(f, i);
		cout << t;
	}
	string snkd[] = { "\t\t\t       ---_ .......---.","\t\t\t      (|\\ /      / /| \\  \\","\t\t\t      /  /     .'  -=-'   `.",
		"\t\t\t     /  /    .'             )","\t\t\t   /  /   .'        .)   /","\t\t\t  / o   o        _.-' /  .'",
		"\t\t\t  \\          .-'    / .'|","\t\t\t   \\___.-'//    .'.' \\|","\t\t\t    \\|  \\ | //   .'.' _ |*|",
		"\t\t\t     `   \\|//  .'.'  ||","\t\t\t      .  .// .'.' |   \\|","\t\t\t      \\`-|\\/ /    \\   \\*\\",
		"\t\t\t                     \\   \\*","\t\t\t                      \\   \\ ","\t\t\t                       \\_" };

	r = 2;
	for (int i = 0; i < 14; i++) {
		Ubicacion_cursor(20, r);
		r++;
		cout << snkd[i] << endl;
	}

	string snkl[] = { "\t\t\t ______                _____   ______  ______   _____         ","\t\t\t|      |     | |\\   | |       |           |    |      |      ",
		"\t\t\t|_____ |     | | \\  | |_____  |           |    |_____ |      ","\t\t\t|      |     | |  \\ | |       |           |    |      |      ","\t\t\t|_____ |_____| |   \\| |_____  |______     |    |_____ |____" };
	for (int i = 0; i < 5; i++) {
		Ubicacion_cursor(10, r);
		r++;
		cout << snkl[i] << endl;
	}
	Ubicacion_cursor(20, 23);
	cout << "\t\t\tPresione cualquier tecla para empezar";
	system("pause > arch");
	sonido_inicio();
}

void Usuario() {
	system("cls");
	system("color D");
	Ubicacion_cursor(1, 2);
	cout << "\t\tIngresa tu nombre: ";
	cin >> Nombre;
}

void inicio() {
	system("cls");
	system("color A");
	Ubicacion_cursor(1, 2);
	cout << "Bienvenido/a " + Nombre + " escoge tu opcion";
	Ubicacion_cursor(1, 4);
	cout << "\t\tDigita 1 para empezar ";
	Ubicacion_cursor(1, 5);
	cout << "\t\tDigita 2 para leer las instrucciones ";
	cout << endl << endl << "\t\t";
}

void velocidades() {
	system("cls");
	system("color B");
	Ubicacion_cursor(1, 2);
	cout << "Hola " + Nombre + " escoge en que nivel quieres empezar!!!";
	Ubicacion_cursor(1, 4);
	cout << "\t\tDigita 1 para facil ";
	Ubicacion_cursor(1, 5);
	cout << "\t\tDigita 2 para nivel medio ";
	Ubicacion_cursor(1, 6);
	cout << "\t\tDigita 3 para nivel dificil ";
	Ubicacion_cursor(1, 7);
	cout << "\t\tDigita 4 para nivel hardcore ";
	Ubicacion_cursor(1, 8);
	cout << "\t\tDigita 5 para nivel aleatorio ";
	cout << endl << endl << "\t\t";
}

void instrucciones() {
	system("cls");
	system("color 9");
	cout << Nombre + " lee atentamente las instrucciones" << endl << endl
		<< "\t\tUsa la letra 'w' para SUBIR." << endl
		<< "\t\tUsa la letra 'a' para ir a la IZQUIERDA." << endl
		<< "\t\tUsa la letra 's' para BAJAR." << endl
		<< "\t\tUsa la letra 'd' para ir a la DERECHA" << endl
		<< "\t\tUsa la letra 'p' para PAUSAR" << endl
		<< "\t\tNO toques los bordes o PERDERAS." << endl
		<< "\t\tNO te comas tu propia cola o obviamente tambien PERDERAS!" << endl << endl;
}

void Mapa() {
	system("cls");
	for (int i = 2; i < 78; i++)//paredes Horizantales
	{
		Ubicacion_cursor(i, 3);
		cout << ("=");//Linea horizontal
		Ubicacion_cursor(i, 23);
		cout << ("=");
	}
	for (int v = 4; v < 23; v++) {
		Ubicacion_cursor(2, v);
		cout << ("|°|");//linea vertical
		Ubicacion_cursor(75, v);
		cout << ("|°|");
	}
	Ubicacion_cursor(2, 3);//caracter fijo 
	cout << "o";//esquinas
	Ubicacion_cursor(2, 23);
	cout << "o";
	Ubicacion_cursor(77, 3);
	cout << "o";
	Ubicacion_cursor(77, 23);
	cout << "o";
}

void dibujar_cuerpo() {
	for (int i = 1; i < tam; i++) {
		Ubicacion_cursor(cuerpo[i][0], cuerpo[i][1]);
		cout << "*";
	}
}

void borrar_cuerpo() {
	Ubicacion_cursor(cuerpo[n][0], cuerpo[n][1]);
	cout << " ";
}

void teclear() {
	if (_kbhit()) {//funcion windows.h para verificar que se presiona una tecla
		tecla = _getch();//pertenece a conio.h
		if (tecla == 112)//pausa p
		{
			Beep(900, 50);
			Beep(1200, 50);
			_getch();//despausa
		}
		if (tecla == 119)//arriba w
		{
			if (dir != 2)
			{
				dir = 1;
			}
		}
		else
		{
			if (tecla == 115)//abajo s
			{
				if (dir != 1)
				{
					dir = 2;
				}
			}
			else
			{
				if (tecla == 100)//derecha d
				{
					if (dir != 4)
					{
						dir = 3;
					}
				}
				else {
					if (tecla == 97)//izquierda a
					{
						if (dir != 3)
						{
							dir = 4;
						}
					}
				}
			}
		}
	}
}

void guardar_posicion() {
	cuerpo[n][0] = x;
	cuerpo[n][1] = y;
	n++;
	if (n == tam) {
		n = 1;
	}
}

void cambiar_color(int random) {
	Beep(523, 100);
	if (random == 1) {
		system("color 1");
	}
	if (random == 2) {
		system("color 2");
	}
	if (random == 3) {
		system("color 3");
	}
	if (random == 4) {
		system("color 4");
	}
	if (random == 5) {
		system("color 5");
	}
	if (random == 6) {
		system("color 6");
	}
	if (random == 7) {
		system("color 7");
	}
	if (random == 8) {
		system("color 8");
	}
	if (random == 9) {
		system("color 9");
	}
	if (random == 10) {
		system("color A");
	}
	if (random == 11) {
		system("color B");
	}
	if (random == 12) {
		system("color C");
	}
	if (random == 13) {
		system("color D");
	}
	if (random == 14) {
		system("color F");
	}
	if (random == 15) {
		system("color E");
	}
}

void fruta() {
	int random = 1 + rand() % (15 - 1 + 1);
	Destello = random;
	if (x == xc) {
		if (y == yc) {
			xc = (rand() % 65) + 6;
			yc = (rand() % 15) + 5;
			tam++;
			puntuacion += 10;
			cambiar_color(random);
			Ubicacion_cursor(xc, yc);
			cout << "\xA2";//ó   Los números y letras que aparecen despúes de \x 
			//es el codigo ASCII de las letras pero en hexadecimal
		}
	}
}

void cambiar_velocidad() {
	if (tam == tam2) {
		Beep(700, 150);
		tam2 += 3;
		velocidad -= 5;
		Nivel++;
		system("color 07");
		cambiar_color(Destello);
	}
}

void puntaje() {
	Ubicacion_cursor(85, 5);
	cout << "***" + Nombre + "***";
	Ubicacion_cursor(85, 8);
	cout << "Puntaje: " << puntuacion;
	Ubicacion_cursor(85, 9);
	cout << "Longitud: " << tam;
	Ubicacion_cursor(85, 10);
	cout << "Nivel: " << Nivel;
}

bool game_over()
{
	if (y == 3)
	{
		return false;
	}
	if (y == 23)
	{
		return false;
	}
	if (x == 2)
	{
		return false;
	}
	if (x == 75)
	{
		return false;
	}
	for (int j = tam - 1; j > 0; j--)
	{
		if (cuerpo[j][0] == x)
		{
			if (cuerpo[j][1] == y)
			{
				return false;
			}
		}
	}
	return true;
}

void final() {
	Beep(329, 300);
	Beep(493, 300);
	Beep(698, 300);
	Beep(659, 600);
	Beep(783, 300);
	Beep(698, 300);
	Beep(659, 600);
	Beep(329, 100);
	Beep(493, 300);
	Beep(698, 300);
	Beep(659, 600);
	Beep(392, 250);
	Beep(440, 200);
	Beep(587, 300);
	Beep(349, 250);
	Beep(587, 500);
}

void pintar_final() {
	system("color CF");
	system("cls");
	cout << endl << endl;
	cout << "\t\t\t  _____      ___       ___  ___   _____ " << endl;
	cout << "\t\t\t / ___ |    /   |     /   |/   | |  ___|" << endl;
	cout << "\t\t\t| |        / /| |    / /|   /| | | |__  " << endl;
	cout << "\t\t\t| |  _    / ___ |   / / |__/ | | |  __| " << endl;
	cout << "\t\t\t| |_| |  / /  | |  / /       | | | |___ " << endl;
	cout << "\t\t\t\\_____/ /_/   |_| /_/        |_| |_____|" << endl;
	cout << "\t\t\t    _____   _     _   _____   _____     " << endl;
	cout << "\t\t\t   /  _  \\ | |   / / |  ___| |  _  \\    " << endl;
	cout << "\t\t\t   | | | | | |  / /  | |__   | |_| |    " << endl;
	cout << "\t\t\t   | | | | | | / /   |  __|  |  _  /    " << endl;
	cout << "\t\t\t   | |_| | | |/ /    | |___  | | \\ \\    " << endl;
	cout << "\t\t\t   \\_____/ |___/     |_____| |_|  \\_\\   " << endl;
	cout << endl << endl;
	cout << "\t\t\t\t" + Nombre + " tu puntuacion fue " << puntuacion << endl << endl;
	system("pause");
}

void Programas() {
	bool Control = true;
	bool Control2 = true;
	while (Control) {
		int respuesta = 0;
		while (Control2) {
			inicio();
			cin >> r;
			Control2 = Validar_Numeros();
		}
		Control2 = true;
		if (r[0] == '1') {
			while (Control2) {
				velocidades();
				cin >> r;
				Control2 = Validar_Numeros();
			}
			if (r[0] == '5') {
				r[0] = 49 + rand() % (52 - 49 + 1);//codigo ASCCI
			}
			if (r[0] == '1') {
				velocidad = 80;
			}
			if (r[0] == '2') {
				velocidad = 70;
			}
			if (r[0] == '3') {
				velocidad = 60;
			}
			if (r[0] == '4') {
				velocidad = 50;
			}
			Mapa();
			Ubicacion_cursor(xc, yc);
			cout << "\xA2";//ó//equivalente
			while (game_over()) {
				borrar_cuerpo();
				puntaje();
				guardar_posicion();
				dibujar_cuerpo();
				fruta();
				cambiar_velocidad();
				teclear();
				if (dir == 1) {
					y--;
				}
				if (dir == 2) {
					y++;
				}
				if (dir == 3) {
					x++;
				}
				if (dir == 4) {
					x--;
				}
				Sleep(velocidad);
			}
			final();
			pintar_final();
			Control = false;
		}
		if (r[0] == '2') {
			instrucciones();
			system("pause");
		}
	}
}

void Proceso() {
	srand(time(NULL));
	inicializar_variables();
	OcultaCursor();
	portada();
	Usuario();
	Programas();
}

bool recurrente() {
	system("cls");
	string r = "si";
	cout << endl;
	cout << Nombre << " Quieres terminar el programa???" << endl;
	cout << "Digita 'si' para finalizar" << endl;
	cin >> r;
	for (int longitud = 0; longitud < 2; longitud++) {
		if (r[longitud] == 'S') {
			r[longitud] = 's';
		}
		if (r[longitud] == 'I') {
			r[longitud] = 'i';
		}
	}
	if (r == "si") {
		cout << "Gracias por visitarnos" << endl;
		return false;
	}
	else {
		cout << endl;
		return true;
	}
}

int main() {
	bool Control = true;
	while (Control) {
		Proceso();
		Control = recurrente();
	}
	return 0;
}