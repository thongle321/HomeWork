#include <iostream>
#include "dathuc.h"
using namespace std;
int main()
{
    dathuc A, B, C, D, E, F;
    A.nhap();
    cout << endl;
    A.xuat();
    B.nhap();
    cout << endl;
    B.xuat();
    C = A + B;
    cout << "Tong 2 da thuc: ";
    C.xuat();
    cout << endl;
    D = A - B;
    cout << "Hieu 2 da thuc: ";
    D.xuat();
    cout << endl;
    E = A * B;
    cout << "Tich 2 da thuc: ";
    E.xuat();
    cout << endl;
    if (A == B)
    {
        cout << "Da thuc A lon hon B";
    }
    else
    {
        cout << "Da thuc B lon hon A";
    }
    cout << endl;
    cout << "Gan da thuc A = B";
    A = B;
    cout << "Da thuc A: ";
    A.xuat();
    float x;
    cout << "Nhap gia tri x cua A: ";
    cin >> x;
    float GiaTriA = A.giatri(x);
    cout << "Gia tri cua da thuc A tai x = " << x << " la: " << GiaTriA << endl;
    cout << "Nhap gia tri x cua B: ";
    cin >> x;
    float GiaTriB = B.giatri(x);
    cout << "Gia tri cua da thuc B tai x = " << x << " la: " << GiaTriB << endl;
}