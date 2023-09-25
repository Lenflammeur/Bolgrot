#include<vector>
#include<string>
#include "grid.h"
#include "tile.h"


Grid::Grid()
{
    std::vector<std::string> initialGrid = {
        "sssssssssssxxxxssssssssssssssss",
        "ssssssssssxxxxxxsssssssssssssss",
        "sssssssssxxxxxxxxssssssssssssss",
        "ssssssssxxxxxxxxxxsssssssssssss",
        "sssssssxxxxxxxxxxxxssssssssssss",
        "ssssssxxxxxxxxxxxxxxsssssssssss",
        "sssssxxxxxxxxxxxxxxxxssssssssss",
        "ssssxxxxxxxxxxxxxxxxxxsssssssss",
        "sssxxxxxxxxxxxxxxxxxWxxssssssss",
        "ssxxxxxxxxxxxxxxxxxxxxxxsssssss",
        "sxxxxxxxxxxxxxxxxxxxxxxxxssssss",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxsssss",
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxssss",
        "xxxxxxxxxxxxxxxcxxxxxxxxxxxxsss",
        "sxxxxxxxxxxxxxxxxxxxxxxxxxxxxss",
        "ssxxxxxxxxxxxxxxxxxxxxxxxxxxxxs",
        "sssxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "ssssxxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "sssssxxxxxxxxxxxxxxxxxxxxxxxxxx",
        "ssssssxxxxxxxxxxxxxxxxxxxxxxxxx",
        "sssssssxxxxxxxxxxxxxxxxxxxxxxxx",
        "sssssssssxxxxxxxxxxxxxxxxxxxxxx",
        "ssssssssssxxxxxxxxxxxxxxxxxxxxs",
        "sssssssssssxxxxxxxxxxxxxxxxxxss",
        "ssssssssssssxxxxxxxxxxxxxxxxsss",
        "sssssssssssssxxxxxxxxxxxxxxssss",
        "ssssssssssssssxxxxxxxxxxxxsssss",
        "sssssssssssssssxxxxxxxxxxssssss",
        "ssssssssssssssssxxxxxxxxsssssss",
        "sssssssssssssssssxxxxxxssssssss"
    };
    
    for (int i = 0; i < initialGrid.size(); ++i) {
            for (int j = 0; j < initialGrid[i].length(); ++j) {
                switch (initialGrid[i][j]) {
                    case 'x':
                        grid[i][j] = new EmptyTile(i, j);
                    case 's':
                        grid[i][j] = new WallTile(i, j);
                    case 'c':
                        grid[i][j] = new CharacterTile(i, j);
                    case 'W':
                        grid[i][j] = new BolgrotTile(i, j);
                    default:
                        grid[i][j] = new EmptyTile(i, j);
                }
            }
    }
}

void Grid::draw(sf::RenderWindow& window) {
    int tileWidth = 20;
    int tileHeight = 20;
    int lineThickness = 1; // thickness of the gray line between squares
    sf::Color gray(128, 128, 128);
    for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                grid[i][j]->draw(window);
            }
        }
}

Tile* Grid::at(int row, int col)
{
    return grid[row][col];
}

