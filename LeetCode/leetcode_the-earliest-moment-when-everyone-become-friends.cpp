/*
*
* Tag: Union Find
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        if(N == 0){
            return 0;
        }
        
        sort(logs.begin(), logs.end(), cmp);
        
        int groupCnt = N;
        vector<int> fa(N, -1);
        for(vector<int> log : logs){
            int u = log[1], v = log[2];
            if(findFa(u, fa) != findFa(v, fa)) {
                unionSet(u, v, fa);
                -- groupCnt;
            }
            if(groupCnt == 1) {
                return log[0];
            }
        }
        return -1;
    }
private:
    struct comparator{
        bool operator() (const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        }
    }cmp;
    
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
    
    void unionSet(int u, int v, vector<int> &fa){
        int faU = findFa(u, fa), faV = findFa(v, fa);
        int newFa = fa[faU] + fa[faV];
        if(fa[faU] <= fa[faV]) {
            fa[faV] = faU;
            fa[faU] = newFa;
        } else {
            fa[faU] = faV;
            fa[faV] = newFa;
        }
        return ;
    }
};
