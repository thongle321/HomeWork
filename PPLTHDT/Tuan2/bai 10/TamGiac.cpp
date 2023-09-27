#include <iostream>
#include <TamGiac.h>
#include <cmath>
using namespace std;
void nhaptamgiac(TamGiac &tamgiac)
{
    nhapdiem(tamgiac.A);
    nhapdiem(tamgiac.B);
    nhapdiem(tamgiac.C);
}
void xuattamgiac(TamGiac tamgiac)
{
    xuatdiem(tamgiac.A);
    cout << ", ";
    xuatdiem(tamgiac.B);
    cout << ", ";
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
Diem trongtamtamgiac(TamGiac &tamgiac)
{
    Diem G;
    G.x = (tamgiac.A.x + tamgiac.B.x + tamgiac.C.x) / 3;
    G.y = (tamgiac.A.y + tamgiac.B.y + tamgiac.C.y) / 3;
    return G;
}