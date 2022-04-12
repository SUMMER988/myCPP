#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
typedef int ElemType;
// 单链表
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
//指定结点的后插操作
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
int main()
{
    LinkList L = nullptr;
}
