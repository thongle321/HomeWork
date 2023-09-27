#include <iostream>
#include "Diem.h"
#include <cmath>
using namespace std;
void nhapdiem(Diem &d)
{
    cin >> d.x >> d.y;
}
void xuatdiem(Diem d)
{
    cout << d.x << ",  " << d.y;
}
float khoangcach(Diem A, Diem B)
{
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}