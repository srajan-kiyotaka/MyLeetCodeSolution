class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Iterativly check if the string contains the part
        // if yes, then remove it from the string and do the check again.
        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};