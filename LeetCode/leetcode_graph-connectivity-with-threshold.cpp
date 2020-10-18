/*
*
* Tag: Union Find
* Time: O(n^1.5)
* Space: O(n)
*/

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if(queries.size() == 0 || threshold > n) {
            return {};
        }
        
        int m = queries.size();
        vector<bool> ans(m, true);
        if(threshold == 0) {
            return ans;
        }
        
        vector<int> fa(n + 1, -1);
        for(int i = threshold + 1; i <= n; ++ i) {
            for(int j = 2; j*j <= i; ++ j) {
                if(i == j || i%j != 0) {
                    continue;
                }
                
                if(j > threshold) {
                    unionSet(j, i, fa);
                }
                
                int v = i/j;
                if(v > threshold) {
                    unionSet(v, i, fa);
                }
            }
        }
        
        for(int i = 0; i < queries.size(); ++ i) {
            vector<int> q = queries[i];
            int u = q[0], v = q[1];
            if(u == v || findFa(u, fa) == findFa(v, fa)) {
                continue;
            }
            
            ans[i] = false;
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
        } else {
            fa[faU] = faV;
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
