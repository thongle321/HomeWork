#pragma once
#include <iostream>
#include <string>
#include "NhanVien.h"
using namespace std;
class NhanVienCN : public NhanVien
{
protected:
	int ngaycong;
public:
	NhanVienCN();
	NhanVienCN(string, string, string, string, int);
	~NhanVienCN();
	float Luong();
	void Nhap();
	void Xuat();

};