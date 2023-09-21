#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Constants.hpp"

//int main()
//{
//    // create the window
//    sf::RenderWindow window(sf::VideoMode(1600, 900), "My Game Project");
//    
//    /*----------------------------------------VARUN------------------------------------------------*/
//    sf::Texture varunTexture;
//    if (!varunTexture.loadFromFile("../varun.png")) {
//        std::cerr << "Error: Failed to load varun texture." << std::endl;
//        return 1;
//    }
//    
//    sf::Sprite varunSprite;
//    varunSprite.setTexture(varunTexture);
//    // scaling my dino image
//    varunSprite.setScale(0.3f,0.3f);
//    // absolute position
//    varunSprite.setPosition(sf::Vector2f(0.f, 600.f));
//    varunSprite.rotate(-5.f);
//    
//    float maxJumpHeight = 200.f; // Adjust this value to control maximum jump height
//    float maxJumpDuration = 0.5f; // Adjust this value to set the maximum jump duration in seconds
//    float jumpSpeed = 0.f; // Initialize jump speed to 0
//    float gravity = 0.5f;  // Adjust this value to control gravity
//    
//    bool isJumping = false;  // Flag to track if Varun is currently jumping
//    float jumpStartY = 0.f;
//    sf::Clock jumpClock;
//    bool canJump = true; // A flag to track whether Varun can jump
//    
//    
//    
//    /*----------------------------------------xcode------------------------------------------------*/
//    
//    sf::Texture xcodeTexture;
//    if (!xcodeTexture.loadFromFile("../xcode.png")){
//        std::cerr << "Error: Failed to load xcode texture." << std::endl;
//        return 1;
//    }
//    
//    sf::Sprite xcodeSprite;
//    xcodeSprite.setTexture(xcodeTexture);
//    
//    // scaling my xcode image
//    xcodeSprite.setScale(0.3f,0.3f);
//    // absolute position
//    xcodeSprite.setPosition(sf::Vector2f(300.f, 670.f));
//    
//    
//    // Define a cooldown timer for the spacebar
//    sf::Clock spacebarCooldown;
//    float spacebarCooldownDuration = 0.5f; // Adjust this value as needed
//    
//    // run the program as long as the window is open
//    while (window.isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        
//        // Handle spacebar press to trigger jump
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping && canJump && spacebarCooldown.getElapsedTime().asSeconds() >= spacebarCooldownDuration)
//        {
//            std::cout << "Spacebar pressed!" << std::endl; // Debug message
//            isJumping = true;
//            jumpStartY = varunSprite.getPosition().y;
//            jumpSpeed = 1.f; // Set the initial jump speed
//            jumpClock.restart(); // Start the jump timer
//            spacebarCooldown.restart(); // Start the spacebar cooldown timer
//        }
//        
//        // Jumping logic
//        if (isJumping)
//        {
//            float currentY = varunSprite.getPosition().y;
//            float deltaY = jumpStartY - currentY;
//            
//            if (deltaY < maxJumpHeight && jumpClock.getElapsedTime().asSeconds() < maxJumpDuration)
//            {
////                jumpSpeed -= gravity; // Apply gravity
//                varunSprite.move(0.f, -jumpSpeed); // Move Varun upward
//                
//                // If Varun goes above the top of the window, set position to the top
//                if (varunSprite.getPosition().y >= jumpStartY)
//                {
//                    varunSprite.setPosition(varunSprite.getPosition().x, jumpStartY);
//                    isJumping = false;
//                    jumpSpeed = 0.f; // Reset jumpSpeed to 0 after landing
//                }
//            }
//            else
//            {
//                isJumping = false; // Reset the jump flag
//            }
//        }
//        else
//        {
//            // Apply gravity when not jumping
//            varunSprite.move(0.f, gravity);
//        }
//        
//        // Prevent Varun from falling below the ground
//        if (varunSprite.getPosition().y >= 600.f)
//        {
//            varunSprite.setPosition(sf::Vector2f(varunSprite.getPosition().x, 600.f));
//            canJump = true; // Varun can jump again
//        }
//        
//        // Limit jump duration
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jumpClock.getElapsedTime().asSeconds() >= maxJumpDuration)
//        {
//            canJump = false; // Prevent continuous jumping after reaching the max jump duration
//        }
//
//        // clear the window with black color
//        window.clear(sf::Color::White);
//
//        window.draw(varunSprite);
//        window.draw(xcodeSprite);
//        
//        // end the current frame
//        window.display();
//    }
//
//    return 0;
//}

int main() {
    // creating an SFML window with the specified size and title
    sf::RenderWindow window(sf::VideoMode(windowSize_x, windowSize_y), "CS6010 Game Project");
    
    // Enabling vertical synchronization for smoother animations
    window.setVerticalSyncEnabled(true);
    
    // Creating an instance of the GameState class to manage the game's state and elements
    GameState gameState;
    
    // Declare an SFML Event object for handling events (e.g., user input)
    sf::Event event;

    // Declare an SFML Time object for tracking elapsed time (delta time)
    // the time elapsed since the last frame
    sf::Time deltaTime;

    // Declare an SFML Clock object for measuring elapsed time between frames
    sf::Clock deltaTimeClock;


    // continues running as long as the game window is open.
    while(window.isOpen())
    {
        // continuously checks for events in the game window.
        while(window.pollEvent(event))
        {
            /* The "Closed" event is generated when the user attempts to close the game window,
             typically by clicking the window's close button (the "X" button in the corner).*/
            if(event.type == sf::Event::Closed)
                // closes the game window, effectively ending the game loop and terminating the program
                window.close();
            
            // gets the current mouse position relative to the game window's coordinates and then passes that position to the setMousePos function of the gameState object
            // continuously updates the mouse position within the game state, allowing the game to respond to mouse-based interactions or controls.
            gameState.setMousePos(sf::Mouse::getPosition(window));
        }
        // returns the time that has elapsed since the clock was last restarted and then restarts the clock
        deltaTime = deltaTimeClock.restart();

        gameState.update(deltaTime);
        
        // Clear the window and prepare it for rendering.
        window.clear(sf::Color::White);
        // Drawing game elements onto the cleared window.
        gameState.drawTo(window);
        // present the rendered frame to the screen
        window.display();
    }

    return 0;
}
