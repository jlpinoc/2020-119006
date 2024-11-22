#include <iostream>
#include <string>
using namespace std;
#include <fstream>

int main() {
	string ruc, producto;
	int unidades;
	double precio;
	char aux;
	ofstream archivo;
	
	archivo.open("output.txt"); //Apertura (creación)
	
	cout << "RUC del cliente (x para terminar): ";
	cin >> ruc;
	
	while (ruc != "X"){
		//Queda pendiente el Intro anterior...
		cin.get(aux); //Leemos el Intro
		cout << "Producto: ";
		getline(cin, producto);
		cout << "Unidades: ";
		cin >> unidades;
		cout << "Precio: ";
		cin >> precio;
		// Escribimos los dato en una línea del archivo...
		// Con un espacio de separación entre ellos
		archivo << ruc << " " << unidades << " "
			<< precio << " " << producto << endl;
		cout << "RUC del cliente (X para terminar): ";
		cin >> ruc;
	}
	//Escribimos el centineal final
	archivo << "X";
	archivo.close(); //Cierre del archivo
	
	return 0;
}