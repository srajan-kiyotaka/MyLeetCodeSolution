/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node* head_copy = NULL;
        Node* p = head, *q = head_copy;
        if(head == NULL){
            return head_copy;
        }
        head_copy = new Node(head->val);
        map[head] = head_copy;
        p = p->next;
        q = head_copy;
        while(p != NULL){
            Node* temp = new Node(p->val);
            q->next = temp;
            q = temp;
            map[p] = temp;
            p = p->next;
        }
        p = head;
        q = head_copy;
        while(p != NULL){
            q->random = map[p->random];
            p = p->next;
            q = q->next;
        }
        return head_copy;
    }
};