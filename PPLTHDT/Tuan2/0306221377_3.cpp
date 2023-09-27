#include <iostream>
using namespace std;
template <class T>
T HoanVi(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
	return 0;
}
void main()
{
	int a, b;
	float c, d;
	a = 5;
	b = 6;
	c = 8.5;
	d = 9.2;
	HoanVi(a, b);
	cout << a << " " << b;
	cout << endl;
	HoanVi(c, d);
	cout << c << " " << d;

}