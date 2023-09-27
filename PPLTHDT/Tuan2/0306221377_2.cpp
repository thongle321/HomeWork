#include <iostream>
using namespace std;
void HoanVi(int& a, int& b);
void HoanVi(long& a, long& b);
void HoanVi(float& a, float& b);
void HoanVi(double& a, double& b);
void HoanVi(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "1: ";
}
void HoanVi(long& a, long& b)
{
	long temp;
	temp = a;
	a = b;
	b = temp;
	cout << "2: ";
}
void HoanVi(float& a, float& b)
{
	float temp;
	temp = a;
	a = b;
	b = temp;
	cout << "3: ";
}
void HoanVi(double& a, double& b)
{
	double temp;
	temp = a;
	a = b;
	b = temp;
	cout << "4: ";
}
void main()
{
	double a, b;
	cin >> a >> b;
	HoanVi(a, b);
	cout << a << " " << b;
}