#include <iostream>
#include "DonThuc.h"
using namespace std;
void DonThuc::SetHeSoA(int A)
{
	this->a = A;
}
void DonThuc::SetHeSoB(int B)
{
	this->b = B;
}
int DonThuc::GetHeSoA()
{
	return this->a;
}
int DonThuc::GetHeSoB()
{
	return this->b;
}
void DonThuc::NhapDonThuc()
{
	cout << "Nhap a:";
	cin >> this->a;
	cout << "Nhap b:";
	cin >> this->b;
}
void DonThuc::XuatDonThuc()
{
	cout << this->a << "x" << " + " << b;
}
DonThuc DonThuc::Tong(DonThuc A, DonThuc B)
{
	DonThuc dt;
	int a;
	int b;
	a = A.GetHeSoA() + B.GetHeSoA();
	b = A.GetHeSoB() + B.GetHeSoB();
	dt.SetHeSoA(a);
	dt.SetHeSoB(b);
	return dt;
}
DonThuc DonThuc::Hieu(DonThuc A, DonThuc B)
{
	DonThuc dt;
	int a;
	int b;
	a = A.GetHeSoA() - B.GetHeSoA();
	b = A.GetHeSoB() - B.GetHeSoB();
	dt.SetHeSoA(a);
	dt.SetHeSoB(b);
	return dt;
}
float DonThuc::fx(DonThuc A, DonThuc B)
{
	float x;
	if (this->a == 0)
	{
		if (this->b == 0)
		{
			cout << "pt vo so nghiem";
		}
		else if (this->b != 0)
		{
			cout << "pt vo nghiem";
		}
	}
	else
		x = -A.GetHeSoB() / A.GetHeSoA();
	return x;
}