#include <iostream>

#include "include/rectangle.hpp"

using namespace std;

void printPP(const PersegiPanjang &pp)
{
    cout << "x min     : " << pp[0] << endl;
    cout << "x max     : " << pp[1] << endl;
    cout << "y min     : " << pp[2] << endl;
    cout << "y max     : " << pp[3] << endl;
    cout << "panjang x : " << pp[1] - pp[0] << endl;
    cout << "lebar  y  : " << pp[3] - pp[2] << endl;
}

int main()
{
    cout << "Membuat persegi panjang 1: " << endl;
    PersegiPanjang pp1(2, 2, 2, 3);
    printPP(pp1);
    cin.ignore();
    
    cout << endl << "Membuat persegi panjang 2: " << endl;
    PersegiPanjang pp2(0, 0, 4, 5);
    printPP(pp2);
    cin.ignore();
    
    cout << endl << "Apakah pp1 dan pp2 beririsan: " << endl;
    cout << ((pp1 == pp2) ? "Ya" : "Tidak") << endl;
    cin.ignore();
    
    cout << endl << "Menambah pp1 dan pp2: (pp3)" << endl;
    PersegiPanjang pp3 = pp1 + pp2;
    printPP(pp3);
    cin.ignore();
    
    cout << endl << "Membuat persegi panjang 4: " << endl;
    PersegiPanjang pp4(-2, -2, 3, 2);
    printPP(pp4);
    cin.ignore();
    
    cout << endl << "Mengurangi pp2 dan pp4: (pp5)" << endl;
    PersegiPanjang pp5 = pp2 - pp4;
    printPP(pp5);
    cin.ignore();
    
    cout << endl << "Apakah pp5 dan pp1 beririsan: " << endl;
    cout << ((pp5 == pp1) ? "Ya" : "Tidak") << endl;
    cin.ignore();

    cout << endl << "Melakukan operator ++ pada pp5: " << endl;
    ++pp5;
    printPP(pp5);
    cin.ignore();

    cout << endl << "Melakukan operator -- pada pp1: " << endl;
    --pp1;
    printPP(pp1);

    cout << endl << "Done" << endl;
    return 0;
}