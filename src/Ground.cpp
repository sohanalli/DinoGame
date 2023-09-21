//
//  Ground.cpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#include "Ground.hpp"
#include "Constants.hpp" // Include the Constants.h file

Ground::Ground()
: groundSprite(), groundTexture()
{
    if (groundTexture.loadFromFile("../rsrc/Images/GroundImage.png"))
    {
        groundSprite.setTexture(groundTexture);
        groundSprite.setPosition(sf::Vector2f(0.f, windowSize_y - groundTexture.getSize().y - 50));
    }
}

void Ground::updateGround()
{
    if (playerDead == false)
    {
        if (offset > groundTexture.getSize().x - windowSize_x)
            offset = 0;
        
        offset += gameSpeed;
        groundSprite.setTextureRect(sf::IntRect(offset, 0, windowSize_x, windowSize_y));
    }
    
    if (playerDead == true)
        groundSprite.setTextureRect(sf::IntRect(offset, 0, windowSize_x, windowSize_y));
}

void Ground::reset()
{
    offset = 0;
    groundSprite.setTextureRect(sf::IntRect(0, 0, windowSize_x, windowSize_y));
}

sf::Sprite Ground::getSprite()
{
    return groundSprite;
}
