#include "tile.h" // Include your header file

std::pair<int, int> Tile::getPosition() const {
    return position;
}

char Tile::getName() const
{
    return this->name;
}

void Tile::setPosition(int x, int y) {
    position = {x, y};
}

void Tile::setName(char name)
{
    this->name = name;
}

EmptyTile::EmptyTile(int x, int y) {
    setPosition(x, y);
    setName('x');
}




void EmptyTile::draw(sf::RenderWindow& window) const {
    int x = getPosition().first;
    int y = getPosition().second;
    sf::Color gray(128, 128, 128);
    sf::RectangleShape rectangle(sf::Vector2f(tileWidth - lineThickness, tileHeight - lineThickness));
                rectangle.setPosition(y * tileWidth, x * tileHeight);
                rectangle.setOutlineThickness(lineThickness);
                rectangle.setOutlineColor(gray);
    rectangle.setFillColor(sf::Color::White);
    window.draw(rectangle);
    // your drawing logic for EmptyTile here using x, y, and window
}

CharacterTile::CharacterTile(int x, int y) {
    setPosition(x, y);
    setName('c');
}

void CharacterTile::draw(sf::RenderWindow& window) const {
    int x = getPosition().first;
    int y = getPosition().second;
    sf::CircleShape circle(tileWidth / 2 - lineThickness);
                        circle.setPosition(y * tileWidth, x * tileHeight);
                        circle.setFillColor(sf::Color::Green);
                        window.draw(circle);
    
    // your drawing logic for CharacterTile here using x, y, and window
}

InvocationTile::InvocationTile(int x, int y) {
    setPosition(x, y);
    setName('i');
}

void InvocationTile::draw(sf::RenderWindow& window) const {
    int x = getPosition().first;
    int y = getPosition().second;
    // your drawing logic for InvocationTile here using x, y, and window
}

PinkTile::PinkTile(int x, int y) {
    setPosition(x, y);
    setName('p');
}

void PinkTile::draw(sf::RenderWindow& window) const {
    int x = getPosition().first;
    int y = getPosition().second;
    // your drawing logic for PinkTile here using x, y, and window
}

WallTile::WallTile(int x, int y) {
    setPosition(x, y);
    setName('s');
}

void WallTile::draw(sf::RenderWindow& window) const {
    int x = getPosition().first;
    int y = getPosition().second;
    sf::Color gray(128, 128, 128);
    sf::RectangleShape rectangle(sf::Vector2f(tileWidth - lineThickness, tileHeight - lineThickness));
                rectangle.setPosition(y * tileWidth, x * tileHeight);
                rectangle.setOutlineThickness(lineThickness);
                rectangle.setOutlineColor(gray);
    rectangle.setFillColor(sf::Color::Black);
    window.draw(rectangle);
    // your drawing logic for EmptyTile here using x, y, and window
}

BolgrotTile::BolgrotTile(int x, int y) {
    setPosition(x, y);
    setName('W');
}

void BolgrotTile::draw(sf::RenderWindow& window) const {
    int x = getPosition().first;
    int y = getPosition().second;
    sf::ConvexShape triangle;
                        triangle.setPointCount(3);
                        triangle.setPoint(0, sf::Vector2f(y * tileWidth + tileWidth / 2, x * tileHeight));
                        triangle.setPoint(1, sf::Vector2f(y * tileWidth, x * tileHeight + tileHeight));
                        triangle.setPoint(2, sf::Vector2f(y * tileWidth + tileWidth, x * tileHeight + tileHeight));
                        triangle.setFillColor(sf::Color::Red);
                        window.draw(triangle);
    // your drawing logic for EmptyTile here using x, y, and window
}
