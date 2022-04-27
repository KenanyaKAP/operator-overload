#include <iostream>

#include "include/square.hpp"

using namespace std;

PersegiPanjang::PersegiPanjang(int xCenter, int yCenter, int width_x, int height_y)
{
    this->xmin = (float)xCenter - (float)width_x/2;
    this->xmax = (float)xCenter + (float)width_x/2;
    this->ymin = (float)yCenter - (float)height_y/2;
    this->ymax = (float)yCenter + (float)height_y/2;
}

PersegiPanjang PersegiPanjang::operator+(const PersegiPanjang& rhs) const
{
    PersegiPanjang res(0,0,0,0);

    if (*this == rhs)
    {
        res.xmin = min(this->xmin, rhs.xmin);
        res.xmax = max(this->xmax, rhs.xmax);
        res.ymin = min(this->ymin, rhs.ymin);
        res.ymax = max(this->ymax, rhs.ymax);
        return res;
    }
    else
    {
        cout << "Peringatan: Persegi Panjang tidak beririsan!\nMengeluarkan value pada sisi kiri" << endl;
        return *this;
    }
}

PersegiPanjang PersegiPanjang::operator-(const PersegiPanjang& rhs) const
{
    PersegiPanjang res(0,0,0,0);
    if (*this == rhs)
    {
        res.xmin = max(this->xmin, rhs.xmin);
        res.xmax = min(this->xmax, rhs.xmax);
        res.ymin = max(this->ymin, rhs.ymin);
        res.ymax = min(this->ymax, rhs.ymax);
        return res;
    }
    else
    {
        cout << "Peringatan: Persegi Panjang tidak beririsan!\nMengeluarkan value pada sisi kiri" << endl;
        return *this;
    }
}

PersegiPanjang PersegiPanjang::operator++()
{
    float width = this->xmax - this->xmin;
    float heigth = this->ymax - this->ymin;
    this->xmin -= width/2;
    this->xmax += width/2;
    this->ymin -= heigth/2;
    this->ymax += heigth/2;
    return *this;
}

PersegiPanjang PersegiPanjang::operator--()
{
    float width = this->xmax - this->xmin;
    float heigth = this->ymax - this->ymin;
    this->xmin += width/4;
    this->xmax -= width/4;
    this->ymin += heigth/4;
    this->ymax -= heigth/4;
    return *this;
}

bool PersegiPanjang::operator==(const PersegiPanjang &rhs) const
{
    if (this->xmin < rhs.xmax && rhs.xmin < this->xmax)
        if (this->ymin < rhs.ymax && rhs.ymin < this->ymax)
            return true;
    return false;
}

float PersegiPanjang::operator[](int index) const
{
    switch (index)
    {
    case 0:
        return xmin;
    case 1:
        return xmax;
    case 2:
        return ymin;
    case 3:
        return ymax;
    default:
        return 0;
    }
}