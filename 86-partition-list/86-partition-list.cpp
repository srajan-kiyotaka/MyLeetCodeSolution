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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> a, b;
        ListNode* p = head;
        while(p != NULL){
            if(p->val < x){
                a.push_back(p->val);
            }
            else{
                b.push_back(p->val);
            }
            p = p->next;
        }
        int n = a.size(), m = b.size();
        int i = 0;
        p = head;
        while(i < n){
            p->val = a[i];
            p = p->next;
            i++;
        }
        i = 0;
        while(i < m){
            p->val = b[i];
            p = p->next;
            i++;
        }
        return head;
    }
};