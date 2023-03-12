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
// Just a function to print the linked list.
    void print(ListNode* root){
        while(root != NULL){
            cout << root->val << " " ;
            root = root->next;
        }
        cout << endl;
    }

    ListNode* merge(ListNode* root1, ListNode* root2){
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        // cout << "List 1" << endl;
        // print(root1);
        // cout << "List 2" << endl;
        // print(root2);
        ListNode* root;
        ListNode* i;
        i = root1;
        if(root1->val < root2->val){
            root = root1;
            i = root1;
            root1 = root1->next;
        }
        else{
            root = root2;
            i = root2;
            root2 = root2->next;
        }

        while(root1 != NULL && root2 != NULL){
            if(root1->val < root2->val){
                i->next = root1;
                i = root1;
                root1 = root1->next;
            }
            else{
                i->next = root2;
                i = root2;
                root2 = root2->next; 
            }
        }

        while(root1 != NULL){
            i->next = root1;
            i = root1;
            root1 = root1->next;
        }

        while(root2 != NULL){
            i->next = root2;
            i = root2;
            root2 = root2->next; 
        }

        // cout << "Final List" << endl;
        // print(root);
        // cout << "List 2" << endl;
        // print(root2);

        return root;
    }

    ListNode* mergeLinkLists(vector<ListNode*>& lists, int s, int e){
        if(e - s == 0) return lists[s];
        if(e - s == 1){
            return merge(lists[s], lists[e]);
        }
        int mid = s + (e - s)/2;
        return merge(mergeLinkLists(lists, s, mid), mergeLinkLists(lists, mid + 1, e));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Using Devide and Conqure Approch.
        if(lists.size() < 1) return NULL;
        // print(merge(lists[0], lists[1]));
        return mergeLinkLists(lists, 0, lists.size() - 1);
    }
};