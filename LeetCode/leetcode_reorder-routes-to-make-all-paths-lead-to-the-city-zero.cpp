/*
*
* Tag: BFS
* Time: O(n + m) where n is the number of nodes, and m is the number of edges
* Space: O(n + m)
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> g(n);
        for(vector<int> conn : connections) {
            g[conn[0]].push_back(make_pair(conn[1], 1));
            g[conn[1]].push_back(make_pair(conn[0], 0));
        }
        
        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        
        int ans = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(pair<int,int> edge : g[u]) {
                int v = edge.first;
                if(vis[v]) {
                    continue;
                }
                
                ans += edge.second;
                q.push(v);
                vis[v] = true;
            }
        }
        return ans;
    }
};
