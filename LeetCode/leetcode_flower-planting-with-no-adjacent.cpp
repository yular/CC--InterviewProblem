/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        if(n == 0) {
            return {};
        }
        
        unordered_map<int,vector<int>> g;
        for(vector<int> path: paths) {
            g[path[0]].push_back(path[1]), g[path[1]].push_back(path[0]);
        }
        
        vector<int> ans(n, 0);
        for(int i = 1; i <= n; ++ i) {
            if(ans[i - 1] == 0) {
                dfs(i, ans, g);
            }
        }
        
        return ans;
    }
private:
    void dfs(int u, vector<int> &ans, unordered_map<int,vector<int>> &g) {
        vector<bool> color(5, false);
        for(int v : g[u]) {
            if(ans[v - 1] != 0) {
                color[ans[v - 1]] = true;
            }
        }
        
        for(int i = 1; i <= 4; ++ i) {
            if(color[i] == false) {
                ans[u - 1] = i;
                break;
            }
        }
        
        for(int v : g[u]) {
            if(ans[v - 1] == 0) {
                dfs(v, ans, g);
            }
        }
        return ;
    }
};
