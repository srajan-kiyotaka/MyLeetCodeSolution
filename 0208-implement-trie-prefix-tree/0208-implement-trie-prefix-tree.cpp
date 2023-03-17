class TrieNode{
public:
    bool isWord;
    TrieNode* charecter[26];

    TrieNode(){
        isWord = false;
        for(int i = 0; i < 26; i++){
            charecter[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    // insert each charecter in the tree.
    void insert(string word) {
        TrieNode* current_pointer = root;
        int len = word.length();
        for(int i = 0; i < len; i++){
            int index = word[i] - 'a';
            if(current_pointer->charecter[index] == NULL){
                current_pointer->charecter[index] = new TrieNode();
            }
            current_pointer = current_pointer->charecter[index];
        }
        current_pointer->isWord = true;
    }
    
    // search the string in the tree
    bool search(string word) {
        TrieNode* current_pointer = root;
        int len = word.length();
        for(int i = 0; i < len; i++){
            int index = word[i] - 'a';
            if(current_pointer->charecter[index] == NULL){
                return false;
            }
            current_pointer = current_pointer->charecter[index];
        }
        return current_pointer->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current_pointer = root;
        int len = prefix.length();
        for(int i = 0; i < len; i++){
            int index = prefix[i] - 'a';
            if(current_pointer->charecter[index] == NULL){
                return false;
            }
            current_pointer = current_pointer->charecter[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */