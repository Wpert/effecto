#include "gui.h"

TWorkArea::TWorkArea(sf::Vector2f pos, sf::Vector2f size) {
    this->area_.setSize(size);
    this->area_.setPosition(pos);
    this->area_.setFillColor(vertexesAreaColor);
}

void TWorkArea::SetSize(sf::Vector2f size) {
    this->area_.setSize(size);
}

void TWorkArea::Render(sf::RenderWindow &window) {
    window.draw(this->area_);
}

TLogic::TLogic(sf::Font font)
        : mainFont_(font)
        , graphWorkspace_({220, 10}, {794, 580})
        , mainGui_(font, font)
{
    mainSprite_.setPosition({220, 10});
    mainGui_.MenuPage();
}

void TLogic::setFilteredImage() {
    currentImage_ = this->mainFilter_.Filter(defaultImage_);
    defaultTexture_.loadFromImage(currentImage_);
    mainSprite_.setTexture(defaultTexture_, true);
}

void TLogic::guiInteraction(sf::RenderWindow &window, Button &button) {
    switch (button.enumNumber_) {
        case ButtonActions::UNIT:
        {
            mainFilter_ = TSample::UnitTransform();
            this->setFilteredImage();
        }
            break;
        case ButtonActions::GAUSS_3:
        {
            mainFilter_ = TSample::GaussianBlur3();
            this->setFilteredImage();
        }
            break;
        case ButtonActions::GAUSS_5:
        {
            mainFilter_ = TSample::GaussianBlur5();
            this->setFilteredImage();
        }
            break;
        case ButtonActions::GAUSS_7:
        {
            mainFilter_ = TSample::GaussianBlur7();
            this->setFilteredImage();
        }
            break;
        case ButtonActions::SHARP:
        {
            mainFilter_ = TSample::SharpenTransform();
            this->setFilteredImage();
        }
            break;
        case ButtonActions::EDGED:
        {
            mainFilter_ = TSample::EdgedTransform();
            this->setFilteredImage();
        }
            break;
        case ButtonActions::MOTION:
        {
            mainFilter_ = TSample::MotionTransform();
            this->setFilteredImage();
        }
            break;
        case ButtonActions::LOAD_IMAGE:
        {
            std::string filename = mainGui_.pageTextBoxes_.GetString(TextBoxes::GET_FILENAME);
                                  //textBoxes_.GetString(TextBoxes::GET_FILENAME);

            std::string path(__FILE__);
            path = path.substr(0, path.rfind("/gui/") + 1);

            sf::Image tryImage;

            if (!tryImage.loadFromFile(path + "pictures/" + filename)) {
                std::cout << "unable to open this file" << std::endl;
                break;
            }

            this->defaultImage_ = tryImage;
            this->setFilteredImage();

            auto imageSize = defaultImage_.getSize();
            this->graphWorkspace_.SetSize({(float)imageSize.x, (float) std::max(int(imageSize.y), 400 - 20)});

            sf::Vector2f pos(0, 0), size(220 + imageSize.x + 10, std::max(imageSize.y + 20, (uint32_t)400));
            window.setView(sf::View(sf::FloatRect(pos, size)));
            window.setSize(static_cast<sf::Vector2u>(size));
        }
            break;
        case ButtonActions::SAVE_IMAGE:
        {
            std::string path(__FILE__);
            std::string filename = mainGui_.pageTextBoxes_.GetString(TextBoxes::SET_FILENAME);

            path = path.substr(0, path.rfind("/gui/") + 1);            
            currentImage_.saveToFile(path + "pictures/" + filename);
        }
        break;
        case ButtonActions::TO_FILE_PAGE:
        {
            this->mainGui_.FilePage();
        }
            break;
        case ButtonActions::TO_MENU_PAGE:
        {
            this->mainGui_.MenuPage();
        }
            break;
        case ButtonActions::TO_BLUR_PAGE:
        {
            this->mainGui_.BlurPage();
        }
            break;
        case ButtonActions::TO_NATURAL_PAGE:
        {
            this->mainGui_.NaturalPage();
        }
            break;
        case ButtonActions::EXIT:
        {
            window.close();
        }
            break;
        default:
        {
            std::cout << "Kek!" << std::endl;
        }
            break;
    }
}

void TLogic::Render(sf::RenderWindow &mainWindow) {
    if (!isMainWindowActive_) {
        return;
    }

    mainWindow.clear(backgroundColor);
    graphWorkspace_.Render(mainWindow);

    mainGui_.Render(mousePosition_, mainWindow);

    mainWindow.draw(mainSprite_);

    mainWindow.display();
}

void TLogic::TakeMousePosition(sf::RenderWindow &mainWindow) {
    mousePosition_ = sf::Mouse::getPosition(mainWindow);
}

void TLogic::ReadInputs(sf::RenderWindow &mainWindow) {
    sf::Event event;
    while (mainWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mainWindow.close();
        }
        // quick time events as I got it right
//        textBoxes_.TakeInput(mousePosition_, event);
        mainGui_.TakeInputs(mousePosition_, event);

        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            // define which button has clicked
            for (auto &button : mainGui_.pageButtons_.buttons_)
                if (button.Contains(mousePosition_))
                    guiInteraction(mainWindow, button);
        }

        // closed or open
        if (event.type == sf::Event::LostFocus) {
            isMainWindowActive_ = false;
        }
        else if (event.type == sf::Event::GainedFocus) {
            isMainWindowActive_ = true;
        }
    }
}