/*
*
* Tag: Union Find
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) {
            return -1;
        }
        
        vector<int> fa(n, -1);
        int cnt = 0, disconCnt = n;
        for(vector<int> connection : connections) {
            if(findFa(connection[0],fa) == findFa(connection[1], fa)) {
                ++ cnt;
                continue;
            }
            
            unionSet(connection[0], connection[1], fa);
            -- disconCnt;
        }
        
        return cnt < disconCnt - 1 ? -1 : disconCnt - 1;
    }
    
private:
    int findFa(int u, vector<int> &fa) {
        int s = u;
        for(; fa[s] >= 0; s = fa[s]);
        while(s != u) {
            int tmp = fa[u];
            fa[u] = s;
            u = tmp;
        }
        return s;
    }
    
    void unionSet(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        int newFa = fa[faU] + fa[faV];
        if(fa[faU] <= fa[faV]) {
            fa[faV] = u;
            fa[faU] = newFa;
        } else {
            fa[faV] = newFa;
            fa[faU] = v;
        }
        return ;
     }
};
