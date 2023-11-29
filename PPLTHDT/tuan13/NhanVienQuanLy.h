#pragma once
#include <iostream>
#include <string>
#include "NhanVien.h"
using namespace std;
class NhanVienQL : public NhanVien
{
protected:
	float LuongCB;
	float hesoluong;
public:
	NhanVienQL();
	NhanVienQL(string, string, string, string, float, float);
	~NhanVienQL();
	float Luong();
	void Nhap();
	void Xuat();

};