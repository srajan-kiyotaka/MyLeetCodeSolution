class Solution {
public:
    string interpret(string command) {
        string ans;
        for(int i = 0; i < command.length();){
            if(command[i] == 'G'){
                ans += command[i++];
            }
            else if(command[i] == '(' && command[i+1] == ')'){
                ans += 'o';
                i = i + 2;
            }
            else{
                ans += "al";
                i = i + 4;
            }
        }
        return ans;
    }
};