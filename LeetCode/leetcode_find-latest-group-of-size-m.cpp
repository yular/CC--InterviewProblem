/*
*
* Tag: Union Find
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        if(m == 0 || m > arr.size()) {
            return 0;
        }
        
        if(m == arr.size()) {
            return m;
        }
        
        int ans = -1, n = arr.size();
        vector<int> fa(n, -1), setSize(n, 0), setSizeCnt(n + 1, 0);
        vector<bool> state(n, false);
        for(int i = 0; i < n; ++ i) {
            int idx = arr[i] - 1;
            state[idx] = true;
            setSize[idx] = 1;
            ++ setSizeCnt[1];
            
            if(idx > 0 && state[idx - 1]) {
                unionSet(idx - 1, idx, fa, setSize, setSizeCnt);
            }
            if(idx < n - 1 && state[idx + 1]) {
                unionSet(idx + 1, idx, fa, setSize, setSizeCnt);
            }
            
            if(setSizeCnt[m] > 0) {
                ans = i + 1;
            }
        }
        return ans;
    }
private:
    void unionSet(int u, int v, vector<int> &fa, vector<int> &setSize, vector<int> &setSizeCnt) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        if(faU == faV) {
            return ;
        }
        
        if(fa[faU] <= fa[faV]) {
            -- setSizeCnt[setSize[faV]];
            -- setSizeCnt[setSize[faU]];
            setSize[faU] += setSize[faV];
            setSize[faV] = 0;
            ++ setSizeCnt[setSize[faU]];
            fa[faV] = faU;
        } else {
            -- setSizeCnt[setSize[faU]];
            -- setSizeCnt[setSize[faV]];
            setSize[faV] += setSize[faU];
            setSize[faU] = 0;
            ++ setSizeCnt[setSize[faV]];
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
