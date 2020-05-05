/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n*n)
*/

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(edges.size() == 0) {
            if(target == 1) {
                return 1;
            }
            return 0;
        }
        
        unordered_map<int,vector<int>> g;
        for(vector<int> edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        vector<int> stk(n + 1, 0);
        vector<bool> vis(n + 1, false);
        int top = 0;
        dfs(1, g, stk, top, vis, 0, t, target);
        
        if(!vis[target] || (top - 1 < t && hasUnvistedChilren(g, target, vis))) {
            return 0;
        }
        
        double ans = 1;
        for(int i = 0; i < top - 1; ++ i) {
            int v = g[stk[i]].size();
            if(i > 0) {
                -- v;
            }
            if(v == 0) {
                v = 1;
            }
            ans *= 1.0/(double)v;
        }
        return ans;
    }
private:
    void dfs(int cur, unordered_map<int,vector<int>> &g, vector<int> &stk, int &top, vector<bool> &vis, int dep, int tot, int target) {
        stk[top ++] = cur;
        vis[cur] = true;
        
        if(dep >= tot || cur == target) {
            return ;
        }
        
        for(int v : g[cur]) {
            if(vis[v]) {
                continue;
            }
            
            dfs(v, g, stk, top, vis, dep + 1, tot, target);
            if(vis[target]) {
                return ;
            }
            -- top;
        }
        return ;
    }
    
    bool hasUnvistedChilren(unordered_map<int,vector<int>> &g, int u, vector<bool> &vis) {
        for(int v : g[u]) {
            if(!vis[v]) {
                return true;
            }
        }
        return false;
    }
};
