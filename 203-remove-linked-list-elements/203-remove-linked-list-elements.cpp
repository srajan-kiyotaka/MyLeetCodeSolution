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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p, *q;
        q = NULL;
        p = head;
        while(p != NULL){
            if(p->val == val){
                if(q == NULL){
                    head = p->next;
                    delete p;
                    p = head;
                    continue;
                }
                else{
                    q->next = p->next;
                    delete p;
                    p = q->next;
                    continue;
                }
            }
            else{
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};