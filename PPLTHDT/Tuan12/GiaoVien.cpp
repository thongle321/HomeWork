#include <iostream>
#include "Nguoi.h"
#include "GiaoVien.h"
#include <string>
#include <ctime>
using namespace std;
GiaoVien::GiaoVien() : Nguoi()
{
	NamBatDau = 1900;
	ChuyenMon = "";
}
GiaoVien::GiaoVien(string HoTen, bool GioiTinh, int NamSinh, string NoiSinh, string DiaChi, int NamBatDau, string ChuyenMon)
	:Nguoi(HoTen, GioiTinh, NamSinh, NoiSinh, DiaChi)
{
	this->NamBatDau = NamBatDau;
	this->ChuyenMon = ChuyenMon;
}

GiaoVien::~GiaoVien()
{
	NamBatDau = 1900;
	ChuyenMon = "";
}
string* GiaoVien::GetChuyenMon()
{
	return this->ChuyenMon;
}
void GiaoVien::Nhap()
{
	Nguoi::Nhap();
	cout << "Ngay nam bat dau giang day: ";
	cin >> NamBatDau;
	cin.ignore();
	cout << "Nhap chuyen mon: ";
	getline(cin, ChuyenMon);
}
void GiaoVien::Xuat()
{
	Nguoi::Xuat();
	cout << "\n Nam bat dau giang day: " << NamBatDau;
	cout << "\n Chuyen Mon: " << ChuyenMon;
}
int GiaoVien::SoNamGiangDay()
{
	int SoNamGD;
	int namhientai;
	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);
	namhientai = now.tm_year + 1900;
	SoNamGD = namhientai - NamBatDau;
	return SoNamGD;
}
int GiaoVien::LoaiThanhVien()
{
	return GIAO_VIEN;
}