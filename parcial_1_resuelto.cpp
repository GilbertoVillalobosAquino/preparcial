#include <iostream> // Incluye la biblioteca para manejo de entrada y salida.
#include <string>   // Incluye la biblioteca para manejar strings.

// Definición de constantes
const int MAX_CLUBS = 10;      // Número máximo de clubes que se pueden crear.
const int MAX_MEMBERS = 50;    // Número máximo de miembros por club.

// Estructura para almacenar la información de cada miembro de un club
struct Member {
    std::string first_name;   // Nombre del miembro.
    std::string last_name;    // Apellido del miembro.
    int age;                  // Edad del miembro.
};

// Estructura para almacenar la información de cada club
struct Club {
    std::string name;             // Nombre del club.
    std::string creation_date;    // Fecha de creación del club.
    int max_capacity;             // Capacidad máxima de miembros que puede tener el club.
    Member* members[MAX_MEMBERS]; // Arreglo de punteros a miembros del club.
    int num_members = 0;          // Número de miembros registrados actualmente en el club.
};

// Función para crear un nuevo club y almacenarlo en el arreglo de clubes.
void CreateClub(Club clubs[], int &num_clubs, int max_clubs) {
    // Verifica si el número máximo de clubes ya se ha alcanzado.
    if (num_clubs >= max_clubs) {
        std::cout << "No se pueden crear más clubes.\n";
        return;
    }
    Club new_club; // Crea una nueva instancia de Club.
    // Solicita los datos del club al usuario.
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> new_club.name;
    std::cout << "Ingrese la fecha de creación (dd/mm/aaaa): ";
    std::cin >> new_club.creation_date;
    std::cout << "Ingrese la capacidad máxima del club: ";
    std::cin >> new_club.max_capacity;
    // Agrega el nuevo club al arreglo y aumenta el contador de clubes.
    clubs[num_clubs++] = new_club;
    std::cout << "Club creado exitosamente.\n";
}

// Función para listar todos los clubes almacenados en el arreglo.
void ListClubs(const Club clubs[], int num_clubs) {
    // Verifica si no hay clubes registrados.
    if (num_clubs == 0) {
        std::cout << "No hay clubes registrados.\n";
        return;
    }
    std::cout << "Lista de clubes:\n";
    // Itera sobre cada club y muestra su información.
    for (int i = 0; i < num_clubs; ++i) {
        std::cout << "Nombre: " << clubs[i].name 
                  << ", Fecha de creación: " << clubs[i].creation_date 
                  << ", Capacidad máxima: " << clubs[i].max_capacity 
                  << ", Miembros registrados: " << clubs[i].num_members << "\n";
    }
}

// Función para registrar un nuevo miembro en un club específico.
void RegisterMember(Club &club) {
    // Verifica si el club ha alcanzado su capacidad máxima de miembros.
    if (club.num_members >= club.max_capacity) {
        std::cout << "El club ha alcanzado su capacidad máxima.\n";
        return;
    }
    // Crea dinámicamente un nuevo miembro.
    Member* new_member = new Member;
    // Solicita al usuario los datos del miembro.
    std::cout << "Ingrese el nombre del miembro: ";
    std::cin >> new_member->first_name;
    std::cout << "Ingrese el apellido del miembro: ";
    std::cin >> new_member->last_name;
    std::cout << "Ingrese la edad del miembro: ";
    std::cin >> new_member->age;
    // Agrega el nuevo miembro al arreglo de miembros del club y actualiza el contador.
    club.members[club.num_members++] = new_member;
    std::cout << "Miembro registrado exitosamente.\n";
}

// Función para listar los miembros de un club dado.
void ListMembers(const Club &club) {
    // Verifica si no hay miembros registrados en el club.
    if (club.num_members == 0) {
        std::cout << "No hay miembros registrados en este club.\n";
        return;
    }
    std::cout << "Lista de miembros del club " << club.name << ":\n";
    // Itera sobre cada miembro y muestra su información.
    for (int i = 0; i < club.num_members; ++i) {
        std::cout << "Nombre: " << club.members[i]->first_name 
                  << " " << club.members[i]->last_name 
                  << ", Edad: " << club.members[i]->age << "\n";
    }
}

// Función para mostrar el número total de miembros de un club específico.
void TotalMembers(const Club &club) {
    std::cout << "El número total de miembros en el club " << club.name << " es: " << club.num_members << "\n";
}

// Función principal que controla el flujo del programa.
int main() {
    Club clubs[MAX_CLUBS]; // Arreglo para almacenar todos los clubes.
    int num_clubs = 0;     // Contador de clubes registrados.
    int option;            // Variable para almacenar la opción seleccionada por el usuario.

    do {
        // Muestra el menú de opciones al usuario.
        std::cout << "\nMenú de Gestión de Clubes\n";
        std::cout << "1. Crear un nuevo club\n";
        std::cout << "2. Listar todos los clubes\n";
        std::cout << "3. Registrar un miembro en un club\n";
        std::cout << "4. Listar los miembros de un club\n";
        std::cout << "5. Mostrar el número total de miembros en un club\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;

        // Estructura switch para gestionar las opciones del usuario.
        switch (option) {
            case 1:
                CreateClub(clubs, num_clubs, MAX_CLUBS); // Llama a la función para crear un club.
                break;
            case 2:
                ListClubs(clubs, num_clubs); // Llama a la función para listar los clubes.
                break;
            case 3: {
                std::string club_name;
                std::cout << "Ingrese el nombre del club: ";
                std::cin >> club_name;
                bool found = false; // Bandera para verificar si se encuentra el club.
                // Busca el club en el arreglo.
                for (int i = 0; i < num_clubs; ++i) {
                    if (clubs[i].name == club_name) {
                        RegisterMember(clubs[i]); // Registra un miembro en el club encontrado.
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Club no encontrado.\n";
                }
                break;
            }
            case 4: {
                std::string club_name;
                std::cout << "Ingrese el nombre del club: ";
                std::cin >> club_name;
                bool found = false;
                // Busca el club para listar sus miembros.
                for (int i = 0; i < num_clubs; ++i) {
                    if (clubs[i].name == club_name) {
                        ListMembers(clubs[i]); // Lista los miembros del club encontrado.
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Club no encontrado.\n";
                }
                break;
            }
            case 5: {
                std::string club_name;
                std::cout << "Ingrese el nombre del club: ";
                std::cin >> club_name;
                bool found = false;
                // Busca el club y muestra el total de miembros.
                for (int i = 0; i < num_clubs; ++i) {
                    if (clubs[i].name == club_name) {
                        TotalMembers(clubs[i]); // Muestra el número total de miembros.
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Club no encontrado.\n";
                }
                break;
            }
            case 6:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    } while (option != 6); // Repite el menú hasta que el usuario elija salir.

    return 0; // Indica que el programa terminó exitosamente.
}