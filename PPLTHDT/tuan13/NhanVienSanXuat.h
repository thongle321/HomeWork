#pragma once
#include <iostream>
#include <string>
#include "NhanVien.h"
using namespace std;
class NhanVienSX : public NhanVien
{
protected:
	int sanpham;
public:
	NhanVienSX();
	NhanVienSX(string, string, string, string, int);
	~NhanVienSX();
	float Luong();
	void Nhap();
	void Xuat();

};