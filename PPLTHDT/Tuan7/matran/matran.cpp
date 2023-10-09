#include "matran.h"
#include <iostream>
using namespace std;
matran::matran()
{
    dong = 1;
    cot = 1;
    for (int i = 0; i < MAX_DONG; i++)
    {
        for (int j = 0; j < MAX_COT; j++)
        {
            n[i][j] = 0;
        }
    }
}
matran::~matran()
{
}
void matran::nhap()
{
    cout << "Nhap so dong: ";
    cin >> this->dong;
    cout << "Nhap so cot: ";
    cin >> this->cot;

    for (int i = 0; i < this->dong; ++i)
    {
        for (int j = 0; j < this->cot; ++j)
        {
            cout << "Nhap gia tri [" << i << ", " << j << "]: ";
            cin >> n[i][j];
        }
    }
}

void matran::xuat()
{
    for (int i = 0; i < this->dong; ++i)
    {
        for (int j = 0; j < this->cot; ++j)
        {
            cout << n[i][j] << " ";
        }
        cout << endl;
    }
}
matran operator+(matran &mt1, matran &mt2)
{
    matran kq;
    kq.dong = mt1.dong;
    kq.cot = mt1.cot;
    for (int i = 0; i < mt1.dong; i++)
    {
        for (int j = 0; j < mt1.cot; j++)
        {
            kq.n[i][j] = mt1.n[i][j] + mt2.n[i][j];
        }
    }
    return kq;
}

matran operator-(matran &mt1, matran &mt2)
{
    matran kq;
    kq.dong = mt1.dong;
    kq.cot = mt1.cot;
    for (int i = 0; i < mt1.dong; i++)
    {
        for (int j = 0; j < mt1.cot; j++)
        {
            kq.n[i][j] = mt1.n[i][j] - mt2.n[i][j];
        }
    }
    return kq;
}
matran operator*(matran &mt1, matran &mt2)
{
    matran kq;
    kq.dong = mt1.dong;
    kq.cot = mt2.cot;

    for (int i = 0; i < mt1.dong; i++)
    {
        for (int j = 0; j < mt2.cot; j++)
        {
            for (int k = 0; k < mt1.cot; k++)
            {
                kq.n[i][j] += mt1.n[i][k] * mt2.n[k][j];
            }
        }
    }

    return kq;
}
matran &matran::operator=(const matran &mt2)
{
    if (this != &mt2)
    {
        this->dong = mt2.dong;
        this->cot = mt2.cot;
        for (int i = 0; i < mt2.dong; i++)
        {
            for (int j = 0; j < mt2.cot; j++)
            {
                this->n[i][j] = mt2.n[i][j];
            }
        }
    }
    return *this;
}