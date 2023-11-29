#include <iostream>
#include <string>
#include "NhanVienCongNhat.h"
using namespace std;
void NhanVienCN::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap ngay cong: ";
	cin >> ngaycong;
}
void NhanVienCN::Xuat()
{
	NhanVien::Xuat();
	cout << "Ngay cong: " << ngaycong;
}
NhanVienCN::NhanVienCN()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
	ngaycong = 0;
}
NhanVienCN::NhanVienCN(string hoten, string ngaysinh, string diachi, string dienthoai, int ngaycong) : NhanVien(hoten, ngaysinh, diachi, dienthoai)
{
	hoten = hoten;
	ngaysinh = ngaysinh;
	diachi = diachi;
	dienthoai = dienthoai;
	ngaycong = ngaycong;
}
NhanVienCN::~NhanVienCN()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
	ngaycong = 0;
}
float NhanVienCN::Luong()
{
	return ngaycong * 70000;
}