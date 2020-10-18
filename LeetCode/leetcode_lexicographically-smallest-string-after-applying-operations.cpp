/*
*
* Tag: DFS
* Time: O(10*n^2)
* Space: O(10*n^2)
*/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        if(s == "") {
            return s;
        }
        
        unordered_set<string> vis;
        string ans = s;
        dfs(s, ans, vis, a, b);
        return ans;
    }
private:
    void dfs(string &s, string &ans, unordered_set<string> &vis, int a, int b) {
        if(vis.count(s) > 0) {
            return ;
        }
        if(ans > s) {
            ans = s;
        }
        vis.insert(s);
        
        int n = s.size();
        if(a > 0) {
            string nxt = s;
            for(int i = 1; i < n; i += 2) {
                nxt[i] = (((nxt[i] - '0') + a)%10 + '0');
            }
            dfs(nxt, ans, vis, a, b);
        }
        
        if(b > 0) {
            string nxt = s;
            for(int i = 0; i < n; ++ i) {
                int idx = (i + b)%n;
                nxt[idx] = s[i];
            }
            dfs(nxt, ans, vis, a, b);
        }
        return ;
    }
};
