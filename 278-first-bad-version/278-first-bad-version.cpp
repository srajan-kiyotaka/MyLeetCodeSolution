// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int h = n;
        long long mid  = (l/2 + h/2 + (l%2 + h%2)/2);
        while(l <= h){
            mid = (l/2 + h/2 + (l%2 + h%2)/2);
            if(isBadVersion(mid)){
                h = mid;
                if(isBadVersion(mid - 1)) h--;
                else return mid;
            }
            else{
                l = mid;
                if(!isBadVersion(mid + 1)) l++;
                else return mid + 1; 
            }
        }
        return mid;
    }
};