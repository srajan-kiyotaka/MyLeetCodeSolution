class Solution {
public:
    bool solutionExits(vector<int>& piles, int h, int ans){
        int currentPile = 0;
        int totalTime = 0;
        for(int i = 0; i < piles.size(); i++){
            totalTime += (piles[i] % ans == 0)?(piles[i]/ans):(piles[i]/ans + 1);
            if(totalTime > h) return false;
        }
        return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        // Search space: 1 -- max(piles)
        // Binary Search Problem
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int mid = s + (e - s)/2;
        int ans = -1;
        while(s <= e){
            if(solutionExits(piles, h, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e - s)/2;
        }
        return ans;
    }
};