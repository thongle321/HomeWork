#include <iostream>
#include "pt.h"
using namespace std;
int main()
{
    ptb1 phuongtrinhb1;
    ptb2 phuongtrinhb2;

    cout << "Phuong trinh bac 1: " << endl;
    phuongtrinhb1.nhap();
    phuongtrinhb1.xuat();
    phuongtrinhb1.nghiem();

    cout << "Phuong trinh bac 2: " << endl;
    phuongtrinhb2.nhap();
    phuongtrinhb2.xuat();
    phuongtrinhb2.nghiem();
    return 0;
}