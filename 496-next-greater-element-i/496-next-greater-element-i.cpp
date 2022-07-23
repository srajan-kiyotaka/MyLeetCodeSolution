class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        // vector<int> ans(nums1.size(), -1)
        for(int i = 0; i < nums1.size(); i++){
            map[nums1[i]] = i;
            nums1[i] = -1;
        }
        
        stack<int> st;
        
        for(int i = 0; i < nums2.size(); i++){
            if(st.empty()){
                if(map.find(nums2[i]) != map.end()){
                    st.push(nums2[i]);
                }
            }
            else{
                while(!st.empty() && st.top() < nums2[i]){
                    // cout << st.top() << endl;
                    // cout << map[st.top()] << endl;
                    // cout << nums1[map[st.top()]] << endl;
                    // cout << nums2[i] << endl;
                    nums1[map[st.top()]] = nums2[i];
                    st.pop();
                }
                
                if(map.find(nums2[i]) != map.end()){
                    st.push(nums2[i]);
                }
            }
        }
        
        return nums1;
    }
};