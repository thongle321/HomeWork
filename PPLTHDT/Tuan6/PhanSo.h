#include<iostream>
using namespace std;
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
	PhanSo();
	PhanSo operator+(PhanSo ps);
	PhanSo operator-(PhanSo ps);
	PhanSo operator*(PhanSo ps);
	PhanSo operator/(PhanSo ps);
	PhanSo operator+(int);
	friend PhanSo operator+(int n, PhanSo ps);
	friend PhanSo operator-(int n, PhanSo ps);
	friend PhanSo operator*(int n, PhanSo ps);
	friend PhanSo operator/(int n, PhanSo ps);
	//So sanh
	bool operator>(PhanSo ps);
	//friend nhap
	friend istream& operator>>(istream& in, PhanSo& ps);
	//friend xuat
	friend ostream& operator<<(ostream& out, PhanSo& ps);

};