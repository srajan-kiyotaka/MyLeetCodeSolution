class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        string temp ;
        for(auto i : strs){
            temp = i;
            sort(i.begin(), i.end());
            map[i].push_back(temp);
        }
        
        for(auto itr = map.begin(); itr != map.end(); itr++){
            ans.push_back(itr->second);
        }
        return ans;
    }
};