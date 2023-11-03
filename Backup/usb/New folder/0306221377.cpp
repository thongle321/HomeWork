#include <iostream>
#include <conio.h>
using namespace std;
struct NODE
{
	int data;
	NODE* next;
};
struct LIST
{
	NODE* head;
	NODE* tail;
};
void in_danh_sach(LIST l);
void them_dau(LIST& l, int x);
void them_cuoi(LIST& l, int x);
NODE* tao_node(int x)
{
	NODE* p;
	p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
}
void in_danh_sach(LIST l)
{
	NODE* p = l.head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void them_dau(LIST& l, int x)
{
	NODE* p = tao_node(x);
	if (p == NULL)
	{
		return;
	}
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = l.head;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void them_cuoi(LIST& l, int x)
{
	NODE* p = tao_node(x);
	if (p == NULL)
	{
		return;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

//int menu()
//{
//	cout << "\nMenu" << endl;
//	cout << "1. In danh sach" << endl;
//	cout << "2. Them phan tu vao dau" << endl;
//	cout << "3. Them phan tu vao cuoi" << endl;
//	cout << "4. Them phan tu vao vi tri" << endl;
//	cout << "5. Dao nguoc danh sach" << endl;
//	cout << "6. Xoa phan tu tai vi tri" << endl;
//	cout << "7. Xoa phan tu co gia tri" << endl;
//	cout << "8. Sap xep danh sach tang dan" << endl;
//	cout << "9. Sap xep danh sach giam dan" << endl;
//	cout << "10. Tach danh sach" << endl;
//	cout << "11. Thoat chuong trinh" << endl;
//	int chon;
//	do
//	{
//		cout << "chon mot chuc nang: ";
//		cin >> chon;
//	} while (chon < 1 || chon > 11);
//	return chon;
//}
//void chuc_nang1()
//{
//
//}
//void chuc_nang2()
//{
//
//}
void main()
{
	LIST l;
	l.head = NULL;
	l.tail = NULL;
	int n, x;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	int i = 0;
	while (i < n)
	{
		int temp;
		cout << "Nhap phan tu thu: " << i << ": ";
		cin >> temp;
		i++;
		them_dau(l, temp);
	}

	cout << endl;
	cout << "1. In danh sach" << endl;
	cout << "2. Them phan tu vao dau" << endl;
	cout << "3. Them phan tu vao cuoi" << endl;
	cout << "4. Them phan tu vao vi tri" << endl;
	cout << "5. Dao nguoc danh sach" << endl;
	cout << "6. Xoa phan tu tai vi tri" << endl;
	cout << "7. Xoa phan tu co gia tri" << endl;
	cout << "8. Sap xep danh sach tang dan" << endl;
	cout << "9. Sap xep danh sach giam dan" << endl;
	cout << "10. Tach danh sach" << endl;
	cout << "11. Thoat chuong trinh" << endl;
	int chon;
	do
	{
		cout << "chon mot chuc nang: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			cout << "danh sach vua nhap: ";
			in_danh_sach(l);
			break;
		}
		case 2:
		{
			cout << "them dau: ";
			cin >> x;
			them_dau(l, x);
			cout << "sau khi them: " << endl;
			in_danh_sach(l);
			break;
		}
		case 3:
		{
			cout << "them cuoi: ";
			cin >> x;
			them_cuoi(l, x);
			cout << "sau khi them: " << endl;
			in_danh_sach(l);
			break;
		}
		case 11:
		{
			break;
		}
		}
	} while (chon < 1 || chon > 11);


	//do
	//{
	//	int chon = menu();
	//	switch (chon)
	//	{
	//	case 1:
	//		{
	//			chuc_nang1();
	//			break;
	//		}
	//	case 2:
	//	{

	//	}
	//	default:
	//		break;
	//	}

	//} while (_getch()!= 27);
}