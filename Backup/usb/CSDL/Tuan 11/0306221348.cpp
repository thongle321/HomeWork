#include <iostream>
#include <conio.h>

using namespace std;

struct node {
	int data;
	node* next;
};

struct list {
	node* head;
	node* tail;
};

node* GetNode(int x);
int menu();
void in_danh_sach(list&);
void them_dau(list&, int);
void them_cuoi(list&, int);
void them_vao_vi_tri(list&, int, int);
void dao_nguoc(list&);
void xoa_vi_tri(list&, int);
void xoa(list&, int);
void sap_xep_tang_dan(list&);
void sap_xep_tang_dan_noi_bot(list&);
void sap_xep_giam_dan(list&);
void sap_xep_giam_dan_noi_bot(list&);
void tach_danh_sach(list&);

void main() {
	//Khai báo list
	list l;
	l.head = NULL;
	l.tail = NULL;

	do {
		int choose = menu();
		switch (choose) {
		case 1:
			//In danh sách
			in_danh_sach(l);
			break;
		case 2:
			//Thêm phần tử vào đầu
			int x;
			cout << "Nhap gia tri can them: ";
			cin >> x;
			them_dau(l, x);
			break;
		case 3:
			//Thêm phần tử vào cuối
			cout << "Nhap gia tri can them: ";
			cin >> x;
			them_cuoi(l, x);
			break;
		case 4:
			//Thêm phần tử vào vị trí
			int k;
			cout << "Nhap gia tri phan tu can them vao danh sach: ";
			cin >> x;
			cout << "Nhap vi tri can chen: ";
			cin >> k;
			them_vao_vi_tri(l, x, k);
			break;
		case 5:
			//Đảo ngược danh sách
			dao_nguoc(l);
			break;
		case 6:
			//Xóa phần tử tại vị trí
			cout << "Nhap vi tri can xoa: ";
			cin >> k;
			xoa_vi_tri(l, k);
			break;
		case 7:
			//Xóa phần tử có giá trị
			cout << "Nhap gia tri phan tu can xoa: ";
			cin >> x;
			xoa(l, x);
			break;
		case 8:
			//Sắp xếp danh sách tăng dần
			sap_xep_tang_dan(l);
			break;
		case 9:
			//Sắp xếp danh sách giảm dần
			sap_xep_giam_dan(l);
			break;
		case 10:
			//Tách danh sách
			tach_danh_sach(l);
			break;
		case 11:
			exit(0);
			break;
		}
		//system("cls");
		cout << "Nhan ESC de thoat hoac nhan phim bat ki de tiep tuc" << endl;


	} while (_getch() != 27);

	cout << endl;
	system("pause");
}

int menu() {
	cout << "-----Bai thuc hanh so 7: DSLK (tt)-----" << endl;
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
	int choose;
	do {
		cout << "Chon mot chuc nang : ";
		cin >> choose;
	} while (choose < 1 || choose > 11);
	return choose;
}

node* GetNode(int x) {
	node* p = new node;
	if (p == NULL) {
		cout << "Khong the tao node!" << endl;
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}

void in_danh_sach(list& l) {
	node* p = l.head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void them_dau(list& l, int x) {
	node* p;
	p = GetNode(x);

	if (p == NULL) {
		cout << "Khong the tao node";
		exit(1);
	}

	//Thêm node p vào đầu danh sách l
	//Danh sách rỗng
	if (l.head == NULL) {
		l.head = p;
	}
	else /*Danh sách rỗng*/ {
		p->next = l.head;
		l.head = p;
	}
}

void them_cuoi(list& l, int x) {
	node* p = GetNode(x);

	if (p == NULL) {
		cout << "Khong the tao node";
		exit(1);
	}

	if (l.head == NULL) {
		// Danh sách rỗng, node mới được thêm sẽ là node đầu tiên của danh sách
		l.head = p;
		l.tail = p;
	}
	else {
		// Danh sách không rỗng, node mới sẽ là node sau của node cuối cùng hiện tại
		l.tail->next = p;
		l.tail = p;
	}
}

void them_vao_vi_tri(list& l, int k, int x) {
	if (k < 1) {
		cout << "Vi tri them khong hop le!" << endl;
		return;
	}

	node* p = GetNode(x);
	if (p == NULL) {
		cout << "Khong the tao node";
		exit(1);
	}

	if (k == 1) {
		// Thêm vào đầu danh sách
		p->next = l.head;
		l.head = p;
		if (l.tail == NULL) {
			l.tail = p;
		}
		return;
	}

	node* prev = l.head;
	for (int i = 1; i < k - 1; i++) {
		if (prev == NULL) {
			cout << "Khong tim thay vi tri can them" << endl;
			return;
		}
		prev = prev->next;
	}

	p->next = prev->next;
	prev->next = p;
	if (p->next == NULL) {
		l.tail = p;
	}
}

void dao_nguoc(list& l) {
	node* p = l.head;
	node* q = NULL;
	node* r = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = q;
		q = p;
		p = r;
	}
	l.head = q;
}


void xoa_vi_tri(list& l, int x, int k) {
	if (k < 1) {
		cout << "Vi tri xoa khong hop le!" << endl;
		return;
	}
	if (l.head == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	node* prev = NULL;
	node* current = l.head;
	int count = 1;
	while (current != NULL && count != k) {
		prev = current;
		current = current->next;
		count++;
	}
	if (current == NULL) {
		cout << "Khong tim thay vi tri can xoa" << endl;
		return;
	}
	if (prev == NULL) {
		// Xoa phan tu dau danh sach
		l.head = current->next;
		if (current->next == NULL) {
			l.tail = NULL;
		}
		delete current;
	}
	else {
		prev->next = current->next;
		if (current->next == NULL) {
			l.tail = prev;
		}
		delete current;
	}

	system("cls");
}

void xoa(list& l, int x) {
	if (l.head == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	node* prev = NULL;
	node* current = l.head;
	while (current != NULL && current->data != x) {
		prev = current;
		current = current->next;
	}
	if (current == NULL) {
		cout << "Khong tim thay phan tu can xoa" << endl;
		return;
	}
	if (prev == NULL) {
		// Xoa phan tu dau danh sach
		l.head = current->next;
		if (current->next == NULL) {
			l.tail = NULL;
		}
		delete current;
	}
	else {
		prev->next = current->next;
		if (current->next == NULL) {
			l.tail = prev;
		}
		delete current;
	}

	system("cls");
}

void sap_xep_tang_dan_doi_cho(list& l) {
	if (l.head == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	bool swapped;
	node* ptr;
	node* last = NULL;
	do {
		swapped = false;
		ptr = l.head;
		while (ptr->next != last) {
			if (ptr->data > ptr->next->data) {
				swap(ptr->data, ptr->next->data);
				swapped = true;
			}
			ptr = ptr->next;
		}
		last = ptr;
	} while (swapped);

}

void sap_xep_tang_dan_noi_bot(list& l) {
	if (l.head == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	node* end = NULL;
	while (end != l.head->next) {
		node* current = l.head;
		while (current->next != end) {
			if (current->data > current->next->data) {
				swap(current->data, current->next->data);
			}
			current = current->next;
		}
		end = current;
	}

}

void sap_xep_giam_dan_doi_cho(list& l) {
	if (l.head == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	bool swapped;
	node* ptr;
	node* last = NULL;
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

	system("cls");
}

void sap_xep_giam_dan_noi_bot(list& l) {
	if (l.head == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	node* end = NULL;
	while (end != l.head->next) {
		node* current = l.head;
		while (current->next != end) {
			if (current->data < current->next->data) {
				swap(current->data, current->next->data);
			}
			current = current->next;
		}
		end = current;
	}

	system("cls");
}

void tach_danh_sach(list& l) {
	if (l.head == NULL) {
		cout << "Danh sach rong!" << endl;
		return;
	}
	list evenList; // Danh sach chua cac so chan
	list oddList; // Danh sach chua cac so le
	evenList.head = NULL;
	evenList.tail = NULL;
	oddList.head = NULL;
	oddList.tail = NULL;
	node* current = l.head;
	while (current != NULL) {
		if (current->data % 2 == 0) {
			// Phan tu la so chan
			if (evenList.head == NULL) {
				evenList.head = current;
				evenList.tail = current;
			}
			else {
				evenList.tail->next = current;
				evenList.tail = current;
			}
		}
		else {
			// Phan tu la so le
			if (oddList.head == NULL) {
				oddList.head = current;
				oddList.tail = current;
			}
			else {
				oddList.tail->next = current;
				oddList.tail = current;
			}
		}
		current = current->next;
	}

	// Kiem tra danh sach chua cac so chan
	cout << "Danh sach chua cac so chan: ";
	node* p = evenList.head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	// Kiem tra danh sach chua cac so le
	cout << "Danh sach chua cac so le: ";
	p = oddList.head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	system("cls");
}