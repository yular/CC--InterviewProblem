/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if(board.size() == 0) {
            return 0;
        }
        
        int n = board.size(), m = board[0].size(), idx = 1;
        unordered_map<int,pair<int,int>> dic;
        for(int i = n - 1, op = 0; i >= 0; -- i, op = (op + 1)%2) {
            int y = 0;
            if(op == 1) {
                y = m - 1;
            }
            for(int j = 0; j < m; ++ j) {
                dic[idx ++] = make_pair(i, y);
                if(op == 0) {
                    ++ y;
                } else {
                    -- y;
                }
            }
        }
        
        int dst = n*m, tot = n*m + 2;
        vector<int> dis(tot, INT_MAX);
        dis[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int i = 1; i < 7; ++ i) {
                int nxt = cur + i;//, v = i == 0? 0 : 1;
                if(nxt > dst) {
                    break;
                }
                int r = dic[nxt].first, c = dic[nxt].second;
                if(board[r][c] != -1) {
                    nxt = board[r][c];
                }
                
                if(dis[nxt] > dis[cur] + 1) {
                    dis[nxt] = dis[cur] + 1;
                    q.push(nxt);
                }
            }
            if(dis[dst] != INT_MAX) {
                break;
            }
        }
        
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};
