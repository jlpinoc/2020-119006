#include <iostream>
using namespace std;

int combinatoria(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return combinatoria(n - 1, k - 1) + combinatoria(n - 1, k);
    }
}

int main() {
    int n, k;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    cout << "Ingrese el valor de k: ";
    cin >> k;
    cout << "El resultado de combinatoria(" << n << ", " << k << ") es: " << combinatoria(n, k) << endl;
    return 0;
}