#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
typedef int ElemType;
// 单链表——按位序插入——不带头结点
typedef struct LNode
{
    ElemType data;
    int length;
    struct LNode *next;
} LNode, *LinkList;
bool InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
    {
        return false;
    }
    L->next = nullptr;
    L->length = 0;
    return true;
}
bool ListInsert(LinkList &L, int pos, ElemType e)
{
    if (pos < 1)
    {
        return false;
    }
    if (pos == 1)
    {
        LNode *s = new LNode;
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p = L;
    int j = 1;
    while (p != nullptr && j < pos - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {
        return false;
    }
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    L->length++;
    return true;
}
void PrintList(LinkList L)
{
    LNode *head = L;
    while (head)
    {
        if (!head->next)
        {
            cout << head->data << endl;
        }
        else
        {
            cout << head->data << "->";
        }
        head = head->next;
    }
}
int main()
{
    LinkList L = nullptr;
}
