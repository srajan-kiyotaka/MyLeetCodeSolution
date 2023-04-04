class Solution {
public:
    int partitionString(string s) {
        // One Pointer Approch
        // Make a visited Array
        vector<bool> visited(26, false);
        // count the total number of pairs
        int ans = 0;
        // Iterator
        int pointer = 0;
        int n = s.length();
        /*
        Move the pointer forward untill you see any repeted charecter,
        once you get a repeted charecter, you get your first substring,
        repeat this process again from that position but make the 
        visted array as all false.
        */
        while(pointer < n){
            if(visited[s[pointer] - 'a']){
                ans++;
                for(int i = 0; i < 26; i++){
                    visited[i] = false;
                }
            }
            visited[s[pointer] - 'a'] = true;
            pointer++;
        }
        ans++;
        return ans;
    }
};