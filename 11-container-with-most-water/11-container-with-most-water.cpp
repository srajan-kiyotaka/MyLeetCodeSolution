class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans, l, r ;
        ans = 0; l = 0;
        r = height.size() - 1;
        while(l < r){
            ans = max(ans, (r - l)*(min(height[r], height[l])));
            if(height[r] > height[l]) l++;
            else r--;
        }
        return ans;
    }
};