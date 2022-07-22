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
    ListNode* middleNode(ListNode* head) {
        ListNode* p;
        ListNode* q;
        p = head;
        q = head;
        while(q != NULL && q->next != NULL){
            q = q->next;
            p = p->next;
            if(q == NULL) return p;
            q = q->next;
        }
        return p;
    }
};