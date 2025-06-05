#include "Pelicula.h"

int main() {
    Pelicula p("Dune", "Ciencia ficción", 155);
    p.agregarCalificacion(5);
    p.agregarCalificacion(4);
    p.mostrarInfo();

    return 0;
}
