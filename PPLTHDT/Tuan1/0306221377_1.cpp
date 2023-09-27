#include <iostream>
#include <conio.h>
#include <stdio.h>
using std::cout;
using std::cin;
void main()
{
	int a, b, c;
	int min;
	cin >> a >> b >> c;
	min = a;
	if (min > b)
	{
		min = b;
		cout << b;
	}
	else if (min > c)
	{
		min = c;
		cout << c;
	}
	else if (min = a)
	{
		cout << a;
	}
	///*if (a < b && a < c)
	//{
	//	min = a;
	//	cout << a;
	//}*/
	//else if (b < a && b < c)
	//{
	//	min = b;
	//	cout << b;
	//}
	//else if (c < a && c < b)
	//{
	//	min = c;
	//	cout << c;
	//}

}