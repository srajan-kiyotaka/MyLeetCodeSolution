class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int i = 0;
        while(intervals[i][0] < newInterval[1]){
            i++;
            if(i == intervals.size()){
                i--;
                break;
            }
        }

        int j = 0;
        while(intervals[j][1] < newInterval[0]){
            j++;
            if(j == intervals.size()){
                j--;
                break;
            }
        }

        if(i == j){
            if(i == intervals.size() - 1){
                if(intervals[i][1] < newInterval[0]){
                    intervals.insert(intervals.end(), newInterval);
                    return intervals;
                }
            }
            if(intervals[i][0] > newInterval[1]){
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
            else{
                intervals[i][0] = min(intervals[i][0], newInterval[0]);
                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                return intervals;
            }
        }
        else{
            if(newInterval[1] < intervals[i][0]){
                i--;
                if(i == j){
                    if(intervals[i][0] > newInterval[1]){
                        intervals.insert(intervals.begin() + i, newInterval);
                        return intervals;
                    }
                    else{
                        intervals[i][0] = min(intervals[i][0], newInterval[0]);
                        intervals[i][1] = max(intervals[i][1], newInterval[1]);
                        return intervals;
                    }
                }
                else{
                    intervals[j][0] = min(intervals[j][0], newInterval[0]);
                    intervals[j][1] = max(intervals[i][1], newInterval[1]);
                    intervals.erase(intervals.begin() + j + 1, intervals.begin() + i + 1);
                    return intervals;
                }
            }
            else{
                intervals[j][0] = min(intervals[j][0], newInterval[0]);
                intervals[j][1] = max(intervals[i][1], newInterval[1]);
                intervals.erase(intervals.begin() + j + 1, intervals.begin() + i + 1);
            }
        }

        return intervals;
    }
};