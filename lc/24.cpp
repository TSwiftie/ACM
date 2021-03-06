#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *sem = new ListNode(0,head);
        ListNode *pre = sem,*first = head, *second = head->next;
        while(true){
            pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;
            first = first->next;
            if(first == nullptr) break;
            second = first->next;
            if(second == nullptr) break;
        }
        head = sem->next;
        delete sem;
        return head;
    }
};
