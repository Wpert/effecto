#ifndef EFFECTO_TFILTER_H
#define EFFECTO_TFILTER_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

class TFilter {
public:
    TFilter() : factor_(1.0)
              , bias_(0.0)
    {
        filter_ = {{0, 0, 0},
                   {0, 1, 0},
                   {0, 0, 0}};
    }

    TFilter(double factor, double bias, std::vector<std::vector<double>> filter)
            : factor_(factor)
            , bias_(bias)
            , filter_(std::move(filter))
    {}

    ~TFilter() = default;

    sf::Image Filter(sf::Image &picture);

private:
    double factor_;
    double bias_;

    std::vector<std::vector<double>> filter_;
};


#endif //EFFECTO_TFILTER_H
