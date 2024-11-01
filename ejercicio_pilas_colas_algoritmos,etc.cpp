#include <iostream>    // Biblioteca para entrada y salida estándar
#include <string>      // Biblioteca para manipular cadenas de texto
#include <list>        // Biblioteca para usar listas
#include <queue>       // Biblioteca para usar colas
#include <stack>       // Biblioteca para usar pilas
#include <algorithm>   // Biblioteca para algoritmos de manipulación de contenedores

// Estructura para representar un libro
struct Book {
    std::string title;        // Título del libro
    std::string author;       // Autor del libro
    bool is_available;        // Estado de disponibilidad del libro (true si está disponible)

    // Sobrecarga del operador < para ordenar libros por título
    bool operator<(const Book &other) const {
        return title < other.title; // Comparar títulos de libros
    }
};

// Estructura para representar un usuario
struct User {
    std::string name;          // Nombre del usuario
    std::stack<Book> borrowed_books; // Pila de libros prestados por el usuario
};

// Lista de libros en la biblioteca
std::list<Book> library_books;

// Lista de usuarios registrados en la biblioteca
std::list<User> users;

// Función para agregar un nuevo libro a la biblioteca
void AddBook(std::list<Book> &library) {
    Book new_book; // Crear un nuevo objeto de tipo Book
    std::cout << "Ingrese el título del libro: ";
    std::cin.ignore(); // Ignorar el salto de línea restante en el búfer
    std::getline(std::cin, new_book.title); // Leer el título del libro
    std::cout << "Ingrese el autor del libro: ";
    std::getline(std::cin, new_book.author); // Leer el autor del libro
    new_book.is_available = true; // Inicialmente, el libro está disponible
    library.push_back(new_book); // Agregar el libro a la lista de libros
    std::cout << "Libro agregado a la biblioteca exitosamente.\n"; // Mensaje de éxito
}

// Función para agregar un nuevo usuario
void AddUser(std::list<User> &users) {
    User new_user; // Crear un nuevo objeto de tipo User
    std::cout << "Ingrese el nombre del usuario: ";
    std::cin.ignore(); // Ignorar el salto de línea restante en el búfer
    std::getline(std::cin, new_user.name); // Leer el nombre del usuario
    users.push_back(new_user); // Agregar el usuario a la lista de usuarios
    std::cout << "Usuario registrado exitosamente.\n"; // Mensaje de éxito
}

// Función para listar todos los libros en la biblioteca
void ListBooks(const std::list<Book> &library) {
    if (library.empty()) { // Verificar si no hay libros registrados
        std::cout << "No hay libros registrados en la biblioteca.\n"; // Mensaje de ausencia de libros
        return; // Salir de la función
    }

    // Crear una copia de la lista de libros para ordenarla
    std::list<Book> sorted_library = library; 
    sorted_library.sort(); // Ordenar la lista de libros por título

    std::cout << "Libros en la biblioteca:\n"; // Encabezado de la lista
    for (const auto &book : sorted_library) { // Iterar sobre cada libro en la lista
        std::cout << "Título: " << book.title // Mostrar el título del libro
                  << ", Autor: " << book.author // Mostrar el autor del libro
                  << ", Disponible: " << (book.is_available ? "Sí" : "No") << "\n"; // Mostrar disponibilidad
    }
}

// Función para listar todos los usuarios registrados
void ListUsers(const std::list<User> &users) {
    if (users.empty()) { // Verificar si no hay usuarios registrados
        std::cout << "No hay usuarios registrados.\n"; // Mensaje de ausencia de usuarios
        return; // Salir de la función
    }

    // Ordenar usuarios alfabéticamente por nombre
    std::list<User> sorted_users = users; // Crear una copia para ordenarla
    sorted_users.sort([](const User &a, const User &b) { return a.name < b.name; });

    std::cout << "Lista de usuarios:\n"; // Encabezado de la lista
    for (const auto &user : sorted_users) { // Iterar sobre cada usuario en la lista
        std::cout << "Nombre: " << user.name << "\n"; // Mostrar el nombre del usuario
    }
}

// Función para buscar un libro por título
void SearchBook(const std::list<Book> &library) {
    std::string title; // Variable para almacenar el título buscado
    std::cout << "Ingrese el título del libro a buscar: ";
    std::cin.ignore(); // Ignorar el salto de línea restante en el búfer
    std::getline(std::cin, title); // Leer el título del libro a buscar

    // Buscar el libro en la lista utilizando una expresión lambda
    auto it = std::find_if(library.begin(), library.end(), [&](const Book &book) {
        return book.title == title; // Comparar con el título buscado
    });

    if (it != library.end()) { // Verificar si se encontró el libro
        // Mostrar la información del libro encontrado
        std::cout << "Libro encontrado: " << it->title << ", Autor: " << it->author
                  << ", Disponible: " << (it->is_available ? "Sí" : "No") << "\n";
    } else {
        std::cout << "Libro no encontrado.\n"; // Mensaje si no se encontró el libro
    }
}

// Función para que un usuario solicite un libro
void BorrowBook(std::list<Book> &library, std::list<User> &users) {
    std::string user_name, book_title; // Variables para almacenar el nombre del usuario y el título del libro

    std::cout << "Ingrese el nombre del usuario: ";
    std::cin.ignore(); // Ignorar el salto de línea restante en el búfer
    std::getline(std::cin, user_name); // Leer el nombre del usuario

    // Buscar el usuario en la lista utilizando una expresión lambda
    auto user_it = std::find_if(users.begin(), users.end(), [&](const User &user) {
        return user.name == user_name; // Comparar con el nombre buscado
    });

    if (user_it == users.end()) { // Verificar si no se encontró el usuario
        std::cout << "Usuario no encontrado.\n"; // Mensaje de error
        return; // Salir de la función
    }

    std::cout << "Ingrese el título del libro que desea solicitar: ";
    std::getline(std::cin, book_title); // Leer el título del libro a solicitar

    // Buscar el libro en la lista que esté disponible
    auto book_it = std::find_if(library.begin(), library.end(), [&](const Book &book) {
        return book.title == book_title && book.is_available; // Comparar con el título y verificar disponibilidad
    });

    if (book_it != library.end()) { // Verificar si se encontró el libro disponible
        user_it->borrowed_books.push(*book_it); // Agregar el libro a la pila de libros prestados del usuario
        book_it->is_available = false; // Marcar el libro como no disponible
        std::cout << "Libro prestado exitosamente.\n"; // Mensaje de éxito
    } else {
        std::cout << "El libro no está disponible o no existe.\n"; // Mensaje de error
    }
}

// Función para que un usuario devuelva un libro
void ReturnBook(std::list<Book> &library, std::list<User> &users) {
    std::string user_name; // Variable para almacenar el nombre del usuario

    std::cout << "Ingrese el nombre del usuario: ";
    std::cin.ignore(); // Ignorar el salto de línea restante en el búfer
    std::getline(std::cin, user_name); // Leer el nombre del usuario

    // Buscar el usuario en la lista
    auto user_it = std::find_if(users.begin(), users.end(), [&](const User &user) {
        return user.name == user_name; // Comparar con el nombre buscado
    });

    if (user_it == users.end()) { // Verificar si no se encontró el usuario
        std::cout << "Usuario no encontrado.\n"; // Mensaje de error
        return; // Salir de la función
    }

    if (user_it->borrowed_books.empty()) { // Verificar si el usuario tiene libros prestados
        std::cout << "El usuario no tiene libros para devolver.\n"; // Mensaje de error
        return; // Salir de la función
    }

    Book returned_book = user_it->borrowed_books.top(); // Obtener el libro prestado más reciente
    user_it->borrowed_books.pop(); // Eliminar el libro de la pila de libros prestados

    // Buscar el libro en la lista de libros de la biblioteca
    auto book_it = std::find_if(library.begin(), library.end(), [&](const Book &book) {
        return book.title == returned_book.title; // Comparar con el título del libro devuelto
    });

    if (book_it != library.end()) { // Verificar si se encontró el libro en la biblioteca
        book_it->is_available = true; // Marcar el libro como disponible
        std::cout << "Libro devuelto exitosamente.\n"; // Mensaje de éxito
    } else {
        std::cout << "Error al devolver el libro.\n"; // Mensaje de error
    }
}

// Función principal
int main() {
    int option; // Variable para almacenar la opción seleccionada por el usuario

    do {
        // Mostrar el menú de opciones al usuario
        std::cout << "\n--- Sistema de Gestión de Biblioteca ---\n";
        std::cout << "1. Agregar un libro\n";
        std::cout << "2. Agregar un usuario\n";
        std::cout << "3. Listar libros\n";
        std::cout << "4. Listar usuarios\n";
        std::cout << "5. Buscar un libro\n";
        std::cout << "6. Solicitar un libro\n";
        std::cout << "7. Devolver un libro\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option; // Leer la opción seleccionada por el usuario

        // Procesar la opción seleccionada
        switch (option) {
            case 1:
                AddBook(library_books); // Llamar a la función para agregar un libro
                break;
            case 2:
                AddUser(users); // Llamar a la función para agregar un usuario
                break;
            case 3:
                ListBooks(library_books); // Llamar a la función para listar libros
                break;
            case 4:
                ListUsers(users); // Llamar a la función para listar usuarios
                break;
            case 5:
                SearchBook(library_books); // Llamar a la función para buscar un libro
                break;
            case 6:
                BorrowBook(library_books, users); // Llamar a la función para solicitar un libro
                break;
            case 7:
                ReturnBook(library_books, users); // Llamar a la función para devolver un libro
                break;
            case 8:
                std::cout << "Saliendo del programa.\n"; // Mensaje de salida
                break;
            default:
                std::cout << "Opción no válida.\n"; // Mensaje de error si la opción no es válida
                break;
        }
    } while (option != 8); // Repetir hasta que el usuario elija salir

    return 0; // Finalizar el programa
}
