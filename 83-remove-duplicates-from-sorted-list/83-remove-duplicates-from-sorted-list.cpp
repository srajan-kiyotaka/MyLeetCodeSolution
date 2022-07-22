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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p, *q;
        p = head;
        if(p == NULL) return head;
        p = p->next;
        q = head;
        while(p != NULL){
            if(p->val == q->val){
                q->next = p->next;
                delete p;
                p = q->next;
                continue;
            }
            q = p;
            p = p->next;
        }
        return head;
    }
};