#ifndef FAV_TBUTTONS_H
#define FAV_TBUTTONS_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../resources/tcolors.h"
#include <mutex>
#include <shared_mutex>

class Button {
private:
    sf::RectangleShape box_;
    sf::Text text_;
public:
    size_t enumNumber_;

    Button(sf::Vector2f position,
           sf::Vector2f size,
           std::string text,
           sf::Font &buttonFont,
           size_t number);
    ~Button() {
//        std::cout << "button has destroyed" << std::endl;
    }

    bool Contains(sf::Vector2i& mousePosition) const;
    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);
};

enum ButtonActions{
    UNIT,
    GAUSS_3,
    GAUSS_5,
    GAUSS_7,
    SHARP,
    EDGED,
    MOTION,
    LOAD_IMAGE,
    SAVE_IMAGE,
    TO_MENU_PAGE,
    TO_FILE_PAGE,
    TO_BLUR_PAGE,
    TO_NATURAL_PAGE,
    EXIT
};

class ButtonContainer {
public:
    std::vector<Button> buttons_;

    explicit ButtonContainer(sf::Font &buttonFont) {
//        const sf::Vector2f buttonSize_ = sf::Vector2f(200, 30);
//
//        this->buttons_.emplace_back(sf::Vector2f(10, 10), buttonSize_, "Unit Transform", buttonFont, UNIT);
//        this->buttons_.emplace_back(sf::Vector2f(10, 45), buttonSize_, "Gaussian Blur 3x3", buttonFont, GAUSS_3);
//        this->buttons_.emplace_back(sf::Vector2f(10, 80), buttonSize_, "Gaussian Blur 5x5", buttonFont, GAUSS_5);
//        this->buttons_.emplace_back(sf::Vector2f(10, 115), buttonSize_, "Gaussian Blur 7x7", buttonFont, GAUSS_7);
//        this->buttons_.emplace_back(sf::Vector2f(10, 150), buttonSize_, "Sharpen Transform", buttonFont, SHARP);
//        this->buttons_.emplace_back(sf::Vector2f(10, 185), buttonSize_, "Edged Transform", buttonFont, EDGED);
//        this->buttons_.emplace_back(sf::Vector2f(10, 220), buttonSize_, "Motion Transform", buttonFont, MOTION);
//
//        this->buttons_.emplace_back(sf::Vector2f(10, 290), buttonSize_, "Load image", buttonFont, LOAD_IMAGE);
//        this->buttons_.emplace_back(sf::Vector2f(10, 395), buttonSize_, "Save image", buttonFont, SAVE_IMAGE);
//
//        this->buttons_.emplace_back(sf::Vector2f(10, 500), buttonSize_, "Exit", buttonFont, EXIT);
    }

    size_t GetSize();
    void AddButton(sf::Vector2f position, const std::string &text, size_t number, sf::Font &buttonFont);
    void ClearButtons();
    void Render(sf::Vector2i &mousePosition, sf::RenderWindow &window);
};

#endif //FAV_TBUTTONS_H
