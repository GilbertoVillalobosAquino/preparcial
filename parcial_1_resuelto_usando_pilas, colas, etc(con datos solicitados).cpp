#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

// Estructura para almacenar la información de cada miembro de un club
struct Member {
    std::string first_name;
    std::string last_name;
    int age;

    // Sobrecarga de operador < para ordenar por edad (de menor a mayor)
    bool operator<(const Member &other) const {
        return age < other.age;
    }
};

// Estructura para almacenar la información de cada club
struct Club {
    std::string name;
    std::string creation_date;
    int max_capacity;
    std::list<Member> members; // Lista de miembros del club
};

// Función para crear un nuevo club y agregarlo a la lista de clubes
void CreateClub(std::list<Club> &clubs) {
    Club new_club;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> new_club.name;
    std::cout << "Ingrese la fecha de creación (dd/mm/aaaa): ";
    std::cin >> new_club.creation_date;
    std::cout << "Ingrese la capacidad máxima del club: ";
    std::cin >> new_club.max_capacity;

    clubs.push_back(new_club);
    std::cout << "Club creado exitosamente.\n";
}

// Función para listar todos los clubes ordenados alfabéticamente
void ListClubs(std::list<Club> &clubs) {
    if (clubs.empty()) {
        std::cout << "No hay clubes registrados.\n";
        return;
    }
    
    // Ordenar los clubes alfabéticamente por nombre
    clubs.sort([](const Club &a, const Club &b) {
        return a.name < b.name;
    });

    std::cout << "Lista de clubes:\n";
    for (const auto &club : clubs) {
        std::cout << "Nombre: " << club.name 
                  << ", Fecha de creación: " << club.creation_date 
                  << ", Capacidad máxima: " << club.max_capacity 
                  << ", Miembros registrados: " << club.members.size() << "\n";
    }
}

// Función para registrar un nuevo miembro en un club específico utilizando una cola
void RegisterMember(std::list<Club> &clubs) {
    std::string club_name;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> club_name;

    auto it = std::find_if(clubs.begin(), clubs.end(), [&](const Club &c) {
        return c.name == club_name;
    });

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

    // Cola de miembros en espera
    std::queue<Member> waitlist;

    if (it->members.size() < it->max_capacity) {
        it->members.push_back(new_member);
    } else {
        waitlist.push(new_member);
    }

    std::cout << "Miembro registrado exitosamente.\n";
}

// Función para listar los miembros de un club dado, ordenados por edad
void ListMembers(const std::list<Club> &clubs) {
    std::string club_name;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> club_name;

    auto it = std::find_if(clubs.begin(), clubs.end(), [&](const Club &c) {
        return c.name == club_name;
    });

    if (it == clubs.end()) {
        std::cout << "Club no encontrado.\n";
        return;
    }

    if (it->members.empty()) {
        std::cout << "No hay miembros registrados en este club.\n";
        return;
    }

    // Crear una pila para almacenar los miembros (de forma invertida)
    std::stack<Member> members_stack;

    // Llenar la pila con los miembros
    for (const auto &member : it->members) {
        members_stack.push(member);
    }

    std::cout << "Lista de miembros del club " << club_name << ":\n";
    while (!members_stack.empty()) {
        const auto &member = members_stack.top();
        std::cout << "Nombre: " << member.first_name 
                  << " " << member.last_name 
                  << ", Edad: " << member.age << "\n";
        members_stack.pop();
    }
}

// Función para mostrar el número total de miembros de un club específico
void TotalMembers(const std::list<Club> &clubs) {
    std::string club_name;
    std::cout << "Ingrese el nombre del club: ";
    std::cin >> club_name;

    auto it = std::find_if(clubs.begin(), clubs.end(), [&](const Club &c) {
        return c.name == club_name;
    });

    if (it == clubs.end()) {
        std::cout << "Club no encontrado.\n";
        return;
    }

    std::cout << "El número total de miembros en el club " << club_name << " es: " << it->members.size() << "\n";
}

// Función principal que controla el flujo del programa
int main() {
    std::list<Club> clubs;
    int option;

    do {
        std::cout << "\nMenú de Gestión de Clubes\n";
        std::cout << "1. Crear un nuevo club\n";
        std::cout << "2. Listar todos los clubes\n";
        std::cout << "3. Registrar un miembro en un club\n";
        std::cout << "4. Listar los miembros de un club\n";
        std::cout << "5. Mostrar el número total de miembros en un club\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;

        switch (option) {
            case 1:
                CreateClub(clubs);
                break;
            case 2:
                ListClubs(clubs);
                break;
            case 3:
                RegisterMember(clubs);
                break;
            case 4:
                ListMembers(clubs);
                break;
            case 5:
                TotalMembers(clubs);
                break;
            case 6:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
                break;
        }
    } while (option != 6);

    return 0;
}
