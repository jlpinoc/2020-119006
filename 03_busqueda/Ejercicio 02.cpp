// 2.-Se tienen los siguientes atributos del personal: código, apellidos, nombres, dias, mes y año de nacimiento. Se pide realizar una busqueda binaria por fecha de nacimiento. Use estructuras y arreglos.
#include <iostream>
using namespace std;

struct Personal {
    int codigo;
    string apellidos;
    string nombres;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
};

int busquedaBinaria(Personal arr[], int n, int dia, int mes, int anio) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio].anioNacimiento == anio && arr[medio].mesNacimiento == mes && arr[medio].diaNacimiento == dia) {
            return medio;
        }

        if (arr[medio].anioNacimiento < anio || (arr[medio].anioNacimiento == anio && arr[medio].mesNacimiento < mes) || (arr[medio].anioNacimiento == anio && arr[medio].mesNacimiento == mes && arr[medio].diaNacimiento < dia)) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return -1;
}

int main() {
    const int MAX_PERSONAL = 10;
    Personal personal[MAX_PERSONAL] = {
        {1, "Lopez", "Juan", 10, 5, 1990},
        {2, "Gomez", "Maria", 15, 8, 1985},
        {3, "Perez", "Pedro", 20, 3, 1992},
        {4, "Rodriguez", "Ana", 5, 10, 1988},
        {5, "Martinez", "Luis", 30, 1, 1995},
        {6, "Gonzalez", "Laura", 12, 7, 1991},
        {7, "Sanchez", "Carlos", 25, 4, 1987},
        {8, "Torres", "Sofia", 8, 11, 1993},
        {9, "Ramirez", "Diego", 18, 9, 1989},
        {10, "Flores", "Ana", 3, 6, 1994}
    };

    int dia, mes, anio;
    cout << "Ingrese la fecha de nacimiento a buscar (dd mm aaaa): ";
    cin >> dia >> mes >> anio;

    int indice = busquedaBinaria(personal, MAX_PERSONAL, dia, mes, anio);

    if (indice != -1) {
        cout << "El personal con la fecha de nacimiento especificada se encuentra en el índice " << indice << endl;
        cout << "Código: " << personal[indice].codigo << endl;
        cout << "Apellidos: " << personal[indice].apellidos << endl;
        cout << "Nombres: " << personal[indice].nombres << endl;
    } else {
        cout << "No se encontró personal con la fecha de nacimiento especificada." << endl;
    }

    return 0;
}