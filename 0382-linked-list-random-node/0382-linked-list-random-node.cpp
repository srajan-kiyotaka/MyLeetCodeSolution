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
private:
    ListNode* head;
    
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0)); // seed the random number generator
    }
    
    int getRandom() {
        int count = 0;
        int result = 0;
        ListNode* curr = head;
        
        while (curr) {
            count++;
            // generate a random number between 1 and the count
            // if the random number is 1, update the result with the current node's value
            if (rand() % count == 0) {
                result = curr->val;
            }
            curr = curr->next;
        }
        
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */