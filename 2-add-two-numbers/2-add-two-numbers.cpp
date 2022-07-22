/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            l1->val = l1->val + l2->val + carry;
            carry = l1->val / 10;
            l1->val = l1->val % 10;
            q = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 != NULL){
            while(carry != 0 && l1 != NULL){
                l1->val = l1->val + carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                q = l1;
                l1 = l1->next;
            }
            if(carry != 0){
                l1 = new ListNode(carry);
                q->next = l1;
            }
        }
        else if(l2 != NULL){
            q->next = l2;
            while(carry != 0 && l2 != NULL){
                l2->val = l2->val + carry;
                carry = l2->val / 10;
                l2->val = l2->val % 10;
                q = l2;
                l2 = l2->next;
            }
            if(carry != 0){
                l2 = new ListNode(carry);
                q->next = l2;
            }
        }
        else if(carry != 0){
            l2 = new ListNode(carry);
            q->next = l2;
        }
        
        return p;
    }
};