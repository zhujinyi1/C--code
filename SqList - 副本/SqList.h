#include<iostream> 
using namespace std;
#define MAXLENGTH 100;

typedef int ElemType;

typedef struct {
	ElemType *elem;
	int maxsize;
	int length;
}SqList;

void Menu();//�˵�
bool ListInitList(SqList& L, int size);//��ʼ�����Ա�
bool Compare(ElemType a, ElemType b);//Ԫ�رȽ�
bool ListSearch(SqList L, ElemType e);//Ԫ�ض�λ
void ListDisplay(SqList L);////���Ա����
bool ListInsert(SqList& L, int pos, ElemType e);//���Ա����
bool ListDelete(SqList& L, int pos);//���Ա�Ԫ��ɾ��
void ListDestory(SqList& L);//���Ա�����
void insert(SqList& L, ElemType e);