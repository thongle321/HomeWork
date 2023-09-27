#include "PhanSo.h"
#include <iostream>
using namespace std;
int main()
{
	PhanSo A, B, C, D, E, F;
	cout << "Nhap phan so A: \n";
	A.NhapPhanSo();
	cout << "Nhap phan so B: \n";
	B.NhapPhanSo();

	// Tong
	C = A.TinhTong(A, B);
	cout << "Tong 2 phan so: ";
	C = C.RutGon();
	C.XuatPhanSo();
	cout << '\n';

	// Hieu
	D = A.TinhHieu(A, B);
	cout << "Hieu 2 phan so: ";
	D = D.RutGon();
	D.XuatPhanSo();
	cout << '\n';

	// Tich
	E = A.TinhTich(A, B);
	cout << "Tich 2 phan so: ";
	E = E.RutGon();
	E.XuatPhanSo();
	cout << '\n';

	// Thuong
	F = A.TinhThuong(A, B);
	cout << "Thuong 2 phan so: ";
	F = F.RutGon();
	F.XuatPhanSo();

	cout << endl;
	int kq = A.SoSanh(A, B);
	if (kq == -1)
	{
		cout << "Phan so A < phan so B" << endl;
	}
	else if (kq == 1)
	{
		cout << "Phan so A > phan so B" << endl;
	}
	else
	{
		cout << "Phan so A = phan so B" << endl;
	}

	return 0;
}