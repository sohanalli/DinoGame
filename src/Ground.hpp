//
//  Ground.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Ground
{
public:
    Ground();
    void updateGround();
    void reset();
    sf::Sprite getSprite(); // Added for getter

private:
    sf::Sprite groundSprite;
    sf::Texture groundTexture;
    int offset{0};
};
