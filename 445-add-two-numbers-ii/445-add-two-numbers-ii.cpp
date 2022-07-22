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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a,b;
        ListNode* p = l1;
        ListNode* q = l2;
        while(p != NULL){
            a.push_back(p->val);
            p = p->next;
        }
        while(q != NULL){
            b.push_back(q->val);
            q = q->next;
        }
        if(a.size() > b.size()){
            vector<int> num;
            int n = a.size() - 1;
            int m = b.size() - 1;
            int carry = 0;
            p = l1;
            q = NULL;
            while(n >= 0 && m >= 0){
                num.push_back((a[n] + b[m] + carry)%10);
                carry = (a[n] + b[m] + carry)/10;
                n--;
                m--;
            }
            if(n >= 0){
                while(n >= 0){
                    num.push_back((a[n] + carry)%10);
                    carry = (a[n] + carry)/10;
                    n--;
                }
            }
            if(m >= 0){
                while(m >= 0){
                    num.push_back((b[m] + carry)%10);
                    carry = (b[m] + carry)/10;
                    m--;
                }
            }
            if(carry != 0){
                num.push_back(carry);
            }
            
            int i = num.size() - 1;
            bool flag = false;
            for(; i >= 0 && p != NULL; i--){
                if(i == 0) flag = true;
                p->val = num[i];
                q = p;
                p = p->next;
            }
            if(!flag){
                for(; i >= 0; i--){
                    p = new ListNode(num[i]);
                    q->next = p;
                    q = p;
                }
            }
            return l1;
        }
        else{
            vector<int> num;
            int n = a.size() - 1;
            int m = b.size() - 1;
            int carry = 0;
            p = l1;
            q = NULL;
            while(n >= 0 && m >= 0){
                num.push_back((a[n] + b[m] + carry)%10);
                carry = (a[n] + b[m] + carry)/10;
                n--;
                m--;
            }
            if(n >= 0){
                while(n >= 0){
                    num.push_back((a[n] + carry)%10);
                    carry = (a[n] + carry)/10;
                    n--;
                }
            }
            if(m >= 0){
                while(m >= 0){
                    num.push_back((b[m] + carry)%10);
                    carry = (b[m] + carry)/10;
                    m--;
                }
            }
            if(carry != 0){
                num.push_back(carry);
            }
            p = l2;
            q = NULL;
            int i = num.size() - 1;
            bool flag = false;
            for(; i >= 0 && p != NULL; i--){
                if(i == 0) flag = true;
                p->val = num[i];
                q = p;
                p = p->next;
            }
            if(!flag){
                for(; i >= 0; i--){
                    p = new ListNode(num[i]);
                    q->next = p;
                    q = p;
                }
            }
            return l2;
        }
        
        return l1;
    }
};