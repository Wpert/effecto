#include "tfilter.h"

sf::Image TFilter::Filter(sf::Image &picture) {
    auto picSize = picture.getSize();
    size_t width = picSize.x, height = picSize.y;

    sf::Image resultPicture = picture;

    size_t filterHeight = filter_.size();
    size_t filterWidth = filter_[0].size();

    for (size_t x = 0; x < width; ++x)
        for (size_t y = 0; y < height; ++y) {
            double red = 0.0, green = 0.0, blue = 0.0;

            // multiply every value of the tfilter with corresponding image pixel
            for(size_t filterY = 0; filterY < filterHeight; filterY++)
                for(size_t filterX = 0; filterX < filterWidth; filterX++) {
                    size_t imageX = (x - filterWidth / 2 + filterX + width) % width;
                    size_t imageY = (y - filterHeight / 2 + filterY + height) % height;

                    sf::Color temp = picture.getPixel(imageX, imageY);

                    red += temp.r * filter_[filterY][filterX];
                    green += temp.g * filter_[filterY][filterX];
                    blue += temp.b * filter_[filterY][filterX];
                }

            //truncate values smaller than zero and larger than 255
            int tempRed = std::min(std::max(int(factor_ * red + bias_), 0), 255);
            int tempGreen = std::min(std::max(int(factor_ * green + bias_), 0), 255);
            int tempBlue = std::min(std::max(int(factor_ * blue + bias_), 0), 255);

            sf::Color smth(tempRed, tempGreen, tempBlue, 255);
            resultPicture.setPixel(x, y, smth);
        }
    return resultPicture;
}