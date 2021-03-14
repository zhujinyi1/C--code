#pragma once
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct Chain {
	ElemType data;
	struct Chain* next;
}MyList;

void menu();
void initial(MyList &s); //初始化
void display(MyList s); //遍历
void daozhi(MyList& s);  //链表倒置
void Delete(MyList& s, ElemType max, ElemType min); //删除链表中大于min小于max的数据