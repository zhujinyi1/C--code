#pragma once
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct Chain {
	ElemType data;
	struct Chain* next;
}MyList;

void menu();
void initial(MyList &s); //��ʼ��
void display(MyList s); //����
void daozhi(MyList& s);  //������
void Delete(MyList& s, ElemType max, ElemType min); //ɾ�������д���minС��max������