#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> cola;
    int opcion;
    int valor;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Encolar un elemento\n";
        cout << "2. Desencolar un elemento\n";
        cout << "3. Mostrar el frente de la cola\n";
        cout << "4. Mostrar el final de la cola\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor a encolar: ";
                cin >> valor;
                cola.push(valor);
                cout << "Valor encolado.\n";
                break;

            case 2:
                if (!cola.empty()) {
                    cout << "Desencolando el elemento: " << cola.front() << endl;
                    cola.pop();
                } else {
                    cout << "La cola esta vacia.\n";
                }
                break;

            case 3:
                if (!cola.empty()) {
                    cout << "El frente de la cola es: " << cola.front() << endl;
                } else {
                    cout << "La cola esta vacia.\n";
                }
                break;

            case 4:
                if (!cola.empty()) {
                    cout << "El final de la cola es: " << cola.back() << endl;
                } else {
                    cout << "La cola esta vacia.\n";
                }
                break;

            case 5:
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opcion invalida, intenta de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
