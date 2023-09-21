//
//  Clouds.cpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//
#include<iostream>
#include "Clouds.hpp"
#include "Constants.hpp" // Include Constants.h for windowSize_x, windowSize_y, and playerDead
#include <random>

Clouds::Clouds(): cloudTexture(), clouds(), currTime()
{
    // Load a cloud texture from a file
    if (cloudTexture.loadFromFile("../rsrc/Images/Clouds.png")){
        std::cout << "Loaded CloudTexture" << std::endl;
    }
    
    // Reserve space in the 'clouds' vector for 4 cloud sprites
    // Reserving space can be useful for optimizing vector operations when adding elements Ex: Reduced Memory Reallocations
    clouds.reserve(4);
    
    // Create a cloud sprite and add it to the 'clouds' vector
    // emplace_back constructs objects directly in the vector's memory,
    // avoiding the need for copying or moving existing objects, making it more efficient than push_back.
    clouds.emplace_back(sf::Sprite(cloudTexture));
    
    // Set the position of the cloud sprite
    clouds.back().setPosition(sf::Vector2f(windowSize_x, windowSize_y / 2 - 40.f));
}

void Clouds::updateClouds(sf::Time& deltaTime)
{
    currTime += deltaTime;
    if (currTime.asSeconds() > 8.f)
    {
        clouds.emplace_back(sf::Sprite(cloudTexture));

        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(windowSize_y / 2 - 200, windowSize_y / 2 - 50);
        clouds.back().setPosition(sf::Vector2f(windowSize_x, dist6(rng)));

        currTime = sf::Time::Zero;
    }

    for (int i = 0; i < clouds.size(); i++)
    {
        if (playerDead == false)
            clouds[i].move(sf::Vector2f(-1.f, 0.f));
        if (playerDead == true)
            clouds[i].move(sf::Vector2f(-0.5f, 0.f));

        if (clouds[i].getPosition().x < 0.f - cloudTexture.getSize().x)
        {
            std::vector<sf::Sprite>::iterator cloudIter = clouds.begin() + i;
            clouds.erase(cloudIter);
        }
    }
}

void Clouds::drawTo(sf::RenderWindow& window)
{
    for (auto& clouds : clouds)
    {
        window.draw(clouds);
    }
}

