#include <iostream>
#include <fstream>
using namespace std;
int doc_file(int a[])
{
	fstream infile;
	infile.open("data.txt");
	int i = 0;
	if (!infile)
		cout << "Khong doc duoc file";
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
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void Interchangesort(int a[], int n)
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
void main()
{
	int a[100]; 
	int n;
	n = doc_file(a);
	cout << "mang vua nhap la: ";
	xuatmang(a, n);
	cout << endl;
	cout << "Interchangesort: " << endl;
	Interchangesort(a, n);
	cout << endl;
	doc_file(a);
	cout << "Selectionsort: " << endl;
	Selectionsort(a, n);
}