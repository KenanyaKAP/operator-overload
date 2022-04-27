#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include <iostream>

class PersegiPanjang {
private:
    float xmin, xmax, ymin, ymax;

public:
    PersegiPanjang(int xCenter, int yCenter, int width_x, int height_y);
    PersegiPanjang operator+(const PersegiPanjang &rhs);
    PersegiPanjang operator-(const PersegiPanjang &rhs);
    void operator++();
    void operator--();
    bool operator==(const PersegiPanjang &other) const;
    float operator[](int index) const;
};

#endif