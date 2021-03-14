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
		cout << "内存分配失败" << endl;
		return false;
	}
	L.length = 0;

	cout << "你想先输入几个数？" << endl;
	cin >> n;
	while (n<0 || n>L.maxsize) {
		cout << "输入有误，请重新输入" << endl;
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
		cout << "没有初始化或线性表已被销毁" << endl;
		return;
	}
	cout << "线性表中元素为：" << L.elem[i];
	for (i = 1; i <= L.length - 1; i++) {
		cout << " " << L.elem[i];
	}
	cout << endl;
}

bool ListInsert(SqList& L, int pos, ElemType e)
{
	int i;
	if (pos >= L.length || pos < 0) {
		cout << "插入位置不合法" << endl;
		return false; //插入位置不合法
	}
	if (L.length == L.maxsize) {
		cout << "线性表已满" << endl;
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
		cout << "删除位置不合法" << endl;
		return false;
	}
	if (L.length == 0) {
		cout << "顺序表中无元素" << endl;
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
			cout << "该元素位序为：" << i << endl;
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
		cout << "|1.初始化线性表         |" << endl;
		cout << "|2.插入元素             |" << endl;
		cout << "|3.删除元素             |" << endl;
		cout << "|4.元素定位             |" << endl;
		cout << "|5.销毁线性表           |" << endl;
		cout << "|6.遍历线性表           |" << endl;
		cout << "|7.有序插入             |" << endl;
		cout << "|8.交换                 |" << endl;
		cout << "|0.退出                 |" << endl;
		cout << "|_______________________|" << endl;
		cin >> i;
		switch (i) {
		case 1:
			cout << "请输入表长：" << endl;
			cin >> n;
			b = ListInitList(list, n);
			if (b) {
				cout << "初始化成功！" << endl;
			}
			else {
				cout << "初始化失败!" << endl;
			}
			break;
		case 2:
			cout << "输入插入位置:" << endl;
			cin >> i;
			cout << "输入插入的数据:" << endl;
			cin >> e;
			b = ListInsert(list, i, e);
			if (b == true) {
				cout << "插入成功！" << endl;
			}
			else {
				cout << "插入失败" << endl;
			}
			break;
		case 3:
			cout << "输入删除位置:" << endl;
			cin >> i;
			b = ListDelete(list, i);
			if (b == true) {
				cout << "删除成功！" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			break;
		case 4:
			cout << "请输入查找的元素：" << endl;
			cin >> e;
			b = ListSearch(list, e, Compare);
			if (!b) {
				cout << "未找到该元素" << endl;
			}
			break;
		case 5:
			ListDestory(list);
			break;
		case 6:
			ListDisplay(list);
			break;
		case 7:
			cout << "请输入要插入的数：" << endl;
			cin >> e;
			insert(list, e);
		case 8:
			swap(list);
		case 0:
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
		if (i == 0) {
			break;
		}
	}
}

