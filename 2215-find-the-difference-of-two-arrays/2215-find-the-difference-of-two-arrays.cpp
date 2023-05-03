class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        // O(n) Time Complexity
        // Use hash map
        unordered_map<int, bool> hash_1;
        unordered_map<int, bool> hash_2;
        // travels both the arrays
        for(auto it : nums1){
            hash_1[it] = true;
        }
        for(auto it : nums2){
            hash_2[it] = true;
        }
        // find the difference in array 1
        for(auto it : nums1){
            if(hash_2.find(it) == hash_2.end()){
                answer[0].push_back(it);
                hash_2[it] = true;
            }
        }
        // find the difference in array 2
        for(auto it : nums2){
            if(hash_1.find(it) == hash_1.end()){
                answer[1].push_back(it);
                hash_1[it] = true;
            }
        }
        return answer;
    }
};