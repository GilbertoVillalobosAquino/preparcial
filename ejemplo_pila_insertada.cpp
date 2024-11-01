#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> pila;
    int opcion;
    int valor;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Apilar un elemento\n";
        cout << "2. Desapilar un elemento\n";
        cout << "3. Mostrar el elemento en la cima\n";
        cout << "4. Mostrar el tamaño de la pila\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor a apilar: ";
                cin >> valor;
                pila.push(valor);
                cout << "Valor apilado.\n";
                break;

            case 2:
                if (!pila.empty()) {
                    cout << "Desapilando el elemento: " << pila.top() << endl;
                    pila.pop();
                } else {
                    cout << "La pila esta vacia.\n";
                }
                break;

            case 3:
                if (!pila.empty()) {
                    cout << "El elemento en la cima es: " << pila.top() << endl;
                } else {
                    cout << "La pila esta vacia.\n";
                }
                break;

            case 4:
                cout << "El tamaño de la pila es: " << pila.size() << endl;
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
