#include <iostream>
using std::cin;
using std::cout;
void nhap_mang(int a[], int &n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}
void xuat_mang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
bool SNT(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
		return true;
	}
	return true;
}
void MangSNT(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (SNT(a[i]) == true)
			cout << i << " ";
	}
}
int main()
{
	int a[100];
	int n;
	nhap_mang(a, n);
	MangSNT(a, n);
	return 0;
}