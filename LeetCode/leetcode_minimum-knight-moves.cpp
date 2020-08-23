/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    const int dir[8][2] = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
public:
    int minKnightMoves(int x, int y) {
        int ans = 0;
        if(x == 0 && y == 0){
            return ans;
        }
        if(x < 0) {
            x = -x;
        }
        if(y < 0){
            y = -y;
        }
        
        queue<vector<int>> q;
        vector<int> start = {0, 0, 0};
        q.push(start);
        unordered_map<int,unordered_set<int>> vis;
        vis[0].insert(0);
        
        while(!q.empty()){
            vector<int> cur = q.front();
            q.pop();
            
            vector<int> nxt = {0, 0, cur[2] + 1};
            for(int i = 0; i < 8; ++ i){
                int nxt_x = abs(cur[0] + dir[i][0]), nxt_y = abs(cur[1] + dir[i][1]);
                if(vis.count(nxt_x) != 0 && vis[nxt_x].count(nxt_y) != 0){
                    continue;
                }
                if(nxt_x == x && nxt_y == y){
                    ans = cur[2] + 1;
                    break;
                }
                nxt[0] = nxt_x, nxt[1] = nxt_y;
                vis[nxt_x].insert(nxt_y);
                q.push(nxt);
            }
            if(ans > 0){
                break;
            }
        }
        return ans;
    }
};
