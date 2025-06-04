#include "Libro.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
Libro::Libro(const string& titulo, const string& genero, int anio, 
             const string& autor, const string& editorial, int numeroPaginas, 
             const string& isbn, bool esBestseller)
    : Entretenimiento(titulo, genero, anio), autor(autor), 
      editorial(editorial), numeroPaginas(numeroPaginas), 
      isbn(isbn), esBestseller(esBestseller) {}

// Implementación de mostrarInfo (versión resumida)
void Libro::mostrarInfo() const {
    cout << "📚 " << titulo << " (" << anio << ") - " 
         << genero << " | " << fixed << setprecision(1) 
         << calificacionPromedio << "⭐ | " << numeroPaginas 
         << " pág. | " << getEstadoBestseller() << endl;
}

// Implementación de getTipo
string Libro::getTipo() const {
    return "Libro";
}

// Override de mostrarDetalles con información específica de libro
void Libro::mostrarDetalles() const {
    cout << "\n📚 =========== LIBRO ===========\n";
    cout << "Título: " << titulo << endl;
    cout << "Género: " << genero << endl;
    cout << "Año: " << anio << endl;
    cout << "Autor: " << autor << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Número de páginas: " << numeroPaginas << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Estado: " << getEstadoBestseller() << endl;
    cout << "Calificación promedio: " << fixed << setprecision(1) 
         << calificacionPromedio << "/5.0 ⭐" << endl;
    cout << "Total de calificaciones: " << totalCalificaciones << endl;
    cout << "==============================\n" << endl;
}

// Método para obtener estado de bestseller
string Libro::getEstadoBestseller() const {
    return esBestseller ? "Bestseller" : "Estándar";
} 