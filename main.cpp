#include "gui/gui.h"

std::string getDirPath() {
    std::string path(__FILE__);
    path = path.substr(0, path.rfind('/') + 1);

    std::cout << "current path is: " << path << std::endl;
    return path;
}

int main() {
    sf::RenderWindow mainWindow(sf::VideoMode(220, 400),
                                "Effecto",
                                sf::Style::Close);

    std::string dirPath = getDirPath();

    // other settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    mainWindow.setFramerateLimit(60);

    sf::Font mainFont;
    if (!mainFont.loadFromFile(dirPath + "resources/calibri.ttf")) {
        std::cout << "Error: calibri.ttf not found!" << std::endl;
        return 0;
    }

    TLogic mainObjects(mainFont);

    while (mainWindow.isOpen()) {
        mainObjects.TakeMousePosition(mainWindow);
        // user devices
        mainObjects.ReadInputs(mainWindow);
        // rendering
        mainObjects.Render(mainWindow);
    }

    return 0;
}