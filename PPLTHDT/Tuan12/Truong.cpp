#include "GiaoVien.h"
#include "Nguoi.h"
#include "HocSinh.h"
#include "Truong.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;
Truong::Truong()
{
	n = 0;
	for (int i = 0; i < MAX; i++)
	{
		arrThanhVien[i] = NULL;
	}
}
Truong::~Truong()
{
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			delete arrThanhVien[i];
			arrThanhVien[i] = NULL;
		}
		n = 0;
	}
}
void Truong::NhapThongTinTruong()
{
	cout << "Nhap so thanh vien: ";
	cin >> n;
	cout << "Chon loai thanh vien: ";
	cout << "\n\t1. Giao vien";
	cout << "\n\t2. Hoc Sinh" << endl;
	for (int i = 0; i < n; i++)
	{
		int loai;
		cout << "Nhap loai cua thanh vien thu " << i << ": ";
		cin >> loai;
		if (loai == 1)
		{
			arrThanhVien[i] = new GiaoVien();
			
		}
		if (loai == 2)
		{
			arrThanhVien[i] = new HocSinh();
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		arrThanhVien[i]->Nhap();
	}
}
void Truong::XuatThongTinTruong()
{
	cout << "\n\nTong so thanh vien: " << n << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\n*Thanh vien thu " << i << ": ";
		arrThanhVien[i]->Xuat();
	}
}
void Truong::XuatHocSinhXepLoaiKha()
{
	cout << "\n\nDanh sach hoc sinh xep loai kha: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (arrThanhVien[i]->LoaiThanhVien() == HOC_SINH)
		{
			HocSinh* hs = (HocSinh*) this->arrThanhVien[i];
			if (hs->XepLoaiHocSinh() == KHA)
			{
				cout << endl;
				hs->Xuat();
			}
		}
	}
}
void Truong::XuatHocSinhXepLoaiGioi()
{
	cout << "\n\nDanh sach hoc sinh xep loai gioi: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (arrThanhVien[i]->LoaiThanhVien() == HOC_SINH)
		{
			HocSinh* hs = (HocSinh*)this->arrThanhVien[i];
			if (hs->XepLoaiHocSinh() == GIOI)
			{
				cout << endl;
				hs->Xuat();
			}
		}
	}
}
void Truong::XuatThanhVienLonTuoiNhat()
{
	int max;
	Nguoi* ThanhVienLonNhat;
	cout << "\n\nThanh vien lon tuoi nhat: " << endl;
	max = arrThanhVien[0]->Tuoi();
	ThanhVienLonNhat = arrThanhVien[0];
	for (int i = 0; i < n; i++)
	{
		if (arrThanhVien[i]->Tuoi() > max)
		{
			ThanhVienLonNhat = arrThanhVien[i];
			max = arrThanhVien[i]->Tuoi();
		}
	}
	ThanhVienLonNhat->Xuat();
	cout << "\nSo tuoi lon nhat la: " << max;
}
void Truong::XuatGiaoVienThamNienTren5Nam()
{
	cout << "\n\nDanh sach giao vien tham nien tren 5 nam: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (arrThanhVien[i]->LoaiThanhVien() == GIAO_VIEN)
		{
			GiaoVien* gv = (GiaoVien*)this->arrThanhVien[i];
			if (gv->SoNamGiangDay() >=5)
			{
				cout << endl;
				gv->Xuat();
			}
		}
	}
}
void Truong::XuatGiaoVienThamNienTren10Nam_CMToan_Ly()
{
	cout << "\n\nDanh sach giao vien tham nien tren 10 nam co chuyen mon Toan Hoac Ly: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (arrThanhVien[i]->LoaiThanhVien() == GIAO_VIEN)
		{
			GiaoVien* gv = (GiaoVien*)this->arrThanhVien[i];
			if (gv->SoNamGiangDay() >= 10 && (strcmp(gv->GetChuyenMon(), "Toan") == 0 || strcmp (gv->GetChuyenMon(), "Ly") == 0 ))
			{
				cout << endl;
				gv->Xuat();
			}
		}
	}
}