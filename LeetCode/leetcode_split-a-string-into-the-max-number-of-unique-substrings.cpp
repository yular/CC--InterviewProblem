/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/

class Solution {
public:
    int maxUniqueSplit(string s) {
        if(s.size() < 2) {
            return s.size();
        }
        
        int ans = 1;
        unordered_set<string> vis;
        dfs(s, 0, vis, 0, ans);
        return ans;
    }
private:
    void dfs(string &s, int start, unordered_set<string> &vis, int cnt, int &ans) {
        int n = s.size();
        if(start >= n) {
            ans = max(ans, cnt);
            return ;
        }
        if(ans >= cnt + n - start) {
            return ;
        }
        
        string str = "";
        for(int i = start; i < n; ++ i) {
            str += s[i];
            if(vis.count(str) > 0) {
                continue;
            }
            
            vis.insert(str);
            dfs(s, i + 1, vis, cnt + 1, ans);
            vis.erase(str);
        }
        return ;
    }
};
