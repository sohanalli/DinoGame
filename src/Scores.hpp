//
//  Scores.hpp
//  testSFML
//
//  Created by SOHAN ALLI on 9/20/23.
//

#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Scores
{
public:
    sf::Text previousScoreText;
    sf::Text HIText;
    sf::Text scoresText;
    sf::Font scoresFont;
    short scores{0};
    short previousScore{0};
    short scoresIndex{0};
    short scoresDiff{0};
    short scoresInital;

    Scores();

    void update();
    void reset();
};

