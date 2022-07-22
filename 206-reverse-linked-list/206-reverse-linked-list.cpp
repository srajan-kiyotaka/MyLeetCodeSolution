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
    ListNode* reverseList(ListNode* head) {
        ListNode* p, *q, *r;
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        p = head->next;
        q = head;
        r = NULL;
        while(q != NULL){
            q->next = r;
            r = q;
            q = p;
            if(p == NULL) return r;
            p = p->next;
        }
        return r;
    }
};