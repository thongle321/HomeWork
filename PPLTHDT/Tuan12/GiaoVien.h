#pragma once
#include "Nguoi.h"
class GiaoVien: public Nguoi
{
protected:
	int NamBatDau;
	string ChuyenMon;
public:
	GiaoVien();
	GiaoVien(string, bool, int, string, string, int, string);
	~GiaoVien();
	string* GetChuyenMon();
	virtual void Nhap();
	virtual void Xuat();
	//friend istream& operator>>(istream in, GiaoVien gv);
	//friend ostream& operator<<(ostream out, GiaoVien gv);
	virtual int LoaiThanhVien();
	int SoNamGiangDay();
};