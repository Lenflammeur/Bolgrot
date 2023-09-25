#include "game.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(800, 600), "Bolgrot"), turn(0), nextTurnAllowed(false), selectedSquaresCount(0), selectedSquares(), graySquares(), currentHP(40), currentPA(10) {
    characterPosition.first = 13;
    characterPosition.second = 15;
    window.setFramerateLimit(60);
    if (!initializeGrid() || !initializeFont() || !initializeButton()) {
        std::cerr << "Failed to initialize game" << std::endl;
    }
}

bool Game::initializeGrid() {
    grid = {
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
    // You can initialize other grid-related things here
    // Return true if everything is successful, otherwise return false
    return true;
}

bool Game::initializeFont() {
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return false;
    }
    turnText.setFillColor(sf::Color::Black);
    turnText.setFont(font);
    turnText.setString("Turn: 0");
    turnText.setCharacterSize(20);
    turnText.setPosition(window.getSize().x - 100, 10);

    std::string hpStr = "HP: " + std::to_string(currentHP);
    hpText.setFillColor(sf::Color::Red);
    hpText.setFont(font);
    hpText.setString(hpStr);
    hpText.setCharacterSize(20);
    hpText.setPosition(window.getSize().x - 100, 30);

    std::string paStr = "PA: " + std::to_string(currentPA);
    paText.setFillColor(sf::Color::Blue);
    paText.setFont(font);
    paText.setString(paStr);
    paText.setCharacterSize(20);
    paText.setPosition(window.getSize().x - 100, 50);
    return true;
}

bool Game::initializeButton() {
    nextTurnButton.setSize(sf::Vector2f(100, 30));
    nextTurnButton.setPosition(window.getSize().x - 110, window.getSize().y - 30);
    nextTurnButton.setFillColor(sf::Color::Green);
    
    buttonText.setFont(font);
    buttonText.setString("Next Turn");
    buttonText.setCharacterSize(20);
    buttonText.setPosition(window.getSize().x - 100, window.getSize().y - 30);

    jumpButton.setSize(sf::Vector2f(30, 30));
    jumpButton.setPosition(window.getSize().x - 100, 100);
    jumpButton.setFillColor(sf::Color::Black);

    doubleJumpButton.setSize(sf::Vector2f(30, 30));
    doubleJumpButton.setPosition(window.getSize().x - 100, 200);
    doubleJumpButton.setFillColor(sf::Color::Black);

    attiranceButton.setSize(sf::Vector2f(30, 30));
    attiranceButton.setPosition(window.getSize().x - 100, window.getSize().y - 300);
    attiranceButton.setFillColor(sf::Color::Black);

    return true;
}


void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            handleMouseClick(event.mouseButton.x, event.mouseButton.y);
            break;
        }
    }
}

void Game::update() {
    // Update game state here
}

void Game::render() {
    window.clear(sf::Color::White);
    drawGrid();
    window.draw(turnText);
    window.draw(nextTurnButton);
    window.draw(buttonText);
    window.draw(jumpButton);
    window.draw(doubleJumpButton);
    window.draw(attiranceButton);
    window.draw(hpText);
    window.draw(paText);
    window.display();
  
}

void Game::drawGrid() {
    int tileWidth = 20;
    int tileHeight = 20;
    int lineThickness = 1; // thickness of the gray line between squares
    sf::Color gray(128, 128, 128);
    for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].length(); ++j) {
                sf::RectangleShape rectangle(sf::Vector2f(tileWidth - lineThickness, tileHeight - lineThickness));
                rectangle.setPosition(j * tileWidth, i * tileHeight);
                rectangle.setOutlineThickness(lineThickness);
                rectangle.setOutlineColor(gray);

                switch (grid[i][j]) {
                    case 'x':
                        rectangle.setFillColor(sf::Color::White);
                        break;
                    case 's':
                        rectangle.setFillColor(sf::Color::Black);
                        break;
                    case 'c': {
                        sf::CircleShape circle(tileWidth / 2 - lineThickness);
                        circle.setPosition(j * tileWidth, i * tileHeight);
                        circle.setFillColor(sf::Color::Green);
                        window.draw(circle);
                        continue; // skip drawing rectangle for 'I'
                    }
                    case 'W': {
                        sf::ConvexShape triangle;
                        triangle.setPointCount(3);
                        triangle.setPoint(0, sf::Vector2f(j * tileWidth + tileWidth / 2, i * tileHeight));
                        triangle.setPoint(1, sf::Vector2f(j * tileWidth, i * tileHeight + tileHeight));
                        triangle.setPoint(2, sf::Vector2f(j * tileWidth + tileWidth, i * tileHeight + tileHeight));
                        triangle.setFillColor(sf::Color::Red);
                        window.draw(triangle);
                        continue; // skip drawing rectangle for 'W'
                    }
                    case 'p':
                        rectangle.setFillColor(sf::Color(255, 105, 180)); // Pink color
                        break;
                    
                    case 'g':
                        rectangle.setFillColor(gray); // Pink color
                        break;
                    
                    case 'i': {
                        sf::CircleShape circle(tileWidth / 2 - lineThickness);
                        circle.setPosition(j * tileWidth, i * tileHeight);
                        circle.setFillColor(sf::Color::Blue);
                        window.draw(circle);
                        continue;
                    }
                    default:
                        rectangle.setFillColor(sf::Color::White);
                        break;
                }
                window.draw(rectangle);
            }
        }
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    // Handle key input here
}

void Game::nextTurn() {
    turn++;
    std::string turnStr = "Turn: " + std::to_string(turn);
    turnText.setString(turnStr);
    std::string hpStr = "HP: " + std::to_string(currentHP);
    hpText.setString(hpStr);
    selectedSquaresCount = 0;
    currentPA = 10;
    std::string paStr = "PA: " + std::to_string(currentPA);
    paText.setString(paStr);

    // Spawn invocations and prepare for next turn
    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell == 'p') {
                cell = 'i'; // Assuming ‘i’ represents an invocation/blue circle
            }
        }
    }
    if (turn > 6) {
        currentHP--;
    }
}


void Game::handleMouseClick(int x, int y) {
    float squareSize = 20.0f;
    int row = y / squareSize;
    int col = x / squareSize;
    auto [xc, yc] = characterPosition;
    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].length()) {
        if(grid[row][col] == 'x' && selectedSquaresCount < 6) {
            grid[row][col] = 'p'; // ‘p’ represents pink squares
            selectedSquaresCount++;
            selectedSquares.insert({row, col});
        }
        else if(grid[row][col] == 'p') { // User can deselect a pink square
            grid[row][col] = 'x';
            selectedSquaresCount--;
            selectedSquares.erase({row, col});
        }

        else if (currentSort != SortType::None && grid[row][col] == 'g') {
        // Find the position of 'p' and replace it with 'x'
        // ... the code where you find ‘p’ and replace it …

        // Move 'c' to the new position and reset the gray square to 'x'
        
        //auto [xc, yc] = characterPosition;
        //grid[xc][yc] = 'x';
        

        currentPA--; // adjust as needed
        std::string paStr = "PA: " + std::to_string(currentPA);
        paText.setString(paStr);
        currentSort = SortType::None;

        // Reset all gray squares
        for(const auto& [grayRow, grayCol] : graySquares) {
            //if (grayRow != row && grayCol != col)
            grid[grayRow][grayCol] = 'x'; // Or restore to its original state before it was gray.
        }
        grid[xc][yc] = 'x';
        characterPosition = {row, col};
        grid[row][col] = 'c';
        graySquares.clear(); // Clear the set after resetting all gray squares.
    }
    }
    if(nextTurnButton.getGlobalBounds().contains(x, y)) { // Assuming nextTurnButton is an sf::RectangleShape
        nextTurn();
    }
    if(jumpButton.getGlobalBounds().contains(x, y) && currentPA > 0) {
        currentSort = SortType::Jump;
        
        graySquares.clear();
        graySquares.insert({xc+1, yc});
        grid[xc+1][yc] = 'g';
        graySquares.insert({xc-1, yc});
        grid[xc-1][yc] = 'g';
        graySquares.insert({xc, yc+1});
        grid[xc][yc+1] = 'g';
        graySquares.insert({xc, yc-1});
        grid[xc][yc-1] = 'g';
        //currentPA--; // if you want to decrease action points immediately

    } else if(doubleJumpButton.getGlobalBounds().contains(x, y) && currentPA > 0) {
        currentSort = SortType::DoubleJump;

        graySquares.clear();
        graySquares.insert({xc+1, yc});
        grid[xc+1][yc] = 'g';
        graySquares.insert({xc-1, yc});
        grid[xc-1][yc] = 'g';
        graySquares.insert({xc, yc+1});
        grid[xc][yc+1] = 'g';
        graySquares.insert({xc, yc-1});
        grid[xc][yc-1] = 'g';

        graySquares.insert({xc+2, yc});
        grid[xc+2][yc] = 'g';
        graySquares.insert({xc-2, yc});
        grid[xc-2][yc] = 'g';
        graySquares.insert({xc, yc+2});
        grid[xc][yc+2] = 'g';
        graySquares.insert({xc, yc-2});
        grid[xc][yc-2] = 'g';
        //currentPA--; // if you want to decrease action points immediately
    } else if(attiranceButton.getGlobalBounds().contains(x, y) && currentPA > 0) {
        currentSort = SortType::Attirance;
        // Perform immobilism logic
        //...
        //currentPA--; // if you want to decrease action points immediately
    }

}

