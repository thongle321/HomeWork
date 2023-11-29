#include "Nguoi.h"
#include "HocSinh.h"
#include <iostream>
#include <string>
#include<ctime>
using namespace std;
HocSinh::HocSinh()
{
	DiemToan = 0;
	DiemVan = 0;
	DiemNgoaiNgu = 0;
}
HocSinh::HocSinh(string HoTen, bool GioiTinh, int NamSinh, string NoiSinh, string DiaChi, float DiemToan, float DiemVan, float DiemNgoaiNgu)
	:Nguoi(HoTen,GioiTinh,NamSinh,NoiSinh,DiaChi)
{
	this->DiemToan = DiemToan;
	this->DiemVan = DiemVan;
	this->DiemNgoaiNgu = DiemNgoaiNgu;
}
HocSinh::~HocSinh()
{
	DiemToan = 0;
	DiemVan = 0;
	DiemNgoaiNgu = 0;
}
void HocSinh::Xuat()
{
	Nguoi::Xuat();
	cout << "\n Diem toan: " << DiemToan;
	cout << "\n Diem van: " << DiemVan;
	cout << "\n Diem ngoai ngu: " << DiemNgoaiNgu;
}
float HocSinh::DiemTrungBinh()
{
	float DiemTB;
	DiemTB = (DiemToan * 2 + DiemVan * 2 + DiemNgoaiNgu) / 5;
	return DiemTB;
}
int HocSinh::XepLoaiHocSinh()
{
	int kq;
	float DiemTB;
	DiemTB = DiemTrungBinh();
	if ((DiemTB >= 8) && (DiemToan >= 6.5) && (DiemVan >= 6.5) && (DiemNgoaiNgu >= 6.5))
	{
		kq = GIOI;
	}
	else
	{
		if ((DiemTB >= 6.5) && (DiemToan >= 5) && (DiemVan >= 5) (DiemNgoaiNgu >= 6.5))
		{
			kq = KHA;
		}
		else
		{
			if ((DiemTB >= 5) && (DiemToan >= 3) && (DiemVan >= 3) && (DiemNgoaiNgu >= 5))
			{
				kq = TRUNG_BINH;
			}
			else
			{
				kq = KEM;
			}
		}
	}
	return kq;
}
int HocSinh::LoaiThanhVien()
{
	return HOC_SINH;
}