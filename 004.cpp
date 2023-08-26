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
    auto headNode = new LNode;
    auto node1 = new LNode(5);
    auto node2 = new LNode(4);
    auto node3 = new LNode(3);
    auto node4 = new LNode(2);
    auto node5 = new LNode(1);

    return 0;
}
