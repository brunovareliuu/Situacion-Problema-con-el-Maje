#ifndef LIBRO_H
#define LIBRO_H

#include "Entretenimiento.h"
#include <string>
using namespace std;

class Libro : public Entretenimiento {
private:
    string autor;
    string editorial;
    int numeroPaginas;
    string isbn;
    bool esBestseller;

public:
    // Constructor
    Libro(const string& titulo, const string& genero, int anio, 
          const string& autor, const string& editorial, int numeroPaginas, 
          const string& isbn, bool esBestseller);

    // Implementación de métodos virtuales puros
    void mostrarInfo() const override;
    string getTipo() const override;
    
    // Override del método mostrarDetalles
    void mostrarDetalles() const override;

    // Getters específicos
    string getAutor() const { return autor; }
    string getEditorial() const { return editorial; }
    int getNumeroPaginas() const { return numeroPaginas; }
    string getIsbn() const { return isbn; }
    bool getEsBestseller() const { return esBestseller; }
    
    // Setters específicos
    void setAutor(const string& autor) { this->autor = autor; }
    void setEditorial(const string& editorial) { this->editorial = editorial; }
    void setNumeroPaginas(int numeroPaginas) { this->numeroPaginas = numeroPaginas; }
    void setIsbn(const string& isbn) { this->isbn = isbn; }
    void setEsBestseller(bool esBestseller) { this->esBestseller = esBestseller; }
    
    // Método para obtener estado de bestseller
    string getEstadoBestseller() const;
};

#endif 