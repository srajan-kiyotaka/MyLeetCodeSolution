class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0;
        n--;
        while(start < n){
            swap(s[start++], s[n--]);
        }
    }
};