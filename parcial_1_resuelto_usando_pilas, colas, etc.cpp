#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

// Definición de constantes
const int MAX_CAPACITY = 50;  // Capacidad máxima de miembros por club
const int MAX_HISTORY = 10;   // Número máximo de actividades recientes

// Estructura para almacenar la información de cada miembro de un club
struct Member {
    std::string first_name;
    std::string last_name;
    int age;
};

// Estructura para almacenar la información de cada club
struct Club {
    std::string name;
    std::string creation_date;
    int max_capacity;
    std::stack<Member> members;

    // Constructor para inicializar el club con su capacidad máxima
    Club(const std::string &n, const std::string &date, int capacity) 
        : name(n), creation_date(date), max_capacity(capacity) {}
};

// Función para agregar una actividad al historial
void LogActivity(std::queue<std::string> &activity_log, const std::string &activity) {
    if (activity_log.size() >= MAX_HISTORY) {
        activity_log.pop(); // Elimina la actividad más antigua si la cola está llena
    }
    activity_log.push(activity); // Agrega la nueva actividad al final de la cola
}

// Función para crear un nuevo club
void CreateClub(std::list<Club> &clubs, std::queue<std::string> &activity_log) {
    std::string name, date;
    int capacity;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> name;
    std::cout << "Ingrese la fecha de creación (dd/mm/aaaa): ";
    std::cin >> date;
    std::cout << "Ingrese la capacidad máxima del club: ";
    std::cin >> capacity;

    clubs.emplace_back(name, date, capacity); // Agrega el nuevo club a la lista
    LogActivity(activity_log, "Club creado: " + name); // Registra la actividad
    std::cout << "Club '" << name << "' creado exitosamente.\n";
}

// Función para listar todos los clubes
void ListClubs(const std::list<Club> &clubs) {
    if (clubs.empty()) {
        std::cout << "No hay clubes registrados.\n";
        return;
    }

    std::cout << "Lista de clubes:\n";
    for (const auto &club : clubs) {
        std::cout << "Nombre: " << club.name
                  << ", Fecha de creación: " << club.creation_date
                  << ", Capacidad máxima: " << club.max_capacity
                  << ", Miembros registrados: " << club.members.size() << "\n";
    }
}

// Función para registrar un miembro en un club específico
void RegisterMember(std::list<Club> &clubs, std::queue<std::string> &activity_log) {
    std::string club_name;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> club_name;

    auto it = std::find_if(clubs.begin(), clubs.end(),
                           [&club_name](const Club &club) { return club.name == club_name; });

    if (it == clubs.end()) {
        std::cout << "Club no encontrado.\n";
        return;
    }

    if (it->members.size() >= it->max_capacity) {
        std::cout << "El club ha alcanzado su capacidad máxima.\n";
        return;
    }

    Member new_member;
    std::cout << "Ingrese el nombre del miembro: ";
    std::cin >> new_member.first_name;
    std::cout << "Ingrese el apellido del miembro: ";
    std::cin >> new_member.last_name;
    std::cout << "Ingrese la edad del miembro: ";
    std::cin >> new_member.age;

    it->members.push(new_member); // Agrega el nuevo miembro a la pila de miembros del club
    LogActivity(activity_log, "Miembro registrado en club: " + club_name); // Registra la actividad
    std::cout << "Miembro registrado exitosamente en el club '" << club_name << "'.\n";
}

// Función para listar los miembros de un club dado
void ListMembers(const std::list<Club> &clubs) {
    std::string club_name;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> club_name;

    auto it = std::find_if(clubs.begin(), clubs.end(),
                           [&club_name](const Club &club) { return club.name == club_name; });

    if (it == clubs.end()) {
        std::cout << "Club no encontrado.\n";
        return;
    }

    if (it->members.empty()) {
        std::cout << "No hay miembros registrados en este club.\n";
        return;
    }

    std::stack<Member> temp_members = it->members;
    std::cout << "Lista de miembros del club '" << it->name << "':\n";
    while (!temp_members.empty()) {
        Member m = temp_members.top();
        temp_members.pop();
        std::cout << "Nombre: " << m.first_name << " " << m.last_name
                  << ", Edad: " << m.age << "\n";
    }
}

// Función para mostrar el número total de miembros en un club
void TotalMembers(const std::list<Club> &clubs) {
    std::string club_name;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> club_name;

    auto it = std::find_if(clubs.begin(), clubs.end(),
                           [&club_name](const Club &club) { return club.name == club_name; });

    if (it == clubs.end()) {
        std::cout << "Club no encontrado.\n";
        return;
    }

    std::cout << "El número total de miembros en el club '" << it->name
              << "' es: " << it->members.size() << "\n";
}

// Función para mostrar las actividades recientes del sistema
void ShowActivityLog(const std::queue<std::string> &activity_log) {
    if (activity_log.empty()) {
        std::cout << "No hay actividades recientes.\n";
        return;
    }

    std::cout << "Actividades recientes:\n";
    std::queue<std::string> temp_log = activity_log;
    while (!temp_log.empty()) {
        std::cout << "- " << temp_log.front() << "\n";
        temp_log.pop();
    }
}

// Función principal para controlar el flujo del programa
int main() {
    std::list<Club> clubs;                // Lista para almacenar todos los clubes.
    std::queue<std::string> activity_log; // Cola para el historial de actividades.
    int option;

    do {
        std::cout << "\nMenú de Gestión de Clubes\n";
        std::cout << "1. Crear un nuevo club\n";
        std::cout << "2. Listar todos los clubes\n";
        std::cout << "3. Registrar un miembro en un club\n";
        std::cout << "4. Listar los miembros de un club\n";
        std::cout << "5. Mostrar el número total de miembros en un club\n";
        std::cout << "6. Ver actividades recientes\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;

        switch (option) {
            case 1:
                CreateClub(clubs, activity_log);
                break;
            case 2:
                ListClubs(clubs);
                break;
            case 3:
                RegisterMember(clubs, activity_log);
                break;
            case 4:
                ListMembers(clubs);
                break;
            case 5:
                TotalMembers(clubs);
                break;
            case 6:
                ShowActivityLog(activity_log);
                break;
            case 7:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    } while (option != 7);

    return 0;
}
