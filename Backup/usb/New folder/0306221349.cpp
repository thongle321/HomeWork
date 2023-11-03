#include <iostream>
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
NODE* tao_node(int x)
{
	NODE* p;
	p = new NODE;
	if (p == NULL)
	{
		cout << "khong the tao node";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
void in_danh_sach(LIST l) {
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
	if (p==NULL)
	{
		cout << "khong the tao node";
		return;
	}
	if (l.head == NULL)
	{
		l.head == p;
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
		cout << "khong the tao node";
		return;
	}
	if (l.head==NULL)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void main()
{
	LIST l;
	l.head = NULL;
	l.tail = NULL;
	int n;
	cout << "nhap so luong phan tu: ";
	cin >> n;
	int i = 0;
	while (i < n)
	{
		int tam;
		cout << " nhap phan tu thu " << i<<": ";
		cin >> tam;

		them_dau(l, tam);
		i++;
	}
	cout << "danh sach vua nhap: ";
	in_danh_sach(l);
	cout << endl;
}