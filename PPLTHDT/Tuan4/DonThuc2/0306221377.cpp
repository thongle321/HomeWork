#include <iostream>
#include "DonThuc.h"
using namespace std;
void main()
{
	DonThuc A, B, C, D, E;
	cout << "Nhap Don Thuc A:" << '\n';
	A.NhapDonThuc();
	cout << "Nhap Don Thuc B:" << '\n';
	B.NhapDonThuc();
	cout << "A = ";
	A.XuatDonThuc();
	cout << '\n';
	cout << "B = ";
	B.XuatDonThuc();
	cout << '\n';
	C = A.Tong(A, B);
	cout << "Tong = ";
	C.XuatDonThuc();
	cout << '\n';
	D = A.Hieu(A, B);
	cout << "Hieu = ";
	D.XuatDonThuc();
	cout << '\n';
	E.fx(A, B);
	cout << "fx = ";
	E.XuatDonThuc();
}
