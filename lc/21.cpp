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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr,*tail = nullptr;
        while(l1 || l2){
            if(l1 && l2){
                if(l1->val < l2->val){
                    if(head==nullptr) head = tail = l1;
                    else{
                        tail->next = l1;
                        tail = tail->next;
                    }
                    l1 = l1->next;
                }else{
                    if(head==nullptr) head = tail = l2;
                    else{
                        tail->next = l2;
                        tail = tail->next;
                    }
                    l2 = l2->next;
                }
            }else if(l1){
                if(head==nullptr) head = tail = l1;
                else{
                    tail->next = l1;
                    tail = tail->next;
                }
                l1 = l1->next;
            }else if(l2){
                if(head==nullptr) head = tail = l2;
                else{
                    tail->next = l2;
                    tail = tail->next;
                }
                l2 = l2->next;
            }
        }
        return head;
    }
};
