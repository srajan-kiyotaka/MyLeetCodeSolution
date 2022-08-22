class Solution {
public:
    /*
    a -> 97
    z -> 122
    A -> 65
    Z -> 90
    */
    bool detectCapitalUse(string word) {
        int count = 0;
        int pos = -1;
        for(int i = 0; i < word.length(); i++){
            if(word[i] <= 'Z' && word[i] >= 'A'){
                count++;
                pos = i;
            }
        }
        if(count == word.length()) return true;
        if(pos == -1 || pos == 0) return true;

        return false;
    }
};