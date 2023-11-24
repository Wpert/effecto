#ifndef FAV_GUI_H
#define FAV_GUI_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../resources/tsample.h"
#include "../filter/tfilter.h"
#include "tpage.h"

class TWorkArea {
private:
    sf::RectangleShape area_;
public:
    TWorkArea(sf::Vector2f pos, sf::Vector2f size);

    void SetSize(sf::Vector2f size);
    void Render(sf::RenderWindow &window);
};

class TLogic {
public:
    TLogic(sf::Font font);

    void Render(sf::RenderWindow &mainWindow);

    void ReadInputs(sf::RenderWindow &mainWindow);

    void TakeMousePosition(sf::RenderWindow &mainWindow);

private:
    void setFilteredImage();

    void guiInteraction(sf::RenderWindow &window, Button &button);

    bool isMainWindowActive_ = true;

    TFilter mainFilter_;
    sf::Image currentImage_;

    sf::Image defaultImage_;
    sf::Texture defaultTexture_;
    sf::Sprite mainSprite_;

    sf::Vector2i mousePosition_;
    sf::Font mainFont_;

    TWorkArea graphWorkspace_;

    TPageManager mainGui_;
};
#endif //FAV_GUI_H
