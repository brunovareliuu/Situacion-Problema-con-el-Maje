#include "Sistema.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Libro.h"
#include "Podcast.h"
#include "Cancion.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

Sistema::Sistema() : usuarioActual(nullptr) {
    cout << "Inicializando sistema..." << endl;
    cargarDatosDesdeArchivos();
    cout << "Sistema listo. Total elementos cargados: " << elementos.size() << endl;
}

Sistema::~Sistema() {
    guardarDatosEnArchivos();
    for (auto elemento : elementos) {
        delete elemento;
    }
}

// Gestión de usuarios
bool Sistema::registrarUsuario(const string& nombre, const string& password, 
                             const string& genero, const string& formato, 
                             const string& duracion) {
    // Verificar usuario existente
    for (const auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre) {
            cerr << "Error: Usuario ya existe\n";
            return false;
        }
    }
    usuarios.emplace_back(nombre, password, genero, formato, duracion);
    return true;
}

bool Sistema::iniciarSesion(const string& nombre, const string& password) {
    for (auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre && usuario.getPassword() == password) {
            usuarioActual = &usuario;
            return true;
        }
    }
    return false;
}

void Sistema::cerrarSesion() {
    usuarioActual = nullptr;
}

Usuario* Sistema::getUsuarioActual() const {
    return usuarioActual;
}

Usuario* Sistema::buscarUsuario(const string& nombre) {
    for (auto& usuario : usuarios) {
        if (usuario.getNombre() == nombre) {
            return &usuario;
        }
    }
    return nullptr;
}

// Archivos
void Sistema::cargarUsuarios(const string& archivo) {
    ifstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al abrir " << archivo << endl;
        return;
    }

    string linea;
    while (getline(file, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nombre, password, genero, formato, duracion;
        
        getline(ss, nombre, ',');
        getline(ss, password, ',');
        getline(ss, genero, ',');
        getline(ss, formato, ',');
        getline(ss, duracion);

        if (!nombre.empty()) {
            usuarios.emplace_back(nombre, password, genero, formato, duracion);
        }
    }
    file.close();
}

void Sistema::guardarUsuarios(const string& archivo) {
    ofstream file(archivo);
    if (!file.is_open()) {
        cerr << "Error al guardar " << archivo << endl;
        return;
    }

    for (const auto& usuario : usuarios) {
        file << usuario.getNombre() << ","
             << usuario.getPassword() << ","
             << usuario.getGeneroFavorito() << ","
             << usuario.getFormatoPreferido() << ","
             << usuario.getDuracionPreferida() << "\n";
    }
    file.close();
}

// Métodos de manejo de archivos para entretenimiento
void Sistema::cargarDatosDesdeArchivos() {
    cargarElementos("peliculas.txt", "Pelicula");
    cargarElementos("series.txt", "Serie");
    cargarElementos("libros.txt", "Libro");
    cargarElementos("canciones.txt", "Cancion");
    cargarElementos("podcasts.txt", "Podcast");
}

void Sistema::cargarElementos(const string& nombreArchivo, const string& tipo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Info: No se pudo abrir " << nombreArchivo << " (archivo podría no existir aún)" << endl;
        return;
    }
    
    string linea;
    int contador = 0;
    
    while (getline(archivo, linea) && contador < 50) { // Límite de seguridad
        contador++;
        
        Entretenimiento* elemento = Entretenimiento::fromFileString(linea, tipo);
        
        if (elemento) {
            elementos.push_back(elemento);
        }
    }
    
    archivo.close();
    cout << "Cargados " << contador << " elementos de " << tipo << " desde " << nombreArchivo << endl;
}

void Sistema::guardarDatosEnArchivos() {
    guardarElementosPorTipo("peliculas.txt", "Pelicula");
    guardarElementosPorTipo("series.txt", "Serie");
    guardarElementosPorTipo("libros.txt", "Libro");
    guardarElementosPorTipo("canciones.txt", "Cancion");
    guardarElementosPorTipo("podcasts.txt", "Podcast");
}

void Sistema::guardarElementosPorTipo(const string& nombreArchivo, const string& tipo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo guardar " << nombreArchivo << endl;
        return;
    }
    
    for (auto elemento : elementos) {
        if (elemento->tipo() == tipo) {
            archivo << elemento->toFileString() << endl;
        }
    }
    archivo.close();
}

// Calificaciones
bool Sistema::actualizarCalificacion(const string& usuario, const string& elemento, 
                                   int nuevaCalif) {
    if (nuevaCalif < 1 || nuevaCalif > 5) {
        cerr << "Error: La calificación debe ser entre 1 y 5\n";
        return false;
    }

    for (auto& user : usuarios) {
        if (user.getNombre() == usuario) {
            // Buscar si ya existe la calificación
            const auto& calificaciones = user.getCalificaciones();
            bool encontrado = false;
            for (const auto& calif : calificaciones) {
                if (calif.first == elemento) {
                    encontrado = true;
                    break;
                }
            }
            
            if (encontrado) {
                // Si existe, necesitamos implementar un método para actualizar
                // Por ahora, simplemente agregamos la nueva calificación
                user.agregarCalificacion(elemento, nuevaCalif);
            } else {
                // Si no existe, agregar nueva
                user.agregarCalificacion(elemento, nuevaCalif);
            }
            return true;
        }
    }
    cerr << "Error: Usuario no encontrado\n";
    return false;
}

void Sistema::mostrarRecomendaciones() const {
    if (!usuarioActual) {
        cout << "No hay usuario logueado\n";
        return;
    }
    
    cout << "\n=== RECOMENDACIONES PERSONALIZADAS ===" << endl;
    cout << "Basadas en tu genero favorito: " << usuarioActual->getGeneroFavorito() << endl;
    cout << "Y formato preferido: " << usuarioActual->getFormatoPreferido() << endl;
    
    vector<string> tipos = {"Pelicula", "Serie", "Libro", "Cancion", "Podcast"};
    
    for (string tipo : tipos) {
        Entretenimiento* recomendacion = nullptr;
        
        // Buscar primero por formato preferido y género favorito
        if (tipo == usuarioActual->getFormatoPreferido()) {
            for (auto elemento : elementos) {
                if (elemento->tipo() == tipo && 
                    elemento->getGenero() == usuarioActual->getGeneroFavorito() &&
                    elemento->getCalificaciones().empty()) {
                    recomendacion = elemento;
                    break;
                }
            }
        }
        
        // Si no encontró, buscar solo por tipo sin calificar
        if (!recomendacion) {
            for (auto elemento : elementos) {
                if (elemento->tipo() == tipo && elemento->getCalificaciones().empty()) {
                    recomendacion = elemento;
                    break;
                }
            }
        }
        
        if (recomendacion) {
            cout << "\n" << tipo << " recomendado:" << endl;
            recomendacion->mostrarInfo();
        }
    }
}

// Gestión de entretenimiento
void Sistema::agregarElemento(Entretenimiento* elemento) {
    if (elemento) {
        elementos.push_back(elemento);
        guardarDatosEnArchivos();
    }
}

vector<Entretenimiento*> Sistema::getElementos() const {
    return elementos;
}

void Sistema::mostrarElementos() const {
    if (elementos.empty()) {
        cout << "No hay elementos disponibles." << endl;
        return;
    }
    
    cout << "\n=== TODOS LOS ELEMENTOS ===" << endl;
    for (size_t i = 0; i < elementos.size(); i++) {
        cout << i + 1 << ". " << elementos[i]->getTitulo() 
             << " (" << elementos[i]->tipo() << ")" << endl;
    }
}

Entretenimiento* Sistema::buscarElemento(const string& titulo) const {
    for (auto elemento : elementos) {
        if (elemento->getTitulo() == titulo) {
            return elemento;
        }
    }
    return nullptr;
}

void Sistema::mostrarTop10(const string& tipo) const {
    cout << "\n=== TOP 10 MEJOR CALIFICADOS ===" << endl;
    
    vector<Entretenimiento*> elementosFiltrados;
    
    if (tipo.empty()) {
        // Mostrar todos los elementos calificados
        for (auto elemento : elementos) {
            if (!elemento->getCalificaciones().empty()) {
                elementosFiltrados.push_back(elemento);
            }
        }
    } else {
        // Filtrar por tipo
        for (auto elemento : elementos) {
            if (elemento->tipo() == tipo && !elemento->getCalificaciones().empty()) {
                elementosFiltrados.push_back(elemento);
            }
        }
    }
    
    if (elementosFiltrados.empty()) {
        cout << "No hay elementos calificados aun." << endl;
        return;
    }
    
    // Ordenar por calificación (mayor a menor)
    sort(elementosFiltrados.begin(), elementosFiltrados.end(), 
         [](Entretenimiento* a, Entretenimiento* b) {
             return a->promedioCalificaciones() > b->promedioCalificaciones();
         });
    
    int limite = min(10, (int)elementosFiltrados.size());
    for (int i = 0; i < limite; i++) {
        cout << i + 1 << ". " << elementosFiltrados[i]->getTitulo() 
             << " (" << elementosFiltrados[i]->tipo() << ") - "
             << elementosFiltrados[i]->promedioCalificaciones() << "/5" << endl;
    }
}