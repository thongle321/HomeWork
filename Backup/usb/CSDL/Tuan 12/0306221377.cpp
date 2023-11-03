//mssv 0306221377
#include <iostream>
#include<iostream>
using namespace std;

struct NODE {
	int data;
	NODE* next;
};

struct STACK {
	NODE* head;
};

NODE* tao_node(int);
int push(STACK&, int);
int top(STACK);
int pop(STACK&);
int size(STACK);
void empty(STACK&);
void print(STACK);

NODE* tao_node(int x)
{
	NODE* p;
	p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}

	p->data = x;
	p->next = NULL;
	return p;
}

int push(STACK& s, int x)
{
	NODE* p;
	p = tao_node(x);
	if (p == NULL)
	{
		cout << " Khong tao duoc nut !";
		return 0;
	}

	if (s.head == NULL)
	{
		s.head = p;
	}
	else
	{
		p->next = s.head;
		s.head = p;
	}
	return 1;
}

int top(STACK s)
{
	NODE* p = s.head;
	if (p != NULL)
	{
		return p->data;
	}
	return -1; // STACK chứa toàn số nguyên dương
}

int pop(STACK& s)
{
	NODE* p;
	int temp = -1; // STACK chứa toàn số nguyên dương
	if (s.head != NULL)
	{
		p = s.head;
		s.head = s.head->next;
		temp = p->data;
		delete p;
	}
	return temp;
}

int size(STACK s)
{
	NODE* p;
	p = s.head;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

void empty(STACK& s)
{
	NODE* p;
	while (s.head != NULL)
	{
		p = s.head;
		s.head = p->next;
		delete p;
	}
}

void print(STACK s)
{
	NODE* p;
	p = s.head;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

void main()
{
	STACK s;
	s.head = NULL;

	while (1)
	{
		int chon;
		do
		{
			cout << "MENU\n";
			cout << "1. PUSH\n";
			cout << "2. TOP\n";
			cout << "3. POP\n";
			cout << "4. SIZE\n";
			cout << "5. EMPTY\n";
			cout << "6. CONVERT TO BINARY NUMBER\n";
			cout << "7. EXIT";
			cout << "SELECT: ";
			cin >> chon;

		} while (chon < 1 || chon > 7);

		if (chon == 7)
		{
			break;
		}

		int t;
		switch (chon)
		{
		case 1:
			cout << "Nhap gia tri: ";
			cin >> t;
			push(s, t);

			break;
		case 2:
			t = top(s);
			cout << "top = " << t << endl;
			break;
		case 3:
			t = pop(s);
			cout << "item = " << t << endl;
			break;
		case 4:
			cout << "size = " << size(s) << endl;
			break;
		case 5:
			empty(s);
			break;
		case 6:
			int sobichia;
			cout << "Nhap so nguyen: ";
			cin >> sobichia;
			int sodu;
			do
			{
				sodu = sobichia % 2;
				sobichia = sobichia / 2;
				push(s, sodu);
			} while (sobichia != 0);
			break;
		}
		cout << "STACK: ";
		print(s);
	}
}
