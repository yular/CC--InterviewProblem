/*
*
* Tag: DFS
* Time: O(m + nlgn)
* Space: O(n^2)
* Credit: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/discuss/1009613/O(n-log-n)-solution-with-explanation
*/

class Solution {
private:
    int N = 500;
public:
    int checkWays(vector<vector<int>>& pairs) {
        if(pairs.size() == 0) {
            return 0;
        }
        
        vector<int> edgeCnt(N, 0);
        vector<vector<int>> adj(N);
        vector<vector<bool>> isPair(N, vector<bool>(N, false));
        for(auto& p : pairs) {
            int u = p[0], v = p[1];
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            isPair[u][v] = isPair[v][u] = true;
            ++edgeCnt[u], ++edgeCnt[v];
        }
        
        int nodeCnt = 0, maxCnt = 0, root = -1;
        for(int i = 0; i < N; i++) {
            nodeCnt += edgeCnt[i] > 0;
            if(edgeCnt[i] > maxCnt) {
                maxCnt = edgeCnt[i];
                root = i;
            }
            sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
               return edgeCnt[a] > edgeCnt[b]; 
            });
            isPair[i][i] = true;
        }
        if(edgeCnt[root] != nodeCnt - 1) {
            return 0;
        }
        
        vector<bool> vis(N, false);
        bool multiWays = false;
        if(canConstructTree(root, root, vis, adj, isPair, edgeCnt, multiWays)) {
            return multiWays ? 2 : 1;
        }
        return 0;
    }
private:
    bool canConstructTree(int cur, int last, vector<bool> &vis, vector<vector<int>> &adj, vector<vector<bool>> &isPair, vector<int> &edgeCnt, bool &multiWays) {
         vis[cur] = true;
         for(int v : adj[cur]) {
             if(!isPair[last][v]) {
                 return false;
             }
             if(vis[v]) {
                 continue;
             }
             if(edgeCnt[cur] == edgeCnt[v]) {
                 multiWays = true;
             }
             if(!canConstructTree(v, cur, vis, adj, isPair, edgeCnt, multiWays)) {
                 return false;
             }
         }
         return true;
    }
};
