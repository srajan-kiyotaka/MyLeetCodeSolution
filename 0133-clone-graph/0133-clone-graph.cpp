/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> hash;
    unordered_map<Node*, bool> hash_map;
public:
    void dfs(Node* node){
        if(hash_map.find(node) != hash_map.end()) return;
        hash_map[node] = false;
        // cout << "pass 1" << endl;
        if(node && hash.find(node) == hash.end()){
            hash[node] = new Node(node->val);
        }
        // cout << "pass 2" << endl;
        for(auto it : node->neighbors){
            if(it == NULL) continue;
            dfs(it);
        }
        // cout << "pass 3" << endl;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        dfs(node);
        Node* root = hash[node];
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(hash_map[curr]) continue;
            hash_map[curr] = true;
            for(auto it : curr->neighbors){
                if(it == NULL) continue;
                hash[curr]->neighbors.push_back(hash[it]);
                q.push(it);
            }
        }
        hash.clear();
        hash_map.clear();
        return root;
    }
};