//
//  RestartButton.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

class RestartButton
{
public:
    sf::Sprite restartButtonSprite;
    sf::FloatRect restartButtonSpriteBounds;
    sf::Texture restartButtonTexture;
    sf::Vector2f mousePos;
    bool checkPressed{false};

    RestartButton();

};
