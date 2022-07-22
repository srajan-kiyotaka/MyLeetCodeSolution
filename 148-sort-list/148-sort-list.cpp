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
    ListNode* Merge(ListNode* L1, ListNode* L2){
        ListNode* first, *second;
        if(L1->val > L2->val){
            first = L2;
            L2 = first->next;
            first->next = NULL;
            second = first;
        }
        else{
            first = L1;
            L1 = first->next;
            first->next = NULL;
            second = first;
        }
        while(L1 != NULL && L2 != NULL){
            if(L1->val > L2->val){
                second->next = L2;
                second = L2;
                L2 = L2->next;
            }
            else{
                second->next = L1;
                second = L1;
                L1 = L1->next;
            }
        }
        if(L1 != NULL){
            second->next = L1;
        }
        else if(L2 != NULL){
            second->next = L2;
        }
        return first;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* slow, *pre_slow, *fast;
        slow = head;
        fast = head;
        while(fast != NULL && fast->next != NULL){
            pre_slow = slow;
            fast = fast->next;
            slow = slow->next;
            fast = fast->next;
        }
        pre_slow->next = NULL;
        head = sortList(head);
        slow = sortList(slow);
        return Merge(head, slow);
    }
};