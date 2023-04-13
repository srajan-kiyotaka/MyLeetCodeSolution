class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Two pointer approch using a stack
        stack<int> s;
        int i = 0;
        int j = 0;
        int n = pushed.size();
        while(i < n && j < n){
            if((!s.empty()) && s.top() == popped[j]){
                s.pop();
                j++;
            }
            else{
                s.push(pushed[i]);
                i++;
            }        
        }
        while(j < n){
            if(s.top() == popped[j]){
                s.pop();
            }
            else{
                return false;
            }
            j++;
        }
        if(!s.empty()) return false;
        return true;
    }
};

/*

        stack<int> s;
        int n = pushed.size();
        for(int i = 0, j = 0; i < n; i++){
            s.push(pushed[i]);
            while(!s.empty() && j < n && popped[j] == s.top()){
                s.pop();
                j++;
            }
        }
        return s.empty();

*/