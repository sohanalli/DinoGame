//
//  RestartButton.cpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#include "RestartButton.hpp"
#include "Constants.hpp" // Include Constants.h for windowSize_x and windowSize_y

RestartButton::RestartButton()
    : restartButtonSprite(), restartButtonTexture(), mousePos(0.f, 0.f), restartButtonSpriteBounds()
{
    if (restartButtonTexture.loadFromFile("../rsrc/Images/RestartButton.png"))
    {
        restartButtonSprite.setTexture(restartButtonTexture);
        restartButtonSprite.setPosition(sf::Vector2f(windowSize_x / 2 - restartButtonTexture.getSize().x / 2, windowSize_y / 2));
        restartButtonSpriteBounds = restartButtonSprite.getGlobalBounds();
    }
}

