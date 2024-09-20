#include <iostream>
using namespace std;

void shellSort(int A[], int n) {
    int k = n + 1;
    
    while (k > 1) {
        k = k / 2;  // Dividimos el tamaño en cada iteración
        bool cen = true;
        
        while (cen) {
            cen = false;
            int i = 0;
            
            while (i + k < n) {
                if (A[i + k] < A[i]) {
                    // Intercambiamos los elementos
                    int aux = A[i];
                    A[i] = A[i + k];
                    A[i + k] = aux;
                    cen = true;
                }
                i++;
            }
        }
    }
}

int main() {
    int A[] = {12, 34, 54, 2, 3};
    int n = sizeof(A) / sizeof(A[0]);
    
    shellSort(A, n);
    
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}

