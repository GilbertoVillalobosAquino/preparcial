#include <iostream>
#include <queue>   // Incluye la biblioteca de colas

using namespace std;

int main() {
    queue<int> cola;   // Definir una cola de enteros

    // Encolar elementos
    cola.push(10);
    cola.push(20);
    cola.push(30);

    cout << "El frente de la cola es: " << cola.front() << endl;  // Muestra el frente de la cola (10)
    cout << "El final de la cola es: " << cola.back() << endl;    // Muestra el final de la cola (30)

    // Desencolar elementos
    cout << "\nDesencolando elementos:\n";
    while (!cola.empty()) {
        cout << "Frente: " << cola.front() << endl;
        cola.pop();   // Elimina el elemento del frente
    }

    return 0;
}
