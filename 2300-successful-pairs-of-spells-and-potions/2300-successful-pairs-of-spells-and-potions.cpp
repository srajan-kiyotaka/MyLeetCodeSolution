class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        // sort the postions array
        sort(potions.begin(), potions.end());
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            int lowIndex = m;
            int s = 0;
            int e = m - 1;
            int mid = s + (e - s)/2;
            while(s <= e){
                if((1ll)*spells[i]*potions[mid] >= success){
                    lowIndex = mid;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
                mid = s + (e - s)/2;
            }

            ans[i] = m - lowIndex;
        }
        return ans;
    }
};