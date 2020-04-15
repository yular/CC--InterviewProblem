/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        if(quiet.size() == 0) {
            return {};
        }
        
        unordered_map<int,vector<int>> g;
        for(vector<int> rich : richer) {
            g[rich[1]].push_back(rich[0]);
        }
        
        int n = quiet.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; ++ i){
            vector<bool> vis(n, false);
            int q = quiet[i], id = i;
            dfs(i, vis, g, q, id, quiet, ans);
            ans[i] = id;
        }
        return ans;
    }
private:
    void dfs(int u, vector<bool> &vis, unordered_map<int,vector<int>> &g, int &q, int &id, vector<int>& quiet, vector<int> &ans) {
        if(ans[u] != 0){
            if(q > quiet[ans[u]]) {
                q = quiet[ans[u]];
                id = ans[u];
            }
            return ;
        }
        vis[u] = true;
        for(int v : g[u]) {
            if(vis[v]) {
                continue;
            }
            if(q > quiet[v]) {
                q = quiet[v];
                id = v;
            }
            dfs(v, vis, g, q, id, quiet, ans);
        }
        return ;
    }
};
