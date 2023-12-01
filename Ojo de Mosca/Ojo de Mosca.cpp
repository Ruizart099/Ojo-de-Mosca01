#include <SFML/Graphics.hpp>
#include <cmath>

const float PI = 3.14159265f;

int main() {
    sf::RenderWindow ventana(sf::VideoMode(800, 800), "Patrón Circular");

    const int numeroLineas = 360; // Una línea por cada grado del círculo
    const float radioMaximo = 400.f; // Radio del círculo

    // Creando las líneas que parten desde el centro
    sf::VertexArray lineas(sf::Lines, 2 * numeroLineas);
    for (int i = 0; i < numeroLineas; ++i) {
        float angulo = 2 * PI * i / numeroLineas;

        lineas[2 * i].position = sf::Vector2f(400, 400); // Centro
        lineas[2 * i + 1].position = sf::Vector2f(400 + radioMaximo * cos(angulo), 400 + radioMaximo * sin(angulo));
    }

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed || (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)) {
                ventana.close();
            }
        }

        ventana.clear(sf::Color::White);

        // Dibujando las líneas que parten desde el centro
        ventana.draw(lineas);

        ventana.display();
    }

    return 0;
}