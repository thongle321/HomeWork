#include <iostream>
#include <string>
#include "NhanVienSanXuat.h"
using namespace std;
void NhanVienSX::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap san pham: ";
	cin >> sanpham;
}
void NhanVienSX::Xuat()
{
	NhanVien::Xuat();
	cout << "\nSan pham: " << sanpham;
}
NhanVienSX::NhanVienSX()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
	sanpham = 0;
}
NhanVienSX::NhanVienSX(string hoten, string ngaysinh, string diachi, string dienthoai, int sanpham) : NhanVien(hoten, ngaysinh, diachi, dienthoai)
{
	hoten = hoten;
	ngaysinh = ngaysinh;
	diachi = diachi;
	dienthoai = dienthoai;
	sanpham = sanpham;
}
NhanVienSX::~NhanVienSX()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
	sanpham = 0;
}
float NhanVienSX::Luong()
{
	return sanpham * 3000;
}