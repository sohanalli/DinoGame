//
//  GameState.cpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#include "GameState.hpp"
#include "Constants.hpp" // Include Constants.hpp for windowSize_x, windowSize_y, and playerDead
#include <SFML/Window/Mouse.hpp>

// constructor initialization list (MENTIONED IN CLASS)
GameState::GameState():dino(), ground(), obstacles(), scores(), clouds(), gameOverFont(), gameOverText(){
    // Load a font from a file
    gameOverFont.loadFromFile("../rsrc/Fonts/Font.ttf");
    
    // Set the font for the gameOverText
    gameOverText.setFont(gameOverFont);
    
    // Set the initial position of the player character (dino)
    dino.getSprite().setPosition(sf::Vector2f(windowSize_x/2 - windowSize_x/4, windowSize_y - 150.f));
    
    // Set the text for the "Game Over" message
    gameOverText.setString("G A M E  O V E R");
    
    // Position the "Game Over" text relative to the restart button
    gameOverText.setPosition(sf::Vector2f(restartButton.restartButtonSprite.getPosition().x - gameOverText.getCharacterSize()-30,
                                          restartButton.restartButtonSprite.getPosition().y - 50));
    
    // Set the fill color for the "Game Over" text
    gameOverText.setFillColor(sf::Color(83, 83, 83));
}

void GameState::setMousePos(sf::Vector2i p_mousePos){
    mousePos.x = p_mousePos.x; // Update the x-coordinate of mousePosition
    mousePos.y = p_mousePos.y; // Update the y-coordinate of mousePosition
}

void GameState::update(sf::Time deltaTime){
    
    // Check if the left mouse button is pressed and update restartButton.checkPressed
    restartButton.checkPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    
    // Check if the player is dead and the mouse is over the restart button
    // it means the player wants to restart the game
    if(playerDead == true && restartButton.restartButtonSpriteBounds.contains(mousePos) && restartButton.checkPressed == true){
        
        // Reset the game elements (ground, obstacles, dino, scores)
        ground.reset();
        obstacles.reset();
        dino.reset();
        scores.reset();
        
        // Set playerDead to false to indicate the player is no longer dead
        playerDead = false;
    }
    else
    {
        // Update game elements if the player is not dead
        ground.updateGround();
        obstacles.update(deltaTime);
        dino.update(deltaTime, obstacles.obstacles);
        clouds.updateClouds(deltaTime);
        scores.update();
    }
}

void GameState::drawTo(sf::RenderWindow& window){
    if(playerDead == true)
    {
        // Draw elements for the game over screen
        clouds.drawTo(window);
        window.draw(ground.getSprite());
        obstacles.drawTo(window);
        window.draw(scores.scoresText);
        window.draw(scores.previousScoreText);
        window.draw(scores.HIText);
        window.draw(dino.getSprite());
        window.draw(gameOverText);
        window.draw(restartButton.restartButtonSprite);
    }
    else
    {
        // Draw regular gameplay elements
        clouds.drawTo(window);
        window.draw(ground.getSprite());
        obstacles.drawTo(window);
        window.draw(scores.scoresText);
        window.draw(scores.previousScoreText);
        window.draw(scores.HIText);
        window.draw(dino.getSprite());
    }
}
