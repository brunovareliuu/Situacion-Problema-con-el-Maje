#include <iostream>
#include <stdexcept>
#include "Sistema.h"
#include "Libro.h"
#include "Cancion.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Podcast.h"

using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "        PLATAFORMA DIGITAL" << endl;
    cout << "     Centro de Entretenimiento" << endl;
    cout << "========================================" << endl;
    cout << "" << endl;
    cout << "  1. Crear nueva cuenta" << endl;
    cout << "  2. Acceder al sistema" << endl;
    cout << "  0. Terminar programa" << endl;
    cout << "" << endl;
    cout << "Elige una opcion: ";
}

void mostrarMenuCategorias(Sistema& sistema) {
    cout << "\n=== SELECCIONAR CATEGORIA ===" << endl;
    cout << "1. Películas" << endl;
    cout << "2. Series" << endl;
    cout << "3. Libros" << endl;
    cout << "4. Canciones" << endl;
    cout << "5. Podcasts" << endl;
    cout << "Opción: ";
    
    int opcion;
    cin >> opcion;
    
    string tipo;
    switch (opcion) {
        case 1: tipo = "Pelicula"; break;
        case 2: tipo = "Serie"; break;
        case 3: tipo = "Libro"; break;
        case 4: tipo = "Cancion"; break;
        case 5: tipo = "Podcast"; break;
        default: 
            cout << "Opción inválida." << endl;
            return;
    }
    
    sistema.mostrarTop10(tipo);
}

void calificarElemento(Sistema& sistema) {
    if (!sistema.getUsuarioActual()) {
        cout << "Debe iniciar sesión primero." << endl;
        return;
    }
    
    vector<Entretenimiento*> elementos = sistema.getElementos();
    if (elementos.empty()) {
        cout << "No hay elementos disponibles." << endl;
        return;
    }
    
    cout << "\n=== CALIFICAR ENTRETENIMIENTO ===" << endl;
    cout << "Elementos disponibles:" << endl;
    
    for (size_t i = 0; i < elementos.size(); i++) {
        cout << i + 1 << ". " << elementos[i]->getTitulo() 
             << " (" << elementos[i]->tipo() << ")";
        if (!elementos[i]->getCalificaciones().empty()) {
            cout << " - Promedio: " << elementos[i]->promedioCalificaciones() << "/5";
        }
        cout << endl;
    }
    
    cout << "Seleccione un elemento (número): ";
    int seleccion;
    cin >> seleccion;
    
    if (seleccion < 1 || seleccion > (int)elementos.size()) {
        cout << "Selección inválida." << endl;
        return;
    }
    
    cout << "Ingrese su calificación (1-5): ";
    int calificacion;
    cin >> calificacion;
    
    if (calificacion < 1 || calificacion > 5) {
        cout << "La calificación debe ser entre 1 y 5." << endl;
        return;
    }
    
    elementos[seleccion - 1]->agregarCalificacion(calificacion);
    cout << "¡Calificación agregada!" << endl;
}

void buscarElemento(Sistema& sistema) {
    cout << "\n=== BUSCAR ELEMENTO ===" << endl;
    cout << "Ingrese el título a buscar: ";
    cin.ignore();
    string titulo;
    getline(cin, titulo);
    
    Entretenimiento* elemento = sistema.buscarElemento(titulo);
    if (elemento) {
        cout << "\nElemento encontrado:" << endl;
        elemento->mostrarInfo();
    } else {
        cout << "Elemento no encontrado." << endl;
    }
}

void agregarNuevoElemento(Sistema& sistema) {
    if (!sistema.getUsuarioActual()) {
        cout << "Debe iniciar sesión primero." << endl;
        return;
    }
    
    cout << "\n=== AGREGAR NUEVO ELEMENTO ===" << endl;
    cout << "¿Qué tipo de elemento desea agregar?" << endl;
    cout << "1. Película\n2. Serie\n3. Libro\n4. Canción\n5. Podcast" << endl;
    cout << "Opción: ";
    
    int tipo;
    cin >> tipo;
    
    if (tipo < 1 || tipo > 5) {
        cout << "Opción inválida." << endl;
        return;
    }
    
    cin.ignore();
    
    string titulo, genero, extra;
    int duracion, fecha;
    
    cout << "Título: ";
    getline(cin, titulo);
    cout << "Género: ";
    getline(cin, genero);
    cout << "Duración (páginas/minutos/segundos): ";
    cin >> duracion;
    cout << "Año: ";
    cin >> fecha;
    
    Entretenimiento* nuevoElemento = nullptr;
    
    switch (tipo) {
        case 1:
            nuevoElemento = new Pelicula(titulo, genero, duracion);
            break;
        case 2:
            nuevoElemento = new Serie(titulo, genero, duracion);
            break;
        case 3:
            cin.ignore();
            cout << "Autor: ";
            getline(cin, extra);
            nuevoElemento = new Libro(titulo, genero, duracion, extra);
            break;
        case 4:
            cin.ignore();
            cout << "Artista: ";
            getline(cin, extra);
            nuevoElemento = new Cancion(titulo, genero, duracion, extra);
            break;
        case 5:
            cin.ignore();
            cout << "Presentador: ";
            getline(cin, extra);
            nuevoElemento = new Podcast(titulo, genero, duracion, extra);
            break;
    }
    
    if (nuevoElemento) {
        nuevoElemento->setFecha(fecha);
        sistema.agregarElemento(nuevoElemento);
        cout << "¡Elemento agregado exitosamente!" << endl;
    }
}

int main() {
    try {
        Sistema sistema;
        int opcion;
        
        do {
            mostrarMenu();
            
            if (sistema.getUsuarioActual()) {
                cout << "\nUsuario actual: " << sistema.getUsuarioActual()->getNombre() << endl;
            } else {
                cout << "\nNo hay usuario logueado" << endl;
            }
            
            cout << "Opción: ";
            cin >> opcion;
            
            // Validar entrada
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada inválida. Intente de nuevo." << endl;
                continue;
            }
            
            switch (opcion) {
                case 1: {
                    string nombre, password, genero, formato, duracion;
                    cout << "\n=== REGISTRO DE USUARIO ===" << endl;
                    cout << "Nombre: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Password: ";
                    getline(cin, password);
                    cout << "Género favorito: ";
                    getline(cin, genero);
                    cout << "Formato preferido: ";
                    getline(cin, formato);
                    cout << "Duración preferida: ";
                    getline(cin, duracion);
                    
                    if (sistema.registrarUsuario(nombre, password, genero, formato, duracion)) {
                        cout << "¡Usuario registrado exitosamente!" << endl;
                    } else {
                        cout << "Error al registrar usuario." << endl;
                    }
                    break;
                }
                case 2: {
                    string nombre, password;
                    cout << "\n=== INICIAR SESIÓN ===" << endl;
                    cout << "Nombre: ";
                    cin.ignore();
                    getline(cin, nombre);
                    cout << "Password: ";
                    getline(cin, password);
                    
                    if (sistema.iniciarSesion(nombre, password)) {
                        cout << "¡Sesión iniciada exitosamente!" << endl;
                        if (sistema.getUsuarioActual()) {
                            sistema.getUsuarioActual()->mostrarPreferencias();
                        }
                    } else {
                        cout << "Credenciales incorrectas." << endl;
                    }
                    break;
                }
                case 3:
                    sistema.mostrarTop10();
                    break;
                case 4:
                    mostrarMenuCategorias(sistema);
                    break;
                case 5:
                    calificarElemento(sistema);
                    break;
                case 6:
                    sistema.mostrarRecomendaciones();
                    break;
                case 7:
                    sistema.mostrarElementos();
                    break;
                case 8:
                    buscarElemento(sistema);
                    break;
                case 9:
                    agregarNuevoElemento(sistema);
                    break;
                case 10: {
                    if (!sistema.getUsuarioActual()) {
                        cout << "Debe iniciar sesión primero." << endl;
                        break;
                    }
                    
                    string nombreElemento;
                    int nuevaCalif;
                    cout << "\n=== CAMBIAR CALIFICACIÓN ===" << endl;
                    cout << "Nombre del elemento: ";
                    cin.ignore();
                    getline(cin, nombreElemento);
                    cout << "Nueva calificación (1-5): ";
                    cin >> nuevaCalif;
                    
                    if (sistema.actualizarCalificacion(sistema.getUsuarioActual()->getNombre(), 
                                                     nombreElemento, nuevaCalif)) {
                        cout << "¡Calificación actualizada!" << endl;
                    } else {
                        cout << "Error al actualizar calificación." << endl;
                    }
                    break;
                }
                case 11:
                    sistema.cerrarSesion();
                    cout << "Sesión cerrada." << endl;
                    break;
                case 0:
                    cout << "¡Gracias por usar el sistema!" << endl;
                    break;
                default:
                    cout << "Opción inválida. Intente de nuevo." << endl;
            }
            
        } while (opcion != 0);
        
    } catch (exception& e) {
        cout << "Error del sistema: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
