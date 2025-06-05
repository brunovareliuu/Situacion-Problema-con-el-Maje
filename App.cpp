#include "Sistema.h"
#include <iostream>
#include <limits>

using namespace std;

void mostrarMenuPrincipal() {
    cout << "Bienvenido, Ingresa una Opción Para Iniciar" << endl;
    cout << "1. Iniciar sesion" << endl;
    cout << "2. Registrar usuario" << endl;
    cout << "3. Salir" << endl;
    cout << "Opcion: ";
}

void mostrarMenuUsuario() {
    cout << "Hola, Elige una Opción" << endl;
    cout << "1. Ver mis preferencias" << endl;
    cout << "2. Calificar elemento" << endl;
    cout << "3. Cerrar sesion" << endl;
    cout << "Opcion: ";
}

int main() {
    Sistema sistema;
    sistema.cargarUsuarios("usuarios.txt"); // Cargar datos al iniciar

    int opcion;
    string nombre, password, genero, formato, duracion, elemento;
    int puntuacion;

    do {
        if (sistema.getUsuarioActual() == nullptr) {
            // Menú principal (no logueado)
            mostrarMenuPrincipal();
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case 1: // Login
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    cout << "Password: ";
                    getline(cin, password);
                    sistema.iniciarSesion(nombre, password);
                    break;

                case 2: // Registro
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    cout << "Password: ";
                    getline(cin, password);
                    cout << "Genero favorito (terror/accion/romance/psicologia/diversion): ";
                    getline(cin, genero);
                    cout << "Formato preferido (pelicula/serie/libro/cancion): ";
                    getline(cin, formato);
                    cout << "Duracion preferida (corta/mediana/larga): ";
                    getline(cin, duracion);

                    sistema.registrarUsuario(nombre, password, genero, formato, duracion);
                    break;

                case 3:
                    cout << "Guardando datos...\n";
                    sistema.guardarUsuarios("usuarios.txt");
                    cout << "Hasta pronto!\n";
                    break;

                default:
                    cout << "Opcion no valida!\n";
            }
        } else {
            // Menú de usuario (logueado)
            mostrarMenuUsuario();
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
                case 1: // Ver preferencias
                    sistema.getUsuarioActual()->mostrarPreferencias();
                    break;

                case 2: // Calificar
                    cout << "Nombre del elemento: ";
                    getline(cin, elemento);
                    cout << "Puntuacion (1-5): ";
                    cin >> puntuacion;
                    cin.ignore();
                    sistema.getUsuarioActual()->agregarCalificacion(elemento, puntuacion);
                    break;

                case 3: // Logout
                    sistema.cerrarSesion();
                    break;

                default:
                    cout << "Opcion no valida!\n";
            }
        }
    } while (opcion != 3 || sistema.getUsuarioActual() != nullptr);

    return 0;
}