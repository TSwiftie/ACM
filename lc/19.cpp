#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    /*
     *使用快慢指针
     *先让first指针指向第n个点
     *此时让second指针指向head
     *然后同时向后移动
     *保持两个节点的距离为n
     *在first指向最后一个节点时
     *second指向倒数第n个节点
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = nullptr;int i;
        for(first = head,i = 1;i < n;++i,first = first->next);
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode *last = sentinel,*second = nullptr,*todel = nullptr;
        for(second = head;first->next!=nullptr;second = last->next,first = first->next)
            last = last->next;
        todel = second;
        last->next = second->next;
        delete todel;
        ListNode *ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};
