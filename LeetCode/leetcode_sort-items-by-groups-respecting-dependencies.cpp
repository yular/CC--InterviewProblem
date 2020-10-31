/*
*
* Tag: Graph, Topological Sort
* Time: O(n + N) N is the length of beforeItems
* Space: O(n + N)
*/

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> emptyAns;
        if(n == 0 || m == 0) {
            return emptyAns;
        }
        
        int gIdx = m;
        unordered_map<int,vector<int>> gDict;
        for(int i = 0; i < n; ++ i) {
            if(group[i] == -1) {
                group[i] = gIdx ++;
            }
            int k = group[i];
            gDict[k].push_back(i);
        }
        
        vector<int> gDeg(gIdx, -1), itemDeg(n, 0);
        vector<vector<int>> g(n, vector<int>(0));
        unordered_map<int,unordered_set<int>> gpG;
        for(int i = 0; i < beforeItems.size(); ++ i) {
            int u = group[i];
            if(gDeg[u] < 0) {
                gDeg[u] = 0;
            }
            for(int j = 0; j < beforeItems[i].size(); ++ j) {
                int v = group[beforeItems[i][j]];
                if(gDeg[v] < 0) {
                    gDeg[v] = 0;
                }
                ++ itemDeg[i];
                
                if(u != v && gpG[v].count(u) == 0) {
                    ++ gDeg[u];
                    gpG[v].insert(u);
                }
                g[beforeItems[i][j]].push_back(i);
            }
        }
        
        queue<int> q;
        for(int i = 0; i < gIdx; ++ i) {
            if(gDeg[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans(n, 0);
        int ansIdx = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            if(!canSortItems(itemDeg, gDeg, u, gDict, g, group, ans, ansIdx)) {
                return emptyAns;
            }
            
            for(int v : gpG[u]) {
                -- gDeg[v];
                if(gDeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ansIdx < n ? emptyAns : ans;
    }
    
private:
    bool canSortItems(vector<int> &itemDeg, vector<int> &gDeg, int gId, unordered_map<int,vector<int>> &gDict, vector<vector<int>> &g, vector<int>& group, vector<int> &ans, int &ansIdx) {
        queue<int> q;
        for(int i : gDict[gId]) {
            if(itemDeg[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans[ansIdx ++] = u;
            ++ cnt;
            
            for(int v : g[u]) {
                -- itemDeg[v];
                int vGId = group[v];
                if(gId != vGId) {
                    continue;
                }
                
                if(itemDeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return cnt == gDict[gId].size();
    }
};
