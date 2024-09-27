#include <iostream>
using namespace std;

int busquedaBinaria(int arr[], int inicio, int fin, int objetivo) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == objetivo)
            return medio;

        if (arr[medio] < objetivo)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 12;

    int resultado = busquedaBinaria(arr, 0, n - 1, objetivo);

    if (resultado == -1)
        cout << "El objetivo no se encuentra en el arreglo." << endl;
    else
        cout << "El objetivo se encuentra en la posición " << resultado << "." << endl;

    return 0;
}
