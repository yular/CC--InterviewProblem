/*
*
* Tag: Union Find
* Time: O(n + m)
* Space: O(1)
*/

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        if(A.size() == 0 || B.size() == 0 || A.size() != B.size()) {
            return S;
        }
        
        vector<int> fa(26, -1);
        for(int i = 0, v = -26; i < 26; ++ i, ++ v) {
            fa[i] = v;
        }
        
        int n = A.size();
        for(int i = 0; i < n; ++ i){
            int u = A[i] - 'a', v = B[i] - 'a';
            unionSet(u, v, fa);
        }
        
        string ans = S;
        for(int i = 0; i < S.size(); ++ i) {
            int u = S[i] - 'a';
            int v = findFa(u, fa);
            ans[i] = (char)('a' + v);
        }
        return ans;
    }
private:
    void unionSet(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        //cout<<u<<": "<<faU<<", "<<v<<": "<<faV<<endl;
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
        while(u != s) {
            int tmp = fa[u];
            fa[u] = s;
            u = tmp;
        }
        return s;
    }
};
