#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
typedef int ElemType;
// 单链表——不带头结点
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
bool InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
    {
        return false;
    }
    L = NULL;
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
    return true;
}
void PrintList(LinkList L)
{
    LNode *p = L;
    while (p)
    {
        if (!p->next)
        {
            cout << p->data << endl;
        }
        else
        {
            cout << p->data << "->";
        }
        p = p->next;
    }
}

bool TailInsert(LinkList &L, ElemType e)
{
    if (L == NULL)
    {
        LNode *s = new LNode;
        s->next = NULL;
        s->data = e;
        L = s;
        return true;
    }

    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    LNode *s = new LNode;
    s->next = NULL;
    s->data = e;
    p->next = s;

    return true;
}
bool EmptyList(LinkList L)
{
    return (L == NULL);
}
void ReverseList(LinkList &L)
{
    if (!L || !L->next)
    {
        return;
    }

    LNode *p = L;
    LinkList newLink = NULL;
    while (p)
    {
        L = L->next;
        p->next = newLink;
        newLink = p;
        p = L;
    }
    L = newLink;
}
int main()
{
    LinkList L;
    InitList(L);
    TailInsert(L, 1);
    TailInsert(L, 2);
    TailInsert(L, 3);
    TailInsert(L, 4);
    PrintList(L);
    ReverseList(L);
    PrintList(L);
}
