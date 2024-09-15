#include <iostream>
using namespace std;

// Función de intercambio directo a la derecha
void InterDirectoDer(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                // Intercambio
                int aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
}

// Función de intercambio directo a la izquierda
void InterDirectoIzq(int A[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (A[j] < A[j - 1]) {
                // Intercambio
                int aux = A[j - 1];
                A[j - 1] = A[j];
                A[j] = aux;
            }
        }
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int opcion;
    int n;

    cout << "Ingrese el tamano del arreglo: ";
    cin >> n;

    int A[n];
    cout << "Ingrese los elementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Intercambio directo hacia la derecha\n";
        cout << "2. Intercambio directo hacia la izquierda\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                InterDirectoDer(A, n);
                cout << "Arreglo ordenado : ";
                imprimirArreglo(A, n);
                break;
            case 2:
                InterDirectoIzq(A, n);
                cout << "Arreglo ordenado : ";
                imprimirArreglo(A, n);
                break;
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida, intente nuevamente.\n";
        }
    } while (opcion != 3);

    return 0;
}
