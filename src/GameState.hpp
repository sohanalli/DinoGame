//
//  GameState.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <iostream>
#include "Dino.hpp"
#include "Ground.hpp"
#include "Obstacles.hpp"
#include "Scores.hpp"
#include "Clouds.hpp"
#include "RestartButton.hpp"
#include <SFML/Graphics.hpp>

class GameState{
public:
    Dino dino;
    Ground ground;
    Obstacles obstacles;
    Scores scores;
    Clouds clouds;
    RestartButton restartButton;
    sf::Font gameOverFont;
    sf::Text gameOverText;
    sf::Vector2f mousePos{0.f, 0.f};
    
    GameState();
    void setMousePos(sf::Vector2i p_mousePos);
    void update(sf::Time deltaTime);
    void drawTo(sf::RenderWindow& window);
};
