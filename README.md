# 🎬 Sistema de Recomendaciones de Entretenimiento

Una aplicación de consola en C++ que funciona como un sistema personalizado de recomendaciones de entretenimiento, implementando conceptos avanzados de programación orientada a objetos.

## 📋 Descripción del Proyecto

Este sistema permite a los usuarios gestionar y calificar diferentes tipos de contenido de entretenimiento (películas, series, libros, canciones y podcasts), obteniendo recomendaciones personalizadas basadas en sus preferencias y calificaciones previas.

## 🏗️ Arquitectura del Sistema

### 📁 Estructura de Archivos

```
📦 Proyecto/
├── 📄 main.cpp              # Archivo principal con menú interactivo
├── 👤 Usuario.h/.cpp        # Clase Usuario con preferencias y historial
├── 🎭 Entretenimiento.h/.cpp # Clase base abstracta
├── 🎬 Pelicula.h/.cpp       # Clase derivada para películas
├── 📺 Serie.h/.cpp          # Clase derivada para series
├── 📚 Libro.h/.cpp          # Clase derivada para libros
├── 🎵 Cancion.h/.cpp        # Clase derivada para canciones
├── 🎙️ Podcast.h/.cpp        # Clase derivada para podcasts
├── 🔧 Sistema.h/.cpp        # Clase principal que integra todo
├── 📋 Makefile              # Para compilación automática
├── 📖 README.md             # Este archivo
└── 📊 Data Files/
    ├── usuarios.txt         # Datos de usuarios (generado automáticamente)
    └── contenido.txt        # Datos de contenido (generado automáticamente)
```

## 🧪 Conceptos de POO Implementados

### ✅ **Herencia**
- **Clase base abstracta**: `Entretenimiento`
- **Clases derivadas**: `Pelicula`, `Serie`, `Libro`, `Cancion`, `Podcast`
- **Métodos virtuales puros**: `mostrarInfo()`, `getTipo()`

### ✅ **Polimorfismo**
- Uso de `vector<unique_ptr<Entretenimiento>>` para manejar listas mixtas
- Métodos virtuales sobrescritos en cada clase derivada
- Casting dinámico para funcionalidades específicas

### ✅ **Composición**
- La clase `Sistema` contiene:
  - `vector<Usuario>` usuarios
  - `vector<unique_ptr<Entretenimiento>>` contenido
  - Puntero al usuario actual

### ✅ **Encapsulamiento**
- Atributos privados en todas las clases
- Getters y setters apropiados
- Métodos públicos bien definidos

## 🚀 Funcionalidades Principales

### 👥 **Gestión de Usuarios**
- ✨ Crear nuevos usuarios con preferencias
- 🔐 Iniciar/cerrar sesión
- ⚙️ Gestionar preferencias de géneros
- 📊 Ver estadísticas personales

### 🎭 **Gestión de Contenido**
- 📋 Ver todo el contenido disponible
- 🔍 Filtrar por categoría (películas, series, etc.)
- 🔎 Ver detalles específicos de cada elemento
- ⭐ Calificar contenido (1-5 estrellas)

### 🏆 **Rankings y Estadísticas**
- 🥇 Top 10 general
- 🎯 Top 10 por categoría
- 📈 Estadísticas del usuario
- 📊 Estadísticas generales del sistema

### 🎯 **Sistema de Recomendaciones**
- 🤖 Recomendaciones personalizadas basadas en:
  - Géneros favoritos del usuario
  - Historial de calificaciones
  - Contenido mejor calificado
- 📱 Al menos 1 recomendación por tipo de contenido

### 💾 **Persistencia de Datos**
- 📄 Guardado automático en archivos `.txt`
- 🔄 Carga automática al iniciar
- 📝 Formato estructurado con delimitadores

## 🔧 Instrucciones de Compilación

### Prerequisitos
- Compilador C++17 o superior (g++, clang++)
- Make (opcional, pero recomendado)

### Usando Makefile (Recomendado)
```bash
# Compilar el proyecto
make

# Compilar y ejecutar
make run

# Verificar sintaxis
make check

# Limpiar archivos compilados
make clean

# Ver ayuda
make help
```

### Compilación Manual
```bash
g++ -std=c++17 -Wall -Wextra -g main.cpp Usuario.cpp Entretenimiento.cpp Pelicula.cpp Serie.cpp Libro.cpp Cancion.cpp Podcast.cpp Sistema.cpp -o entretenimiento
```

### Ejecutar
```bash
./entretenimiento
```

## 📱 Guía de Uso

### 🎯 **Primer Uso**
1. Al ejecutar por primera vez, el sistema carga contenido de demostración
2. Crea un nuevo usuario con tus preferencias
3. Inicia sesión y explora las opciones

### 🎮 **Menú Principal**
```
🎬 ===== SISTEMA DE RECOMENDACIONES =====
1️⃣  Iniciar sesión con usuario existente
2️⃣  Crear nuevo usuario
3️⃣  Ver usuarios registrados
4️⃣  Salir
```

### 🎭 **Menú de Usuario**
```
🎭 ===== MENÚ PRINCIPAL - [Usuario] =====
1️⃣  Ver todo el contenido disponible
2️⃣  Ver contenido por categoría
3️⃣  Ver detalles de un elemento específico
4️⃣  Calificar un elemento
5️⃣  Ver Top 10 general
6️⃣  Ver Top 10 por categoría
7️⃣  Ver recomendaciones personalizadas
8️⃣  Ver mi perfil y estadísticas
9️⃣  Gestionar mis preferencias
🔟 Ver estadísticas generales del sistema
0️⃣  Cerrar sesión
```

## 🔍 Validaciones Implementadas

### ✅ **Entrada de Datos**
- Validación de calificaciones (1-5)
- Manejo de errores con try/catch
- Limpieza de buffer de entrada
- Verificación de campos obligatorios

### ✅ **Lógica de Negocio**
- Prevención de usuarios duplicados
- Validación de contenido existente
- Control de sesiones activas
- Manejo seguro de punteros

## 📊 Contenido de Demostración

El sistema incluye contenido preconfigurado:

- **🎬 Películas**: El Padrino, Inception, Pulp Fiction, etc.
- **📺 Series**: Breaking Bad, Game of Thrones, Stranger Things, etc.
- **📚 Libros**: 1984, Cien Años de Soledad, El Hobbit, etc.
- **🎵 Canciones**: Bohemian Rhapsody, Imagine, Stairway to Heaven, etc.
- **🎙️ Podcasts**: The Joe Rogan Experience, Serial, TED Talks, etc.

## 🎯 Algoritmo de Recomendaciones

1. **Filtrado por tipo**: Se obtiene contenido del tipo solicitado
2. **Priorización**: Se priorizan géneros de las preferencias del usuario
3. **Exclusión**: Se excluye contenido ya calificado por el usuario
4. **Ordenamiento**: Se ordena por calificación promedio
5. **Limitación**: Se devuelve la cantidad solicitada

## 🚧 Características Técnicas Destacadas

### 🔧 **Gestión de Memoria**
- Uso de `unique_ptr` para gestión automática de memoria
- Evita memory leaks en objetos polimórficos
- RAII (Resource Acquisition Is Initialization)

### 🎯 **Diseño Modular**
- Separación clara de responsabilidades
- Interfaces bien definidas
- Facilidad para agregar nuevos tipos de entretenimiento

### 📁 **Manejo de Archivos**
- Formato delimitado por pipes (|) y comas (,)
- Carga/guardado automático
- Manejo de errores en E/S

## 🔮 Escalabilidad Futura

El diseño permite fácilmente:
- ➕ Agregar nuevos tipos de entretenimiento
- 🔧 Modificar algoritmos de recomendación
- 📊 Implementar nuevas métricas
- 🎨 Agregar nuevas funcionalidades al menú

## 👨‍💻 Desarrollo

Este proyecto implementa los conceptos solicitados:
- ✅ **Herencia** con clase base abstracta
- ✅ **Polimorfismo** con métodos virtuales
- ✅ **Composición** en la clase Sistema
- ✅ **Manejo de archivos** para persistencia
- ✅ **Arreglos/vectores** para colecciones
- ✅ **Validación de datos** con try/catch
- ✅ **Rankings** con algoritmos de ordenamiento
- ✅ **Recomendaciones** personalizadas

## 📄 Licencia

Este proyecto fue desarrollado como parte de un ejercicio académico de Programación Orientada a Objetos.

---

¡Disfruta explorando y calificando tu contenido favorito! 🎬🎵📚 