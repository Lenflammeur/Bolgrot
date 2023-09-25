// game.h
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <set>

enum class SortType { None, Jump, DoubleJump, Attirance };

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    void nextTurn();

    void handleMouseClick(int x, int y);

    bool initializeGrid();
    bool initializeFont();
    bool initializeButton();
    void drawGrid();
    int selectedSquaresCount; // to keep the count of selected squares.
    int currentHP;
    int currentPA;
    std::set<std::pair<int, int>> selectedSquares; // to keep the positions of selected squares.
    std::set<std::pair<int, int>> graySquares;
    std::pair<int, int> characterPosition; // to store the position of 'p'



    sf::RectangleShape jumpButton;
    sf::RectangleShape doubleJumpButton;
    sf::RectangleShape attiranceButton;
    SortType currentSort;

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text turnText;
    sf::Text hpText;
    sf::Text paText;
    sf::RectangleShape nextTurnButton;
    sf::Text buttonText;
    std::vector<std::string> grid;

    int turn;
    bool nextTurnAllowed;
};
