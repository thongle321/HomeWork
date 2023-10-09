#include <iostream>
#include "PhanSo.h"
using namespace std;
int PhanSo::GetTu()
{
	return this->_tu;
}
int PhanSo::GetMau()
{
	return this->_mau;
}
void PhanSo::SetTu(int tu)
{
	this->_tu = tu;
}
void PhanSo::SetMau(int mau)
{
	this->_mau = mau;
}

PhanSo::PhanSo()
{
	_tu = -1;
	_mau = 1;
}
PhanSo::~PhanSo()
{
}
PhanSo PhanSo::operator+(PhanSo ps)
{
	PhanSo kq;
	kq._tu = this->_tu * ps._mau + this->_mau * ps._tu;
	kq._mau = this->_mau * ps._mau;
	return kq;
}
PhanSo PhanSo::operator+(int n)
{
	PhanSo kq;
	kq._tu = this->_tu + this->_mau * n;
	kq._mau = this->_mau;
	return kq;
}
PhanSo PhanSo::operator-(PhanSo ps)
{
	PhanSo kq;
	kq._tu = this->_tu * ps._mau - this->_mau * ps._tu;
	kq._mau = this->_mau * ps._mau;
	return kq;
}
PhanSo PhanSo::operator*(PhanSo ps)
{
	PhanSo kq;
	kq._tu = this->_tu * ps._tu;
	kq._mau = this->_mau * ps._mau;
	return kq;
}
PhanSo PhanSo::operator/(PhanSo ps)
{
	PhanSo kq;
	kq._tu = this->_tu * ps._mau;
	kq._mau = this->_mau * ps._mau;
	return kq;
}
//so sanh
bool PhanSo::operator>(PhanSo ps)
{
	bool kq;
	if (this->_tu * ps._mau > ps._tu * this->_mau)
	{
		kq = true;
	}
	else
	{
		kq = false;
	}
	return kq;
}

//friend class
PhanSo operator+(int n, PhanSo ps)
{
	PhanSo kq;
	kq._tu = ps._tu + ps._mau * n;
	kq._mau = ps._mau;
	return kq;
}
//PhanSo operator-(int n, PhanSo ps)
//{
//	
//}
//PhanSo operator*(int n, PhanSo ps)
//{
//
//}
//PhanSo operator/(int n, PhanSo ps)
//{
//
//}
istream& operator>>(istream& in, PhanSo& ps)
{
	cout << "Nhap tu so: ";
	in >> ps._tu;
	cout << "Nhap mau so: ";
	in >> ps._mau;
	return in;
} 
ostream& operator<<(ostream& out, PhanSo& ps)
{
	out << ps._tu << "/" << ps._mau;
	return out;
} 