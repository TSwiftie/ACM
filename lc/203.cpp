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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode *last = sentinel, *todel = nullptr;
        for(ListNode *curr = head;curr != nullptr;curr = last->next){
            if(curr->val == val){
                todel = curr;
                last->next = curr->next;
                delete todel;
            }else last = last->next;
        }
        ListNode *ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};
