#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
using namespace std;

int Tim_Kiem_1(int A[], int n, int x);
int Tim_Kiem_2(int A[], int n, int x);

void Doc_gia_tri(int A[], int n);
void Ghi_gia_tri(int A[], int n);

int TaoSoNgauNhien(int min, int max);
void Tao_file();

int dem(int []);

int main()
{
	int A[500];
	int mang[500];
	srand(time(0));
	Tao_file();
	int n= dem(mang);
	int x;
	Doc_gia_tri(A, n);
	cout << "Gia tri cua mang la: ";
	Ghi_gia_tri(A, n);
	do 
	{
		cout << "\nNhap gia tri can tim: ";
		cin >> x;
		cout<<"Vi tri can tim la: "<<Tim_Kiem_1(A, n, x) << "\n";
		cout<<"Vi tri can tim la: " << Tim_Kiem_2(A, n, x);
		cout<< "\nNhan Esc de thoat, nhan phim bat ki de tiep tuc";
	} while (_getch() != 27);
	return 0;
}
int Tim_Kiem_1(int A[], int n, int x)
{
	int i=0;
	while ((i<n)&&(A[i]!=x))
	{
		i++;
	}
	if (i == n) return -1;
	return i;
}
int Tim_Kiem_2(int A[], int n, int x)
{
	int i = 0;
	while (A[i] != x)
	{
		i++;
		if (i == n) return -1;
	}
	return i;
}

void Doc_gia_tri(int A[], int n)
{
	ifstream Doc_file;
	Doc_file.open("DATA2.txt");
	for (int i = 0; i < n; i++)
	{
		Doc_file >> A[i];
	}
	Doc_file.close();
}
void Ghi_gia_tri(int A[], int n)
{
	for (int  i = 0; i < n; i++)
	{
		cout << A[i];
		if (i+1 < n) cout << ", ";
	}
}

int TaoSoNgauNhien(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
void Tao_file()
{
	ofstream Taofile;
	Taofile.open("DATA2.txt");
	int n =TaoSoNgauNhien(100, 500);
	for (int i = 0; i < n; i++)
	{
		Taofile << TaoSoNgauNhien(1, 9999)<<" ";
	}
	Taofile.close();
}
int dem(int mang[])
{
	ifstream dem_PT;
	dem_PT.open("DATA2.txt");
	int i = 0;
	while (dem_PT.peek()!=EOF)
	{
		dem_PT >> mang[i];
		i++;
	}
	return --i;
}