#include"Chain.h"

void menu()
{
	MyList list;
	while (true) {
		cout << "___________________ " << endl;
		cout << "|1.��ʼ��         | " << endl;
		cout << "|2.����           | " << endl;
		cout << "|3.���� | " << endl;
		cout << "|4.| " << endl;
		cout << "|5.| " << endl;
		cout << "|6.| " << endl;
		cout << "|7.| " << endl;
		cout << "|8.| " << endl;
		cout << "|9.| " << endl;
		cout << "|10.| " << endl;
		cout << "|11.| " << endl;
		cout << "|_________________| " << endl;
		int i;
		cin >> i;
		switch (i) {
		case 1:
			initial(list);
			break;
		case 2:
			display(list);
			break;
		case 3:
			daozhi(list);
			break;
		case 4:
			ElemType max, min;
			cout << " ����max��min " << endl;
			cin >> max >> min;
			Delete(list, max, min);
			break;
		case 0:
			break;
		}
		if (i == 0) {
			break;
		}
	}
}

void initial(MyList& s)
{
	MyList* p,*pnew;
	p = &s;
	pnew = new MyList;
	cout << "���������ݣ�" << endl;
	cin >> pnew->data;
	p->next = pnew;
	pnew->next = NULL;
	p = p->next;
	int i;
	cout << "�Ƿ��ٴ����" << endl;
	cin >> i;
	while (i == 1) {
		pnew = new MyList;
		cout << "���������ݣ�" << endl;
		cin >> pnew->data;
		p->next = pnew;
		pnew->next = NULL;
		p = p->next;
		cout << "�Ƿ��ٴ����" << endl;
		cin >> i;
	}
}

void display(MyList s)
{
	MyList* p = &s;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data << " ";	
	}
	cout<< endl;
}

void daozhi(MyList& s)
{
	MyList* p, * q;
	p = q = &s;
	while (p->next != NULL) {
		p = p->next;
	}
	q = q->next;
	s.next = q->next;
	p->next = q;
	q->next = NULL;
	q = s.next;
	while (p != q) {
		s.next = q->next;
		q->next = p->next;
		p->next = q;
		q = s.next;
	}
}

void Delete(MyList& s, ElemType max, ElemType min)
{
	MyList* p = &s,*q;
	while (p->next != NULL) {
		if (p->next->data > min && p->next->data < max) {
			q = p->next;
			p->next = p->next->next;
			delete q;
		}
		else
			p = p->next;
	}
}
