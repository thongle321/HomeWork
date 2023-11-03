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
int menu();
void in_danh_sach(LIST l);
void them_dau(LIST& l, int x);
void them_cuoi(LIST& l, int x);
void them_vao_vi_tri(LIST& l, int k, int x);
void dao_nguoc(LIST& l);
void xoa_vi_tri(LIST& l, int k);
void xoa(LIST& l, int x);
void sx_tang_dan_doi_cho(LIST& l);
void sx_tang_dan_noi_bot(LIST& l);
void sx_giam_dan_doi_cho(LIST& l);
void sx_giam_dan_noi_bot(LIST& l);

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
void them_vao_vi_tri(LIST& l, int k, int x) {
	if (k < 1) {
		cout << "Sai vi tri them" << endl;
		return;
	}

	NODE* p = tao_node(x);
	if (p == NULL) {
		cout << "Khong the tao node";
		return;
	}

	if (k == 1) {
		p->next = l.head;
		l.head = p;
		if (l.tail == NULL) {
			l.tail = p;
		}
		return;
	}

	NODE* pre = l.head;
	for (int i = 1; i < k - 1; i++) {
		if (pre == NULL) {
			return;
		}
		pre = pre->next;
	}

	p->next = pre->next;
	pre->next = p;
	if (p->next == NULL) {
		l.tail = p;
	}
}
void dao_nguoc(LIST& l) {
	NODE* p = l.head;
	NODE* q = NULL;
	NODE* r = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = q;
		q = p;
		p = r;
	}
	l.head = q;
}
void xoa_vi_tri(LIST& l, int k) {
	if (k < 1) {
		return;
	}
	if (l.head == NULL) {
		return;
	}
	NODE* pre = NULL;
	NODE* current = l.head;
	int count = 1;
	while (current != NULL && count != k) {
		pre = current;
		current = current->next;
		count++;
	}
	if (current == NULL) {
		return;
	}
	if (pre == NULL) {
		// Xoa phan tu dau danh sach
		l.head = current->next;
		if (current->next == NULL) {
			l.tail = NULL;
		}
		delete current;
	}
	else {
		pre->next = current->next;
		if (current->next == NULL) {
			l.tail = pre;
		}
		delete current;
	}

}
void xoa(LIST& l, int x) {
	if (l.head == NULL) {
		return;
	}
	NODE* pre = NULL;
	NODE* current = l.head;
	while (current != NULL && current->data != x) {
		pre = current;
		current = current->next;
	}
	if (current == NULL) {
		return;
	}
	if (pre == NULL) {
		// Xoa phan tu dau danh sach
		l.head = current->next;
		if (current->next == NULL) {
			l.tail = NULL;
		}
		delete current;
	}
	else {
		pre->next = current->next;
		if (current->next == NULL) {
			l.tail = pre;
		}
		delete current;
	}

}
void sx_tang_dan_doi_cho(LIST &l) {
	if (l.head == NULL) {
		return;
	}
	bool swapped;
	NODE* pre;
	NODE* last = NULL;
	do {
		swapped = false;
		pre = l.head;
		while (pre->next != last) {
			if (pre->data > pre->next->data) {
				swap(pre->data, pre->next->data);
				swapped = true;
			}
			pre = pre->next;
		}
		last = pre;
	} while (swapped);

}
void sx_tang_dan_noi_bot(LIST & l) {
	if (l.head == NULL) {
		return;
	}
	NODE* end = NULL;
	while (end != l.head->next) {
		NODE* current = l.head;
		while (current->next != end) {
			if (current->data > current->next->data) {
				swap(current->data, current->next->data);
			}
			current = current->next;
		}
		end = current;
	}

}
void sx_giam_dan_doi_cho(LIST& l) {
	if (l.head == NULL) {
		return;
	}
	bool swapped;
	NODE* ptr;
	NODE* last = NULL;
	do {
		swapped = false;
		ptr = l.head;
		while (ptr->next != last) {
			if (ptr->data < ptr->next->data) {
				swap(ptr->data, ptr->next->data);
				swapped = true;
			}
			ptr = ptr->next;
		}
		last = ptr;
	} while (swapped);
}

void sx_giam_dan_noi_bot(LIST& l) {
	if (l.head == NULL) {
		return;
	}
	NODE* end = NULL;
	while (end != l.head->next) {
		NODE* current = l.head;
		while (current->next != end) {
			if (current->data < current->next->data) {
				swap(current->data, current->next->data);
			}
			current = current->next;
		}
		end = current;
	}
}
void main()
{
	LIST l;
	l.head = NULL;
	l.tail = NULL;
	int n, x, k;
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
	cout << "Danh sach vua nhap: ";
	in_danh_sach(l);
	cout << endl;
	do
	{
		int chon = menu();
		switch (chon)
		{
		case 1:
		{
			cout << "danh sach vua nhap: ";
			in_danh_sach(l);
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "them dau: ";
			cin >> x;
			them_dau(l, x);
			cout << "sau khi them: " << endl;
			in_danh_sach(l);
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "them cuoi: ";
			cin >> x;
			them_cuoi(l, x);
			cout << "sau khi them: " << endl;
			in_danh_sach(l);
			cout << endl;
			break;
		}
		case 4:
		{
			int k;
			cout << "Nhap gia tri phan tu can them vao danh sach: ";
			cin >> x;
			cout << "Nhap vi tri can chen: ";
			cin >> k;
			them_vao_vi_tri(l, x, k);
			in_danh_sach(l);
			cout << endl;
			break;
		}
		case 5:
		{
			dao_nguoc(l);
			in_danh_sach(l);
			cout << endl;
			break;
		}
		case 6:
		{
			cout << "Nhap vi tri can xoa: ";
			cin >> k;
			xoa_vi_tri(l, k);
			in_danh_sach(l);
			cout << endl;
			break;
		}
		case 7:
		{
			cout << "Nhap gia tri phan tu can xoa: ";
			cin >> x;
			xoa(l, x);
			in_danh_sach(l);
			cout << endl;
			break;
		}
		case 8:
		{
			int sx;
			cout << "1. Sap xep tang dan doi cho" << endl;
			cout << "2. Sap xep tang dan noi bot" << endl;
			cout << "chon sap xep: ";cin >> sx;
			switch (sx)
			{
			case 1:
			{
				sx_tang_dan_doi_cho(l);
				cout << "Danh sach vua chon: "; in_danh_sach(l);
				break;
			}
			case 2:
			{
				sx_tang_dan_noi_bot(l);
				cout << "Danh sach vua chon: "; in_danh_sach(l);
				break;
			}
			default:
				break;
			}
		}
		case 9:
		{
			int sx;
			cout << "1. Sap xep giam dan doi cho" << endl;
			cout << "2. Sap xep giam dan noi bot" << endl;
			cout << "chon sap xep: "; cin >> sx;
			switch (sx)
			{
			case 1:
			{
				sx_giam_dan_doi_cho(l);
				cout << "Danh sach vua chon: "; in_danh_sach(l);
				break;
			}
			case 2:
			{
				sx_giam_dan_noi_bot(l);
				cout << "Danh sach vua chon: "; in_danh_sach(l);
				break;
			}
			default:
				break;
			}
		}
		case 10:
		{
		}
		case 11:
		{
			break;
		}
		}
	} while (_getch() != 27);
}
int menu()
{
	cout << endl;
	cout << "MENU" << endl;
	cout << "1. In danh sach " << endl;
	cout << "2. Them phan tu vao dau " << endl;
	cout << "3. Them phan tu vao cuoi " << endl;
	cout << "4. Them phan tu vao vi tri " << endl;
	cout << "5. Dao nguoc danh sach " << endl;
	cout << "6. Xoa phan tu tai vi tri " << endl;
	cout << "7. Xoa phan tu co gia tri " << endl;
	cout << "8. Sap xep danh sach tang dan " << endl;
	cout << "9. Sap xep danh sach giam dan " << endl;
	cout << "10. Tach danh sach " << endl;
	cout << "11. Thoat chuong trinh " << endl;
	int chon;
	do {
		cout << "Chon mot chuc nang : ";
		cin >> chon;
	} while (chon < 1 || chon > 11);
	return chon;
}