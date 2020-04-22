/*
*
* Tag: Union Find
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        if(equations.size() == 0) {
            return true;
        }
        
        vector<int> fa(26, -1);
        for(string eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            if(eq[1] == '=') {
                unionSet(u, v, fa);
            }
        }
        for(string eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            if(eq[1] == '!' && findFa(u, fa) == findFa(v, fa)) {
                return false;
            }
        }
        return true;
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
