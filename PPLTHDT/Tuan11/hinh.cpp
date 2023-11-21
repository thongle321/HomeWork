#include "hinh.h"
#include <cmath>
#include <iostream>
#define PI 3.14
using namespace std;
// hinh
Hinh::Hinh()
{
}
Hinh::~Hinh()
{
}
// ChuNhat
ChuNhat::ChuNhat()
{
    this->ChieuDai = 0;
    this->ChieuRong = 0;
}
ChuNhat::ChuNhat(float ChieuDai, float ChieuRong)
{
    this->ChieuDai = ChieuDai;
    this->ChieuRong = ChieuRong;
}
float ChuNhat::ChuVi()
{
    return (ChieuDai + ChieuRong) * 2;
}
float ChuNhat::DienTich()
{
    return ChieuDai * ChieuRong;
}
// Hinh Vuong
HinhVuong::HinhVuong(float a)
{
    this->ChieuDai = a;
    this->ChieuRong = a;
}
// Hinh Tam Giac
TamGiac::TamGiac()
{
    this->a = 0;
    this->b = 0;
    this->c = 0;
}
TamGiac::TamGiac(float a, float b, float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}
float TamGiac::ChuVi()
{
    return a + b + c;
}
float TamGiac::DienTich()
{
    float p = TamGiac::ChuVi() / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
// Tam Giac Deu
TamGiacDeu::TamGiacDeu(float a)
{
    this->a = a;
    this->b = a;
    this->c = a;
}
// Tam Giac Vuong
TamGiacVuong::TamGiacVuong(float a, float b)
{
    this->a = a;
    this->b = b;
    this->c = sqrt(a * a + b * b);
}

// Hinh Tron
Tron::Tron()
{
    r = 0;
}
Tron::Tron(float r)
{
    this->r = r;
}
float Tron::ChuVi()
{
    return 2 * PI * r;
}
float Tron::DienTich()
{
    return PI * r * r;
}
