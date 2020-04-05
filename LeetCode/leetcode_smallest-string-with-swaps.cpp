/*
*
* Tag: Union Find, Greedy
* Time: O(m + nlgn)
* Space: O(n)
*/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.size() == 0){
            return s;
        }
        
        vector<int> fa(s.size(), -1);
        for(vector<int> pair : pairs) {
            if(pair[0] == pair[1]) {
                continue;
            }
            if(findFa(pair[0], fa) == findFa(pair[1], fa)) {
                continue;
            }
            unionSet(pair[0], pair[1], fa);
        }
        
        int setIdx = 0;
        unordered_map<int, int> setDict;
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> charSet;
        for(int i = 0; i < s.size(); ++ i) {
            if(fa[i] < 0) {
                if(setDict.count(i) == 0) {
                    setDict[i] = setIdx ++;
                }
            } else {
                int p = findFa(i, fa);
                if(setDict.count(p) == 0) {
                    setDict[p] = setIdx ++;
                }
                
                setDict[i] = setDict[p];
            }
            
            charSet[setDict[i]].push(s[i]);
        }
        
        string ans = "";
        for(int i = 0; i < s.size(); ++ i) {
            int idx = setDict[i];
            ans += charSet[idx].top();
            charSet[idx].pop();
        }
        return ans;
    }
private:
    void unionSet(int u, int v, vector<int> &fa) {
        int faU = findFa(u, fa), faV = findFa(v, fa);
        int tmp = fa[faU] + fa[faV];
        if(fa[faU] <= fa[faV]) {
            fa[faV] = faU;
            fa[faU] = tmp;
        } else {
            fa[faU] = faV;
            fa[faV] = tmp;
        }
        return ;
    }
    
    long long findFa(int u, vector<int> &fa) {
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
