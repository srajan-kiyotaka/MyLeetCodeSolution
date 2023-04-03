class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        // sort the peoples weights
        sort(people.begin(), people.end());
        int pairs = 0;
        // find the maximum number of pairs where the sum 
        // of the weights is less then or equal to limits.
        int i = 0;
        int j = n - 1;
        while(i < j){
            if(people[i] + people[j] <= limit){
                pairs++;
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        return (n - pairs);
    }
};