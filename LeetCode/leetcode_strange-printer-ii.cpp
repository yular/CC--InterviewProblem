/*
*
* Tag: Topological Sort
* Time: O(m*n^2)
* Space: O(1)
*/

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        if(targetGrid.size() == 0 || targetGrid[0].size() == 0) {
            return false;
        }
        
        int tot = 0, n = targetGrid.size(), m = targetGrid[0].size();
        vector<vector<int>> g(61);
        vector<int> indeg(61, -1);
        for(int c = 1; c <= 60; ++ c){
            int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
            
            for(int i = 0; i < n; ++ i) {
                for(int j = 0; j < m; ++ j) {
                    if(targetGrid[i][j] != c) {
                        continue;
                    }
                    
                    minx = min(i, minx);
                    miny = min(j, miny);
                    maxx = max(i, maxx);
                    maxy = max(j, maxy);
                }
            }
            
            if(minx == INT_MAX) {
                continue;
            }
            if(indeg[c] == -1){
                indeg[c] = 0;
            }
                
            ++ tot;
            for(int i = minx; i <= maxx; ++ i) {
                for(int j = miny; j <= maxy; ++ j) {
                    if(targetGrid[i][j] == c) {
                        continue;
                    }
                    
                    int u = targetGrid[i][j];
                    g[u].push_back(c);
                    if(indeg[c] == -1) {
                        indeg[c] = 0;
                    }
                    ++ indeg[c];
                }
            }
        }
        
        unordered_set<int> vis;
        queue<int> q;
        for(int i = 1; i <= 60; ++ i){
            if(indeg[i] == 0) {
                vis.insert(i);
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis.insert(u);
            
            for(int v : g[u]) {
                -- indeg[v];
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return vis.size() == tot;
    }
};
