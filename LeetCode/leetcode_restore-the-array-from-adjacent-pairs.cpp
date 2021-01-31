/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        if(adjacentPairs.size() == 0) {
            return {};
        }
        
        int n = adjacentPairs.size() + 1;
        unordered_map<int,int> ndDeg;
        unordered_map<int,vector<int>> g;
        for(vector<int> p : adjacentPairs) {
            int u = p[0], v = p[1];
            ++ ndDeg[v], ++ ndDeg[u];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int s = 0;
        for(auto it = ndDeg.begin(); it != ndDeg.end(); it ++) {
            if(it->second == 1) {
                s = it->first;
                break;
            }
        }
        
        vector<int> ans(n, -1);
        unordered_set<int> vis;
        bool isFound = false;
        dfs(s, g, vis, ans, 0, isFound, n);
        return ans;
    }
private:
    void dfs(int u, unordered_map<int,vector<int>> &g, unordered_set<int> &vis, vector<int> &ans, int tot, bool &isFound, int n) {
        vis.insert(u);
        ans[tot] = u;
        if(tot >= n) {
            isFound = true;
            return ;
        }
        
        for(int v : g[u]) {
            if(vis.count(v) > 0) {
                continue;
            }
            
            dfs(v, g, vis, ans, tot + 1, isFound, n);
            if(isFound) {
                break;
            }
            vis.erase(v);
        }
        return ;
    }
};
