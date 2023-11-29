#pragma once
#include "Nguoi.h"
#define GIOI 1
#define KHA 2
#define TRUNG_BINH 3
#define KEM 4
class HocSinh : public Nguoi
{
protected:
	float DiemToan;
	float DiemVan;
	float DiemNgoaiNgu;
public:
	HocSinh();
	HocSinh(string, bool, int, string, string, float, float, float);
	~HocSinh();
	virtual void Nhap();
	virtual void Xuat();
	float DiemTrungBinh();
	int XepLoaiHocSinh();
	virtual int LoaiThanhVien();
};