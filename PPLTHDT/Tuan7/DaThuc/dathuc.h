#pragma once
#define MAX 100
class dathuc
{
private:
    int bac;
    float heso[MAX];

public:
    dathuc();
    dathuc(int bac, float heso[]);
    ~dathuc();
    void nhap();
    void xuat();
    friend dathuc operator+(dathuc dt1, dathuc dt2);
    friend dathuc operator-(dathuc dt1, dathuc dt2);
    friend dathuc operator*(dathuc dt1, dathuc dt2);
    dathuc operator=(dathuc dt);
    bool operator==(dathuc dt);
    bool operator!=(dathuc dt);
    float giatri(float x);
};