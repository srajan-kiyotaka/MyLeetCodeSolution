class Solution {
public:
    int kthFactor(int n, int k) {
        int temp = 1;
        while(temp <= n){
            if(n % temp == 0){
                k--;
                if(k == 0){
                    return temp;
                }
            }
            temp++;
        }
        return -1;
    }
};