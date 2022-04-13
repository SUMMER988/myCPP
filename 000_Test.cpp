#include <iostream>
using namespace std;
#include <vector>

//链表结点结构
class ListNode
{
public:
    int data;                 //数据域
    ListNode *next = nullptr; //指针域

    ListNode(int val) //有参构造，data赋值
    {
        data = val;
    }
};

vector<int> inputV()
{
    int n;
    cout << "请输入待排序组元素的个数" << endl;
    cin >> n;

    vector<int> nums;
    cout << "请输入待排序组" << endl;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    return nums;
}

//创建链表
ListNode *creat(vector<int> &nums)
{
    //创建头节点
    ListNode *head = nullptr;
    head = new ListNode(0); //头结点数据域可为空

    ListNode *p = head; //记录头指针
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        ListNode *pNewNode = new ListNode(*it); //创建新结点
        p->next = pNewNode;                     //上个节点指针域放新节点的地址

        p = pNewNode; //更新结点
    }
    p->next = nullptr;
    return head;
}

void printList(ListNode *L) //传入头指针,利用头指针可找到整个链表
{
    while (L->next)
    {
        L = L->next; //头结点数据不用
        cout << L->data << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums;
    nums = inputV(); // inputNum()用户输入一组数字,保存在vector中

    ListNode *head = nullptr;
    head = creat(nums);
    printList(head);

    return 0;
}
