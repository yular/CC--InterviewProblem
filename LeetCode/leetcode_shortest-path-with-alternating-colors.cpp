/*
*
* Tag: BFS
* Time: O(n + m)
* Space: O(n + m)
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        if(n == 0){
            return {};
        }
        
        unordered_map<int,vector<pair<int,int>>> g;
        for(vector<int> edge : red_edges) {
            g[edge[0]].push_back(make_pair(edge[1], 0));
        }
        for(vector<int> edge : blue_edges) {
            g[edge[0]].push_back(make_pair(edge[1], 1));
        }
        
        vector<vector<int>> dis(n, vector<int>(2, INT_MAX));
        dis[0][0] = dis[0][1] = 0;
        
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        q.push(make_pair(0, 1));
        
        vector<int> ans(n, -1);
        ans[0] = 0;
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            
            int u = cur.first, c = cur.second;
            for(pair<int,int> nxt : g[u]) {
                int v = nxt.first, nc = nxt.second;
                if(c == nc || dis[u][c] + 1 >= dis[v][nc]) {
                    continue;
                }
                
                dis[v][nc] = dis[u][c] + 1;
                q.push(make_pair(v, nc));
                ans[v] = ans[v] == -1 ? dis[v][nc] : min(ans[v], dis[v][nc]);
            }
        }        
        return ans;
    }
};
