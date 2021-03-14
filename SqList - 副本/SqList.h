#include<iostream> 
using namespace std;
#define MAXLENGTH 100;

typedef int ElemType;

typedef struct {
	ElemType *elem;
	int maxsize;
	int length;
}SqList;

void Menu();//菜单
bool ListInitList(SqList& L, int size);//初始化线性表
bool Compare(ElemType a, ElemType b);//元素比较
bool ListSearch(SqList L, ElemType e);//元素定位
void ListDisplay(SqList L);////线性表遍历
bool ListInsert(SqList& L, int pos, ElemType e);//线性表插入
bool ListDelete(SqList& L, int pos);//线性表元素删除
void ListDestory(SqList& L);//线性表销毁
void insert(SqList& L, ElemType e);