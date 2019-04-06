/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int ans = 0;
        if(A.size() == 0){
            return ans;
        }
        
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < m; ++ i) {
            if(A[0][i] == 1) {
                removeReachableLand(0,i,A);
            }
            if(A[n - 1][i] == 1) {
                removeReachableLand(n - 1, i, A);
            }
        }
        for(int i = 0; i < n; ++ i) {
            if(A[i][0] == 1) {
                removeReachableLand(i,0,A);
            }
            if(A[i][m - 1] == 1) {
                removeReachableLand(i, m - 1, A);
            }
        }
        
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(A[i][j] == 1){
                    ++ ans;
                }
            }
        }
        return ans;
    }
    
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void removeReachableLand(int r, int c, vector<vector<int>>& g){
        g[r][c] = 0;
        int n = g.size(), m = g[0].size();
        for(int i = 0; i < 4; ++ i){
            int nxtR = r + dir[i][0], nxtC = c + dir[i][1];
            if(nxtR >= 0 && nxtR < n && nxtC >= 0 && nxtC < m && g[nxtR][nxtC] == 1){
                removeReachableLand(nxtR, nxtC, g);
            }
        }
    }
};
