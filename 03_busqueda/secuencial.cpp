#include <iostream>
using namespace std;

int busquedaSecuencial(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int arreglo[] = {1, 2, 3, 4, 5};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    int valorBuscado = 3;

    int resultado = busquedaSecuencial(arreglo, tamano, valorBuscado);

    if (resultado == -1) {
        cout << "El valor no se encontró en el arreglo." << endl;
    } else {
        cout << "El valor se encontró en la posición " << resultado << " del arreglo." << endl;
    }

    return 0;
}

