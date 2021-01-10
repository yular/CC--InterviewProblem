/*
*
* Tag: Union Find
* Time: O(n + m)
* Space: O(n)
*/

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        if(source.size() != target.size()) {
            return -1;
        }
        
        int n = source.size(), ans = 0;
        if(allowedSwaps.size() == 0) {
            for(int i = 0; i < n; ++ i){
                if(source[i] != target[i]) {
                    ++ ans;
                }
            }
            return ans;
        }
        
        vector<int> fa(n, -1);
        for(vector<int> sw : allowedSwaps) {
            int u = sw[0], v = sw[1];
            unionSet(u, v, fa);
        }
        
        unordered_map<int, unordered_map<int,int>> gDict;
        for(int i = 0; i < n; ++ i) {
            int idx = findFa(i, fa);
            ++ gDict[idx][source[i]];
            -- gDict[idx][target[i]];
        }
        
        for(pair<int,unordered_map<int,int>> g : gDict) {
            int cnt = 0;
            for(pair<int,int> r : g.second) {
                if(r.second != 0) {
                    cnt += abs(r.second);
                }
            }
            ans += cnt/2;
        }
        return ans;
    }
private:
    void unionSet(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        if(faU == faV) {
            return ;
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
