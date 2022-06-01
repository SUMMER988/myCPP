#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
typedef int ElemType;
// 单链表——带头结点
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
    L->next = NULL;
    return true;
}
// 头插法
bool HeadInsert(LinkList &L)
{
    if (!L)
    {
        return false;
    }
    LNode *head = L;
    LNode *s;
    int size, num;
    cin >> size;
    while (size-- > 0)
    {
        s = new LNode;
        cin >> num;
        s->data = num;
        s->next = head->next;
        head->next = s;
    }
    return true;
}
// 尾插法
bool TailInsert(LinkList &L)
{
    if (!L)
    {
        return false;
    }
    LNode *r = L;
    LNode *s = nullptr;
    // make 'num' to hold the value to the node
    int num;
    while (std::cin >> num)
    {
        s = new LNode;
        s->data = num;
        r->next = s;
        r = s;
    }
    r->next = nullptr;
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
    while (p && j < pos - 1)
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
    while (p && target < pos - 1)
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
bool DeleteNode(LinkList &L, LNode *p)
{
    if (!p)
    {
        return false;
    }
    if (!p->next)
    {
        LNode *q = L;
        while (q->next != p)
        {
            q = q->next;
        }
        free(p);
        q->next = NULL;
        return true;
    }

    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
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
    L->next = NULL;
}
// 打印单链表元素
void PrintList(LinkList L)
{
    LNode *p = L->next;
    while (p->next)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << p->data << endl;
}
// 判断表空

bool IsEmpty(LinkList L)
{
    return (!L->next);
}
// 按位查找
LNode *GetElem(LinkList L, int pos)
{
    if (pos == 0)
    {
        return L;
    }
    if (pos < 1)
    {
        return NULL;
    }
    int target = 1;
    LNode *p = L->next;
    while (p && target < pos)
    {
        p = p->next;
        target++;
    }
    return p;
}
// 按值查找
LNode *LocateElem(LinkList L, ElemType e)
{
    if (!L)
    {
        return NULL;
    }
    LNode *p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}
// 求表长
int Length(LinkList L)
{
    int len = 0;
    if (IsEmpty(L))
    {
        return len;
    }

    while (L->next)
    {
        len++;
        L = L->next;
    }
    return len;
}
// 逆置
LNode *ReverseList(LinkList &L)
{
    if (!L)
    {
        return NULL;
    }
    LNode *p = L->next;
    LNode *q = p;
    L->next = NULL;
    while (p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return L;
}
// 逆置
LNode *ReverseList0(LinkList &L)
{
    if (!L)
    {
        return NULL;
    }
    LNode *p = L->next;
    LNode *q = nullptr;
    L->next = nullptr;
    while (p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return L;
}
int main()
{

    LinkList L;
    InitList(L);
    TailInsert(L);
    PrintList(L);
    ReverseList0(L);
    PrintList(L);
    std::cout << "The length of List is " << Length(L) << std::endl;

    ReverseList0(L);
    PrintList(L);
}
