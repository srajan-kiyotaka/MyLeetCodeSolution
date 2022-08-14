class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = 0; i < columnTitle.length(); i++){
            ans = ans*26 + (columnTitle[i] - 'A') + 1;
        }
        return ans;
    }
};