#include <iostream>
#include "PhanSo.h"
using namespace std;
void main()
{
	//PhanSo *a = new PhanSo (8);
	//cout << a->GetTu() << "/" << a->GetMau();
	//delete a;
	PhanSo a(1, 2);
	PhanSo b(1, 4);
	PhanSo c = a + b;
	cout << "Cong: " << c.GetTu() << "/" << c.GetMau() << '\n';
	PhanSo h = a + 1;
	cout << "Cong: " << h.GetTu() << "/" << h.GetMau() << '\n';

	PhanSo d = a - b;
	cout << "Tru: " << d.GetTu() << "/" << d.GetMau() << '\n';

	PhanSo e = a * b;
	cout << "Nhan: " << e.GetTu() << "/" << e.GetMau() << '\n';

	PhanSo f = a / b;
	cout << "Chia" << f.GetTu() << "/" << f.GetMau() << '\n';

}