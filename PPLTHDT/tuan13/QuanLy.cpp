#include <iostream>
#include "QuanLy.h"
#include "NhanVienSanXuat.h"
#include "NhanVienCongNhat.h"
#include "NhanVienQuanLy.h"
using namespace std;
void QuanLy::Nhap()
{
	int chon;
	do
	{
		cout << "So luong nhan vien: ";
		cin >> soluongnv;

		cout << "\n1. Nhan vien san xuat";
		cout << "\n2. Nhan vien cong nhat";
		cout << "\n3. Nhan vien quan ly";
		cout << "\n4. Xuất loại\n";

		for (int i = 0; i < soluongnv; i++)
		{
			cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":";

			cin >> chon;

			switch (chon)
			{
			case 1:
				arrNhanVien[i] = new NhanVienSX();
				arrNhanVien[i]->Nhap();
				soluongnvsx++;
				break;
			case 2:
				arrNhanVien[i] = new NhanVienCN();
				arrNhanVien[i]->Nhap();
				soluongnvcn++;
				break;
			case 3:
				arrNhanVien[i] = new NhanVienQL();
				arrNhanVien[i]->Nhap();
				soluongnvql++;
				break;
			case 4:
				// Exit the loop when selecting option 4
			default:
				cout << "Lua chon khong hop le. Vui long nhap lai!";
				break;
			}
		}

		cout << "\nBan co muon nhap them nhan vien khong? (0: Khong, 1: Co): ";
		cin >> chon;
	} while (chon == 1); // Continue the loop if the user chooses to add more employees
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
