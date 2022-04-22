#include <iostream>

#include "include/square.hpp"

using namespace std;

int main()
{
    cout << "Membuat persegi panjang 1: " << endl;
    PersegiPanjang pp1(2, 1, 2, 3);
    pp1.print();
    
    cout << endl << "Membuat persegi panjang 2: " << endl;
    PersegiPanjang pp2(-1, 2, 5, 2);
    pp2.print();

    cout << endl << "Menambah persegi panjang 1 dan 2: (pp3)" << endl;
    PersegiPanjang pp3 = pp1 + pp2;
    pp3.print();

    cout << endl << "Mengurangi persegi panjang 1 dan 2: (pp4)" << endl;
    PersegiPanjang pp4 = pp1 - pp2;
    pp4.print();

    cout << endl << "Melakukan operator ++ pada pp4: " << endl;
    ++pp4;
    pp4.print();

    cout << endl << "Melakukan operator -- pada pp3: " << endl;
    --  pp3;
    pp3.print();

    cout << "Done" << endl;
    return 0;
}