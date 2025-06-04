#ifndef SISTEMA_H
#define SISTEMA_H

#include "Usuario.h"
#include "Entretenimiento.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Libro.h"
#include "Cancion.h"
#include "Podcast.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Sistema {
private:
    vector<Usuario> usuarios;
    vector<unique_ptr<Entretenimiento>> contenido;
    Usuario* usuarioActual;
    
    // Métodos privados para manejo de archivos
    bool cargarUsuarios();
    bool guardarUsuarios();
    bool cargarContenido();
    bool guardarContenido();
    
    // Métodos auxiliares
    int buscarUsuario(const string& nombre);
    int buscarContenido(const string& titulo);
    void inicializarContenidoDemo();

public:
    // Constructor y destructor
    Sistema();
    ~Sistema();
    
    // Gestión de usuarios
    bool crearUsuario(const string& nombre, const string& generoFavorito, 
                      const vector<string>& preferencias = {});
    bool iniciarSesion(const string& nombre);
    void cerrarSesion();
    Usuario* getUsuarioActual() { return usuarioActual; }
    
    // Gestión de contenido
    void agregarPelicula(const string& titulo, const string& genero, int anio,
                        const string& director, const string& actorPrincipal,
                        int duracionMinutos, const string& clasificacion);
    void agregarSerie(const string& titulo, const string& genero, int anio,
                     const string& creador, int temporadas, int episodiosTotales,
                     const string& plataforma, bool enEmision);
    void agregarLibro(const string& titulo, const string& genero, int anio,
                     const string& autor, const string& editorial, int numeroPaginas,
                     const string& isbn, bool esBestseller);
    void agregarCancion(const string& titulo, const string& genero, int anio,
                       const string& artista, const string& album, int duracionSegundos,
                       const string& discografia, bool esSimple);
    void agregarPodcast(const string& titulo, const string& genero, int anio,
                       const string& anfitrion, int duracionMinutos, int numeroEpisodio,
                       const string& plataforma, bool esExplicito);
    
    // Calificaciones
    bool calificarContenido(const string& titulo, int calificacion);
    
    // Visualización
    void mostrarTodoElContenido();
    void mostrarContenidoPorTipo(const string& tipo);
    void mostrarDetallesContenido(const string& titulo);
    
    // Rankings
    void mostrarTop10General();
    void mostrarTop10PorTipo(const string& tipo);
    
    // Recomendaciones
    void mostrarRecomendacionesPersonalizadas();
    vector<Entretenimiento*> obtenerRecomendaciones(const string& tipo, int cantidad = 3);
    
    // Búsqueda
    vector<Entretenimiento*> buscarPorGenero(const string& genero);
    vector<Entretenimiento*> buscarPorAnio(int anio);
    vector<Entretenimiento*> buscarPorTitulo(const string& titulo);
    
    // Estadísticas
    void mostrarEstadisticasUsuario();
    void mostrarEstadisticasGenerales();
    
    // Gestión de datos
    bool cargarDatos();
    bool guardarDatos();
    void mostrarUsuarios();
};

#endif 