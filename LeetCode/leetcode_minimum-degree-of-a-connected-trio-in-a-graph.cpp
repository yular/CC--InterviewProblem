/*
*
* Tag: Graph
* Time: O(n^3)
* Space: O(n^2)
*/

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        if(edges.size() < 3 || n < 3) {
            return -1;
        }
        
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
        vector<vector<int>> adjG(n + 1, vector<int>(0));
        vector<int> degCnt(n + 1, 0);
        for(vector<int> e : edges) {
            g[e[0]][e[1]] = g[e[1]][e[0]] = true;
            ++ degCnt[e[0]], ++ degCnt[e[1]];
            adjG[e[0]].push_back(e[1]);
            adjG[e[1]].push_back(e[0]);
        }
        
        int ans = INT_MAX;
        for(int u = 1; u <= n; ++ u) {
            if(adjG[u].size() < 2) {
                continue;
            }
            
            for(int i = 0; i < adjG[u].size(); ++ i) {
                int v1 = adjG[u][i];
                for(int j = i + 1; j < adjG[u].size(); ++ j){
                    int v2 = adjG[u][j];
                    if(!g[v1][v2]) {
                        continue;
                    }
                    
                    ans = min(ans, degCnt[u] + degCnt[v1] + degCnt[v2] - 6);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
