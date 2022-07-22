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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* p, *q;
        if(list1->val > list2->val){
            p = q = list2;
            list2 = list2->next;
            q->next = NULL;
        }
        else{
            p = q = list1;
            list1 = list1->next;
            q->next = NULL;
        }
        while(list1 != NULL && list2 != NULL){
            if(list1->val > list2->val){
                q->next = list2;
                q = list2;
                list2 = list2->next;
                q->next = NULL;
            }
            else{
                q->next = list1;
                q = list1;
                list1 = list1->next;
                q->next = NULL;
            }
        }
        if(list1 != NULL){
            q->next = list1;
        }
        if(list2 != NULL){
            q->next = list2;
        }
        
        return p;
    }
};                                                                                                                                                                                                                                                                                                                                                             