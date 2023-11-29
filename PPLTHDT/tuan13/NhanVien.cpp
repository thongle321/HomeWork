#include <iostream>
#include <string>
#include "NhanVien.h"
using namespace std;
NhanVien::NhanVien()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
}
NhanVien::NhanVien(string hoten, string ngaysinh, string diachi, string dienthoai)
{
	hoten = hoten;
	ngaysinh = ngaysinh;
	diachi = diachi;
	dienthoai = dienthoai;
}
NhanVien::~NhanVien()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
}
void NhanVien::Nhap()
{
	cin.ignore();
	cout << "Nhap ho va ten: "; 
	getline(cin, hoten);
	cout << "Nhap ngay sinh: ";
	getline(cin, ngaysinh);
	cout << "Nhap dia chi: ";
	getline(cin, diachi);
	cout << "Nhap dien thoai: ";
	getline(cin, dienthoai);
}
void NhanVien::Xuat()
{
	cout << "\nHo va ten: " << hoten;
	cout << "\nNgay sinh: " << ngaysinh;
	cout << "\nDia chi: " << diachi;
	cout << "\nDien thoai: " << dienthoai;
}