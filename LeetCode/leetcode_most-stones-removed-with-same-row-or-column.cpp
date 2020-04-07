/*
*
* Tag: Union Find (Data Structure)
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size() == 0) {
            return 0;
        }
        
        int n = stones.size();
        vector<int> fa(n, -1);
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    unionSet(i, j, fa);
                }
            }
        }
        
        int ans = n;
        for(long long v : fa) {
            if(v < 0) {
                -- ans;
            }
        }
        return ans;
    }
    
private:
    void unionSet(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        if(faU == faV) {
            return;
        }
        
        if(fa[faU] <= fa[faV]) {
            fa[faV] = faU;
            fa[faU] = -1;
        } else {
            fa[faU] = faV;
            fa[faV] = -1;
        }
        return ;
    }
    
    int findFa(int u, vector<int> &fa) {
        int s = u;
        for(; fa[s] >= 0; s = fa[s]) ;
        while(s != u) {
            int tmp = fa[u];
            fa[u] = s;
            u = tmp;
        }
        return s;
    }
};
