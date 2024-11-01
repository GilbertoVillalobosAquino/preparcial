#include <iostream>
#include <vector>
#include <algorithm>  // Para std::sort

using namespace std;

int busquedaBinaria(const vector<int>& arreglo, int valor) {
    int inicio = 0;
    int fin = arreglo.size() - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arreglo[medio] == valor) {
            return medio;  // Devuelve la posición del elemento si se encuentra
        }
        if (arreglo[medio] < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;  // Devuelve -1 si el elemento no se encuentra
}

int main() {
    vector<int> arreglo = {2, 4, 5, 8, 9, 12};
    int valor = 8;

    int posicion = busquedaBinaria(arreglo, valor);
    if (posicion != -1) {
        cout << "Elemento encontrado en la posición: " << posicion << endl;
    } else {
        cout << "Elemento no encontrado en el arreglo." << endl;
    }

    return 0;
}
