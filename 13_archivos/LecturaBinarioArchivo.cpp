#include <iostream>
#include <fstream>
#include "registro.h"
using namespace std;
int main() {
	tRegistro registro;
	fstream archivo;
	archivo.open("bd.dat", ios::in | ios::binary);
	archivo.read( (char *) &registro, SIZE);
	int cuantos = archivo.gcount();
	while (cuantos == SIZE) {
		mostrar(registro); //Función mostrar registro
		archivo.read( (char *) &registro, SIZE);
		cuantos = archivo.gcount();
	}
	archivo.close();
	return 0;
}

const int MAX= 80;
struct tRegistro{
	int codigo;
	char itema[MAX];
	double valor;
};
int SIZE = sizeof(tRegistro);