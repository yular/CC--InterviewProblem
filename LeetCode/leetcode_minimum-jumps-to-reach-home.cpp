/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0) {
            return 0;
        }
        
        int n = x + b + 2000;
        vector<vector<int>> dp(n, vector<int>(2, n));
        dp[0][0] = dp[0][1] = 0;
        
        vector<bool> blocks(n, false);
        for(int f : forbidden) {
            if(f >= n) {
                continue;
            }
            blocks[f] = true;
        }
        
        queue<vector<int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            
            int nxt = cur[0] + a;
            if(nxt < n && dp[cur[0]][cur[1]] + 1 < dp[nxt][0] && !blocks[nxt]) {
                dp[nxt][0] = dp[cur[0]][cur[1]] + 1;
                q.push({nxt, 0});
            }
            if(cur[1] == 1) {
                continue;
            }
            
            nxt = cur[0] - b;
            if(nxt > 0 && dp[cur[0]][0] + 1 < dp[nxt][1] && !blocks[nxt]) {
                dp[nxt][1] = dp[cur[0]][0] + 1;
                q.push({nxt, 1});
            }
        }
        
        int ans = min(dp[x][0], dp[x][1]);
        return ans == n ? -1 : ans;
    }
};
