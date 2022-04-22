#include <iostream>

#include "include/square.hpp"

using namespace std;

void PersegiPanjang::print()
{
    cout << "x min     : " << this->xmin << endl;
    cout << "x max     : " << this->xmax << endl;
    cout << "y min     : " << this->ymin << endl;
    cout << "y max     : " << this->ymax << endl;
    cout << "panjang x : " << (this->xmax - this->xmin) << endl;
    cout << "tinggi y  : " << (this->ymax - this->ymin) << endl;
}

PersegiPanjang::PersegiPanjang(int xCenter, int yCenter, int width_x, int height_y)
{
    this->xmin = (float)xCenter - (float)width_x/2;
    this->xmax = (float)xCenter + (float)width_x/2;
    this->ymin = (float)yCenter - (float)height_y/2;
    this->ymax = (float)yCenter + (float)height_y/2;
}

PersegiPanjang PersegiPanjang::operator+(const PersegiPanjang& rhs)
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

void PersegiPanjang::operator+=(const PersegiPanjang& rhs)
{
    *this = PersegiPanjang(*this+rhs);
}

PersegiPanjang PersegiPanjang::operator-(const PersegiPanjang& rhs)
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

void PersegiPanjang::operator-=(const PersegiPanjang& rhs)
{
    *this = PersegiPanjang(*this-rhs);
}

void PersegiPanjang::operator++()
{
    float width = this->xmax - this->xmin;
    float heigth = this->ymax - this->ymin;
    this->xmin -= width/2;
    this->xmax += width/2;
    this->ymin -= heigth/2;
    this->ymax += heigth/2;
}

void PersegiPanjang::operator--()
{
    float width = this->xmax - this->xmin;
    float heigth = this->ymax - this->ymin;
    this->xmin += width/4;
    this->xmax -= width/4;
    this->ymin += heigth/4;
    this->ymax -= heigth/4;
}

bool PersegiPanjang::operator==(const PersegiPanjang &other) const
{
    if (this->xmin < other.xmax && other.xmin < this->xmax)
        if (this->ymin < other.ymax && other.ymin < this->ymax)
            return true;
    return false;
}