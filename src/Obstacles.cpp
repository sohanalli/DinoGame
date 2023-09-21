//
//  Obstacles.cpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#include "Obstacles.hpp"
#include "Constants.hpp" // Include Constants.h for gameSpeed and playerDead

Obstacles::Obstacles()
    : spawnTimer(sf::Time::Zero)
{
    obstacles.reserve(5);

    if (obstacleTexture_1.loadFromFile("../rsrc/Images/Cactus1.png"))
    {
        std::cout << "Loaded cactus Image 1 " << std::endl;
    }

    if (obstacleTexture_2.loadFromFile("../rsrc/Images/Cactus2.png"))
    {
        std::cout << "Loaded cactus Image 2" << std::endl;
    }

    if (obstacleTexture_3.loadFromFile("../rsrc/Images/Cactus3.png"))
    {
        std::cout << "Loaded cactus Image 3" << std::endl;
    }
}

void Obstacles::update(sf::Time& deltaTime)
{
    spawnTimer += deltaTime;
    if (spawnTimer.asSeconds() > 0.5f + gameSpeed / 8)
    {
        randomNumber = (rand() % 3) + 1;
        if (randomNumber == 1)
        {
            obstacles.emplace_back(Obstacle(obstacleTexture_1));
        }
        if (randomNumber == 2)
        {
            obstacles.emplace_back(Obstacle(obstacleTexture_2));
        }
        if (randomNumber == 3)
        {
            obstacles.emplace_back(Obstacle(obstacleTexture_3));
        }
        spawnTimer = sf::Time::Zero;
    }

    if (playerDead == false)
    {
        for (int i = 0; i < obstacles.size(); i++)
        {
            obstacles[i].obstacleBounds = obstacles[i].obstacleSprite.getGlobalBounds();
            obstacles[i].obstacleBounds.width -= 10.f;
            obstacles[i].obstacleSprite.move(-1.f * gameSpeed, 0.f);
            if (obstacles[i].obstacleSprite.getPosition().x < -150.f)
            {
                std::vector<Obstacle>::iterator obstacleIter = obstacles.begin() + i;
                obstacles.erase(obstacleIter);
            }
        }
    }

    if (playerDead == true)
    {
        for (auto& obstacles : obstacles)
        {
            obstacles.obstacleSprite.move(0.f, 0.f);
        }
    }
}

void Obstacles::drawTo(sf::RenderWindow& window)
{
    for (auto& obstacles : obstacles)
    {
        window.draw(obstacles.obstacleSprite);
    }
}

void Obstacles::reset()
{
    obstacles.erase(obstacles.begin(), obstacles.end());
}

