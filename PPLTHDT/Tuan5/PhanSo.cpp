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

PhanSo::PhanSo(int tu, int mau)
{
	_tu = tu;
	_mau = mau;
}
PhanSo::~PhanSo()
{
}
PhanSo PhanSo::operator+(PhanSo ps)
{
	PhanSo kq(0,0);
	kq._tu = this->_tu * ps._mau + this->mau * ps._tu;
	kq._mau = this->_mau * ps._mau;
	return kq;                                                                                                   
}
PhanSo PhanSo::operator-(PhanSo ps)
{
	PhanSo kq(0, 0);
	kq._tu = this->_tu * ps._mau - ps._tu * this->_mau;
	kq._mau = this->_mau * ps._mau;
	return kq;
}
PhanSo PhanSo::operator*(PhanSo ps)
{
	PhanSo kq(0, 0);
	kq._tu = this->_tu * ps._mau;
	kq._mau = this->_mau * ps._mau;
	return kq;
}
PhanSo PhanSo::operator/(PhanSo ps)
{
	PhanSo kq(0, 0);
	kq._tu = this->_tu * ps._mau * ps._tu * this->_mau;
	kq._mau = this->_mau * ps._mau;
	return kq;
}
PhanSo PhanSo::operator+(int n)
{
	PhanSo kq(0, 0);
	kq._tu = this->_tu + this->_mau;
	kq._mau = this->_mau;
	return kq;
}
PhanSo operator+(int n, PhanSo ps)
{
	PhanSo kq(0, 0);
	kq._tu = ps._tu
}