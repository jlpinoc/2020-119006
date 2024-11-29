//Actualización de un registro
#include <iostream>
#include <fstream>
#include "registro.h"
using namespace std;

// Declaración de la función
void mostrar(const tRegistro& registro);

int main(){
	tRegistro registro;
	fstream archivo;
	archivo.open("bd.dat", ios::in | ios::out | ios::binary);
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	int numReg = pos / SIZE;
	cout << "Numero de registros: " << numReg << endl;
	int num;
	cout << "Registro numero?: ";
	cin >> num;
	if ((num >0) && (num <= num <= numReg)){
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.read((char *) &registro, SIZE);
		mostrar(registro);
		cout << endl << "Cambiar nombre [S/N]? ";
		char c;
		cin.sync();
		cin >> c;
		if ((c == 's') || (c == 'S')){
			cout << "Nombre: ";
			cin.sync();
			cin.getline(registro.itema, 80);
		}
		cout << endl << "Cambiar precio[S/N]? ";
		cin.sync();
		cin >> c;
		if ((c == 's') || (c == 'S')){
			cout << "Precio: ";
			cin >> registro.valor;
		}
		archivo.seekg((num - 1) * SIZE, ios::beg);
		archivo.write( (char *) &registro, SIZE);
		cout << endl << "Registro actualizado:" << endl;
		archivo.seekg((num - 1) *SIZE, ios::beg);
		archivo.read( (char *) &registro, SIZE);
		mostrar(registro); 
	}
	archivo.close();
	return 0;
}

// Implementación de la función mostrar
void mostrar(const tRegistro& registro) {
    cout << "Codigo: " << registro.codigo << endl;
    cout << "Nombre: " << registro.itema << endl;
    cout << "Precio: " << registro.valor << endl;
    cout << "-------------------" << endl;
}