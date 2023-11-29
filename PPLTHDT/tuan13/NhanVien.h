#pragma once
#include <string>
#include <iostream>
using namespace std;
class NhanVien
{
protected:
	string hoten;
	string ngaysinh;
	string diachi;
	string dienthoai;
public:
	NhanVien();
	NhanVien(string, string, string, string);
	virtual ~NhanVien();
	virtual void Nhap();
	virtual void Xuat();
	virtual float Luong() = 0;

};