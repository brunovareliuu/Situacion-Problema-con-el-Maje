#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

// Constructor
Sistema::Sistema() : usuarioActual(nullptr) {
    cout << "🎬 Inicializando Sistema de Recomendaciones..." << endl;
    cargarDatos();
    if (contenido.empty()) {
        cout << "📝 Cargando contenido de demostración..." << endl;
        inicializarContenidoDemo();
    }
}

// Destructor
Sistema::~Sistema() {
    guardarDatos();
}

// ===== GESTIÓN DE USUARIOS =====

bool Sistema::crearUsuario(const string& nombre, const string& generoFavorito, 
                           const vector<string>& preferencias) {
    try {
        if (buscarUsuario(nombre) != -1) {
            cout << "❌ Error: Ya existe un usuario con ese nombre." << endl;
            return false;
        }
        
        if (preferencias.empty()) {
            usuarios.emplace_back(nombre, generoFavorito);
        } else {
            usuarios.emplace_back(nombre, generoFavorito, preferencias);
        }
        
        cout << "✅ Usuario '" << nombre << "' creado exitosamente!" << endl;
        return true;
    } catch (const exception& e) {
        cout << "❌ Error al crear usuario: " << e.what() << endl;
        return false;
    }
}

bool Sistema::iniciarSesion(const string& nombre) {
    try {
        int indice = buscarUsuario(nombre);
        if (indice == -1) {
            cout << "❌ Usuario no encontrado." << endl;
            return false;
        }
        
        usuarioActual = &usuarios[indice];
        cout << "✅ Sesión iniciada. ¡Bienvenido/a " << nombre << "!" << endl;
        return true;
    } catch (const exception& e) {
        cout << "❌ Error al iniciar sesión: " << e.what() << endl;
        return false;
    }
}

void Sistema::cerrarSesion() {
    if (usuarioActual) {
        cout << "👋 Hasta luego, " << usuarioActual->getNombre() << "!" << endl;
        usuarioActual = nullptr;
    }
}

// ===== MÉTODOS AUXILIARES =====

int Sistema::buscarUsuario(const string& nombre) {
    for (size_t i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].getNombre() == nombre) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int Sistema::buscarContenido(const string& titulo) {
    for (size_t i = 0; i < contenido.size(); ++i) {
        if (contenido[i]->getTitulo() == titulo) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// ===== GESTIÓN DE CONTENIDO =====

void Sistema::agregarPelicula(const string& titulo, const string& genero, int anio,
                              const string& director, const string& actorPrincipal,
                              int duracionMinutos, const string& clasificacion) {
    try {
        if (buscarContenido(titulo) != -1) {
            cout << "❌ Ya existe contenido con ese título." << endl;
            return;
        }
        
        contenido.push_back(make_unique<Pelicula>(titulo, genero, anio, director, 
                                                 actorPrincipal, duracionMinutos, clasificacion));
        cout << "✅ Película '" << titulo << "' agregada exitosamente!" << endl;
    } catch (const exception& e) {
        cout << "❌ Error al agregar película: " << e.what() << endl;
    }
}

void Sistema::agregarSerie(const string& titulo, const string& genero, int anio,
                          const string& creador, int temporadas, int episodiosTotales,
                          const string& plataforma, bool enEmision) {
    try {
        if (buscarContenido(titulo) != -1) {
            cout << "❌ Ya existe contenido con ese título." << endl;
            return;
        }
        
        contenido.push_back(make_unique<Serie>(titulo, genero, anio, creador, 
                                              temporadas, episodiosTotales, plataforma, enEmision));
        cout << "✅ Serie '" << titulo << "' agregada exitosamente!" << endl;
    } catch (const exception& e) {
        cout << "❌ Error al agregar serie: " << e.what() << endl;
    }
}

void Sistema::agregarLibro(const string& titulo, const string& genero, int anio,
                          const string& autor, const string& editorial, int numeroPaginas,
                          const string& isbn, bool esBestseller) {
    try {
        if (buscarContenido(titulo) != -1) {
            cout << "❌ Ya existe contenido con ese título." << endl;
            return;
        }
        
        contenido.push_back(make_unique<Libro>(titulo, genero, anio, autor, 
                                              editorial, numeroPaginas, isbn, esBestseller));
        cout << "✅ Libro '" << titulo << "' agregado exitosamente!" << endl;
    } catch (const exception& e) {
        cout << "❌ Error al agregar libro: " << e.what() << endl;
    }
}

void Sistema::agregarCancion(const string& titulo, const string& genero, int anio,
                            const string& artista, const string& album, int duracionSegundos,
                            const string& discografia, bool esSimple) {
    try {
        if (buscarContenido(titulo) != -1) {
            cout << "❌ Ya existe contenido con ese título." << endl;
            return;
        }
        
        contenido.push_back(make_unique<Cancion>(titulo, genero, anio, artista, 
                                                album, duracionSegundos, discografia, esSimple));
        cout << "✅ Canción '" << titulo << "' agregada exitosamente!" << endl;
    } catch (const exception& e) {
        cout << "❌ Error al agregar canción: " << e.what() << endl;
    }
}

void Sistema::agregarPodcast(const string& titulo, const string& genero, int anio,
                            const string& anfitrion, int duracionMinutos, int numeroEpisodio,
                            const string& plataforma, bool esExplicito) {
    try {
        if (buscarContenido(titulo) != -1) {
            cout << "❌ Ya existe contenido con ese título." << endl;
            return;
        }
        
        contenido.push_back(make_unique<Podcast>(titulo, genero, anio, anfitrion, 
                                                duracionMinutos, numeroEpisodio, plataforma, esExplicito));
        cout << "✅ Podcast '" << titulo << "' agregado exitosamente!" << endl;
    } catch (const exception& e) {
        cout << "❌ Error al agregar podcast: " << e.what() << endl;
    }
}

// ===== CALIFICACIONES =====

bool Sistema::calificarContenido(const string& titulo, int calificacion) {
    try {
        if (!usuarioActual) {
            cout << "❌ Debes iniciar sesión para calificar contenido." << endl;
            return false;
        }
        
        if (!Entretenimiento::validarCalificacion(calificacion)) {
            cout << "❌ La calificación debe estar entre 1 y 5." << endl;
            return false;
        }
        
        int indice = buscarContenido(titulo);
        if (indice == -1) {
            cout << "❌ Contenido no encontrado." << endl;
            return false;
        }
        
        // Agregar calificación al contenido
        contenido[indice]->agregarCalificacion(calificacion);
        
        // Agregar al historial del usuario
        usuarioActual->agregarCalificacion(titulo, calificacion);
        
        cout << "✅ Has calificado '" << titulo << "' con " << calificacion << " estrellas!" << endl;
        return true;
    } catch (const exception& e) {
        cout << "❌ Error al calificar contenido: " << e.what() << endl;
        return false;
    }
}

// ===== VISUALIZACIÓN =====

void Sistema::mostrarTodoElContenido() {
    if (contenido.empty()) {
        cout << "📭 No hay contenido disponible." << endl;
        return;
    }
    
    cout << "\n🎬 ===== TODO EL CONTENIDO DISPONIBLE =====" << endl;
    for (const auto& item : contenido) {
        item->mostrarInfo();
    }
    cout << "==========================================\n" << endl;
}

void Sistema::mostrarContenidoPorTipo(const string& tipo) {
    cout << "\n🔍 ===== CONTENIDO DE TIPO: " << tipo << " =====" << endl;
    bool encontrado = false;
    
    for (const auto& item : contenido) {
        if (item->getTipo() == tipo) {
            item->mostrarInfo();
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "📭 No se encontró contenido de tipo '" << tipo << "'." << endl;
    }
    cout << "==========================================\n" << endl;
}

void Sistema::mostrarDetallesContenido(const string& titulo) {
    int indice = buscarContenido(titulo);
    if (indice == -1) {
        cout << "❌ Contenido '" << titulo << "' no encontrado." << endl;
        return;
    }
    
    contenido[indice]->mostrarDetalles();
}

// ===== RANKINGS =====

void Sistema::mostrarTop10General() {
    if (contenido.empty()) {
        cout << "📭 No hay contenido disponible." << endl;
        return;
    }
    
    // Crear vector de punteros para ordenar
    vector<Entretenimiento*> items;
    for (const auto& item : contenido) {
        if (item->getTotalCalificaciones() > 0) { // Solo incluir contenido calificado
            items.push_back(item.get());
        }
    }
    
    // Ordenar por calificación promedio (descendente)
    sort(items.begin(), items.end(), [](const Entretenimiento* a, const Entretenimiento* b) {
        return a->getCalificacionPromedio() > b->getCalificacionPromedio();
    });
    
    cout << "\n🏆 ===== TOP 10 GENERAL =====" << endl;
    int limite = min(10, static_cast<int>(items.size()));
    
    for (int i = 0; i < limite; ++i) {
        cout << "#" << (i + 1) << " ";
        items[i]->mostrarInfo();
    }
    
    if (items.empty()) {
        cout << "📭 No hay contenido calificado aún." << endl;
    }
    cout << "============================\n" << endl;
}

void Sistema::mostrarTop10PorTipo(const string& tipo) {
    vector<Entretenimiento*> items;
    for (const auto& item : contenido) {
        if (item->getTipo() == tipo && item->getTotalCalificaciones() > 0) {
            items.push_back(item.get());
        }
    }
    
    sort(items.begin(), items.end(), [](const Entretenimiento* a, const Entretenimiento* b) {
        return a->getCalificacionPromedio() > b->getCalificacionPromedio();
    });
    
    cout << "\n🏆 ===== TOP 10 " << tipo << "S =====" << endl;
    int limite = min(10, static_cast<int>(items.size()));
    
    for (int i = 0; i < limite; ++i) {
        cout << "#" << (i + 1) << " ";
        items[i]->mostrarInfo();
    }
    
    if (items.empty()) {
        cout << "📭 No hay " << tipo << "s calificadas aún." << endl;
    }
    cout << "============================\n" << endl;
}

// ===== RECOMENDACIONES =====

void Sistema::mostrarRecomendacionesPersonalizadas() {
    if (!usuarioActual) {
        cout << "❌ Debes iniciar sesión para ver recomendaciones." << endl;
        return;
    }
    
    cout << "\n⭐ ===== RECOMENDACIONES PARA " << usuarioActual->getNombre() << " =====" << endl;
    
    // Obtener recomendaciones por tipo
    vector<string> tipos = {"Pelicula", "Serie", "Libro", "Cancion", "Podcast"};
    
    for (const string& tipo : tipos) {
        vector<Entretenimiento*> recomendaciones = obtenerRecomendaciones(tipo, 2);
        
        if (!recomendaciones.empty()) {
            cout << "\n🎯 " << tipo << "s recomendadas:" << endl;
            for (auto* item : recomendaciones) {
                item->mostrarInfo();
            }
        }
    }
    cout << "================================================\n" << endl;
}

vector<Entretenimiento*> Sistema::obtenerRecomendaciones(const string& tipo, int cantidad) {
    if (!usuarioActual) return {};
    
    vector<Entretenimiento*> candidatos;
    vector<string> preferencias = usuarioActual->getPreferencias();
    
    // Filtrar por tipo y preferencias del usuario
    for (const auto& item : contenido) {
        if (item->getTipo() == tipo && !usuarioActual->haCalificado(item->getTitulo())) {
            // Priorizar contenido de géneros preferidos
            for (const string& genero : preferencias) {
                if (item->getGenero() == genero) {
                    candidatos.push_back(item.get());
                    break;
                }
            }
        }
    }
    
    // Si no hay suficientes de géneros preferidos, agregar otros
    if (candidatos.size() < cantidad) {
        for (const auto& item : contenido) {
            if (item->getTipo() == tipo && !usuarioActual->haCalificado(item->getTitulo())) {
                bool yaEnLista = find(candidatos.begin(), candidatos.end(), item.get()) != candidatos.end();
                if (!yaEnLista) {
                    candidatos.push_back(item.get());
                }
            }
        }
    }
    
    // Ordenar por calificación promedio
    sort(candidatos.begin(), candidatos.end(), [](const Entretenimiento* a, const Entretenimiento* b) {
        return a->getCalificacionPromedio() > b->getCalificacionPromedio();
    });
    
    // Limitar la cantidad
    if (candidatos.size() > cantidad) {
        candidatos.resize(cantidad);
    }
    
    return candidatos;
}

// ===== BÚSQUEDA =====

vector<Entretenimiento*> Sistema::buscarPorGenero(const string& genero) {
    vector<Entretenimiento*> resultados;
    for (const auto& item : contenido) {
        if (item->getGenero() == genero) {
            resultados.push_back(item.get());
        }
    }
    return resultados;
}

vector<Entretenimiento*> Sistema::buscarPorAnio(int anio) {
    vector<Entretenimiento*> resultados;
    for (const auto& item : contenido) {
        if (item->getAnio() == anio) {
            resultados.push_back(item.get());
        }
    }
    return resultados;
}

vector<Entretenimiento*> Sistema::buscarPorTitulo(const string& titulo) {
    vector<Entretenimiento*> resultados;
    for (const auto& item : contenido) {
        if (item->getTitulo().find(titulo) != string::npos) {
            resultados.push_back(item.get());
        }
    }
    return resultados;
}

// ===== ESTADÍSTICAS =====

void Sistema::mostrarEstadisticasUsuario() {
    if (!usuarioActual) {
        cout << "❌ Debes iniciar sesión para ver estadísticas." << endl;
        return;
    }
    
    usuarioActual->mostrarPerfil();
    usuarioActual->mostrarPreferencias();
    usuarioActual->mostrarHistorial();
}

void Sistema::mostrarEstadisticasGenerales() {
    cout << "\n📊 ===== ESTADÍSTICAS GENERALES =====" << endl;
    cout << "Total de usuarios: " << usuarios.size() << endl;
    cout << "Total de contenido: " << contenido.size() << endl;
    
    // Contar por tipo
    map<string, int> tipoCount;
    for (const auto& item : contenido) {
        tipoCount[item->getTipo()]++;
    }
    
    cout << "\nContenido por tipo:" << endl;
    for (const auto& par : tipoCount) {
        cout << "• " << par.first << "s: " << par.second << endl;
    }
    cout << "====================================\n" << endl;
}

void Sistema::mostrarUsuarios() {
    if (usuarios.empty()) {
        cout << "📭 No hay usuarios registrados." << endl;
        return;
    }
    
    cout << "\n👥 ===== USUARIOS REGISTRADOS =====" << endl;
    for (size_t i = 0; i < usuarios.size(); ++i) {
        cout << (i + 1) << ". " << usuarios[i].getNombre() 
             << " (Género favorito: " << usuarios[i].getGeneroFavorito() << ")" << endl;
    }
    cout << "==================================\n" << endl;
}

// ===== MANEJO DE ARCHIVOS =====

bool Sistema::cargarDatos() {
    bool usuariosCargados = cargarUsuarios();
    bool contenidoCargado = cargarContenido();
    return usuariosCargados && contenidoCargado;
}

bool Sistema::guardarDatos() {
    bool usuariosGuardados = guardarUsuarios();
    bool contenidoGuardado = guardarContenido();
    return usuariosGuardados && contenidoGuardado;
}

bool Sistema::cargarUsuarios() {
    try {
        ifstream archivo("usuarios.txt");
        if (!archivo.is_open()) {
            cout << "📝 Archivo de usuarios no encontrado. Se creará uno nuevo." << endl;
            return false;
        }
        
        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue;
            
            stringstream ss(linea);
            string nombre, generoFavorito, preferenciasStr;
            
            getline(ss, nombre, '|');
            getline(ss, generoFavorito, '|');
            getline(ss, preferenciasStr);
            
            // Parsear preferencias
            vector<string> preferencias;
            stringstream prefsStream(preferenciasStr);
            string pref;
            while (getline(prefsStream, pref, ',')) {
                if (!pref.empty()) {
                    preferencias.push_back(pref);
                }
            }
            
            usuarios.emplace_back(nombre, generoFavorito, preferencias);
        }
        
        archivo.close();
        cout << "✅ Usuarios cargados exitosamente (" << usuarios.size() << " usuarios)." << endl;
        return true;
    } catch (const exception& e) {
        cout << "❌ Error al cargar usuarios: " << e.what() << endl;
        return false;
    }
}

bool Sistema::guardarUsuarios() {
    try {
        ofstream archivo("usuarios.txt");
        if (!archivo.is_open()) {
            cout << "❌ Error: No se pudo crear el archivo de usuarios." << endl;
            return false;
        }
        
        for (const auto& usuario : usuarios) {
            archivo << usuario.getNombre() << "|" << usuario.getGeneroFavorito() << "|";
            
            vector<string> preferencias = usuario.getPreferencias();
            for (size_t i = 0; i < preferencias.size(); ++i) {
                archivo << preferencias[i];
                if (i < preferencias.size() - 1) archivo << ",";
            }
            archivo << endl;
        }
        
        archivo.close();
        return true;
    } catch (const exception& e) {
        cout << "❌ Error al guardar usuarios: " << e.what() << endl;
        return false;
    }
}

bool Sistema::cargarContenido() {
    try {
        ifstream archivo("contenido.txt");
        if (!archivo.is_open()) {
            cout << "📝 Archivo de contenido no encontrado. Se creará uno nuevo." << endl;
            return false;
        }
        
        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue;
            
            stringstream ss(linea);
            vector<string> campos;
            string campo;
            
            while (getline(ss, campo, '|')) {
                campos.push_back(campo);
            }
            
            if (campos.size() < 3) continue;
            
            string tipo = campos[0];
            string titulo = campos[1];
            string genero = campos[2];
            int anio = stoi(campos[3]);
            
            // Crear objeto según el tipo
            if (tipo == "Pelicula" && campos.size() >= 8) {
                contenido.push_back(make_unique<Pelicula>(titulo, genero, anio, 
                    campos[4], campos[5], stoi(campos[6]), campos[7]));
            } else if (tipo == "Serie" && campos.size() >= 9) {
                contenido.push_back(make_unique<Serie>(titulo, genero, anio, 
                    campos[4], stoi(campos[5]), stoi(campos[6]), campos[7], campos[8] == "1"));
            } else if (tipo == "Libro" && campos.size() >= 9) {
                contenido.push_back(make_unique<Libro>(titulo, genero, anio, 
                    campos[4], campos[5], stoi(campos[6]), campos[7], campos[8] == "1"));
            } else if (tipo == "Cancion" && campos.size() >= 9) {
                contenido.push_back(make_unique<Cancion>(titulo, genero, anio, 
                    campos[4], campos[5], stoi(campos[6]), campos[7], campos[8] == "1"));
            } else if (tipo == "Podcast" && campos.size() >= 9) {
                contenido.push_back(make_unique<Podcast>(titulo, genero, anio, 
                    campos[4], stoi(campos[5]), stoi(campos[6]), campos[7], campos[8] == "1"));
            }
        }
        
        archivo.close();
        cout << "✅ Contenido cargado exitosamente (" << contenido.size() << " elementos)." << endl;
        return true;
    } catch (const exception& e) {
        cout << "❌ Error al cargar contenido: " << e.what() << endl;
        return false;
    }
}

bool Sistema::guardarContenido() {
    try {
        ofstream archivo("contenido.txt");
        if (!archivo.is_open()) {
            cout << "❌ Error: No se pudo crear el archivo de contenido." << endl;
            return false;
        }
        
        for (const auto& item : contenido) {
            string tipo = item->getTipo();
            archivo << tipo << "|" << item->getTitulo() << "|" << item->getGenero() 
                    << "|" << item->getAnio() << "|";
            
            // Información específica según el tipo
            if (tipo == "Pelicula") {
                Pelicula* p = dynamic_cast<Pelicula*>(item.get());
                if (p) {
                    archivo << p->getDirector() << "|" << p->getActorPrincipal() 
                            << "|" << p->getDuracionMinutos() << "|" << p->getClasificacion();
                }
            } else if (tipo == "Serie") {
                Serie* s = dynamic_cast<Serie*>(item.get());
                if (s) {
                    archivo << s->getCreador() << "|" << s->getTemporadas() 
                            << "|" << s->getEpisodiosTotales() << "|" << s->getPlataforma()
                            << "|" << (s->getEnEmision() ? "1" : "0");
                }
            } else if (tipo == "Libro") {
                Libro* l = dynamic_cast<Libro*>(item.get());
                if (l) {
                    archivo << l->getAutor() << "|" << l->getEditorial() 
                            << "|" << l->getNumeroPaginas() << "|" << l->getIsbn()
                            << "|" << (l->getEsBestseller() ? "1" : "0");
                }
            } else if (tipo == "Cancion") {
                Cancion* c = dynamic_cast<Cancion*>(item.get());
                if (c) {
                    archivo << c->getArtista() << "|" << c->getAlbum() 
                            << "|" << c->getDuracionSegundos() << "|" << c->getDiscografia()
                            << "|" << (c->getEsSimple() ? "1" : "0");
                }
            } else if (tipo == "Podcast") {
                Podcast* p = dynamic_cast<Podcast*>(item.get());
                if (p) {
                    archivo << p->getAnfitrion() << "|" << p->getDuracionMinutos() 
                            << "|" << p->getNumeroEpisodio() << "|" << p->getPlataforma()
                            << "|" << (p->getEsExplicito() ? "1" : "0");
                }
            }
            archivo << endl;
        }
        
        archivo.close();
        return true;
    } catch (const exception& e) {
        cout << "❌ Error al guardar contenido: " << e.what() << endl;
        return false;
    }
}

// ===== CONTENIDO DE DEMOSTRACIÓN =====

void Sistema::inicializarContenidoDemo() {
    // Películas
    agregarPelicula("El Padrino", "Drama", 1972, "Francis Ford Coppola", "Marlon Brando", 175, "R");
    agregarPelicula("Inception", "Ciencia Ficción", 2010, "Christopher Nolan", "Leonardo DiCaprio", 148, "PG-13");
    agregarPelicula("Pulp Fiction", "Crimen", 1994, "Quentin Tarantino", "John Travolta", 154, "R");
    agregarPelicula("Forrest Gump", "Drama", 1994, "Robert Zemeckis", "Tom Hanks", 142, "PG-13");
    agregarPelicula("The Dark Knight", "Acción", 2008, "Christopher Nolan", "Christian Bale", 152, "PG-13");
    
    // Series
    agregarSerie("Breaking Bad", "Drama", 2008, "Vince Gilligan", 5, 62, "Netflix", false);
    agregarSerie("Game of Thrones", "Fantasía", 2011, "David Benioff", 8, 73, "HBO", false);
    agregarSerie("Stranger Things", "Ciencia Ficción", 2016, "Duffer Brothers", 4, 42, "Netflix", true);
    agregarSerie("The Office", "Comedia", 2005, "Greg Daniels", 9, 201, "Netflix", false);
    agregarSerie("Better Call Saul", "Drama", 2015, "Vince Gilligan", 6, 63, "Netflix", false);
    
    // Libros
    agregarLibro("1984", "Distopía", 1949, "George Orwell", "Secker & Warburg", 328, "978-0-452-28423-4", true);
    agregarLibro("Cien Años de Soledad", "Realismo Mágico", 1967, "Gabriel García Márquez", "Sudamericana", 471, "978-84-376-0494-7", true);
    agregarLibro("El Hobbit", "Fantasía", 1937, "J.R.R. Tolkien", "George Allen & Unwin", 310, "978-0-547-92822-7", true);
    agregarLibro("Dune", "Ciencia Ficción", 1965, "Frank Herbert", "Chilton Books", 688, "978-0-441-17271-9", true);
    agregarLibro("Pride and Prejudice", "Romance", 1813, "Jane Austen", "T. Egerton", 432, "978-0-14-143951-8", true);
    
    // Canciones
    agregarCancion("Bohemian Rhapsody", "Rock", 1975, "Queen", "A Night at the Opera", 355, "EMI", false);
    agregarCancion("Imagine", "Rock", 1971, "John Lennon", "Imagine", 183, "Apple Records", true);
    agregarCancion("Stairway to Heaven", "Rock", 1971, "Led Zeppelin", "Led Zeppelin IV", 482, "Atlantic", false);
    agregarCancion("Hotel California", "Rock", 1976, "Eagles", "Hotel California", 391, "Asylum", false);
    agregarCancion("Yesterday", "Pop", 1965, "The Beatles", "Help!", 125, "Parlophone", true);
    
    // Podcasts
    agregarPodcast("The Joe Rogan Experience", "Comedia", 2009, "Joe Rogan", 180, 1500, "Spotify", true);
    agregarPodcast("Serial", "Crimen", 2014, "Sarah Koenig", 45, 12, "This American Life", false);
    agregarPodcast("TED Talks Daily", "Educación", 2006, "TED", 20, 2800, "TED", false);
    agregarPodcast("Conan O'Brien Needs a Friend", "Comedia", 2018, "Conan O'Brien", 60, 200, "Team Coco", false);
    agregarPodcast("Planet Money", "Negocios", 2008, "NPR", 25, 1000, "NPR", false);
    
    // Agregar algunas calificaciones de ejemplo
    for (auto& item : contenido) {
        // Simular algunas calificaciones aleatorias
        int numCalificaciones = rand() % 5 + 1; // 1-5 calificaciones
        for (int i = 0; i < numCalificaciones; ++i) {
            int calificacion = rand() % 5 + 1; // 1-5 estrellas
            item->agregarCalificacion(calificacion);
        }
    }
    
    cout << "✅ Contenido de demostración cargado exitosamente!" << endl;
} 