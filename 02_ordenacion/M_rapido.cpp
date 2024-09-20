#include <iostream>
using namespace std;

void reduce(int A[], int inicio, int final) {
    int izq = inicio;
    int der = final;
    int pos = izq;
    bool cen = true;

    while (cen) {
        cen = false;

        // Recorrido de derecha a izquierda
        while (pos != der && A[pos] <= A[der]) {
            der--;
        }
        if (pos != der) {
            swap(A[pos], A[der]);
            pos = der;
        }

        // Recorrido de izquierda a derecha
        while (pos != izq && A[pos] >= A[izq]) {
            izq++;
        }
        if (pos != izq) {
            swap(A[pos], A[izq]);
            pos = izq;
            cen = true;
        }
    }

    // Llamada recursiva para el subarreglo izquierdo
    if (pos - 1 > inicio) {
        reduce(A, inicio, pos - 1);
    }
    
    // Llamada recursiva para el subarreglo derecho
    if (pos + 1 < final) {
        reduce(A, pos + 1, final);
    }
}

void quickSort(int A[], int n) {
    reduce(A, 0, n - 1);
}

int main() {
    int A[] = {33, 10, 55, 71, 29, 12, 2, 7};
    int n = sizeof(A) / sizeof(A[0]);
    
    quickSort(A, n);
    
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}
