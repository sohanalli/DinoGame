//
//  Varun.cpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#include<iostream>
#include "GameState.hpp"
#include "Dino.hpp"
#include "Constants.hpp"

Dino::Dino()
    : dino(), dinoTex(), timeTracker(), animationCounter(0)
{
    if (dinoTex.loadFromFile("../rsrc/Images/PlayerSpriteSheet.png"))
    {
        dino.setTexture(dinoTex);
        for (int i = 0; i < frames.size(); i++)
            frames[i] = sf::IntRect(i * 90, 0, 90, 95);
        dino.setTextureRect(frames[0]);
        dinoPos = dino.getPosition();
    }
    else
    {
        std::cout << "Error loading the PlayerSprite texture" << std::endl;
    }
}

void Dino::update(sf::Time& deltaTime, std::vector<Obstacle>& obstacles)
{
    dinoPos = dino.getPosition();
    dinoBounds = dino.getGlobalBounds();
    dinoBounds.height -= 15.f;
    dinoBounds.width -= 10.f;
    timeTracker += deltaTime;
    for (auto& obstacle : obstacles)
    {
        if (dinoBounds.intersects(obstacle.obstacleBounds))
        {
            playerDead = true;
        }
    }

    if (!playerDead)
    {
        walk();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true && dinoPos.y >= windowSize_y - 150.f)
        {
            animationCounter = 0;
            dinoMotion.y = -20.f;
            dino.setTextureRect(frames[1]);
        }

        if (dinoPos.y < windowSize_y - 150.f)
        {
            dinoMotion.y += 1.f;
            dino.setTextureRect(frames[1]);
        }

        if (dinoPos.y > windowSize_y - 150.f)
        {
            dino.setPosition(sf::Vector2f(dino.getPosition().x, windowSize_y - 150.f));
            dinoMotion.y = 0.f;
        }

        dino.move(dinoMotion);
    }
    if (playerDead == true)
    {
        dinoMotion.y = 0.f;
        dino.setTextureRect(frames[3]);
        if (timeTracker.asMilliseconds() > 170.f)
        {
            timeTracker = sf::Time::Zero;
        }
    }
}

void Dino::walk()
{
    for (int i = 0; i < frames.size() - 3; i++)
        if (animationCounter == (i + 1) * 3)
            dino.setTextureRect(frames[i]);

    if (animationCounter >= (frames.size() - 2) * 3)
        animationCounter = 0;

    animationCounter++;
}

void Dino::reset()
{
    dinoMotion.y = 0;
    
    dino.setPosition(sf::Vector2f(dino.getPosition().x, windowSize_y - 150.f));
    dino.setTextureRect(frames[0]);
}

sf::Sprite Dino::getSprite()
{
    return dino;
}
