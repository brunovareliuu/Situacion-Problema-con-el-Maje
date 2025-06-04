# Makefile para el Sistema de Recomendaciones de Entretenimiento
# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Nombre del ejecutable
TARGET = entretenimiento

# Archivos fuente
SOURCES = main.cpp Usuario.cpp Entretenimiento.cpp Pelicula.cpp Serie.cpp Libro.cpp Cancion.cpp Podcast.cpp Sistema.cpp

# Archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Archivos de cabecera
HEADERS = Usuario.h Entretenimiento.h Pelicula.h Serie.h Libro.h Cancion.h Podcast.h Sistema.h

# Regla principal
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(OBJECTS)
	@echo "🔗 Enlazando $(TARGET)..."
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "✅ Compilación exitosa! Ejecuta con: ./$(TARGET)"

# Compilar archivos objeto
%.o: %.cpp $(HEADERS)
	@echo "🔧 Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	@echo "🧹 Limpiando archivos..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "✅ Limpieza completada!"

# Limpiar también archivos de datos
clean-all: clean
	@echo "🗑️ Eliminando archivos de datos..."
	rm -f usuarios.txt contenido.txt
	@echo "✅ Limpieza completa!"

# Ejecutar el programa
run: $(TARGET)
	@echo "🚀 Ejecutando $(TARGET)..."
	./$(TARGET)

# Verificar sintaxis sin compilar completamente
check:
	@echo "📝 Verificando sintaxis..."
	$(CXX) $(CXXFLAGS) -fsyntax-only $(SOURCES)
	@echo "✅ Sintaxis correcta!"

# Instalar dependencias (si es necesario)
install:
	@echo "📦 No hay dependencias externas que instalar."
	@echo "✅ El proyecto está listo para compilar!"

# Información de ayuda
help:
	@echo "📚 Comandos disponibles:"
	@echo "  make         - Compilar el proyecto"
	@echo "  make run     - Compilar y ejecutar"
	@echo "  make clean   - Limpiar archivos compilados"
	@echo "  make clean-all - Limpiar todo incluyendo datos"
	@echo "  make check   - Verificar sintaxis"
	@echo "  make help    - Mostrar esta ayuda"

# Declarar reglas que no son archivos
.PHONY: all clean clean-all run check install help 