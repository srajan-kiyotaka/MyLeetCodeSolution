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
    ListNode* travelTree(ListNode* root, unordered_map<ListNode*, int>& hash, int i){
        if(root == NULL){
            return NULL;
        }
        if(hash.find(root) != hash.end()){
            return root;
        }
        hash[root] = i;
        return travelTree(root->next, hash, i++);
    }

    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> hashMap;
        return travelTree(head, hashMap, 0);;
    }
};