#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
void main()
{
	float a, b, c, delta, x1, x2;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		cout << "vo nghiem";
	}
	if (delta == 0)
	{
		x1 = -b / 2 * a;
		cout << "co nghiem";
	}
	if (delta > 0)
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "co 2 nghiem" << '\n';
		cout << "x1 = " << x1 << '\n';
		cout << "x2 = " << x2;
	}
	return;
}