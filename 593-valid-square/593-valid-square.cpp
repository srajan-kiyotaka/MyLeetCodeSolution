class Solution {
public:
    double distance(vector<int>& a, vector<int>& b){
        return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<double, int> map;
        map[distance(p1, p2)] = 1;
        if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4){
            return false;
        }
        if(map.find(distance(p2, p3)) != map.end()){
            map[distance(p2, p3)]++;
        }
        else{
            map[distance(p2, p3)] = 1;
        }
        if(map.find(distance(p3, p4)) != map.end()){
            map[distance(p3, p4)]++;
        }
        else{
            map[distance(p3, p4)] = 1;
        }
        if(map.find(distance(p1, p4)) != map.end()){
            map[distance(p1, p4)]++;
        }
        else{
            map[distance(p1, p4)] = 1;
        }
        if(map.find(distance(p1, p3)) != map.end()){
            map[distance(p1, p3)]++;
        }
        else{
            map[distance(p1, p3)] = 1;
        }
        if(map.find(distance(p2, p4)) != map.end()){
            map[distance(p2, p4)]++;
        }
        else{
            map[distance(p2, p4)] = 1;
        }
        if(map.size() != 2){
            return false;
        }
        else{
            for(auto i : map){
                return (i.second == 2) || (i.second == 4);
            }
        }
        return false;
    }
};