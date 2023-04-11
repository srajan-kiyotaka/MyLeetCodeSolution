class Solution {
public:
    string removeStars(string s) {
        // Two Pointer Approch
        // More Optimized
        // Time Complexity: O(n)
        // Space Complexity: O(1)
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '*'){
                s[j] = s[i];
                j++;
            }
            else{
                j--;
            }
        }
        return s.substr(0, j);
    }
};

/*
    Using Stack

-> Time Complexity: O(n)
-> Space Complexity: O(n)

string removeStars(string s) {
        stack<char> stk;
        bool flag = true;
        // O(n)
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                stk.pop();
                flag = false;
            }
            else{
                stk.push(s[i]);
            }
        }
        if(flag) return s;
        // Construct the string
        s.erase();
        while(!stk.empty()){
            s = stk.top() + s;
            stk.pop();
        }
        return s;
    }

*/

/*
    done using erase opperator
    Time Complexity: O(n^2)

string removeStars(string s) {
        int i = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] != '*'){i++;}
            int j = i;
            while(j < s.length() && s[j] == '*'){j++;}
            s.erase((2*i-j), 2*(j-i));
            i = 2*i - j;
        }
        return s;
    }

*/