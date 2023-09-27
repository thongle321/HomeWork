#include "PhanSo.h"
#include <iostream>
using namespace std;
void PhanSo::SetTuSo(int TuSo)
{
	this->tuso = TuSo;
}
void PhanSo::SetMauSo(int MauSo)
{
	this->mauso = MauSo;
}
int PhanSo::GetTuSo()
{
	return this->tuso;
}
int PhanSo::GetMauSo()
{
	return this->mauso;
}
void PhanSo::NhapPhanSo()
{
	cout << "Nhap tu so: ";
	cin >> this->tuso;
	cout << "Nhap mau so: ";
	cin >> this->mauso;
}
void PhanSo::XuatPhanSo()
{
	cout << this->tuso << "/" << this->mauso;
}
PhanSo PhanSo::TinhTong(PhanSo A, PhanSo B)
{
	PhanSo ps;
	int tuso;
	int mauso;
	tuso = A.GetTuSo() * B.GetMauSo() + B.GetTuSo() + A.GetMauSo();
	mauso = A.GetTuSo() * B.GetMauSo();
	ps.SetTuSo(tuso);
	ps.SetMauSo(mauso);
	return ps;
}
PhanSo PhanSo::TinhHieu(PhanSo A, PhanSo B)
{
	PhanSo ps;
	int tuso;
	int mauso;
	tuso = A.GetTuSo() * B.GetMauSo() - B.GetTuSo() + A.GetMauSo();
	mauso = A.GetTuSo() * B.GetMauSo();
	ps.SetTuSo(tuso);
	ps.SetMauSo(mauso);
	return ps;
}
PhanSo PhanSo::TinhTich(PhanSo A, PhanSo B)
{
	PhanSo ps;
	int tuso;
	int mauso;
	tuso = A.GetTuSo() * B.GetTuSo();
	mauso = A.GetMauSo() * B.GetMauSo();
	ps.SetTuSo(tuso);
	ps.SetMauSo(mauso);
	return ps;
}
PhanSo PhanSo::TinhThuong(PhanSo A, PhanSo B)
{
	PhanSo ps;
	int tuso;
	int mauso;
	tuso = A.GetTuSo() * B.GetMauSo();
	mauso = B.GetTuSo() * A.GetMauSo();
	ps.SetTuSo(tuso);
	ps.SetMauSo(mauso);
	return ps;
}
int PhanSo::UCLN(int a, int b)
{
	while (a * b != 0)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return a + b;
}
PhanSo PhanSo::RutGon()
{
	PhanSo ps;
	int tuso = this->tuso;
	int mauso = this->mauso;
	int ucln = this->UCLN(tuso, mauso);
	tuso /= ucln;
	mauso /= ucln;
	ps.SetTuSo(tuso);
	ps.SetMauSo(mauso);
	return ps;
}
int PhanSo::SoSanh(PhanSo A, PhanSo B) {
	if (A.GetTuSo() * B.GetMauSo() > B.GetTuSo() * A.GetMauSo()) {
		return 1;
	}
	else if (A.GetTuSo() * B.GetMauSo() < B.GetTuSo() * A.GetMauSo()) {
		return -1;
	}
	else {
		return 0;
	}
}
