class Tried {
    public:
    bool isWord;
    Tried* children[26];

    Tried(){
        isWord = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class WordDictionary {
private:
    Tried* root;
public:
    WordDictionary() {
        root = new Tried;
    }
    
    void addWord(string word) {
        Tried* curr;
        curr = root;
        for(int i = 0; i < word.length(); i++){
            if(curr->children[word[i] - 'a'] == NULL){
                curr->children[word[i] - 'a'] = new Tried;
            }
            curr = curr->children[word[i] - 'a'];
        }
        curr->isWord = true;
    }
    
    bool rSearch(Tried* curr, int now, string word){
        for(int i = now; i < word.size(); i++){
            if(word[i] == '.'){
                Tried* pointer;
                pointer = curr;
                bool flag = true;
                for(int j = 0; j < 26; j++){
                    if(curr->children[j] != NULL){
                        flag = false;
                        pointer = curr->children[j];
                        if(rSearch(pointer, i+1, word)){
                            return true;
                        }
                    }
                }
                if(flag){
                    // if(i == word.length() - 1){
                    //     return pointer->isWord;
                    // }
                    return false;
                }
                curr = pointer;
            }
            else{
                if(curr->children[word[i] - 'a'] == NULL){
                    return false;
                }
                curr = curr->children[word[i] - 'a'];
            }
        }
        return curr->isWord;
    }

    bool search(string word) {
        Tried* curr;
        curr = root;
        return rSearch(curr, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */