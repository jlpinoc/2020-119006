#include <iostream>
#include <fstream>
#include "registro.h"

using namespace std;

// Declaración de la función
void mostrar(const tRegistro& registro);

int main() {
    tRegistro registro;
    fstream archivo;

    archivo.open("bd.dat", ios::in | ios::binary);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    archivo.read((char*)&registro, SIZE);
    int cuantos = archivo.gcount();
    while (cuantos == SIZE) {
        mostrar(registro); // Llamada a la función mostrar
        archivo.read((char*)&registro, SIZE);
        cuantos = archivo.gcount();
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
