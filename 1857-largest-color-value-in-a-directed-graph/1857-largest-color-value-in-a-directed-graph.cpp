class Solution {
public:
    int dfs(int i, string &c, vector<vector<int>> &al, vector<vector<int>> &cnt, vector<int> &visited) {
    if (!visited[i]) {
        visited[i] = 1;
        for (auto j : al[i]) {
            if (dfs(j, c, al, cnt, visited) == INT_MAX)
                return INT_MAX;
            for (auto k = 0; k < 26; ++k)
                cnt[i][k] = max(cnt[i][k], cnt[j][k]);
        }
        ++cnt[i][c[i] - 'a'];
        visited[i] = 2;
    }
    return visited[i] == 2 ? cnt[i][c[i] - 'a'] : INT_MAX;
}
int largestPathValue(string c, vector<vector<int>>& edges) {
    vector<vector<int>> al(c.size()), cnt(c.size(), vector<int>(26));
    vector<int> visited(c.size());
    for (auto &e : edges)
        al[e[0]].push_back(e[1]);
    int res = 0;
    for (auto i = 0; i < c.size() && res != INT_MAX; ++i)
        res = max(res, dfs(i, c, al, cnt, visited));
    return res == INT_MAX ? -1 : res;
}
};