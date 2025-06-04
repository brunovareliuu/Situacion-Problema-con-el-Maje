#include <iostream>
#include <string>
#include "Usuario.h" 
using namespace std;

int main() {
    // 1. Pedir datos iniciales al usuario
    string nombre, genero;
    cout << "Ingresa tu nombre: ";
    getline(cin, nombre);  // Usamos getline para capturar nombres con espacios
    cout << "Cual es tu genero favorito? ";
    getline(cin, genero);

    // 2. Crear objeto Usuario
    Usuario usuario(nombre, genero);

    int opcion;
    do {
        // 3. Mostrar menú
        cout << "\n--- MENU ---" << endl;
        cout << "1: Ver Perfil" << endl;
        cout << "2: Cambiar genero" << endl;
        cout << "3: Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore();  // Limpiar el buffer para evitar problemas con getline

        // 4. Manejar opciones
        switch (opcion) {
            case 1:
                usuario.mostrarPerfil();
                break;
            case 2: {
                string nuevoGenero;
                cout << "Ingresa tu nuevo genero favorito: ";
                getline(cin, nuevoGenero);
                usuario.setGenero(nuevoGenero);  // Actualizar género
                cout << "Genero actualizado correctamente!" << endl;
                break;
            }
            case 3:
                cout << "Fue un placer, bye!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intenta de nuevo." << endl;
        }
    } while (opcion != 3);

    return 0;
}