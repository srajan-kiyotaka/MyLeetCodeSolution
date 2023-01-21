class Solution {
public:
    vector<string> result;

    void recursivefun(string& s, vector<int> pointer){
        if(pointer.size() == 3 && s.size() - (pointer[0] + pointer[1] + pointer[2]) > 0 && s.size() - (pointer[0] + pointer[1] + pointer[2]) <= 3){
            if(s.size() - (pointer[0] + pointer[1] + pointer[2]) > 1 && s[pointer[0] + pointer[1] + pointer[2]] == '0') return;
            if(stoi(s.substr(pointer[0] + pointer[1] + pointer[2], 3)) > 255) return ;
            string ans;
            ans = s.substr(0,pointer[0]) + "." + s.substr(pointer[0], pointer[1]) + "." + s.substr(pointer[0] + pointer[1], pointer[2]) + "." + s.substr(pointer[0] + pointer[1] + pointer[2], s.size() - (pointer[0] + pointer[1] + pointer[2]));
            result.push_back(ans);
            return;
        }

        else if(pointer.size() == 2){
            int temp = pointer[0] + pointer[1];
            if(s.size() - temp > 1){
                pointer.push_back(1);
                recursivefun(s, pointer);
                pointer.pop_back();
                if(s.size() - temp > 2 && s[temp] != '0'){
                    pointer.push_back(2);
                    recursivefun(s, pointer);
                    pointer.pop_back();
                }
                if(s.size() - temp > 3 && s[temp] != '0' && stoi(s.substr(temp, 3)) <= 255){
                    pointer.push_back(3);
                    recursivefun(s, pointer);
                } 
            }
        }

        else if(pointer.size() == 1){
            if(s.size() - pointer[0] > 1){
                pointer.push_back(1);
                recursivefun(s, pointer);
                pointer.pop_back();
            }
            if(s.size() - pointer[0] > 2 && s[pointer[0]] != '0'){
                pointer.push_back(2);
                recursivefun(s, pointer);
                pointer.pop_back();
            }
            if(s.size() - pointer[0] > 3 && s[pointer[0]] != '0' && stoi(s.substr(pointer[0], 3)) <= 255){
                pointer.push_back(3);
                recursivefun(s, pointer);
            }
        }

        else if(pointer.size() == 0){
            pointer.push_back(1);
            recursivefun(s, pointer);
            pointer.pop_back();
            if(s.size() > 2 && s[0] != '0'){
                pointer.push_back(2);
                recursivefun(s, pointer);
                pointer.pop_back();
            }
            if(s.size() > 3 && stoi(s.substr(0, 3)) <= 255 && s[0] != '0'){ 
                pointer.push_back(3);
                recursivefun(s, pointer);
            }
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12 || s.size() < 4) return result;
        vector<int> pointer;
        recursivefun(s, pointer);
        return result;
    }
};