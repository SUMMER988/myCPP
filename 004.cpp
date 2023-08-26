#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;
// 单链表
typedef struct LNode {
    int data;
    struct LNode *next;
    LNode() : next(NULL) {}
    LNode(int val) : next(NULL), data(val) {}
} LNode, *LinkList;

int main() {
    std::cout << "单链表" << std::endl;

    return 0;
}
