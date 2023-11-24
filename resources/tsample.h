#ifndef FAV_TSAMPLE_H
#define FAV_TSAMPLE_H

#pragma once
#include "../filter/tfilter.h"
#include <vector>

class TSample {
public:
    using filter = std::vector<std::vector<double>>;

    static TFilter GaussianBlur3() {
        filter f(3, std::vector<double>(3));
        f = {{1, 2, 1},
            {2, 4, 2},
            {1, 2, 1}};
        TFilter result(1.0 / 16.0, 0.0, f);
        return result;
    }

    static TFilter GaussianBlur5() {
        filter f(5, std::vector<double>(5));
        f = {{1,  4,  6,  4, 1},
             {4, 16, 24, 16, 4},
             {6, 24, 36, 24, 6},
             {4, 16, 24, 16, 4},
             {1,  4,  6,  4, 1}};
        TFilter result(1.0 / 256.0, 0.0, f);
        return result;
    }

    static TFilter GaussianBlur7() {
        filter f(7, std::vector<double>(7));
        f = {{0,  0,   0,   5,   0,  0, 0},
             {0,  5,  18,  32,  18,  5, 0},
             {0, 18,  64, 100,  64, 18, 0},
             {5, 32, 100, 100, 100, 32, 5},
             {0, 18,  64, 100,  64, 18, 0},
             {0,  5,  18,  32,  18,  5, 0},
             {0,  0,   0,   5,   0,  0, 0}};
        TFilter result(1.0 / 1068.0, 0.0, f);
        return result;
    }

    static TFilter UnitTransform() {
        filter f(3, std::vector<double>(3));
        f = {{0, 0, 0},
             {0, 1, 0},
             {0, 0, 0}};
        TFilter result(1.0, 0.0, f);
        return result;
    }

    static TFilter EdgedTransform() {
        filter f(3, std::vector<double>(3));
        f = {{1, 1, 1},
             {1, -7, 1},
             {1, 1, 1}};
        TFilter result(1.0, 0.0, f);
        return result;
    }

    static TFilter SharpenTransform() {
        filter f(3, std::vector<double>(3));
        f = {{-1, -1, -1},
             {-1,  9, -1},
             {-1, -1, -1}};
        TFilter result(1.0, 0.0, f);
        return result;
    }

    static TFilter MotionTransform() {
        std::vector<std::vector<double>> f(9, std::vector<double>(9));
        f = {{1, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 1, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 1, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 1, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 1, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 1, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 1, 0},
             {0, 0, 0, 0, 0, 0, 0, 0, 1}};
        TFilter result(1.0 / 9.0, 0.0, f);
        return result;
    }

    // i dont know
//    std::vector<std::vector<double>> f(3, std::vector<double>(3));
//    f = {{1, 1, 1},
//         {1, 1, 1},
//         {1, 1, 1}};
//    TFilter filt(1.0 / 9.0, 0.0, f);


};

#endif //FAV_TSAMPLE_H
