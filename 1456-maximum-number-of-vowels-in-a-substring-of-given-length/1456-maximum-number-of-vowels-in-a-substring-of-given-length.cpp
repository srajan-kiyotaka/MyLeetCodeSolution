class Solution {
public:
    int maxVowels(string s, int k) {
        // sliding window
        int window = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                window++;
            }
        }
        int ans = window;
        for(int i = k; i < s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                window++;
            }
            if(s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u'){
                window--;
            }
            ans = max(ans, window);
        }
        return ans;
    }
};