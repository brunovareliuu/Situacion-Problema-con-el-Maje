#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
#include "Sistema.h"
using namespace std;

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para obtener entrada segura de entero
int obtenerEntero(const string& prompt) {
    int valor;
    while (true) {
        cout << prompt;
        try {
            if (cin >> valor) {
                limpiarBuffer();
                return valor;
            } else {
                throw invalid_argument("Entrada inválida");
            }
        } catch (const exception& e) {
            cout << "❌ Error: Por favor ingresa un número válido." << endl;
            limpiarBuffer();
        }
    }
}

// Función para obtener entrada segura de string
string obtenerString(const string& prompt) {
    string valor;
    cout << prompt;
    limpiarBuffer();
    getline(cin, valor);
    return valor;
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    cout << "\n🎬 ===== SISTEMA DE RECOMENDACIONES DE ENTRETENIMIENTO =====" << endl;
    cout << "1️⃣  Iniciar sesión con usuario existente" << endl;
    cout << "2️⃣  Crear nuevo usuario" << endl;
    cout << "3️⃣  Ver usuarios registrados" << endl;
    cout << "4️⃣  Salir" << endl;
    cout << "==========================================================" << endl;
}

// Función para mostrar el menú de usuario
void mostrarMenuUsuario(const string& nombreUsuario) {
    cout << "\n🎭 ===== MENÚ PRINCIPAL - " << nombreUsuario << " =====" << endl;
    cout << "1️⃣  Ver todo el contenido disponible" << endl;
    cout << "2️⃣  Ver contenido por categoría" << endl;
    cout << "3️⃣  Ver detalles de un elemento específico" << endl;
    cout << "4️⃣  Calificar un elemento" << endl;
    cout << "5️⃣  Ver Top 10 general" << endl;
    cout << "6️⃣  Ver Top 10 por categoría" << endl;
    cout << "7️⃣  Ver recomendaciones personalizadas" << endl;
    cout << "8️⃣  Ver mi perfil y estadísticas" << endl;
    cout << "9️⃣  Gestionar mis preferencias" << endl;
    cout << "🔟 Ver estadísticas generales del sistema" << endl;
    cout << "0️⃣  Cerrar sesión" << endl;
    cout << "=================================================" << endl;
}

// Función para mostrar menú de categorías
void mostrarMenuCategorias() {
    cout << "\n📂 Selecciona una categoría:" << endl;
    cout << "1. Películas" << endl;
    cout << "2. Series" << endl;
    cout << "3. Libros" << endl;
    cout << "4. Canciones" << endl;
    cout << "5. Podcasts" << endl;
}

// Función para obtener el tipo según la opción
string obtenerTipoPorOpcion(int opcion) {
    switch (opcion) {
        case 1: return "Pelicula";
        case 2: return "Serie";
        case 3: return "Libro";
        case 4: return "Cancion";
        case 5: return "Podcast";
        default: return "";
    }
}

// Función para crear nuevo usuario
void crearNuevoUsuario(Sistema& sistema) {
    cout << "\n🆕 ===== CREAR NUEVO USUARIO =====" << endl;
    
    string nombre = obtenerString("Ingresa tu nombre: ");
    if (nombre.empty()) {
        cout << "❌ El nombre no puede estar vacío." << endl;
        return;
    }
    
    string generoFavorito = obtenerString("¿Cuál es tu género favorito? ");
    if (generoFavorito.empty()) {
        cout << "❌ El género favorito no puede estar vacío." << endl;
        return;
    }
    
    // Preguntar por preferencias adicionales
    vector<string> preferencias;
    preferencias.push_back(generoFavorito); // Agregar el género favorito
    
    cout << "\n¿Quieres agregar más géneros de tu preferencia? (s/n): ";
    char respuesta;
    cin >> respuesta;
    
    if (respuesta == 's' || respuesta == 'S') {
        int numPreferencias = obtenerEntero("¿Cuántos géneros adicionales quieres agregar? ");
        
        for (int i = 0; i < numPreferencias; ++i) {
            string genero = obtenerString("Género " + to_string(i + 1) + ": ");
            if (!genero.empty()) {
                preferencias.push_back(genero);
            }
        }
    }
    
    if (sistema.crearUsuario(nombre, generoFavorito, preferencias)) {
        cout << "✅ ¡Usuario creado exitosamente!" << endl;
        cout << "💡 Ahora puedes iniciar sesión con tu nombre." << endl;
    }
}

// Función para gestionar preferencias
void gestionarPreferencias(Sistema& sistema) {
    Usuario* usuario = sistema.getUsuarioActual();
    if (!usuario) return;
    
    cout << "\n⚙️ ===== GESTIÓN DE PREFERENCIAS =====" << endl;
    cout << "1. Ver mis preferencias actuales" << endl;
    cout << "2. Agregar nueva preferencia" << endl;
    cout << "3. Eliminar preferencia" << endl;
    cout << "4. Volver al menú principal" << endl;
    
    int opcion = obtenerEntero("Selecciona una opción: ");
    
    switch (opcion) {
        case 1:
            usuario->mostrarPreferencias();
            break;
        case 2: {
            string nuevoGenero = obtenerString("Ingresa el nuevo género de preferencia: ");
            if (!nuevoGenero.empty()) {
                usuario->agregarPreferencia(nuevoGenero);
                cout << "✅ Preferencia '" << nuevoGenero << "' agregada!" << endl;
            }
            break;
        }
        case 3: {
            usuario->mostrarPreferencias();
            string generoEliminar = obtenerString("Ingresa el género que quieres eliminar: ");
            if (!generoEliminar.empty()) {
                usuario->eliminarPreferencia(generoEliminar);
                cout << "✅ Preferencia '" << generoEliminar << "' eliminada!" << endl;
            }
            break;
        }
        case 4:
            return;
        default:
            cout << "❌ Opción inválida." << endl;
    }
}

// Función para calificar contenido con validación
void calificarContenido(Sistema& sistema) {
    cout << "\n⭐ ===== CALIFICAR CONTENIDO =====" << endl;
    
    // Mostrar contenido disponible
    sistema.mostrarTodoElContenido();
    
    string titulo = obtenerString("Ingresa el título exacto del contenido que quieres calificar: ");
    if (titulo.empty()) {
        cout << "❌ El título no puede estar vacío." << endl;
        return;
    }
    
    int calificacion = obtenerEntero("Ingresa tu calificación (1-5 estrellas): ");
    
    sistema.calificarContenido(titulo, calificacion);
}

// Función para ver contenido por categoría
void verContenidoPorCategoria(Sistema& sistema) {
    mostrarMenuCategorias();
    int opcion = obtenerEntero("Selecciona una opción: ");
    
    string tipo = obtenerTipoPorOpcion(opcion);
    if (tipo.empty()) {
        cout << "❌ Opción inválida." << endl;
        return;
    }
    
    sistema.mostrarContenidoPorTipo(tipo);
}

// Función para ver top 10 por categoría
void verTop10PorCategoria(Sistema& sistema) {
    mostrarMenuCategorias();
    int opcion = obtenerEntero("Selecciona una opción: ");
    
    string tipo = obtenerTipoPorOpcion(opcion);
    if (tipo.empty()) {
        cout << "❌ Opción inválida." << endl;
        return;
    }
    
    sistema.mostrarTop10PorTipo(tipo);
}

// Función principal para el menú de usuario logueado
void menuUsuario(Sistema& sistema) {
    Usuario* usuario = sistema.getUsuarioActual();
    if (!usuario) return;
    
    int opcion;
    do {
        mostrarMenuUsuario(usuario->getNombre());
        opcion = obtenerEntero("Selecciona una opción: ");
        
        try {
            switch (opcion) {
                case 1:
                    sistema.mostrarTodoElContenido();
                    break;
                case 2:
                    verContenidoPorCategoria(sistema);
                    break;
                case 3: {
                    string titulo = obtenerString("Ingresa el título del contenido: ");
                    if (!titulo.empty()) {
                        sistema.mostrarDetallesContenido(titulo);
                    }
                    break;
                }
                case 4:
                    calificarContenido(sistema);
                    break;
                case 5:
                    sistema.mostrarTop10General();
                    break;
                case 6:
                    verTop10PorCategoria(sistema);
                    break;
                case 7:
                    sistema.mostrarRecomendacionesPersonalizadas();
                    break;
                case 8:
                    sistema.mostrarEstadisticasUsuario();
                    break;
                case 9:
                    gestionarPreferencias(sistema);
                    break;
                case 10:
                    sistema.mostrarEstadisticasGenerales();
                    break;
                case 0:
                    sistema.cerrarSesion();
                    cout << "📱 Regresando al menú principal..." << endl;
                    break;
                default:
                    cout << "❌ Opción inválida. Por favor intenta de nuevo." << endl;
            }
            
            if (opcion != 0) {
                cout << "\n⏸️ Presiona Enter para continuar...";
                cin.get();
            }
            
        } catch (const exception& e) {
            cout << "❌ Error: " << e.what() << endl;
        }
        
    } while (opcion != 0);
}

// Función principal
int main() {
    try {
        cout << "🎬 ¡Bienvenido al Sistema de Recomendaciones de Entretenimiento!" << endl;
        cout << "===============================================================" << endl;
        
        Sistema sistema;
        
        int opcion;
        do {
            mostrarMenuPrincipal();
            opcion = obtenerEntero("Selecciona una opción: ");
            
            switch (opcion) {
                case 1: {
                    sistema.mostrarUsuarios();
                    string nombre = obtenerString("Ingresa tu nombre de usuario: ");
                    if (!nombre.empty()) {
                        if (sistema.iniciarSesion(nombre)) {
                            menuUsuario(sistema);
                        }
                    }
                    break;
                }
                case 2:
                    crearNuevoUsuario(sistema);
                    break;
                case 3:
                    sistema.mostrarUsuarios();
                    break;
                case 4:
                    cout << "👋 ¡Gracias por usar nuestro sistema!" << endl;
                    cout << "💾 Guardando datos..." << endl;
                    sistema.guardarDatos();
                    cout << "✅ Datos guardados exitosamente." << endl;
                    cout << "🎬 ¡Hasta la próxima!" << endl;
                    break;
                default:
                    cout << "❌ Opción inválida. Por favor intenta de nuevo." << endl;
            }
            
            if (opcion != 4) {
                cout << "\n⏸️ Presiona Enter para continuar...";
                cin.get();
            }
            
        } while (opcion != 4);
        
    } catch (const exception& e) {
        cout << "❌ Error fatal en el sistema: " << e.what() << endl;
        return 1;
    }
    
    return 0;
} 