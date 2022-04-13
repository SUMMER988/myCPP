#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxSize 10
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
bool initList(LinkList &L)
{
    L = new LNode;
    if (!L)
    {
        return false;
    }
    L->next = nullptr;
    return true;
}
LinkList List_TailInsert(LinkList &L)
{
    int num;
    L = new LNode;
    LNode *r = L;
    LNode *s;
    while (cin >> num && num != 999)
    {
        s = new LNode;
        s->data = num;
        r->next = s;
        r = s;
    }
    r->next = nullptr;
    return L;
}
void printList(LinkList L)
{
    LNode *p = L->next;
    while (p->next)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << p->data << endl;
}
int main()
{
    LinkList L;
    initList(L);
    List_TailInsert(L);
    printList(L);
}
