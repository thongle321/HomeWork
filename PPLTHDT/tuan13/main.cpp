#include <iostream>
#include "NhanVien.h"
#include "NhanVienCongNhat.h"
#include "NhanVienQuanLy.h"
#include "NhanVienSanXuat.h"
#include "QuanLy.h"
using namespace std;
int main()
{
	QuanLy *a = new QuanLy();
	a->Nhap();
	a->Xuat();
	a->XuatLoaiNhanVien();
	int tong = a->tongluong();
	cout << "Tong luong: " << tong;
	return 0;
}