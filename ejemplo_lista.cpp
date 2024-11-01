#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> lista;
    int opcion;
    int valor;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Eliminar un elemento\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor a insertar al inicio: ";
                cin >> valor;
                lista.push_front(valor);
                cout << "Valor insertado al inicio.\n";
                break;

            case 2:
                cout << "Ingresa el valor a insertar al final: ";
                cin >> valor;
                lista.push_back(valor);
                cout << "Valor insertado al final.\n";
                break;

            case 3:
                cout << "Ingresa el valor a eliminar: ";
                cin >> valor;
                lista.remove(valor);
                cout << "Si el valor estaba en la lista, fue eliminado.\n";
                break;

            case 4:
                cout << "Lista actual: ";
                for (int v : lista) {
                    cout << v << " -> ";
                }
                cout << "nullptr\n";
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
