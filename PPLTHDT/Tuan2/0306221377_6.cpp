#include <iostream>
using namespace std;
template <class T>
T nhap(T a[], T& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	return 0;
}
template <class T>
T xuat(T a[], T n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
template <class T>
T tong(T a[], T n)
{
	T tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong += a[i];
	}
	return tong;
}
template <class T>
T max(T a[], T n)
{
	T max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}
template <class T>
T count(T a[], T n)
{
	T count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			count++;
		}
	}
	return count;
}
template <class T>
T tangdan(T a[], T n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
	return 0;
}
void main()
{
	int a[100];
	int n;
	nhap(a, n);
	xuat(a, n);
	cout << "\n";
	cout << tong(a, n);
	cout << "\n";
	cout << max(a, n);
	cout << "\n";
	cout << "Co " << count(a, n) << " phan tu duong";
	cout << "\n";
	tangdan(a, n);
	cout << xuat(a, n);
}