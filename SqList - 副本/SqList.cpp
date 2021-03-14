#include"SqList.h"

bool ListInitList(SqList& L, int size) {
	int n = -1, i;
	if (size == 0) {
		L.maxsize = MAXLENGTH;
	}
	else{
		L.maxsize = size;
	}
	L.elem = new ElemType[L.maxsize];
	if (!L.elem) {
		cout << "�ڴ����ʧ��" << endl;
		return false;
	}
	L.length = 0;

	cout << "���������뼸������" << endl;
	cin >> n;
	while (n<0 || n>L.maxsize) {
		cout << "������������������" << endl;
		cin >> n;
	}
	for (i = 0; i < n; i++) {
		cin >> L.elem[i];
	}
	L.length = n;

	return true;
}

bool Compare(ElemType a, ElemType b) {
	return a == b;
}


void ListDisplay(SqList L)
{
	int i = 0;
	if (L.length == 0) {
		cout << "û�г�ʼ�������Ա��ѱ�����" << endl;
		return;
	}
	cout << "���Ա���Ԫ��Ϊ��" << L.elem[i];
	for (i = 1; i <= L.length - 1; i++) {
		cout << " " << L.elem[i];
	}
	cout << endl;
}

bool ListInsert(SqList& L, int pos, ElemType e)
{
	int i;
	if (pos >= L.length || pos < 0) {
		cout << "����λ�ò��Ϸ�" << endl;
		return false; //����λ�ò��Ϸ�
	}
	if (L.length == L.maxsize) {
		cout << "���Ա�����" << endl;
		return false;
	}
	for (i = L.length; i >= pos; i--) {
		L.elem[i] = L.elem[i - 1];
	}
	L.length++;
	L.elem[pos] = e;
	return true;
}

bool ListDelete(SqList& L, int pos)
{
	int i;
	if (pos < 0 || pos >= L.length) {
		cout << "ɾ��λ�ò��Ϸ�" << endl;
		return false;
	}
	if (L.length == 0) {
		cout << "˳�������Ԫ��" << endl;
		return false;
	}
	for (i = pos; i < L.length - 1; i++) {
		L.elem[i] = L.elem[i + 1];
	}
	L.length++;
	return true;
}

void ListDestory(SqList& L)
{
	delete[] L.elem;
	L.length = 0;
	L.maxsize = 0;
}

bool ListSearch(SqList L, ElemType e, bool (*compare)(ElemType, ElemType))
{
	int i;
	for (i = 0; i <= L.length - 1; i++) {
		if (compare(L.elem[i], e)) {
			cout << "��Ԫ��λ��Ϊ��" << i << endl;
			break;
		}
	}
	if (i > L.length) {
		return false;
	}
	return true;
}

void insert(SqList& L, ElemType e) {
	int i;
	for (i = L.length; i > 0; i--) {
		if (L.elem[i - 1] <= e) {
			break;
		}
		L.elem[i] = L.elem[i - 1];
	}
		L.elem[i] = e;
	L.length++;
}

void swap(SqList& L) {
	ElemType t;
	int i, j;
	for (i = 0, j = L.length - 1;; i++, j--) {
		
		while (L.elem[i] % 2 != 0) {
			i++;
		}
		while (L.elem[j] % 2 == 0) {
			j--;
		}
		if (i >= j) {
			break;
		}
		t = L.elem[i];
		L.elem[i] = L.elem[j];
		L.elem[j] = t;
	}
}

void Menu() {
	SqList list;
	ElemType e;
	int i, n;
	bool b;

	while (true) {
		cout << "_________________________" << endl;
		cout << "|1.��ʼ�����Ա�         |" << endl;
		cout << "|2.����Ԫ��             |" << endl;
		cout << "|3.ɾ��Ԫ��             |" << endl;
		cout << "|4.Ԫ�ض�λ             |" << endl;
		cout << "|5.�������Ա�           |" << endl;
		cout << "|6.�������Ա�           |" << endl;
		cout << "|7.�������             |" << endl;
		cout << "|8.����                 |" << endl;
		cout << "|0.�˳�                 |" << endl;
		cout << "|_______________________|" << endl;
		cin >> i;
		switch (i) {
		case 1:
			cout << "���������" << endl;
			cin >> n;
			b = ListInitList(list, n);
			if (b) {
				cout << "��ʼ���ɹ���" << endl;
			}
			else {
				cout << "��ʼ��ʧ��!" << endl;
			}
			break;
		case 2:
			cout << "�������λ��:" << endl;
			cin >> i;
			cout << "������������:" << endl;
			cin >> e;
			b = ListInsert(list, i, e);
			if (b == true) {
				cout << "����ɹ���" << endl;
			}
			else {
				cout << "����ʧ��" << endl;
			}
			break;
		case 3:
			cout << "����ɾ��λ��:" << endl;
			cin >> i;
			b = ListDelete(list, i);
			if (b == true) {
				cout << "ɾ���ɹ���" << endl;
			}
			else {
				cout << "ɾ��ʧ��" << endl;
			}
			break;
		case 4:
			cout << "��������ҵ�Ԫ�أ�" << endl;
			cin >> e;
			b = ListSearch(list, e, Compare);
			if (!b) {
				cout << "δ�ҵ���Ԫ��" << endl;
			}
			break;
		case 5:
			ListDestory(list);
			break;
		case 6:
			ListDisplay(list);
			break;
		case 7:
			cout << "������Ҫ���������" << endl;
			cin >> e;
			insert(list, e);
		case 8:
			swap(list);
		case 0:
			break;
		default:
			cout << "������������������" << endl;
			break;
		}
		if (i == 0) {
			break;
		}
	}
}

