#include "tbuttons.h"

Button::Button(sf::Vector2f position,
               sf::Vector2f size,
               std::string text,
               sf::Font &buttonFont,
               size_t number) {
    this->box_.setSize(size);

    {
        this->box_.setPosition(position);
        sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
        this->text_.setPosition(tempPosition);
    }

    this->box_.setFillColor(defaultButtonColor);
    this->text_.setFillColor(defaultTextColor);

    this->text_.setCharacterSize(18);
    this->text_.setFont(buttonFont);

    this->text_.setString(text);

    this->enumNumber_ = number;

//    std::cout << "button has costructed" << std::endl;
}

bool Button::Contains(sf::Vector2i &mousePosition) const {
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return this->box_.getGlobalBounds().contains(tempPosition);
}

void Button::Render(sf::Vector2i &mousePosition, sf::RenderWindow &window) {

    if (this->Contains(mousePosition)) {
        this->box_.setFillColor(activeButtonColor);
    }
    else {
        this->box_.setFillColor(defaultButtonColor);
    }

    window.draw(this->box_);
    window.draw(this->text_);
}

size_t ButtonContainer::GetSize() {
    return this->buttons_.size();
}

void ButtonContainer::Render(sf::Vector2i &mousePosition, sf::RenderWindow &window) {
    for (auto & button : this->buttons_) {
        button.Render(mousePosition, window);
    }
}

void ButtonContainer::AddButton(sf::Vector2f position, const std::string &text, size_t number, sf::Font &buttonFont) {
    sf::Vector2f buttonSize(200, 30);
    this->buttons_.emplace_back(position, buttonSize, text, buttonFont, number);
}

void ButtonContainer::ClearButtons() {
    this->buttons_.clear();
}