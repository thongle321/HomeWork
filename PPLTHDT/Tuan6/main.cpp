#include"PhanSo.h"
#include<iostream>
using namespace std;
void main()
{
	//PhanSo a, b;
	//cin >> a >> b;
	//PhanSo c = a + b;
	//PhanSo h = a + 2;
	//PhanSo k = 1 + a;

	//cout << "cong 2 ps:" << c.GetTu() << "/" << c.GetMau() << endl;
	//cout << "cong ps vs ps nguyen:" << h.GetTu() << "/" << h.GetMau() << endl;
	//cout << "cong so nguyen voi ps:" << k.GetTu() << "/" << k.GetMau() << endl;


	int x = 2;
	PhanSo A, B, C, D, E, F;
	cout << "\nNhap phan so A: \n";
	cin >> A;

	cout << "\nNhap phan so B: \n";
	cin >> B;

	C = A + B;
	D = A - B;
	E = A * B;
	F = A / B;

	cout << "\nTong 2 phan so:";
	cout << C;

	cout << "\n";

	cout << "\n 2 phan so:";
	cout << C;

	cout << "\n";

	cout << "\nTong 2 phan so:";
	cout << C;

	cout << "\n";

	cout << "\nTong 2 phan so:";
	cout << C;

	cout << "\n";

	if (A > B)
	{
		cout << "Tham so A lon hon B";
	}
	else
	{
		cout << "Tham so B lon hon A";
	}


}