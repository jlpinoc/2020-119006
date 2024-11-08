#include <iostream>
#include <string>

using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
    string numeroPlaca;
    string color;
    string marca;
    int velocimetro;

public:
    // Constructor de la clase Vehiculo
    Vehiculo(string numPlaca, string color, string marca, int velocimetro)
        : numeroPlaca(numPlaca), color(color), marca(marca), velocimetro(velocimetro) {}

    // M�todo para mostrar los datos del veh�culo
    void mostrarDatos() {
        cout << "N�mero de placa: " << numeroPlaca << endl;
        cout << "Color: " << color << endl;
        cout << "Marca: " << marca << endl;
        cout << "Velocimetro: " << velocimetro << " km/h" << endl;
    }

    // M�todo para cambiar la velocidad
    void cambiarVelocidad(int nuevaVelocidad) {
        velocimetro = nuevaVelocidad;
        cout << "Nueva velocidad: " << velocimetro << " km/h" << endl;
    }
};

// Clase derivada Automovil
class Automovil : public Vehiculo {
private:
    int cantidadPuertas;
    int cantidadPasajeros;

public:
    // Constructor de la clase Automovil
    Automovil(string numPlaca, string color, string marca, int velocimetro, int puertas, int pasajeros)
        : Vehiculo(numPlaca, color, marca, velocimetro), cantidadPuertas(puertas), cantidadPasajeros(pasajeros) {}

    // M�todo para mostrar los datos del autom�vil
    void mostrarAutomovil() {
        mostrarDatos();
        cout << "Cantidad de puertas: " << cantidadPuertas << endl;
        cout << "Cantidad de pasajeros: " << cantidadPasajeros << endl;
    }

    // M�todo para subir pasajeros
    void subirPasajeros(int nuevosPasajeros) {
        cantidadPasajeros += nuevosPasajeros;
        cout << "Cantidad de pasajeros actual: " << cantidadPasajeros << endl;
    }

    // M�todo para bajar pasajeros
    void bajarPasajeros(int pasajerosQueBajan) {
        cantidadPasajeros -= pasajerosQueBajan;
        if (cantidadPasajeros < 0) cantidadPasajeros = 0;
        cout << "Cantidad de pasajeros actual: " << cantidadPasajeros << endl;
    }
};

// Clase derivada Camion
class Camion : public Vehiculo {
private:
    int carga;

public:
    // Constructor de la clase Camion
    Camion(string numPlaca, string color, string marca, int velocimetro, int cargaInicial)
        : Vehiculo(numPlaca, color, marca, velocimetro), carga(cargaInicial) {}

    // M�todo para mostrar los datos del cami�n
    void mostrarCamion() {
        mostrarDatos();
        cout << "Carga: " << carga << " kg" << endl;
    }

    // M�todo para cambiar la carga del cami�n
    void cambiarCarga(int nuevaCarga) {
        carga = nuevaCarga;
        cout << "Nueva carga: " << carga << " kg" << endl;
    }
};

// Funci�n principal
int main() {
    // Crear un objeto de Automovil
    Automovil auto1("ABC123", "Rojo", "Toyota", 0, 4, 5);
    cout << "Datos del Automovil:" << endl;
    auto1.mostrarAutomovil();
    auto1.subirPasajeros(2);
    auto1.bajarPasajeros(1);
    auto1.cambiarVelocidad(60);

    cout << "\n";

    // Crear un objeto de Camion
    Camion camion1("XYZ789", "Azul", "Volvo", 0, 1000);
    cout << "Datos del Camion:" << endl;
    camion1.mostrarCamion();
    camion1.cambiarCarga(2000);
    camion1.cambiarVelocidad(80);

    return 0;
}

