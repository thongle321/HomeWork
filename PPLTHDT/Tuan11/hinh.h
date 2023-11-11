#pragma once
#include <iostream>
using namespace std;
class hinh
{
public:
    hinh();
    virtual ~hinh() = 0;
    virtual float ChuVi() = 0;
    virtual float DienTich() = 0;
};

class HinhCN : public hinh
{
protected:
    float ChieuDai;
    float ChieuRong;

public:
    HinhCN();
    HinhCN(float ChieuDai, float ChieuRong);
    virtual float ChuVi();
    virtual float DienTich();
};

class HinhVuong : public HinhCN
{
public:
    HinhVuong(float a = 0);
};

class TamGiac : public hinh
{
protected:
    float a, b, c;

public:
    TamGiac();
    TamGiac(float a, float b, float c);
    virtual float ChuVi();
    virtual float DienTich();
};

class TamGiacDeu : public TamGiac
{
public:
    TamGiacDeu(float a = 0);
};

class TamGiacVuong : public TamGiac
{
public:
    TamGiacVuong(float a = 0, float b = 0, float c = 0);
};

class Tron : public hinh
{
protected:
    float r;

public:
    Tron();
    Tron(float r);
    float ChuVi();
    float DienTich();
};
