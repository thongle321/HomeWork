#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
struct list {
	node* head;
};

node* tao_node(int);
void them_dau_danh_sach(list&, int);
void in_danh_sach(list);
int tinh_tong(list);

node* tao_node(int x)
{
	node* p;
	p = new node;

	if (p==NULL)
	{
		cout << "Khong du bo nho";
		return NULL;
	}

	p->data = x;
	p->next = NULL;

	return p;
}
void  them_dau_danh_sach(list& l, int x)
{
	node* p = tao_node(x);
	if (p==NULL)
	{
		cout << "khong tao duoc node";
		return;
	}
	if (l.head == NULL)
	{
		l.head = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void in_danh_sach(list l)
{
	node* p = l.head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
int tinh_tong(list l)
{
	node* p = l.head;
	int tong = 0;
	while (p!=NULL)
	{
		tong += p->data;
		p = p->next;
	}
	return tong;
}
int dem_node(list l)
{
	int dem = 0;
	node* p = l.head;
	while (p != NULL)
	{
		p = p->next;
		dem++;
	}
	return dem;
}
void tim_x(list l, int x, int n)
{
	node* p = l.head;
	while (p!= NULL)
	{
		//if (p->data == x)
		//{
		//	cout << "co ";
		//	return;
		//}
		//else
		//{
		//	cout << "khong co ";
		//	return;
		//}
		//p = p->next;
		for (int i = 0; i < n; i++)
		{
			if (p->data == x) 
			{
				cout << "co";
			}
			else
			{
				cout << "khong";
			}
			p = p->next;
		}
	}
}
void main()
{
	list l;
	l.head = NULL;
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	int i = 0;
	int x;
	while(i < n)
	{
		int nhap;
		cout << "Phan tu thu " << i + 1 << ": ";
		cin >> nhap;

		them_dau_danh_sach(l, nhap);
		i++;
	}
	cout << "Danh sach vua nhap: ";
	in_danh_sach(l);
	cout << endl;
	cout << "Tong: " << tinh_tong(l) << endl;
	cout << "So node: " << dem_node(l) << endl;
	cout << "Nhap x: "; cin >> x;
	cout << "x co trong danh sach hay khong: "; 
	tim_x(l, x, n);
	system("pause");
}