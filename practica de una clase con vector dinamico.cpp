#include <iostream>
#include <vector>

// Clase base para representar un miembro en el combate
class MiembroCombate {
public:
    MiembroCombate(const std::string& nombre, int nivel) : nombre(nombre), nivel(nivel) {}

    void mostrarDetalles() const {
        std::cout << "Nombre: " << nombre << ", Nivel: " << nivel << std::endl;
    }

private:
    std::string nombre;
    int nivel;
};

// Clase derivada Azul que hereda de MiembroCombate
class MiembroAzul : public MiembroCombate {
public:
    MiembroAzul(const std::string& nombre, int nivel, const std::string& arma) : MiembroCombate(nombre, nivel), arma(arma) {}

    void mostrarDetalles() const {
        MiembroCombate::mostrarDetalles();
        std::cout << "Arma: " << arma << std::endl;
    }

private:
    std::string arma;
};

// Clase derivada Naranja que hereda de MiembroCombate
class MiembroNaranja : public MiembroCombate {
public:
    MiembroNaranja(const std::string& nombre, int nivel, const std::string& hechizo) : MiembroCombate(nombre, nivel), hechizo(hechizo) {}

    void mostrarDetalles() const {
        MiembroCombate::mostrarDetalles();
        std::cout << "Hechizo: " << hechizo << std::endl;
    }

private:
    std::string hechizo;
};

// Clase Combate que tiene dos equipos: Azul y Naranja
class Combate {
public:
    // Constructor
    Combate() {}

    // Métodos para agregar miembros a cada equipo
    void agregarMiembroAzul(const MiembroAzul& miembro) {
        equipoAzul.push_back(miembro);
    }

    void agregarMiembroNaranja(const MiembroNaranja& miembro) {
        equipoNaranja.push_back(miembro);
    }

    // Método para mostrar detalles de todos los miembros de cada equipo
    void mostrarDetallesCombate() const {
        std::cout << "Equipo Azul:" << std::endl;
        for (const auto& miembro : equipoAzul) {
            miembro.mostrarDetalles();
        }

        std::cout << "\nEquipo Naranja:" << std::endl;
        for (const auto& miembro : equipoNaranja) {
            miembro.mostrarDetalles();
        }
    }

private:
    std::vector<MiembroAzul> equipoAzul;
    std::vector<MiembroNaranja> equipoNaranja;
};

int main() {
    // Crear un combate
    Combate combate;

    // Agregar miembros a cada equipo
    combate.agregarMiembroAzul(MiembroAzul("Guerrero Azul", 10, "Espada"));
    combate.agregarMiembroNaranja(MiembroNaranja("Mago Naranja", 8, "Rayo"));

    // Mostrar detalles del combate
    combate.mostrarDetallesCombate();

    return 0;
}
