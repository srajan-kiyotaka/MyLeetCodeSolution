class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_size = s1.length();
        int s2_size = s2.length();
        if(s1_size > s2_size) return false;
        unordered_map<char, int> HashMap;
        for(int i = 0; i < s1_size; i++){
            if(HashMap.find(s1[i]) != HashMap.end()){
                HashMap[s1[i]] += 1;
                continue;
            }
            HashMap[s1[i]] = 1;
        }
        int n = s2_size - s1_size + 1;
        unordered_map<char, int> hashMap;
        // cout << s2 << endl;
        for(int i = 0; i < n; i++){
            cout << s2[i] << endl;
            if(HashMap.find(s2[i]) != HashMap.end()){
                int m = 0;
                hashMap = HashMap;
                // cout << s2[i] << endl;
                for(int j = 0; j < s1_size; j++){
                    if(hashMap.find(s2[j + i]) != hashMap.end() && hashMap[s2[j + i]] != 0){
                        hashMap[s2[j + i]] -= 1;
                        m++;
                        continue;
                    }
                    break;
                }
                if(m == s1_size) return true;
            }
        }
        return false;

    }
};