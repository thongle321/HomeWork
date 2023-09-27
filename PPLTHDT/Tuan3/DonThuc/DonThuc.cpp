#include "DonThuc.h"
#include <iostream>

using namespace std;

void DonThuc::Nhap()
{
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
}

/*void DonThuc::Xuat()
{
    cout << "f(x) = " << a << "x + " << b << endl;
}
*/
void DonThuc::Xuat()
{
    cout << "f(x) = " << a << "x ";
    if (b >= 0)
    {
        cout << "+ " << b;
    }
    else
    {
        cout << "- " << -b;
    }
    cout << endl;
}

DonThuc DonThuc::TinhTong(DonThuc A, DonThuc B)
{
    DonThuc dt;
    dt.a = A.a + B.a;
    dt.b = A.b + B.b;
    return dt;
}

DonThuc DonThuc::TinhHieu(DonThuc A, DonThuc B)
{
    DonThuc dt;
    dt.a = A.a - B.a;
    dt.b = A.b - B.b;
    return dt;
}

void DonThuc::Nghiem()
{
    if (a == 0)
    {
        if (b == 0)
        {
            cout << "Phuong trinh vo so nghiem" << endl;
        }
        else
        {
            cout << "Phuong trinh vo nghiem" << endl;
        }
    }
    else
    {
        float x = -b / (float)a;
        cout << "Nghiem cua phuong trinh la x = " << x << endl;
    }
}
