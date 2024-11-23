#ifndef REGISTRO_H
#define REGISTRO_H

#define MAX 80

struct tRegistro {
    int codigo;       // Código del ítem
    char itema[MAX];  // Nombre del ítem
    float valor;      // Precio del ítem
};

#define SIZE sizeof(tRegistro) // Tamaño de la estructura

#endif

