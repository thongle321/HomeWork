#include "DonThuc.h"
#include <iostream>

using namespace std;

int main()
{
    DonThuc A, B, C, D;

    cout << "Nhap don thuc A: " << endl;
    A.Nhap();
    cout << "Nhap don thuc B: " << endl;
    B.Nhap();
    cout << "Don thuc A: ";
    A.Xuat();
    cout << "Don thuc B: ";
    B.Xuat();
    C = A.TinhTong(A, B);
    cout << "Tong 2 don thuc: ";
    C.Xuat();
    D = A.TinhHieu(A, B);
    cout << "Hieu 2 don thuc: ";
    D.Xuat();
    cout << "Giai phuong trinh f(x) = 0: " << endl;
    A.Nghiem();
    cout << "Giai phuong trinh f(x) = 0: " << endl;
    B.Nghiem();

    return 0;
}
