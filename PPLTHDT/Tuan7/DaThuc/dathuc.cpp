#include <iostream>
#include "dathuc.h"
#define MAX 100
using namespace std;
dathuc::dathuc()
{
    this->bac = 0;
    for (int i = 0; i < MAX; i++)
    {
        this->heso[i] = 0;
    }
}
dathuc::dathuc(int bac, float heso[])
{
    this->bac = bac;
    for (int i = 0; i < MAX; i++)
    {
        this->heso[i] = heso[i];
    }
    for (int i = this->bac + 1; i < MAX; i++)
    {
        this->heso[i] = 0;
    }
}
dathuc::~dathuc()
{
}
void dathuc::nhap()
{
    cout << "Nhap bac cua da thuc: ";
    cin >> this->bac;
    cout << "Nhap he so cho da thuc \n";
    for (int i = bac; i >= 0; i--)
    {
        cout << "He so cua x^" << i << "=";
        cin >> this->heso[i];
    }
}
void dathuc::xuat()
{
    for (int i = this->bac; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << this->heso[i];
        }
        else
        {
            cout << this->heso[i] << "x^" << i << " + ";
        }
    }
    cout << endl;
}
dathuc operator+(dathuc dt1, dathuc dt2)
{
    dathuc kq;
    kq.bac = max(dt1.bac, dt2.bac);
    for (int i = 0; i <= kq.bac; i++)
    {
        kq.heso[i] = dt1.heso[i] + dt2.heso[i];
    }
    return kq;
}
dathuc operator-(dathuc dt1, dathuc dt2)
{
    dathuc kq;
    kq.bac = max(dt1.bac, dt2.bac);
    for (int i = 0; i <= kq.bac; i++)
    {
        kq.heso[i] = dt1.heso[i] - dt2.heso[i];
    }
    return kq;
}
dathuc operator*(dathuc dt1, dathuc dt2)
{
    dathuc kq;
    kq.bac = dt1.bac + dt2.bac;
    for (int i = 0; i <= dt1.bac; i++)
    {
        for (int j = 0; j <= dt2.bac; j++)
        {
            kq.heso[i + j] += dt1.heso[i] * dt2.heso[j];
        }
    }
    return kq;
}
dathuc dathuc::operator=(dathuc dt)
{
    this->bac = dt.bac;
    for (int i = 0; i <= this->bac; i++)
    {
        this->heso[i] = dt.heso[i];
    }
    return *this;
}
bool dathuc::operator==(dathuc dt)
{
    if (this->bac != dt.bac)
    {
        return false;
    }
    for (int i = 0; i <= this->bac; i++)
    {
        if (this->heso[i] != dt.heso[i])
        {
            return false;
        }
    }
    return true;
}
bool dathuc::operator!=(dathuc dt)
{
    return !(operator==(dt));
}
float dathuc::giatri(float x)
{
    float kq = 0;
    for (int i = this->bac; i >= 0; i--)
    {
        kq = kq * x + this->heso[i];
    }
    return kq;
}
