#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "tile.h"

class Grid {
public:
    Grid();
    Grid(const std::vector<std::string>& initialGrid);

    void draw(sf::RenderWindow& window);

    Tile* at(int row, int col);
    // Other grid-related functions can be added here


    std::vector<std::vector<Tile*>> grid;
    // Other grid-related private members can be added here
};
