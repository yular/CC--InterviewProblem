/*
*
* Tag: BFS
* Time: O(2^(n*m))
* Space: O(2^(n*m))
*/

class Solution {
private:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0,  1}};
public:
    int minFlips(vector<vector<int>>& mat) {
        if(mat.size() == 0) {
            return 0;
        }
        
        unordered_map<int,int> dis;
        dis[0] = -1;
        int src = convertMtxToInt(mat);
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        int n = mat.size(), m = mat[0].size();
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(cur == 0) {
                break;
            }
            
            vector<vector<int>> mtx = convertIntToMtx(cur, n, m);
            for(int i = 0; i < n; ++ i) {
                for(int j = 0; j < m; ++ j) {
                    vector<vector<int>> nxt = mtx;
                    nxt[i][j] = (nxt[i][j] + 1)%2;                    
                    for(int k = 0; k < 4; ++ k) {
                        int nxt_i = i + dir[k][0], nxt_j = j + dir[k][1];
                        if(nxt_i < 0 || nxt_i >= n || nxt_j < 0 || nxt_j >= m) {
                            continue;
                        }
                        nxt[nxt_i][nxt_j] = (nxt[nxt_i][nxt_j] + 1)%2;
                    }
                    
                    int v = convertMtxToInt(nxt);
                    if(dis.count(v) > 0 && v != 0) {
                        continue;
                    }
                    
                    dis[v] = dis[cur] + 1;
                    q.push(v);
                    if(v == 0) {
                        break;
                    }
                }
                if(dis[0] != -1) {
                    break;
                }
            }
            
            if(dis[0] != -1) {
                break;
            }
        }
        
        return dis[0];
    }
private:
    int convertMtxToInt(vector<vector<int>>& mat) {
        int res = 0, mask = 1, n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(mat[i][j] == 1) {
                    res |= mask;
                }
                mask <<= 1;
            }
        }
        return res;
    }
    
    vector<vector<int>> convertIntToMtx(int v, int n, int m) {
        vector<vector<int>> res(n, vector<int>(m, 0));
        int mask = 1;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                res[i][j] = (v&mask) > 0 ? 1 : 0;
                mask <<= 1;
            }
        }
        return res;
    }
};
