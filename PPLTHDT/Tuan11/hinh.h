#pragma once
#include <iostream>
using namespace std;
class Hinh
{
public:
    Hinh();
    virtual ~Hinh() = 0;
    virtual float ChuVi() = 0;
    virtual float DienTich() = 0;
};

class ChuNhat : public Hinh
{
protected:
    float ChieuDai;
    float ChieuRong;

public:
    ChuNhat();
    ChuNhat(float ChieuDai, float ChieuRong);
    virtual float ChuVi();
    virtual float DienTich();
};

class HinhVuong : public ChuNhat
{
public:
    HinhVuong(float a = 0);
};

class TamGiac : public Hinh
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
    TamGiacVuong(float a = 0, float b = 0);
};

class Tron : public Hinh
{
protected:
    float r;

public:
    Tron();
    Tron(float r);
    float ChuVi();
    float DienTich();
};
