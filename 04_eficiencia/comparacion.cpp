#include <iostream>
#include <chrono>  // Para medir el tiempo
using namespace std;
using namespace std::chrono;

// Tamaño máximo del arreglo
const int MAX_SIZE = 100;

// Función de intercambio
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Método de ordenación: Bubble Sort (con contador de iteraciones)
void bubbleSort(int arr[], int n, int &iteraciones) {
    iteraciones = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            iteraciones++;  // Contamos cada iteración
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Método de ordenación: Quick Sort (con contador de iteraciones)
int partition(int arr[], int low, int high, int &iteraciones) {
    int pivot = arr[high]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        iteraciones++;  // Contamos cada iteración
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int &iteraciones) {
    if (low < high) {
        int pi = partition(arr, low, high, iteraciones);
        quickSort(arr, low, pi - 1, iteraciones);
        quickSort(arr, pi + 1, high, iteraciones);
    }
}

// Método de búsqueda: Búsqueda Binaria (requiere arreglo ordenado, con contador de iteraciones)
int binarySearch(int arr[], int low, int high, int x, int &iteraciones) {
    iteraciones = 0;
    while (high >= low) {
        iteraciones++;  // Contamos cada iteración
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Método de búsqueda: Búsqueda Secuencial (con contador de iteraciones)
int sequentialSearch(int arr[], int n, int x, int &iteraciones) {
    iteraciones = 0;
    for (int i = 0; i < n; i++) {
        iteraciones++;  // Contamos cada iteración
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Función para imprimir el arreglo
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Función para calcular la memoria usada
void calcularMemoria(int n) {
    size_t memoriaUsada = n * sizeof(int);  // Tamaño en bytes
    cout << "Memoria usada por el arreglo: " << memoriaUsada << " bytes (" << memoriaUsada / 1024.0 << " KB)" << endl;
}

int main() {
    int arr[MAX_SIZE];  // Declaramos el arreglo con tamaño máximo
    int n;  // Cantidad de elementos a ingresar

    // Solicitar al usuario la cantidad de números que desea ingresar
    do {
        cout << "Ingresa el número de elementos (máximo " << MAX_SIZE << "): ";
        cin >> n;
        if (n > MAX_SIZE) {
            cout << "La cantidad de elementos no puede superar " << MAX_SIZE << ". Inténtalo de nuevo.\n";
        }
    } while (n > MAX_SIZE);

    // Ingreso de los elementos al arreglo
    cout << "Ingresa " << n << " números:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemento " << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "Arreglo original: ";
    printArray(arr, n);

    // Calcular memoria usada
    calcularMemoria(n);

    // Ordenación usando Bubble Sort con medición de tiempo y conteo de iteraciones
    int iteracionesBubble = 0;
    auto start = high_resolution_clock::now();
    bubbleSort(arr, n, iteracionesBubble);
    auto stop = high_resolution_clock::now();
    auto durationBubble = duration_cast<microseconds>(stop - start);
    cout << "Arreglo ordenado con Bubble Sort: ";
    printArray(arr, n);
    cout << "Iteraciones en Bubble Sort: " << iteracionesBubble << endl;
    cout << "Tiempo de Bubble Sort: " << durationBubble.count() << " microsegundos\n";

    // Ordenación usando Quick Sort con medición de tiempo y conteo de iteraciones
    int arr2[MAX_SIZE];  // Segundo arreglo para QuickSort
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];  // Copiamos los elementos del primer arreglo
    }

    int iteracionesQuick = 0;
    start = high_resolution_clock::now();
    quickSort(arr2, 0, n-1, iteracionesQuick);
    stop = high_resolution_clock::now();
    auto durationQuick = duration_cast<microseconds>(stop - start);
    cout << "Arreglo ordenado con Quick Sort: ";
    printArray(arr2, n);
    cout << "Iteraciones en Quick Sort: " << iteracionesQuick << endl;
    cout << "Tiempo de Quick Sort: " << durationQuick.count() << " microsegundos\n";

    // Búsqueda Binaria con medición de tiempo y conteo de iteraciones
    int x, iteracionesBinary;
    cout << "Ingresa el elemento a buscar con Búsqueda Binaria: ";
    cin >> x;
    start = high_resolution_clock::now();
    int result = binarySearch(arr2, 0, n - 1, x, iteracionesBinary);
    stop = high_resolution_clock::now();
    auto durationBinary = duration_cast<microseconds>(stop - start);
    if (result != -1)
        cout << "El elemento " << x << " se encuentra en el índice " << result << " (Búsqueda Binaria)\n";
    else
        cout << "Elemento no encontrado en el arreglo (Búsqueda Binaria)\n";
    cout << "Iteraciones en Búsqueda Binaria: " << iteracionesBinary << endl;
    cout << "Tiempo de Búsqueda Binaria: " << durationBinary.count() << " microsegundos\n";

    // Búsqueda Secuencial con medición de tiempo y conteo de iteraciones
    int iteracionesSecuencial;
    cout << "Ingresa el elemento a buscar con Búsqueda Secuencial: ";
    cin >> x;
    start = high_resolution_clock::now();
    result = sequentialSearch(arr2, n, x, iteracionesSecuencial);
    stop = high_resolution_clock::now();
    auto durationSecuencial = duration_cast<microseconds>(stop - start);
    if (result != -1)
        cout << "El elemento " << x << " se encuentra en el índice " << result << " (Búsqueda Secuencial)\n";
    else
        cout << "Elemento no encontrado en el arreglo (Búsqueda Secuencial)\n";
    cout << "Iteraciones en Búsqueda Secuencial: " << iteracionesSecuencial << endl;
    cout << "Tiempo de Búsqueda Secuencial: " << durationSecuencial.count() << " microsegundos\n";

    return 0;
}
