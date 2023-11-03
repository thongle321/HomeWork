#include <iostream>
#include <cmath>
using namespace std;
class PhuongTrinh
{
protected:
    double a, b, c;

public:
    virtual void nghiem();
    virtual void nhap();
    virtual void xuat();
};
class ptb1 : public PhuongTrinh
{
public:
    void nghiem();
    void nhap();
    void xuat();
};
class ptb2 : public PhuongTrinh
{
public:
    void nghiem();
    void nhap();
    void xuat();
};
