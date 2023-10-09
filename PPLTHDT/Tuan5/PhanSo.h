#pragma once
class PhanSo
{
private:
	int _tu;
	int _mau;
public:
	void SetTu(int tu);
	void SetMau(int mau);
	int GetTu();
	int GetMau();
	~PhanSo();
	PhanSo(int tu, int mau);
	PhanSo operator+(PhanSo ps);
	PhanSo operator-(PhanSo ps);
	PhanSo operator*(PhanSo ps);
	PhanSo operator/(PhanSo ps);
	PhanSo operator+(int);
	friend PhanSo operator+(int n, PhanSo ps);
	friend PhanSo operator-(int n, PhanSo ps);
	friend PhanSo operator*(int n, PhanSo ps);
	friend PhanSo operator/(int n, PhanSo ps);


};