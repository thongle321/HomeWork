#include <iostream>
#include <string>
#include "Nguoi.h"
#include <ctime>
using namespace std;
Nguoi::Nguoi()
{
	HoTen = "";
	GioiTinh = true;
	NamSinh = 1900;
	NoiSinh = "";
	DiaChi = "";
}
Nguoi::Nguoi(string HoTen, bool GioiTinh, int NamSinh, string NoiSinh, string DiaChi)
{
	this->HoTen = HoTen;
	this->GioiTinh = GioiTinh;
	this->NamSinh = NamSinh;
	this->NoiSinh = NoiSinh;
	this->DiaChi = DiaChi;
}
Nguoi::~Nguoi()
{
	HoTen = "";
	GioiTinh = true;
	NamSinh = 0;
	NoiSinh = "";
	DiaChi = "";
}
void Nguoi::Nhap()
{
	cout << "Nhap ho va ten: ";
	cin.ignore();
	getline(cin, HoTen);
	cin.ignore();
	int gt;
	cout << "Nhap gioi tinh (0: Nu, 1: Nam) : ";
	cin >> gt;
	if (gt == 0)
	{
		this->GioiTinh = false;
	}
	else
	{
		this->GioiTinh = true;
	}
	cout << "Nhap nam sinh: ";
	cin >> NamSinh;
	cin.ignore();
	cout << "Nhap noi sinh: ";
	getline(cin, NoiSinh);
	cin.ignore();
	cout << "Nhap dia chi: ";
	getline(cin, DiaChi);
}
void Nguoi::Xuat()
{
	cout << "\n Ho va Ten: " << HoTen;
	cout << "\n Gioi Tinh: " << GioiTinh;
	cout << "\n Nam Sinh: " << NamSinh;
	cout << "\n Noi Sinh: " << NoiSinh;
	cout << "\n Dia Chi: " << DiaChi;
}
int Nguoi::Tuoi()
{
	int tuoi;
	int namhientai;
	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);
	namhientai = now.tm_year + 1900;
	tuoi = namhientai - NamSinh;
	return tuoi;
}
