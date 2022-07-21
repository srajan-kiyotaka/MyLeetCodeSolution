class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> map;
        double slop;
        int maxi = 0;
        int i_maxi = 0;
        int n = points.size();
        for(int i = 0; i < n- 1 - maxi; i++){
            i_maxi = 0;
            for(int j = i + 1; j < n; j++){
                if(points[i][0] - points[j][0] == 0) slop = INT_MAX;
                else{
                    slop = (double)(points[i][1] - points[j][1])/(double)(points[i][0] - points[j][0]);
                }
                if(map.find(slop) != map.end()){
                    map[slop]++;
                }
                else{
                    map[slop] = 1;
                }
                i_maxi = max(i_maxi, map[slop]);
            }
            map.erase(map.begin(), map.end());
            maxi = max(maxi, i_maxi);
        }
        return maxi + 1;
    }
};