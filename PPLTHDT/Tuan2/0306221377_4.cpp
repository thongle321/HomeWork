#include <iostream>
using namespace std;
template <class T>
T max(T a, T b, T c)
{
	T kq;
	if (a >= b && a >= c)
		kq = a;
	else if (b >= a && b >= c)
		kq = b;
	else if (c >= a && c >= b)
		kq = c;
	return kq;
}
void main()
{
	int a, b, c;
	char d, e, g;
	float h, j, k;
	a = 5;
	b = 6;
	c = 7;
	d = 'a';
	e = 'b';
	g = 'c';
	h = 5.6;
	j = 10.2;
	k = 13.4;
	cout << max(a, b, c);
	cout << endl;
	cout << max(d, e, g);
	cout << endl;
	cout << max(h, j, k);
}