#include "pt.h"
#include <iostream>
#include <cmath>
using namespace std;
void PhuongTrinh::nhap()
{
}
void PhuongTrinh::xuat()
{
}
void PhuongTrinh::nghiem()
{
}
void ptb1::nhap()
{
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
}

void ptb1::xuat()
{
    cout << "Phuong trinh bac 1 co dang: " << a << "x + " << b << " = 0" << endl;
}
void ptb1::nghiem()
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
        cout << "Phuong trinh co nghiem x = " << -b / a << endl;
    }
}

void ptb2::nhap()
{
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;
}

void ptb2::xuat()
{
    cout << "Phuong trinh bac 2 co dang: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

void ptb2::nghiem()
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Phuong trinh vo so nghiem" << endl;
            }
            else
            {
                cout << "Phuong trinh vo nghien" << endl;
            }
        }
        else
        {
            cout << "Phuong trinh co nghiem x = " << -c / b << endl;
        }
    }
    else
    {
        double delta = (b * b) - (4 * a * c);
        if (delta == 0)
        {
            cout << "Delta = " << b << " - "
                 << "4"
                 << "." << a << "." << c << " = " << delta << endl;
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a) << endl;
        }
        else if (delta < 0)
        {
            cout << "Delta = " << b << " - "
                 << "4"
                 << "." << a << "." << c << " = " << delta << endl;
            cout << "Phuong trinh vo nghiem." << endl;
        }
        else
        {
            cout << "Delta = " << b << " - "
                 << "4"
                 << "." << a << "." << c << " = " << delta << endl;
            cout << "Phuong trinh co 2 nghiem phan biet: " << endl;
            cout << "x1: " << (-b + sqrt(delta)) / (2 * a);
            cout << "x2: " << (-b - sqrt(delta)) / (2 * a);
        }
    }
}
