class Solution {
public:
    int countSegments(string s) {
        string token;
        stringstream split(s);
        int i = 0;
        while(getline(split, token, ' ')){
            if(token != "")
                i++;
        }
        return i;
    }
};