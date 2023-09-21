//
//  Obstacle.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <SFML/Graphics.hpp>

class Obstacle
{
public:
    sf::Sprite obstacleSprite;
    sf::FloatRect obstacleBounds{0.f, 0.f, 0.f, 0.f};

    Obstacle(sf::Texture& texture);
};
