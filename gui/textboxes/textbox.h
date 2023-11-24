#ifndef GRAPHICO_TEXTBOX_H
#define GRAPHICO_TEXTBOX_H

#pragma once
#include <SFML/Graphics.hpp>
#include "../../resources/tcolors.h"
#include <string>
#include <iostream>

class TextBox {
    sf::RectangleShape box_;
    sf::Text text_;
    std::string inputText_;
    bool focus_;
public:
    size_t enumNumber_;

    TextBox(sf::Vector2f position, sf::Vector2f size,
            sf::Font &buttonFont, size_t number);
    ~TextBox() = default;

    bool Contains(sf::Vector2i& mousePosition);
    void TakeInput(sf::Vector2i& mousePosition, sf::Event &event);
    void Render(sf::RenderWindow &window);
    std::string GetString();
};

class TextBoxContainer {
    size_t textCharSize_ = 18;

public:
    std::vector<TextBox> textboxes_;
    std::vector<sf::Text> names_;

    explicit TextBoxContainer(sf::Font &buttonFont) {
//        const sf::Vector2f textboxSize_ = sf::Vector2f(200, 30);
//
//        this->textboxes_.emplace_back(sf::Vector2f(10, 360), textboxSize_, buttonFont);
//        this->textboxes_.emplace_back(sf::Vector2f(10, 465), textboxSize_, buttonFont);
//
//        sf::Text getFilename("Filename of image:", buttonFont, textCharSize_);
//        getFilename.setPosition({10 + 5, 325 + 5});
//
//        sf::Text setFilename("Filename of new image:", buttonFont, textCharSize_);
//        setFilename.setPosition({10 + 5, 430 + 5});
//
//        this->names_.push_back(getFilename);
//        this->names_.push_back(setFilename);
    }

    size_t GetSize() {
        return this->textboxes_.size();
    }

    std::string GetString(size_t num);
    void AddTextbox(sf::Vector2f position, size_t number, sf::Font &textboxFont);
    void AddName(sf::Vector2f position, const std::string &text, sf::Font &textboxFont);
    void ClearTextboxes();
    void TakeInput(sf::Vector2i& mousePosition, sf::Event &event);
    void Render(sf::RenderWindow &window);
};

enum TextBoxes {
    GET_FILENAME,
    SET_FILENAME
};

#endif //GRAPHICO_TEXTBOX_H
