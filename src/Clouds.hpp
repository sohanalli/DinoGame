//
//  Clouds.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>

class Clouds
{
public:
    // This vector will hold the cloud sprites.
    std::vector<sf::Sprite> clouds;
    
    sf::Time currTime;
    sf::Texture cloudTexture;

    Clouds();

    void updateClouds(sf::Time& deltaTime);
    void drawTo(sf::RenderWindow& window);
};
