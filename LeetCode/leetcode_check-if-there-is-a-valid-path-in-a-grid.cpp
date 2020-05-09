/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return true;
        }
        
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++ i) {
                int nxt_r = cur.first + dir[i][0], nxt_c = cur.second + dir[i][1];
                if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || vis[nxt_r][nxt_c] || !isAccessible(grid[cur.first][cur.second], i, grid[nxt_r][nxt_c])) {
                    continue;
                }
                
                vis[nxt_r][nxt_c] = true;
                if(nxt_r == n - 1 && nxt_c == m - 1) {
                    break;
                }
                q.push(make_pair(nxt_r, nxt_c));
            }
        }
        return vis[n - 1][m - 1];
    }
private:
    bool isAccessible(int cur, int d, int nxt) {
        switch(cur) {
            case 1:
                if(d == 0 || d == 2) {
                    return false;
                }
                if(d == 1 && (nxt == 1 || nxt == 3 || nxt == 5)) {
                    return true;
                }
                if(d == 3 && (nxt == 1 || nxt == 4 || nxt == 6)) {
                    return true;
                }
                return false;
            case 2:
                if(d == 1 || d == 3) {
                    return false;
                }
                if(d == 0 && (nxt == 2 || nxt == 3 || nxt == 4)) {
                    return true;
                }
                if(d == 2 && (nxt == 2 || nxt == 5 || nxt == 6)) {
                    return true;
                }
                return false;
            case 3:
                if(d == 0 || d == 1) {
                    return false;
                }
                if(d == 2 && (nxt == 2 || nxt == 5 || nxt == 6)) {
                    return true;
                }
                if(d == 3 && (nxt == 1 || nxt == 4 || nxt == 6)) {
                    return true;
                }
                return false;
            case 4:
                if(d == 0 || d == 3) {
                    return false;
                }
                if(d == 1 && (nxt == 1 || nxt == 3 || nxt == 5)) {
                    return true;
                }
                if(d == 2 && (nxt == 2 || nxt == 5 || nxt == 6)) {
                    return true;
                }
                return false;
            case 5:
                if(d == 1 || d == 2) {
                    return false;
                }
                if(d == 0 && (nxt == 2 || nxt == 3 || nxt == 4)) {
                    return true;
                }
                if(d == 3 && (nxt == 1 || nxt == 4 || nxt == 6)) {
                    return true;
                }
                return false;
            case 6:
                if(d == 2 || d == 3) {
                    return false;
                }
                if(d == 0 && (nxt == 2 || nxt == 3 || nxt == 4)) {
                    return true;
                }
                if(d == 1 && (nxt == 1 || nxt == 3 || nxt == 5)) {
                    return true;
                }
                return false;
        }
        return false;
    }
};
