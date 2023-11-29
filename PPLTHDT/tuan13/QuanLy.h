#pragma once
#include <iostream>
#include "NhanVien.h"
using namespace std;
class QuanLy
{
protected:
	int soluongnv;
	int soluongnvsx, soluongnvcn, soluongnvql;

	NhanVien *arrNhanVien[100];

public:
	QuanLy();
	~QuanLy();
	void Nhap();
	void Xuat();
	void XuatLoaiNhanVien();
	float tongluong();
};