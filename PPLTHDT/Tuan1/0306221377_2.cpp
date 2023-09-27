#include <iostream>
#include <conio.h>
#include <stdio.h>
using std::cout;
using std::cin;
void main()
{
	int n, a, b, c, d, min, min2;
	cin >> n;
	a = n % 10;
	n /= 10;
	b = n % 10;
	n /= 10;
	c = n % 10;
	d = n / 10;
	min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	if (min > d) min = d;
	min2 = a;
	if (min2 > b && b > min) min2 = b;
	if (min2 > c && c > min) min2 = c;
	if (min2 > d && d > min) min2 = d;
	if (min2 > min) cout << min2;
	else cout << "bang nhau";
}