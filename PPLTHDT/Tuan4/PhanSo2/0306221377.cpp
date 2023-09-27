#include "PhanSo.h"
#include <iostream>
using namespace std;
void main()
{
	PhanSo A, B, C, D, E, F;
	cout << "Nhap phan so A: \n";
	A.NhapPhanSo();
	cout << "Nhap phan so B: \n";
	B.NhapPhanSo();
	//Tong
	C = A.TinhTong(A, B);
	cout << "Tong 2 phan so: ";
	C.RutGon();
	C.XuatPhanSo();
	cout << '\n';
	//Hieu
	D = A.TinhHieu(A, B);
	cout << "Hieu 2 phan so: ";
	D.RutGon();
	D.XuatPhanSo();
	cout << '\n';
	//Tich
	E = A.TinhTich(A, B);
	cout << "Tich 2 phan so: ";
	E.RutGon();
	E.XuatPhanSo();
	cout << '\n';
	//Thuong
	F = A.TinhThuong(A, B);
	cout << "Thuong 2 phan so: ";
	F.RutGon();
	F.XuatPhanSo();

}