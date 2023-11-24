#ifndef EFFECTO_TPAGE_H
#define EFFECTO_TPAGE_H

#include "textboxes/textbox.h"
#include "buttons/tbuttons.h"

class TPageManager {
    sf::Font mainFont_;

public:
    TextBoxContainer pageTextBoxes_;
    ButtonContainer pageButtons_;

    enum {
        MENU_PAGE,
        BLUR_PAGE,
        SHARP_PAGE
    };

    TPageManager(sf::Font &buttonFont, sf::Font textboxFont)
    : mainFont_(buttonFont)
    , pageTextBoxes_(mainFont_)
    , pageButtons_(mainFont_)
    {}

    void ClearEverything() {
        pageButtons_.ClearButtons();
        pageTextBoxes_.ClearTextboxes();
    }

    void MenuPage() {
        this->ClearEverything();

        // gui
        pageButtons_.AddButton(sf::Vector2f(10, 10), "Unit Transform", UNIT, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 45), "Load / Save file", TO_FILE_PAGE, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 80), "Blur Transforms", TO_BLUR_PAGE, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 115), "Natural Transforms", TO_NATURAL_PAGE, mainFont_);

        pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", EXIT, mainFont_);
    }

    void FilePage() {
        this->ClearEverything();

        // gui
        pageButtons_.AddButton(sf::Vector2f(10, 10), "Load image", LOAD_IMAGE, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 115), "Save image", SAVE_IMAGE, mainFont_);

        // textboxes
        pageTextBoxes_.AddTextbox(sf::Vector2f(10, 80), GET_FILENAME, mainFont_);
        pageTextBoxes_.AddTextbox(sf::Vector2f(10, 185), SET_FILENAME, mainFont_);

        pageTextBoxes_.AddName(sf::Vector2f(10, 45), "Filename of image:", mainFont_);
        pageTextBoxes_.AddName(sf::Vector2f(10, 150), "Filename of new image", mainFont_);

        pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", TO_MENU_PAGE, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", EXIT, mainFont_);
    }

    void BlurPage() {
        this->ClearEverything();

        // gui
        pageButtons_.AddButton(sf::Vector2f(10, 10), "Gaussian Blur 3x3", GAUSS_3, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 45), "Gaussian Blur 5x5", GAUSS_5, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 80), "Gaussian Blur 7x7", GAUSS_7, mainFont_);

        pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", TO_MENU_PAGE, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", EXIT, mainFont_);
    }

    void NaturalPage() {
        this->ClearEverything();

        // gui
        pageButtons_.AddButton(sf::Vector2f(10, 10), "Sharpen Transform", SHARP, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 45), "Edged Transform", EDGED, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 80), "Motion Transform", MOTION, mainFont_);

        pageButtons_.AddButton(sf::Vector2f(10, 325), "Back to menu", TO_MENU_PAGE, mainFont_);
        pageButtons_.AddButton(sf::Vector2f(10, 360), "Exit", EXIT, mainFont_);
    }

    void TakeInputs(sf::Vector2i& mousePosition, sf::Event event) {
        pageTextBoxes_.TakeInput(mousePosition, event);
    }

    void Render(sf::Vector2i& mousePosition, sf::RenderWindow &window) {
        pageButtons_.Render(mousePosition, window);
        pageTextBoxes_.Render(window);
    }

};


#endif //EFFECTO_TPAGE_H
