#include <iostream>
#include <chrono> // para medir el tiempo

using namespace std;
using namespace std::chrono;

// Función para el algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función para Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivote
    int i = (low - 1); // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // Incrementar el índice del elemento más pequeño
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // Ordenar las partes
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int n = 5;
    int arr1[n] = {64, 25, 12, 22, 11};
    int arr2[n] = {64, 25, 12, 22, 11};

    // Medir tiempo para Bubble Sort
    auto start = high_resolution_clock::now();
    bubbleSort(arr1, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo para Bubble Sort: " << duration.count() << " microsegundos" << endl;

    // Medir tiempo para Quick Sort
    start = high_resolution_clock::now();
    quickSort(arr2, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo para Quick Sort: " << duration.count() << " microsegundos" << endl;

    return 0;
}

