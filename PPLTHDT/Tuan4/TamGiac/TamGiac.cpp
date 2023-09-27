#include <iostream>
#include "TamGiac.h"
#include <cmath>
using namespace std;
void nhaptamgiac(TamGiac& tamgiac)
{
    cout << "Nhap A \n" ; nhapdiem(tamgiac.A);
    cout << '\n';
    cout << "Nhap B \n"; nhapdiem(tamgiac.B);
    cout << '\n';
    cout << "Nhap C \n"; nhapdiem(tamgiac.C);
}
void xuattamgiac(TamGiac tamgiac)
{
    cout << "A:";
    xuatdiem(tamgiac.A);
    cout << '\n';
    cout << "B:";
    xuatdiem(tamgiac.B);
    cout << '\n';
    cout << "C:";
    xuatdiem(tamgiac.C);
    cout << endl;
}
float dientichtamgiac(TamGiac tamgiac)
{
    float a = khoangcach(tamgiac.A, tamgiac.B);
    float b = khoangcach(tamgiac.B, tamgiac.C);
    float c = khoangcach(tamgiac.C, tamgiac.A);
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
Diem trongtamtamgiac(TamGiac tamgiac)
{
    Diem G;
    G.x = (tamgiac.A.x + tamgiac.B.x + tamgiac.C.x) / 3;
    G.y = (tamgiac.A.y + tamgiac.B.y + tamgiac.C.y) / 3;
    return G;
}