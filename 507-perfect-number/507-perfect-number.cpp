class Solution {
public:
    // vector<int> findDiv(int num){
    //     vector<int> ans;
    //     ans.push_back(1);
    //     int temp = 2;
    //     while(temp <= sqrt(num)){
    //         if(num % temp == 0){
    //             if(temp == num/temp) ans.push_back(temp);
    //             else{
    //                 ans.push_back(temp);
    //                 ans.push_back(num/temp);
    //             }
    //         }
    //         temp++;
    //     }
    //     return ans;
    // }
    
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int ans = 1;
        int temp = 2;
        while(temp <= sqrt(num)){
            if(num % temp == 0){
                if(temp == num/temp) ans += temp;
                else{
                    ans += temp;
                    ans += num/temp;
                }
            }
            temp++;
        }
        
        // vector<int> ans = findDiv(num);
        // cout << accumulate(ans.begin(), ans.end(), 0) << endl;
        if(num == ans) return true;
        return false;
    }
};