#include "textbox.h"

TextBox::TextBox(sf::Vector2f position, sf::Vector2f size, sf::Font &buttonFont, size_t number) {
    enumNumber_ = number;

    this->box_.setSize(size);
    {
        this->box_.setPosition(position);
        sf::Vector2f tempPosition = sf::Vector2f(position.x + 5, position.y + 5);
        this->text_.setPosition(tempPosition);
    }
    this->box_.setFillColor(defaultButtonColor);

    this->text_.setCharacterSize(18);
    this->text_.setFont(buttonFont);

    this->inputText_ = "";

    this->focus_ = false;

//    std::cout << "textbox has costructed" << std::endl;
}

bool TextBox::Contains(sf::Vector2i &mousePosition) {
    auto tempPosition = static_cast<sf::Vector2f>(mousePosition);
    return this->box_.getGlobalBounds().contains(tempPosition);
}

void TextBox::TakeInput(sf::Vector2i &mousePosition, sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (this->Contains(mousePosition)) {
            this->focus_ = true;
            this->box_.setFillColor(activeButtonColor);
        }
        else {
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }

    }
    if (event.type == sf::Event::KeyPressed && this->focus_) {
        if (!this->inputText_.empty() && event.key.code == sf::Keyboard::BackSpace) {
            this->inputText_.pop_back();
        }
        if (event.key.code == sf::Keyboard::Return) {
            this->focus_ = false;
            this->box_.setFillColor(defaultButtonColor);
        }
    }

    if (event.type == sf::Event::TextEntered && this->inputText_.size() < 20) {
        if (std::isprint(event.text.unicode) && this->focus_) {
                this->inputText_ += (char)(event.text.unicode);
        }

        this->text_.setString(this->inputText_);
    }
}

void TextBox::Render(sf::RenderWindow &window) {
    window.draw(this->box_);
    window.draw(this->text_);
}

std::string TextBox::GetString() {
    return this->inputText_;
}

std::string TextBoxContainer::GetString(size_t num) {
    for (auto &textbox : this->textboxes_)
        if (textbox.enumNumber_ == num) {
            return textbox.GetString();
        }
    return "";
}

void TextBoxContainer::TakeInput(sf::Vector2i &mousePosition, sf::Event &event) {
    for (auto &textBox : this->textboxes_) {
        textBox.TakeInput(mousePosition, event);
    }
}

void TextBoxContainer::Render(sf::RenderWindow &window) {
    for (auto &name : this->names_) {
        window.draw(name);
    }
    for (auto &textbox : this->textboxes_) {
        textbox.Render(window);
    }
}

void TextBoxContainer::AddName(sf::Vector2f position, const std::string &text, sf::Font &textboxFont) {
    sf::Text setFilename(text, textboxFont, textCharSize_);
    position += {5, 5};
    setFilename.setPosition(position);

    this->names_.push_back(setFilename);
}

void TextBoxContainer::AddTextbox(sf::Vector2f position, size_t number, sf::Font &textboxFont) {
    sf::Vector2f textboxSize(200, 30);
    this->textboxes_.emplace_back(position, textboxSize, textboxFont, number);
}

void TextBoxContainer::ClearTextboxes() {
    this->textboxes_.clear();
    this->names_.clear();
}