#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
typedef int ElemType;
// 单链表——不带头结点
typedef struct LNode {
    ElemType data;
    LNode *next = nullptr;
    LNode *LinkTail = nullptr;
    LNode *LinkHead = nullptr;
} LNode, *LinkList;

bool InitList(LinkList &L);
void PrintList(LinkList L);
bool TailInsert(LinkList &L, ElemType e);
bool TailInsert1(LinkList &L, ElemType e);
bool HeadInsert(LinkList &L, ElemType e);
bool ListInsert(LinkList &L, int pos, ElemType e);
bool deleteNode(LinkList &L, int pos);
LNode *findPreNode(LinkList &L, int pos);
bool IsEmpty(LinkList L);
LNode *LocateElem(LinkList L, ElemType e);
int getLength(LinkList L);
void showTail(LinkList &L);
void ReverseList(LinkList &L);
void ReverseList1(LinkList &L);

int main() {
    LinkList L;
    InitList(L);
    HeadInsert(L, 1);
    HeadInsert(L, 2);
    HeadInsert(L, 3);
    HeadInsert(L, 4);
    HeadInsert(L, 5);
    HeadInsert(L, 6);
    HeadInsert(L, 7);
    HeadInsert(L, 8);
    HeadInsert(L, 9);
    PrintList(L);
    showTail(L);
    ReverseList(L);
    PrintList(L);
    showTail(L);
    deleteNode(L, getLength(L));
    PrintList(L);
    showTail(L);
}

bool InitList(LinkList &L) {
    L = new LNode;
    if (!L) {
        return false;
    }
    return true;
}
void PrintList(LinkList L) {
    int countNum = 0;
    LNode *p = L->next;
    while (p) {
        ++countNum;
        if (!p->next) {
            cout << p->data << endl;
        } else {
            cout << p->data << "->";
        }
        p = p->next;
    }
    cout << "THE LENGTH IS " << countNum << endl;
}

bool TailInsert(LinkList &L, ElemType e) {
    if (L->next == nullptr) {
        LNode *s = new LNode;
        // s->next = nullptr;
        s->data = e;
        L->next = s;
        L->LinkTail = s;
        return true;
    }

    LNode *tail = L;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    LNode *s = new LNode;
    s->next = nullptr;
    s->data = e;
    tail->next = s;

    return true;
}
bool TailInsert1(LinkList &L, ElemType e) {
    if (L->next == nullptr) {
        LNode *s = new LNode;
        // s->next = nullptr;
        s->data = e;
        L->next = s;
        L->LinkTail = s;
        return true;
    }

    LNode *s = new LNode;
    s->next = nullptr;
    s->data = e;
    L->LinkTail->next = s;
    L->LinkTail = s;

    return true;
}
bool HeadInsert(LinkList &L, ElemType e) {
    if (L->next == nullptr) {
        LNode *s = new LNode;
        // s->next = nullptr;
        s->data = e;
        L->next = s;
        L->LinkTail = s;
        return true;
    }

    LNode *s = new LNode;
    s->next = L->next;
    s->data = e;
    L->next = s;

    return true;
}

LNode *findPreNode(LinkList &L, int pos) {
    LNode *node = L;
    while (pos-- > 0) {
        node = node->next;
    }
    return node;
}
bool deleteNode(LinkList &L, int pos) {
    if (pos < 1 || pos > getLength(L)) {
        std::cout << "删除有误" << std::endl;
        return false;
    }

    LNode *preNode = findPreNode(L, pos - 1);
    LNode *delNode = preNode->next;
    preNode->next = preNode->next->next;
    delete delNode;
    if (!preNode->next) {
        L->LinkTail = preNode;
    }

    return true;
}
void showTail(LinkList &L) { cout << "Tail is " << L->LinkTail->data << endl; }

bool ListInsert(LinkList &L, int pos, ElemType e) {
    if (pos < 1) {
        return false;
    }
    if (pos == 1) {
        HeadInsert(L, e);
        return true;
    }
    if (pos > getLength(L) + 1) {
        std::cout << pos << " " << e << "插入有误" << std::endl;
        return false;
    }

    LNode *p = L->next;
    int j = 1;
    while (p != nullptr && j < pos - 1) {
        p = p->next;
        j++;
    }
    // if (!p) {
    //     std::cout << pos << " " << e << "插入有误" << std::endl;
    //     return false;
    // }
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 判断表是否为空
bool IsEmpty(LinkList L) { return (L->next == nullptr); }

// 按值查找
LNode *LocateElem(LinkList L, ElemType e) {
    if (!L) {
        return NULL;
    }
    LNode *p = L;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

// 求表长
int getLength(LinkList L) {
    int len = 0;
    if (IsEmpty(L)) {
        return len;
    }
    LNode *p = L->next;
    while (p) {
        len++;
        p = p->next;
    }
    // std::cout << "The Length is " << len << std::endl;
    return len;
}
// 表逆置
void ReverseList(LinkList &L) {
    if (!L || !L->next) {
        return;
    }
    LNode *p = L->next;
    L->LinkTail = L->next;
    LNode *s = nullptr, *q = p;
    while (p) {
        q = p->next;
        p->next = s;
        s = p;
        p = q;
    }
    L->next = s;
}
// 表逆置
void ReverseList1(LinkList &L) {
    if (!L || !L->next) {
        return;
    }
    LNode *p = L->next;
    LNode *pre = nullptr, *q = nullptr;
    while (p) {
        q = p->next;
        p->next = pre;
        pre = p;
        p = q;
    }
    L->next = pre;
}
