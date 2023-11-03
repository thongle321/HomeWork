#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>

using namespace std;

struct SINHVIEN
{
	char mssv[10];
	float toan;
	float van;
};

void menu(int& m);
void nhap_sinh_vien();
void doc_ds_sinh_vien(SINHVIEN A[], int &n);
void in_ds_sinh_vien(SINHVIEN A[], int n);
void sx_mssv_tang(SINHVIEN[], int);
void sx_mssv_giam(SINHVIEN[], int);
void sx_diem_toan_tang(SINHVIEN[], int);
void sx_diem_toan_giam(SINHVIEN[], int);
void sx_diem_van_tang(SINHVIEN[], int);
void sx_diem_van_giam(SINHVIEN[], int);
void sx_diem_tb_tang(SINHVIEN[], int);
void sx_diem_tb_giam(SINHVIEN[], int);

void main()
{
	SINHVIEN A[100];
	int n;
	int m;
	do
	{
		menu(m);
		switch (m)
		{
		case 1: nhap_sinh_vien(); break;
		case 2: doc_ds_sinh_vien(A, n); break;
		case 3: {
			doc_ds_sinh_vien(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 4: {
			sx_mssv_tang(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 5: {
			sx_mssv_giam(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 6: {
			sx_diem_toan_tang(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 7: {
			sx_diem_toan_giam(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 8: {
			sx_diem_van_tang(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 9: {
			sx_diem_van_giam(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 10: {
			sx_diem_tb_tang(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		case 11: {
			sx_diem_tb_giam(A, n);
			in_ds_sinh_vien(A, n);
		}; break;
		}
		cout << "Nhap ESC de thoat, nhap phim bat ki de tiep tuc.";
	} while (_getch()!=27);
}

void nhap_sinh_vien()
{
	int n;
	SINHVIEN A[100];
	cout << "Nhap so luong sinh vien can nhap: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sinh vien:" << endl;
		cout << "Nhap ma so sinh vien: ";
		gets_s(A[i].mssv);
		cout << "Nhap diem toan: ";
		do {
		cin >> A[i].toan;
		} while (A[i].toan>10 || A[i].toan<0);

		cout << "Nhap diem van: ";
		do {
			cin >> A[i].van;
		} while (A[i].van > 10 || A[i].van < 0);

		cin.ignore();
	}

	ofstream ghi_file;
	ghi_file.open("SINHVIEN.txt", ios::app);
	for (int i = 0; i < n; i++)
	{
		ghi_file << A[i].mssv << endl;
		ghi_file << A[i].toan << " ";
		ghi_file << A[i].van << endl;
	}
	ghi_file.close();
}

void doc_ds_sinh_vien(SINHVIEN A[], int& n)
{
	n = 0;
	int i = 0;
	ifstream doc_file;
	doc_file.open("SINHVIEN.txt");
	while (doc_file.peek()!=EOF)
	{
		doc_file >> A[i].mssv;
		if (strlen(A[i].mssv)==0)
		{
			return;
		}
		doc_file >> A[i].toan;
		doc_file >> A[i].van;
		n++;
		i++;
	}
	doc_file.close();
}

void in_ds_sinh_vien(SINHVIEN A[], int n)
{
	cout <<" " << "\t" << "MSSV" << "\t" << "TOAN" << "\t" << "VAN"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout <<i+1<<"\t" << A[i].mssv << "\t" << A[i].toan << "\t" << A[i].van << endl;
	}
}

void sx_mssv_tang(SINHVIEN A[], int n)
{
	int min;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i+1; j < n; j++)
		{
			if (strcmp(A[i].mssv, A[j].mssv) > 0) min = j;
		}
		swap(A[i], A[min]);
	}
}

void sx_mssv_giam(SINHVIEN A[], int n)
{
	int max;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(A[i].mssv, A[j].mssv) < 0) max = j;
		}
		swap(A[i], A[max]);
	}
}

void sx_diem_toan_tang(SINHVIEN A[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i].toan>A[j].toan) min = j;
		}
		swap(A[i], A[min]);
	}
}

void sx_diem_toan_giam(SINHVIEN A[], int n) {
	int max;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i].toan < A[j].toan) max = j;
		}
		swap(A[i], A[max]);
	}
}

void sx_diem_van_tang(SINHVIEN A[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i].van > A[j].van) min = j;
		}
		swap(A[i], A[min]);
	}
}

void sx_diem_van_giam(SINHVIEN A[], int n) {
	int max;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[i].van < A[j].van) max = j;
		}
		swap(A[i], A[max]);
	}
}

void sx_diem_tb_tang(SINHVIEN A[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if ((A[i].van+A[i].toan)/2 > (A[j].van+A[j].toan)/2) min = j;
		}
		swap(A[i], A[min]);
	}
}
void sx_diem_tb_giam(SINHVIEN A[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if ((A[i].van + A[i].toan) / 2.0 < (A[j].van + A[j].toan) / 2.0) min = j;
		}
		swap(A[i], A[min]);
	}
}

void menu(int& m)
{
	cout << "MENU: " << endl;
	cout << "1. Nhap du lieu sinh vien." << endl;
	cout << "2. Doc danh sach sinh vien." << endl;
	cout << "3. In danh sach sinh vien." << endl;
	cout << "4. Sap xep mssv tang." << endl;
	cout << "5. Sap xep mssv giam." << endl;
	cout << "6. Sap xep toan tang." << endl;
	cout << "7. Sap xep toan giam." << endl;
	cout << "8. Sap xep van tang." << endl;
	cout << "9. Sap xep van giam." << endl;
	cout << "10. Sap xep trung binh tang." << endl;
	cout << "11. Sap xep trung binh giam." << endl;

	cout<< "nhap m: ";
	do {
		cin >> m;
	} while (m < 1 || m > 11);
}