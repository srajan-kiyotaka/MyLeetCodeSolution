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
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        while(head != NULL){
            ans.push_back(head->val);
            head = head->next;
        }
        int p = 0, q = ans.size() - 1;
        while(p < q){
            if(ans[p] != ans[q]) return false;
            p++;
            q--;
        }
        return true;
    }
};