/*
 * Fila.h
 *
 *  Created on: 4 oct 2024
 *      Author: P0L0
 */

#ifndef FILA_H_
#define FILA_H_
using namespace std;


class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class Fila {
private:
    Nodo* frente;
    Nodo* final;
    int longitud;

public:
    Fila() : frente(nullptr), final(nullptr), longitud(0) {}

    // Verifica si la fila está vacía
    bool EsFilaVacia() {
        return frente == nullptr;
    }

    // Devuelve el elemento al frente de la fila
    int Frente() {
        if (!EsFilaVacia()) {
            return frente->dato;
        }
        throw std::runtime_error("Fila vacía, no hay elemento al frente.");
    }

    // Elimina el elemento al frente de la fila (Defila)
    void Defila() {
        if (!EsFilaVacia()) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
            longitud--;

            if (frente == nullptr) { // Si la fila se vacía
                final = nullptr;
            }
        } else {
            throw std::runtime_error("Fila vacía, no se puede Defila.");
        }
    }

    // Agrega un nuevo elemento al final de la fila (Enfila)
    void Enfila(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (EsFilaVacia()) {
            frente = nuevoNodo;
            final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
        longitud++;
    }

    // Devuelve la longitud de la fila
    int Longitud() {
        return longitud;
    }

    // Verifica si un valor pertenece a la fila
    bool Pertenece(int valor) {
        Nodo* temp = frente;
        while (temp != nullptr) {
            if (temp->dato == valor) {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    void Mostrar() {
        if (EsFilaVacia()) {
            std::cout << "La fila está vacía." << std::endl;
        } else {
            Nodo* actual = frente;
            while (actual != nullptr) {
                std::cout << actual->dato << " ";
                actual = actual->siguiente;
            }
            std::cout << std::endl;
        }
    }

};




#endif /* FILA_H_ */
