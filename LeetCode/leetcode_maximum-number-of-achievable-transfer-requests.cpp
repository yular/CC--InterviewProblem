/*
*
* Tag: DFS + DP
* Time: O(nm + (m^2)*(2^m)) n is the number of buildings, and m is the number of requests
* Space: O(nm + 2^m)
*/

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        if(n == 0 || requests.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        unordered_map<int, vector<pair<int,int>>> g;
        for(int i = 0; i < requests.size(); ++ i) {
            int u = requests[i][0], v = requests[i][1];
            if(u == v) {
                ++ ans;
                continue;
            }
            g[u].push_back(make_pair(v, i));
        }
        
        unordered_set<int> cirset;
        for(int i = 0; i < n; ++ i){
            vector<bool> vis(n, false);
            int edgeset = 0;
            dfs(i, i, edgeset, 0, vis, g, cirset);
        }
        
        int m = cirset.size(), tot = (1<<requests.size());
        vector<bool> dp(tot + 1, false);
        dp[0] = true;
        auto it = cirset.begin();
        for(int i = 0; i < m; ++ i, it ++) {
            int mask = *it;
            for(int j = tot; j >= mask; -- j){
                if((j&mask) != mask) {
                    continue;
                }
                
                int v = (j^mask);
                dp[j] = (dp[j]|dp[v]);
            }
        }
        
        int maxVal = 0;
        for(int i = 1; i <= tot; ++ i){
            if(!dp[i]) {
                continue;
            }
            maxVal = max(maxVal, getBitCnt(i));
        }
        ans += maxVal;
        return ans;
    }
private:    
    void dfs(int u, int start, int &edgeset, int edgecnt, vector<bool> &vis, unordered_map<int, vector<pair<int,int>>> &g, unordered_set<int> &cirset) {
        vis[u] = true;
        if(start == u && edgecnt > 0){
            if(cirset.count(edgeset) == 0) {
                cirset.insert(edgeset);
            }
            return ;
        }
        
        for(pair<int,int> edge : g[u]){
            int v = edge.first, id = (1<<edge.second);
            if(vis[v] && v != start) {
                continue;
            }
            
            edgeset ^= id;
            dfs(v, start, edgeset, edgecnt + 1, vis, g, cirset);
            edgeset ^= id;
        }
        vis[u] = false;
        return ;
    }
    
    int getBitCnt(int v) {
        int res = 0;
        for(; v > 0; v >>= 1) {
            if((v&1) > 0) {
                ++ res;
            }
        }
        return res;
    }
};
