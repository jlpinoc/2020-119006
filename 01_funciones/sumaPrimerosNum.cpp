#include <iostream>

using namespace std;

int sumaPrimerosNumeros(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumaPrimerosNumeros(n - 1);
    }
}

int main() {
    int num;
    cout << "Ingrese un número: ";
    cin >> num;
    int resultado = sumaPrimerosNumeros(num);
    cout << "La suma de los primeros " << num << " números es: " << resultado << endl;
    return 0;
}