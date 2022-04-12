#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
typedef int ElemType;
// 单链表
typedef struct LNode
{
    ElemType data;
    struct LNode *head, *tail;
    struct LNode *next;
} LNode, *LinkList;
bool InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
    {
        return false;
    }
    L->head = L;
    L->tail = L;
    L->next = nullptr;
    return true;
}
// 头插法
bool HeadInsert(LinkList &L, ElemType e)
{
    if (!L)
    {
        return false;
    }
    LNode *p = new LNode;
    p->data = e;
    p->next = L->next;
    L->next = p;
    return true;
}
// 尾插法
bool TailInsert(LinkList &L, ElemType e)
{
    if (!L)
    {
        return false;
    }
    LNode *p = new LNode;
    p->data = e;
    p->next = L->tail->next;
    L->tail->next = p;
    L->tail = p;
    return true;
}
// 指定结点的后插操作
bool InsertNextNode(LNode *p, ElemType e)
{
    if (!p)
    {
        return false;
    }
    LNode *s = new LNode;
    if (!s)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}
// 指定结点的前插操作
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (!p)
    {
        return false;
    }
    LNode *s = new LNode;
    if (!s)
    {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
// 按位序插入——带头结点
bool ListInsert(LinkList &L, int pos, ElemType e)
{
    if (pos < 1)
    {
        return false;
    }
    LNode *p = L;
    int j = 0;
    while (p != nullptr && j < pos - 1)
    {
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}
// 按位序删除——带头结点
bool ListDelete(LinkList &L, int pos, ElemType &e)
{
    if (pos < 1)
    {
        return false;
    }
    int target = 0;
    LNode *p = L;
    while (!p && target < pos - 1)
    {
        p = p->next;
        target++;
    }
    if (!p || !p->next)
    {
        return false;
    }
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}
// 删除指定结点
bool DeleteNode(LNode *p)
{
    if (!p)
    {
        return false;
    }
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    delete q;
    return true;
}
// 删除全部
void ListDeleteAll(LinkList &L)
{
    if (!L->next)
    {
        return;
    }
    ListDeleteAll(L->next);
    delete L->next;
    L->next = nullptr;
}
// 打印单链表元素
void PrintList(LinkList L)
{
    LNode *head = L->next;
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
// 判断表空

bool EmptyList(LinkList L)
{
    return (!L->next);
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
}
