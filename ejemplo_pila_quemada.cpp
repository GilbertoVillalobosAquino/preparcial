#include <iostream>
#include <stack>  // Incluye la biblioteca de pilas

using namespace std;

int main() {
    stack<int> pila;   // Definir una pila de enteros

    // Apilar elementos
    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout << "El elemento en la cima de la pila es: " << pila.top() << endl;  // Muestra el valor en la cima (30)

    // Desapilar elementos
    cout << "\nDesapilando elementos:\n";
    while (!pila.empty()) {
        cout << "Cima: " << pila.top() << endl;  // Mostrar el elemento en la cima
        pila.pop();                              // Eliminar el elemento en la cima
    }

    return 0;
}
