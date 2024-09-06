#include <iostream>
using namespace std;

int multiplicar(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return a + multiplicar(a, b - 1);
}

int main() {
    int num1, num2;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    
    int resultado = multiplicar(num1, num2);
    cout << "El resultado de la multiplicación es: " << resultado << endl;
    
    return 0;
}