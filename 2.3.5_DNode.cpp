#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxSize 10
typedef int ElemType;
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
bool InitDLinkList(DLinkList &L)
{
    L = new DNode;
    if (!L)
    {
        return false;
    }
    L->prior = nullptr;
    L->next = nullptr;
    return true;
}

int main()
{
    DLinkList L;
    InitDLinkList(L);
}
