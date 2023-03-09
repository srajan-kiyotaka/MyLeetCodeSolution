/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
/*
Two Pointer Approch:
Pointer 1 -> Slow
Pointer 2 -> Fast
*/
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
    

    /*
     Hash Map Approch: 
     Time Complexity: O(n)
    */
    // ListNode* travelTree(ListNode* root, unordered_map<ListNode*, int>& hash, int i){
    //     if(root == NULL){
    //         return NULL;
    //     }
    //     if(hash.find(root) != hash.end()){
    //         return root;
    //     }
    //     hash[root] = i;
    //     return travelTree(root->next, hash, i++);
    // }

    // ListNode *detectCycle(ListNode *head) {
    //     unordered_map<ListNode*, int> hashMap;
    //     return travelTree(head, hashMap, 0);;
    // }
};