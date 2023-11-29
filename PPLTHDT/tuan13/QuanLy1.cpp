#include <iostream>
#include "QuanLy.h"
#include "NhanVienSanXuat.h"
#include "NhanVienCongNhat.h"
#include "NhanVienQuanLy.h"
using namespace std;
void QuanLy::Nhap()
{

	cout << "Nhập số luong nhan vien: ";
	cin >> soluongnv;
	cout << "\n1. Nhan vien san xuat";
	cout << "\n2. Nhan vien cong nhat";
	cout << "\n3. Nhan vien quan ly";
	cout << "\n4. Xuất loại\n";

	for (int i = 0; i < soluongnv; i++)
	{
		int chon;
		cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":";

		cin >> chon;

		if (chon == 1)
		{
			arrNhanVien[i] = new NhanVienSX();

			soluongnvsx++;
		}
		else if (chon == 2)
		{
			arrNhanVien[i] = new NhanVienCN();

			soluongnvcn++;
		}
		else if (chon == 3)
		{
			arrNhanVien[i] = new NhanVienQL();

			soluongnvql++;
		}
		else if (chon == 4)
		{
			// Exit the loop when selecting option 4
			break;
		}
		else
		{
			cout << "Lua chon khong hop le. Vui long nhap lai!";
		}
	}

	for (int i = 0; i < soluongnv; i++)
	{
		cout << "Nhap nhan vien thu: " << i << ": " << endl;
		arrNhanVien[i]->Nhap();
	}
}

void QuanLy::Xuat()
{
	cout << "Tong so nhan vien: " << soluongnv << endl;
	for (int i = 0; i < soluongnv; i++)
	{
		arrNhanVien[i]->Xuat();
		cout << "Luong: " << arrNhanVien[i]->Luong() << endl;
	}
}
QuanLy::QuanLy()
{
	soluongnv = 0;
	soluongnvsx = 0;
	soluongnvcn = 0;
	soluongnvql = 0;
	for (int i = 0; i < 100; i++)
	{
		arrNhanVien[i] = nullptr;
	}
}
QuanLy::~QuanLy()
{
	for (int i = 0; i < soluongnv; i++)
	{
		delete arrNhanVien[i];
	}
}
void QuanLy::XuatLoaiNhanVien()
{
	cout << "So luong nhan vien san xuat: " << soluongnvsx << endl;
	cout << "So luong nhan vien cong nhat: " << soluongnvcn << endl;
	cout << "So luong nhan vien quan ly: " << soluongnvql << endl;
}
float QuanLy::tongluong()
{
	float tongluong = 0;
	for (int i = 0; i < soluongnv; i++)
	{
		tongluong += arrNhanVien[i]->Luong();
	}
	return tongluong;
}
