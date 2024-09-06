#include <iostream>

using namespace std;

int sumArray(int arr[], int size) {
    // Caso base: si el tamaño del arreglo es 0, retornar 0
    if (size == 0) {
        return 0;
    }
    
    // Caso recursivo: sumar el primer elemento con la suma del resto del arreglo
    return arr[0] + sumArray(arr + 1, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int sum = sumArray(arr, size);
    
    cout << "Suma de los elementos del arreglo: " << sum << endl;
    
    return 0;
}