#include <SFML/Graphics.hpp>

class Tile {

private:
    std::pair<int, int> position;
    char name;
public:
    virtual void draw(sf::RenderWindow& window) const = 0; // pure virtual function
    std::pair<int, int> getPosition() const;
    char getName() const;
    void setPosition(int x, int y);
    void setName(char name);
    virtual ~Tile() = default; // virtual destructor
    int tileWidth = 20;
    int tileHeight = 20;
    int lineThickness = 1;
};

class EmptyTile : public Tile {
public:
    EmptyTile(int x, int y);
    void draw(sf::RenderWindow& window) const override;
};

class BolgrotTile : public Tile {
public:
    BolgrotTile(int x, int y);
    void draw(sf::RenderWindow& window) const override;
};

class WallTile : public Tile {
public:
    WallTile(int x, int y);
    void draw(sf::RenderWindow& window) const override;
};

class CharacterTile : public Tile {
public:
    CharacterTile(int x, int y);
    void draw(sf::RenderWindow& window) const override;
};

class InvocationTile : public Tile {
public:
    InvocationTile(int x, int y);
    void draw(sf::RenderWindow& window) const override;
};

class PinkTile : public Tile {
public:
    PinkTile(int x, int y);
    void draw(sf::RenderWindow& window) const override;
};