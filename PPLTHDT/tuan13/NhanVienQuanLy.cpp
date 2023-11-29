#include <iostream>
#include <string>
#include "NhanVienQuanLy.h"
using namespace std;
void NhanVienQL::Nhap()
{
	NhanVien::Nhap();
	cout << "Nhap luong co ban: ";
	cin >> LuongCB;
	cout << "Nhap he so luong: ";
	cin >> hesoluong;
}
void NhanVienQL::Xuat()
{
	NhanVien::Xuat();
	cout << "Luong co ban: " << LuongCB;
	cout << "He so luong: " << hesoluong;
}
NhanVienQL::NhanVienQL()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
	LuongCB = 0;
	hesoluong = 0;
}
NhanVienQL::NhanVienQL(string hoten, string ngaysinh, string diachi, string dienthoai, float LuongCB, float hesoluong)
{
	hoten = hoten;
	ngaysinh = ngaysinh;
	diachi = diachi;
	dienthoai = dienthoai;
	LuongCB = LuongCB;
	hesoluong = hesoluong;
}
NhanVienQL::~NhanVienQL()
{
	hoten = "";
	ngaysinh = "";
	diachi = "";
	dienthoai = "";
	LuongCB = 0;
	hesoluong = 0;
}
float NhanVienQL::Luong()
{
	return LuongCB * hesoluong;
}