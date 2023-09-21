//
//  Obstacles.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Obstacle.hpp"

class Obstacles
{
public:
    std::vector<Obstacle> obstacles;

    sf::Time spawnTimer;
    sf::Texture obstacleTexture_1;
    sf::Texture obstacleTexture_2;
    sf::Texture obstacleTexture_3;
    int randomNumber{0};

    Obstacles();

    void update(sf::Time& deltaTime);
    void drawTo(sf::RenderWindow& window);
    void reset();
};

