/*
*
* Tag: DFS + Dijka
* Time: O(mlgn)
* Space: O(n^2)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0 || n < 1) {
            return 0;
        }
        
        vector<vector<pair<long long,int>>> graph(n+1,vector<pair<long long,int>>{});
        vector<long long> dist(n+1,INT_MAX);
        dist[n]=0;
        for (vector<int> &edge:edges) {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push(make_pair(dist[n],n));
        while (!pq.empty()) {
            pair<long long,int> p=pq.top(); 
            pq.pop();
            int u=p.second;
            for (pair<long long,int> &nxt:graph[u]) {
                int v=nxt.first, w=nxt.second;
                if (dist[v]>dist[u]+w) {
                    dist[v]=dist[u]+w;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        vector<int> dp(n+1,-1);
        dp[n] = 1;
        return dfs(graph, dp,dist,1,n,INT_MAX);
    }
    
    int dfs(vector<vector<pair<long long,int>>> &graph, vector<int> &dp, vector<long long> &dist, int u, int n, long long prev) {
        if(dist[u]>=prev) {
            return 0;
        }
        if(dp[u]>=0) {
            return dp[u];
        }
        int res = 0;
        for (pair<long long,int> &v:graph[u]) {
            res=(res+dfs(graph,dp,dist,v.first,n,dist[u])%MOD)%MOD;
        }
        dp[u] = res;
        return res;
    }
};
