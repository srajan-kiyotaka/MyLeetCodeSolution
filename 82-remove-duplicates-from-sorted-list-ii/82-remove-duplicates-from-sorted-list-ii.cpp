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
        if(head == NULL || head->next == NULL) return head;
        ListNode* p, *q, *r;
        q = r = NULL;
        p = head;
        int prev = INT_MAX;
        while(p != NULL){
            if(q == NULL){
                r = q;
                q = p;
                p = p->next;
            }
            else if(r == NULL){
                if(q->val == p->val){
                    prev = q->val;
                    head = p->next;
                    delete q;
                    delete p;
                    p = head;
                    q = NULL;
                }
                else{
                    if(q->val == prev){
                        head = p;
                        delete q;
                        q = NULL;
                    }
                    else{
                        r = q;
                        q = p;
                        p = p->next;
                    }
                }
            }
            else{
                if(q->val == p->val){
                    prev = q->val;
                    r->next = p->next;
                    delete q;
                    delete p;
                    q = r->next;
                    if(q == NULL) return head;
                    p = q->next;
                }
                else{
                    if(q->val == prev){
                        r->next = p;
                        delete q;
                        q = p;
                        p = p->next;
                    }
                    else{
                        r = q;
                        q = p;
                        p = p->next;
                    }
                }
            }
        }
        if(q != NULL){
            if(q->val == prev){
                if(head == q) head = NULL;
                delete q;
                if(r != NULL) r->next = NULL;
            }
        }
        return head;
    }
};