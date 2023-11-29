#pragma once
#include<string>
#define GIAO_VIEN 1
#define HOC_SINH 2
using namespace std;
class Nguoi
{
protected:
	string HoTen;
	bool GioiTinh;
	int NamSinh;
	string NoiSinh;
	string DiaChi;
public:
	Nguoi();
	Nguoi(string, bool, int, string, string);
	~Nguoi();
	virtual void Nhap();
	virtual void Xuat();
	//friend istream& operator>>(istream in, Nguoi n);
	//friend istream& operator<<(ostream out, Nguoi n);
	int Tuoi();
	virtual int LoaiThanhVien() = 0;
};