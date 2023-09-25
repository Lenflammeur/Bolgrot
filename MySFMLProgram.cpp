#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    
    // Create a circle
    sf::CircleShape shape(50); // radius of the circle
    shape.setFillColor(sf::Color::Green); // fill color of the circle
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(); // clear the window
        window.draw(shape); // draw the circle
        window.display(); // display the window content
    }

    return 0;
}
