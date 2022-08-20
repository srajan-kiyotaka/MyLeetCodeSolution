class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0;
        int j = 0;
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < g.size() && j < s.size()){
            while(j < s.size() && g[i] > s[j]){j++;}
            if(j < s.size())
                count++;
            i++;j++;
        }
        return count;
    }
};