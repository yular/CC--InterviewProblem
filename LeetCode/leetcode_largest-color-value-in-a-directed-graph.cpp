/*
*
* Tag: Topological Sort
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);
        for(int i = 0; i < edges.size(); ++ i){
            g[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++ i){
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(26, 0));
        int ans = 0, cnt = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ++ cnt;
            
            ++ dp[u][colors[u]-'a'];
            for(int i = 0; i < 26; ++ i){
                ans = max(ans, dp[u][i]);
            }
            for(int v : g[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
                for(int j = 0; j < 26; ++ j){
                    dp[v][j] = max(dp[v][j], dp[u][j]);
                }
            }
        }
        if(cnt < n) {
            return -1;
        }
        return ans;
    }
};
