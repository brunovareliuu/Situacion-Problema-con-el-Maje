#include <Usuario.h>
#include <iostream>
#include <string>
using namespace std;


Usuario::Usuario(const string& nombre, const string& genero) : nombre(nombre), genero(genero) {}

void Usuario::setGenero(string genero) {
    this->genero = genero;
}

string Usuario::getGenero() {
    return genero;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getNombre() {
    return nombre;
}

void Usuario::mostrarPerfil() {
    cout << "Tu nombre es: " << nombre << " y tu genero favorito es: " << genero << endl;
}