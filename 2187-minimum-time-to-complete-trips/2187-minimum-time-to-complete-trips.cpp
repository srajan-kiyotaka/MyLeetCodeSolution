class Solution {
public:
    bool checkSolution(vector<int>& time, int totalTrips, long long ans){
        long long result = 0;
        for(auto it : time){
            result += ans/it;
            if(result >= totalTrips) return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s = 1;
        auto it = max_element(time.begin(), time.end());
        long long e = static_cast<long long>(*it);
        e *= totalTrips;
        long long mid = s + (e - s)/2;
        long long ans = -1;
        while(s <= e){
            cout << "s = " << s << ", e = " << e << ", mid = " << mid << ", ans = " << ans << endl; 
            if(checkSolution(time, totalTrips, mid)){
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