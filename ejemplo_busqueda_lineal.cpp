#include <iostream>
#include <vector>

using namespace std;

int busquedaLineal(const vector<int>& arreglo, int valor) {
    for (int i = 0; i < arreglo.size(); i++) {
        if (arreglo[i] == valor) {
            return i;  // Devuelve la posición del elemento si se encuentra
        }
    }
    return -1;  // Devuelve -1 si el elemento no se encuentra
}

int main() {
    vector<int> arreglo = {5, 3, 8, 4, 2, 9};
    int valor = 4;

    int posicion = busquedaLineal(arreglo, valor);
    if (posicion != -1) {
        cout << "Elemento encontrado en la posición: " << posicion << endl;
    } else {
        cout << "Elemento no encontrado en el arreglo." << endl;
    }

    return 0;
}
