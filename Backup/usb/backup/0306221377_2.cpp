#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
using namespace std;
int doc_file(int a[])
{
	fstream infile;
	infile.open("data.txt");
	int i = 0;
	if (!infile)
	{
		cout << "khong doc duoc file";
	}
	else
	{
		while (infile.peek() != EOF)
		{
			infile >> a[i];
			i++;
		}
	}
	infile.close();
	return i;
}void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a" << "[" << i << "]" << " = ";
		cin >> a[i];
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void songaunhien(int a[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}
}
void interchangesort(int a[], int n)
{
	for (int i = 0; i <= n - 2; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
				xuatmang(a, n); cout << endl;
			}
		}
	}
}
void Selectionsort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
		xuatmang(a, n);
		cout << endl;
	}
}
int menu()
{
	cout << "\nMenu" << endl;
	cout << "1. Xuat mang so nguyen" << endl;
	cout << "2. doc file xuat mang" << endl;
	cout << "3. Xuat mang so ngau nhien" << endl;
	cout << "4. Xuat mang interchangesort ngau nhien" << endl;
	cout << "5. Xuat mang selectionsort tu file" << endl;
	int chon;
	do
	{
		cout << "chon mot chuc nang: ";
		cin >> chon;
	} while (chon < 1 || chon > 5);
	return chon;
}
void chuc_nang1()
{
	cout << "ban da chon chuc nang 1" << endl;
	int a[100];
	int n;
	cout << "Nhap n: "; 
	cin >> n;
	nhapmang(a, n);
	xuatmang(a, n);
}void chuc_nang2()
{
	cout << "ban da chon chuc nang 2" << endl;
	int a[100];
	int n;
	n = doc_file(a);
	xuatmang(a, n);
	cout << endl;
}void chuc_nang3()
{
	cout << "ban da chon chuc nang 3" << endl;
	int a[100];
	int n;
	cin >> n;
	songaunhien(a, n);
	xuatmang(a, n);
	cout << endl;
}
void chuc_nang4()
{
	cout << "ban da chon chuc nang 4" << endl;
	int a[100];
	int n;
	cin >> n;
	songaunhien(a, n);
	cout << "mang vua nhap la: ";
	xuatmang(a, n);
	cout << endl;
	cout << "Interchangesort: " << endl;
	interchangesort(a, n);
	cout << endl;
}
void chuc_nang5()
{
	int a[100];
	int n;
	n = doc_file(a);
	cout << "mang vua nhap la: ";
	xuatmang(a, n);
	cout << endl;
	cout << "Selectionsort: " << endl;
	Selectionsort(a, n);
}
void main()
{
	do
	{
		int chon = menu();
		switch (chon)
		{
		case 1:
			chuc_nang1();
			break;
		case 2:
			chuc_nang2();
			break;
		case 3:
			chuc_nang3();
			break;
		case 4:
			chuc_nang4();
			break;
		case 5:
			chuc_nang5();
			break;
		}
		cout << "Nhan ESC de thoat chuong trinh";
	} while (_getch() != 27);
}