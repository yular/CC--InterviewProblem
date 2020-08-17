/*
*
* Tag: MST (Minimum Spanning Tree)
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        if(n == 0 || n != wells.size()) {
            return 0;
        }
        if(pipes.size() == 0) {
            return accumulate(wells.begin(), wells.end(), 0);
        }
        
        for(int i = 0; i < wells.size(); ++ i){
            pipes.push_back({0, i + 1, wells[i]});
        }
        
        sort(pipes.begin(), pipes.end(), cmp);
        
        vector<int> fa(n + 1, -1);
        int ans = 0;
        for(vector<int> pipe : pipes) {
            int u = pipe[0], v = pipe[1];
            if(findFa(u, fa) == findFa(v, fa)) {
                continue;
            }
            
            ans += pipe[2];
            unionSet(u, v, fa);
        }
        return ans;
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
        if(fa[faU] <= fa[faV]) {
            fa[faV] = faU;
        } else {
            fa[faU] = faV;
        }
        return ;
    }
    
private:
    struct comparator {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        }
    }cmp;
};
