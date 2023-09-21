//
//  Obstacle.cpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#include "Obstacle.hpp"
#include "Constants.hpp" // Include Constants.h for windowSize_x and groundOffset

Obstacle::Obstacle(sf::Texture& texture)
    : obstacleSprite(), obstacleBounds()
{
    obstacleSprite.setTexture(texture);
    obstacleSprite.setPosition(sf::Vector2f(windowSize_x, groundOffset));
}

