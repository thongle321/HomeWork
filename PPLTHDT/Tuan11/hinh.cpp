#include "hinh.h"
#include <cmath>
#include <iostream>
const float PI = 3.14;
using namespace std;
// hinh
hinh::hinh()
{
}
hinh::~hinh()
{
}
// HinhCN
HinhCN::HinhCN() : ChieuDai(0), ChieuRong(0) {}
HinhCN::HinhCN(float ChieuDai, float ChieuRong)
{
    this->ChieuDai = ChieuDai;
    this->ChieuRong = ChieuRong;
}
float HinhCN::ChuVi()
{
    return (ChieuDai + ChieuRong) * 2;
}
float HinhCN::DienTich()
{
    return ChieuDai * ChieuRong;
}
// Hinh Vuong
HinhVuong::HinhVuong(float a) : HinhCN(a, a) {}
// Hinh Tam Giac
TamGiac::TamGiac() : a(0), b(0), c(0) {}
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
TamGiacDeu::TamGiacDeu(float a) : TamGiac(a, a, a) {}
// Tam Giac Vuong
TamGiacVuong::TamGiacVuong(float a, float b, float c) : TamGiac(a, b, sqrt(a * a + b * b)) {}
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
