#include "Sistema.h"
#include <iostream>
#include <limits>

using namespace std;

void mostrarMenuPrincipal() {
    cout << "\n=== MENÚ PRINCIPAL ===" << endl;
    cout << "1. Iniciar sesión" << endl;
    cout << "2. Registrar usuario" << endl;
    cout << "3. Salir" << endl;
    cout << "Opción: ";
}

void mostrarMenuUsuario() {
    cout << "\n=== MENÚ USUARIO ===" << endl;
    cout << "1. Ver mis preferencias" << endl;
    cout << "2. Calificar elemento" << endl;
    cout << "3. Ver recomendaciones" << endl;
    cout << "4. Cerrar sesión" << endl;
    cout << "Opción: ";
}

int main() {
    Sistema sistema;
    sistema.cargarUsuarios("usuarios.txt");
    sistema.cargarElementos("elementos.txt");

    int opcion;
    string nombre, password, genero, formato, duracion, elemento;
    int puntuacion;

    do {
        if (sistema.getUsuarioActual()) {
            mostrarMenuUsuario();
            cin >> opcion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (opcion) {
                case 1:
                    sistema.getUsuarioActual()->mostrarPreferencias();
                    break;
                case 2:
                    cout << "Elemento a calificar: ";
                    getline(cin, elemento);
                    cout << "Puntuación (1-5): ";
                    cin >> puntuacion;
                    sistema.actualizarCalificacion(
                        sistema.getUsuarioActual()->getNombre(), 
                        elemento, 
                        puntuacion
                    );
                    break;
                case 3:
                    sistema.mostrarRecomendaciones();
                    break;
                case 4:
                    sistema.cerrarSesion();
                    break;
                default:
                    cout << "Opción inválida\n";
            }
        } else {
            mostrarMenuPrincipal();
            cin >> opcion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (opcion) {
                case 1:
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    cout << "Contraseña: ";
                    getline(cin, password);
                    if (!sistema.iniciarSesion(nombre, password)) {
                        cout << "Credenciales incorrectas\n";
                    }
                    break;
                case 2:
                    cout << "Nombre: ";
                    getline(cin, nombre);
                    cout << "Contraseña: ";
                    getline(cin, password);
                    cout << "Género favorito: ";
                    getline(cin, genero);
                    cout << "Formato preferido: ";
                    getline(cin, formato);
                    cout << "Duración preferida: ";
                    getline(cin, duracion);
                    sistema.registrarUsuario(nombre, password, genero, formato, duracion);
                    break;
                case 3:
                    sistema.guardarUsuarios("usuarios.txt");
                    sistema.guardarElementos("elementos.txt");
                    cout << "Datos guardados. Hasta pronto!\n";
                    break;
                default:
                    cout << "Opción inválida\n";
            }
        }
    } while (opcion != 3 || sistema.getUsuarioActual());

    return 0;
}