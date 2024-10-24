#include <iostream>
#include <chrono>
#include <cstdlib>  // Para generar números aleatorios
#include <ctime>    // Para la semilla aleatoria

using namespace std;

// Función para generar un arreglo con valores aleatorios
void generateRandomArray(int arr[], int n, int range) {
    srand(time(0));  // Inicializa la semilla aleatoria
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % range;  // Genera valores aleatorios entre 0 y el valor máximo definido por el usuario
    }
}

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Método de ordenación 1: Bubble Sort (con impresión de iteraciones)
void bubbleSort(int arr[], int n) {
    cout << "Iniciando Bubble Sort...\n";
    for (int i = 0; i < n-1; i++) {
        cout << "Iteración " << i+1 << ": ";
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        printArray(arr, n); // Imprimir el arreglo en cada iteración
        if (!swapped) break; // Optimización: Si no se hicieron intercambios, ya está ordenado
    }
    cout << "Bubble Sort completado.\n";
}

// Método de ordenación 2: Quick Sort (con impresión de iteraciones)
int partition(int arr[], int low, int high, int& iter) {
    int pivot = arr[high];
    int i = (low - 1); // Índice más pequeño
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    cout << "Iteración " << iter++ << ": ";
    printArray(arr, high + 1);  // Imprimir el estado actual del arreglo
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int& iter) {
    if (low < high) {
        int pi = partition(arr, low, high, iter);
        quickSort(arr, low, pi - 1, iter);
        quickSort(arr, pi + 1, high, iter);
    }
}

// Método de búsqueda 1: Búsqueda Lineal (con impresión de iteraciones)
int linearSearch(int arr[], int n, int key) {
    cout << "Iniciando Búsqueda Lineal...\n";
    for (int i = 0; i < n; i++) {
        cout << "Iteración " << i+1 << ": Comparando " << arr[i] << " con " << key << endl;
        if (arr[i] == key)
            return i; // Devuelve el índice donde se encuentra el elemento
    }
    return -1; // Si no se encuentra el elemento
}

// Método de búsqueda 2: Búsqueda Binaria (con impresión de iteraciones)
int binarySearch(int arr[], int low, int high, int key) {
    int iter = 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "Iteración " << iter++ << ": Comparando " << arr[mid] << " con " << key << endl;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Si no se encuentra el elemento
}

// Función para calcular la memoria utilizada por el arreglo
void calculateMemoryUsage(int n) {
    size_t memoryUsed = n * sizeof(int);  // Estimación de la memoria utilizada (en bytes)
    cout << "Memoria utilizada por el arreglo: " << memoryUsed << " bytes (" << memoryUsed / 1024.0 << " KB)\n";
}

int main() {
    int n, range;
    
    // Permitir al usuario definir el tamaño del arreglo y el rango de valores aleatorios
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    cout << "Ingrese el rango máximo de los valores aleatorios (ej. 100 para valores entre 0 y 100): ";
    cin >> range;
    
    // Crear el arreglo dinámicamente
    int* arr = new int[n];
    
    // Generar valores aleatorios para el arreglo
    generateRandomArray(arr, n, range);
    
    cout << "Arreglo generado aleatoriamente: ";
    printArray(arr, n);

    // Calcular el uso de memoria
    calculateMemoryUsage(n);

    // --------- Ordenación con Bubble Sort ---------
    int* arr1 = new int[n];  // Copia del arreglo original
    copy(arr, arr + n, arr1);  // Copiar el arreglo original a arr1
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr1, n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Bubble Sort tomó " << duration.count() << " microsegundos\n\n";
    
    // --------- Ordenación con Quick Sort ---------
    int* arr2 = new int[n];  // Otra copia del arreglo original
    copy(arr, arr + n, arr2);
    int iter = 1;  // Para contar las iteraciones en Quick Sort
    start = chrono::high_resolution_clock::now();
    quickSort(arr2, 0, n - 1, iter);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Quick Sort tomó " << duration.count() << " microsegundos\n\n";
    
    // --------- Búsqueda con Búsqueda Lineal ---------
    int key;
    cout << "Ingrese el valor a buscar con Búsqueda Lineal y Binaria: ";
    cin >> key;
    start = chrono::high_resolution_clock::now();
    int result = linearSearch(arr, n, key);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if (result != -1)
        cout << "Búsqueda Lineal: Elemento encontrado en el índice " << result << endl;
    else
        cout << "Búsqueda Lineal: Elemento no encontrado\n";
    cout << "Búsqueda Lineal tomó " << duration.count() << " microsegundos\n\n";
    
    // --------- Búsqueda con Búsqueda Binaria ---------
    start = chrono::high_resolution_clock::now();
    result = binarySearch(arr2, 0, n - 1, key);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if (result != -1)
        cout << "Búsqueda Binaria: Elemento encontrado en el índice " << result << endl;
    else
        cout << "Búsqueda Binaria: Elemento no encontrado\n";
    cout << "Búsqueda Binaria tomó " << duration.count() << " microsegundos\n\n";
    
    // Liberar la memoria dinámica
    delete[] arr;
    delete[] arr1;
    delete[] arr2;

    return 0;
}

