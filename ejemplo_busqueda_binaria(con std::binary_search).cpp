#include <iostream>
#include <vector>
#include <algorithm>  // Para std::sort y std::binary_search

using namespace std;

int main() {
    vector<int> arreglo = {2, 4, 5, 8, 9, 12};
    int valor = 8;

    // Es necesario que el arreglo esté ordenado
    sort(arreglo.begin(), arreglo.end());

    if (binary_search(arreglo.begin(), arreglo.end(), valor)) {
        cout << "Elemento encontrado en el arreglo." << endl;
    } else {
        cout << "Elemento no encontrado en el arreglo." << endl;
    }

    return 0;
}
