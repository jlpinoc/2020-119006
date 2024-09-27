//1 Se tiene un polinomio almacenado en un arreglo. Se pide leer un monomio y buscar si forma parte del polinomio. Usa busqueda secuencial.
#include <iostream>
using namespace std;
bool buscarMonomio(int polinomio[], int tam, int monomio) {
    for (int i = 0; i < tam; i++) {
        if (polinomio[i] == monomio) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int polinomio[] = {2, 4, 6, 8, 10}; 
    int tam = sizeof(polinomio) / sizeof(polinomio[0]); 

    int monomio;
    cout << "Ingrese el monomio a buscar: ";
    cin >> monomio;

    if (buscarMonomio(polinomio, tam, monomio)) {
        cout << "El monomio forma parte del polinomio." << endl;
    } else {
        cout << "El monomio no forma parte del polinomio." << endl;
    }

    return 0;
}