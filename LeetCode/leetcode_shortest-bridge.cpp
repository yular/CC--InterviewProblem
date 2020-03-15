/*
*
* Tag: DFS + BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int shortestBridge(vector<vector<int>>& A) {
        if(A.size() == 0) {
            return 0;
        }
        
        
        int n = A.size(), m = A[0].size();
        vector<vector<int>> mp(n, vector<int>(m, 0)), dis(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;
        int partyIdx = 1;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(A[i][j] == 0 || mp[i][j] != 0){
                    continue;
                }
                
                dfs(i, j, A, mp, dis, q, partyIdx);
                ++ partyIdx;
            }
        }
        
        int ans = INT_MAX;
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            
            int d = dis[cur.first][cur.second]; 
            for(int i = 0; i < 4; ++ i){
                int nxt_r = cur.first + dir[i][0], nxt_c = cur.second + dir[i][1];
                if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || dis[nxt_r][nxt_c] <= d + 1 || mp[nxt_r][nxt_c] == 1){
                    continue;
                }
                
                dis[nxt_r][nxt_c] = d + 1;
                if(mp[nxt_r][nxt_c] == 2) {
                    ans = min(ans, d + 1);
                    continue;
                }
                q.push(make_pair(nxt_r, nxt_c));
            }
        }
        return ans - 1;
    }
private:
    void dfs(int r, int c, vector<vector<int>>& a, vector<vector<int>> &mp, vector<vector<int>> &dis, queue<pair<int,int>> &q, int partyIdx) {
        mp[r][c] = partyIdx;
        if(partyIdx == 1) {
            dis[r][c] = 0;
            q.push(make_pair(r, c));
        }
        int n = a.size(), m = a[0].size();
        for(int i = 0; i < 4; ++ i) {
            int nxt_r  = r + dir[i][0], nxt_c = c + dir[i][1];
            if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || a[nxt_r][nxt_c] == 0 || mp[nxt_r][nxt_c] > 0) {
                continue;
            }
            dfs(nxt_r, nxt_c, a, mp, dis, q, partyIdx);
        }
        return ;
    }
};
