class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;
        double mini = INT_MAX;
        double maxi = INT_MIN;
        for(int i = 0; i < salary.size(); i++){
            ans += salary[i];
            if(mini > salary[i]){
                mini = salary[i];
            }
            if(maxi < salary[i]){
                maxi = salary[i];
            }
        }
        double avg = ((ans - mini - maxi)/(salary.size() - 2));
        return avg;
    }
};