class Solution {
public:
    bool compHash(vector<int>& a, vector<int>& b){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        // Sliding Window approch
        if(s1.length() > s2.length()) return false;
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for(int i = 0; i < s1.length(); i++){
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        
        // First Window
        if(compHash(hash1, hash2)) return true;

        // For the remaining windows
        for(int i = 1; i <= s2.length() - s1.length(); i++){
            hash2[s2[i - 1] - 'a']--;
            hash2[s2[i + s1.length() - 1] - 'a']++;
            // cout << s2[i - 1] << ", " << s2[i + s1.length() - 1] << endl;
            if(compHash(hash1, hash2)) return true;
        }
        return false;
    }
};

/*

bool checkPermutation(string a, string b, vector<int> hash){
        for(int i = 0; i < a.length(); i++){
            if(hash[b[i] - 'a'] == 0) return false;
            hash[b[i] - 'a']--;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // Sliding Window approch
        if(s1.length() > s2.length()) return false;
        vector<int> hash(26, 0);
        for(int i = 0; i < s1.length(); i++){
            hash[s1[i] - 'a']++;
        }
        // First Window
        string w = s2.substr(0, s1.length());
        if(checkPermutation(s1, w, hash)) return true;

        for(int i = 1; i <= s2.length() - s1.length(); i++){
            w = w.erase(0, 1);
            w.push_back(s2[i + s1.length() - 1]);
            if(checkPermutation(s1, w, hash)) return true;
        }
        return false;
    }

*/


// int s1_size = s1.length();
//         int s2_size = s2.length();
//         if(s1_size > s2_size) return false;
//         unordered_map<char, int> HashMap;
//         for(int i = 0; i < s1_size; i++){
//             if(HashMap.find(s1[i]) != HashMap.end()){
//                 HashMap[s1[i]] += 1;
//                 continue;
//             }
//             HashMap[s1[i]] = 1;
//         }
//         int n = s2_size - s1_size + 1;
//         unordered_map<char, int> hashMap;
//         // cout << s2 << endl;
//         for(int i = 0; i < n; i++){
//             cout << s2[i] << endl;
//             if(HashMap.find(s2[i]) != HashMap.end()){
//                 int m = 0;
//                 hashMap = HashMap;
//                 // cout << s2[i] << endl;
//                 for(int j = 0; j < s1_size; j++){
//                     if(hashMap.find(s2[j + i]) != hashMap.end() && hashMap[s2[j + i]] != 0){
//                         hashMap[s2[j + i]] -= 1;
//                         m++;
//                         continue;
//                     }
//                     break;
//                 }
//                 if(m == s1_size) return true;
//             }
//         }
//         return false;