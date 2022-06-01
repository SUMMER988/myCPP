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
    L->data = 0;
    return true;
}
LinkList List_TailInsert(LinkList &L)
{
    int num;
    LNode *r = L;
    LNode *s;
    while (cin >> num)
    {
        s = new LNode;
        s->data = num;
        r->next = s;
        r = s;
        L->data++;
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
    cout << L->data << endl;
    return 0;
}
