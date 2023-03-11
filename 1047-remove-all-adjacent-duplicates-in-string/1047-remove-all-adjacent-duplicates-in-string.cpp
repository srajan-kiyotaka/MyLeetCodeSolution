class Solution {
public:
    string removeDuplicates(string s) {
        // Simple travelser approch
        // Time Complexity : O(n)
        // Space Complexity : O(n)
        int i = 0;
        string ans = "";
        while(i < s.length()){
            if(ans.length() == 0){
                ans.push_back(s[i]);
            }
            else{
                if(ans.back() == s[i]){
                    ans.pop_back();
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            i++;
        }
        return ans;
    }
};

/*
TLE Solution

while(s.length() != 0){
            int start = 0;
            bool flag = true; 
            for(int i = 1; i < s.length(); i++){
                if(s[i-1] == s[i]){
                    flag = false;
                    s.erase(i-1, 2);
                }
            }
            if(flag) return s;
        }
        return s;

*/