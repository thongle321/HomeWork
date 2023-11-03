#include<iostream>
#include<cstring>

using namespace std;

struct SINHVIEN {
	char mssv[10];
	float toan;
	float van;
};

	void nhap_sinh_vien();
	int doc_du_lieu(SINHVIEN[]);
	void in_sinh_vien(SINHVIEN);
	void sx_mssv_tang(SINHVIEN[], int);
	/*void sx_mssv_giam(SINHVIEN[], int);
	void sx_diem_toan_tang(SINHVIEN[], int);
	void sx_diem_toan_giam(SINHVIEN[], int);
	void sx_diem_van_tang(SINHVIEN[], int);
	void sx_diem_van_giam(SINHVIEN[], int);
	void sx_diem_tb_tang(SINHVIEN[], int);
	void sx_diem_tb_giam(SINHVIEN[], int);*/

void main()
{
	// DEMO SO SANH CHUỖI
	char s1[10], s2[10];
	cout << "Nhap chuoi 1: ";
	gets_s(s1);

	cout << "Nhap chuoi 2: ";
	gets_s(s2);

	int kq = strcmp(s1, s2);
	cout << kq << endl;

	/*
	// DEMO NHẬP DSSV
	for (int i = 0; i < 3; i++)
	{
		nhap_sinh_vien();
	}

	// Đọc tập tin => in danh sách sinh viên
	SINHVIEN dssv[100];
	int sl_sv = doc_du_lieu(dssv);
	for (int i = 0; i < sl_sv; i++)
	{
		in_sinh_vien(dssv[i]);
	}*/

	system("pause");
}

void nhap_sinh_vien()
{
	SINHVIEN sv;
	cout << "Nhap thong tin sinh vien:\n";
	cout << "- MSSV: ";

	gets_s(sv.mssv);
	cout << "- Diem toan: ";
	cin >> sv.toan;
	cout << "- Diem van: ";
	cin >> sv.van;

	cin.ignore();

	// Ghi dữ liệu sinh viên vào tập tin SINHVIEN.TXT
	// ...
}

void in_sinh_vien(SINHVIEN sv)
{
	cout << sv.mssv << "\t\t" << sv.toan << "\t" << sv.van << endl;
}

// Đọc dữ liệu sinh viên từ tập tin SINHVIEN.TXT
// Output: số lượng sinh viên trong tập tin
int doc_du_lieu(SINHVIEN sv[100])
{
	int sl_sv = 0;
	// Mở tập tin để đọc
	FILE* f = fopen("SINHVIEN.TXT", "r");

	// Kiểm tra nếu không mở được tập tin
	if (!f) {
		cout << "Khong mo duoc file" << endl;
		return 0;


		// Sắp xếp sinh viên theo MSSV tăng dần
		void sx_mssv_tang(SINHVIEN sv[100], int n);
		{
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (strcmp(sv[i].mssv, sv[j].mssv) > 0) {
						swap(sv[i], sv[j]);
					}
				}
			}
		}

		// Sắp xếp sinh viên theo MSSV giảm dần
		void sx_mssv_giam(SINHVIEN sv[100], int n)
		{
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (strcmp(sv[i].mssv, sv[j].mssv) < 0) {
						swap(sv[i], sv[j]);
					}
				}
			}
		}

		// Sắp xếp sinh viên theo điểm toán tăng dần
		void sx_diem_toan_tang(SINHVIEN sv[100], int n)
		{
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (sv[i].toan > sv[j].toan) {
						swap(sv[i], sv[j]);
					}
				}
			}
		}

		// Sắp xếp sinh viên theo điểm toán giảm dần
		void sx_diem_toan_giam(SINHVIEN sv[100], int n)
		{
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (sv[i].toan < sv[j].toan) {
						swap(sv[i], sv[j]);
					}
				}
			}
		}

		// Sắp xếp sinh viên theo điểm văn tăng dần
		void sx_diem_van_tang(SINHVIEN sv[100], int n)
		{
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (sv[i].van > sv[j].van) {
						swap(sv[i], sv[j]);
					}
				}
			}
		}

		// Sắp xếp sinh viên theo điểm văn giảm dần
		void sx_diem_van_giam(SINHVIEN sv[100], int n)
		{
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (sv[i].van < sv[j].van) {
						swap(sv[i], sv[j]);
					}
				}
			}
		}

		// Sắp xếp sinh viên theo điểm trung bình tăng dần
		void sx_diem_tb_tang(SINHVIEN sv[100], int n)
		{
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < n - i - 1; j++)
				{
					float diem_tb_j = (sv[j].toan + sv[j].van) / 2.0;
					float diem_tb_j1 = (sv[j + 1].toan + sv[j + 1].van) / 2.0;
				}
				if (diem_tb_j > diem_tb_j1) {
					SINHVIEN temp = sv[j];
					sv[j] = sv[j + 1];
					sv[j + 1] = temp;
				}
			}
		}

		// Sắp xếp sinh viên theo điểm trung bình giảm dần
		void sx_diem_tb_giam(SINHVIEN sv[100], int n)
		{
			for (int i = 0; i < n - 1; i++)
			{
				for (j = 0; j < n - i - 1; j++)
				{
					float diem_tb_j = (sv[j].toan + sv[i].van) / 2.0;
					float diem_tb_j1 = (sv[j + 1].toan + sv[j + 1].van) / 2.0;
				}
				if (diem_tb_j < diem_tb_j1) {
					SINHVIEN temp = sv[j];
					sv[j] = sv[j + 1];
					sv[j + 1] = temp;
				}
			}
		}
	}