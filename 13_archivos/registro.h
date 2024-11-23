#ifndef REGISTRO_H
#define REGISTRO_H

#define MAX 80

struct tRegistro {
    int codigo;       // C�digo del �tem
    char itema[MAX];  // Nombre del �tem
    float valor;      // Precio del �tem
};

#define SIZE sizeof(tRegistro) // Tama�o de la estructura

#endif

