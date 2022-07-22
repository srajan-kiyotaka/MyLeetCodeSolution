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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        if(head->next == NULL) return NULL;
        stack<ListNode*> st;
        ListNode* p = head;
        while(p != NULL){
            st.push(p);
            p = p->next;
        }
        ListNode* q = NULL;
        while(n > 0){
            q = st.top();
            st.pop();
            n--;
        }
        if(st.empty()){
            head = q->next;
            delete q;
            return head;
        }
        else{
            p = st.top();
            p->next = q->next;
            delete q;
            return head;
        }
    }
};