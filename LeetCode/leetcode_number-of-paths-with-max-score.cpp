/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
    int dir[3][2] = {{0, 1}, {1, 0}, {1, 1}};
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        if(board.size() == 0) {
            return {0, 0};
        }
        
        int n = board.size(), m = board[0].size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0)), pathCnt(n + 1, vector<long long>(m + 1, 0));
        pathCnt[n - 1][m - 1] = 1;
        for(int i = n - 1; i >= 0; -- i) {
            for(int j = m - 1; j >= 0; -- j) {
                if(board[i][j] == 'S' || board[i][j] == 'X') {
                    continue;
                }
                
                for(int k = 0; k < 3; ++ k) {
                    long long v = 0;
                    if(board[i][j] != 'E') {
                        v = board[i][j] - '0';
                    }
                    
                    long long sum = v;
                    int r = i + dir[k][0], c = j + dir[k][1];
                    if(r >= n || c >= m) {
                        continue;
                    }
                    
                    sum += dp[r][c];
                    if(dp[i][j] < sum) {
                        dp[i][j] = sum;
                        pathCnt[i][j] = pathCnt[r][c];
                    } else if(dp[i][j] == sum) {
                        pathCnt[i][j] = (pathCnt[i][j] + pathCnt[r][c])%MOD;
                    }
                }
                
                if(pathCnt[i][j] == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        return {(int)dp[0][0], (int)pathCnt[0][0]};
    }
};
