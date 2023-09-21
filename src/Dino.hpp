//
//  Varun.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Obstacle.hpp"  // Include the necessary header for Obstacle

class Dino
{
public:
    Dino();  // Constructor declaration
    void update(sf::Time& deltaTime, std::vector<Obstacle>& obstacles);
    void reset();
    sf::Sprite getSprite();

private:
    sf::Sprite dino;
    sf::Vector2f dinoPos;
    sf::Vector2f dinoMotion;
    sf::Texture dinoTex;
    sf::FloatRect dinoBounds;
    std::array<sf::IntRect, 6> frames;
    sf::Time timeTracker;
    int animationCounter;

    void walk();
};

