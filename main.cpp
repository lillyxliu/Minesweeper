#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
  //  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Close);
   // sf:RenderTarget::clear(const color & color = sf::Color::Black);
    window.clear(sf::Color::Blue);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    // create graphial text:


    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Blue);
        window.draw(shape);
        window.display();
    }
    return 0;
}
