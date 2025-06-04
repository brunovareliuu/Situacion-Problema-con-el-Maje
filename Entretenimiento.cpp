#include "Entretenimiento.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
Entretenimiento::Entretenimiento(const string& titulo, const string& genero, int anio) 
    : titulo(titulo), genero(genero), anio(anio), calificacionPromedio(0.0), totalCalificaciones(0) {}

// Método virtual para mostrar detalles básicos
void Entretenimiento::mostrarDetalles() const {
    cout << "=====================================\n";
    cout << "Título: " << titulo << endl;
    cout << "Género: " << genero << endl;
    cout << "Año: " << anio << endl;
    cout << "Calificación promedio: " << fixed << setprecision(1) << calificacionPromedio << "/5.0" << endl;
    cout << "Total de calificaciones: " << totalCalificaciones << endl;
    cout << "=====================================\n";
}

// Agregar una calificación nueva
void Entretenimiento::agregarCalificacion(int calificacion) {
    if (validarCalificacion(calificacion)) {
        calificaciones.push_back(calificacion);
        totalCalificaciones++;
        calcularCalificacionPromedio();
    } else {
        cout << "Error: La calificación debe estar entre 1 y 5" << endl;
    }
}

// Calcular el promedio de calificaciones
void Entretenimiento::calcularCalificacionPromedio() {
    if (totalCalificaciones > 0) {
        double suma = 0;
        for (int cal : calificaciones) {
            suma += cal;
        }
        calificacionPromedio = suma / totalCalificaciones;
    }
}

// Validar que la calificación esté en el rango correcto
bool Entretenimiento::validarCalificacion(int calificacion) {
    return calificacion >= 1 && calificacion <= 5;
} 