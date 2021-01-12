/*
*
* Tag: DFS
* Time: O(n^n)
* Space: O(n)
/

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        if(n == 0) {
            return {};
        }
        
        int len = 2*n - 1, cnt = 0;
        vector<int> ans(len, -1);
        vector<bool> vis(n + 1, false);
        bool isFind = false;
        dfs(ans, n, len, vis, 0, 0, isFind);
        return ans;
    }
private:
    void dfs(vector<int> &ans, int n, int len, vector<bool> &vis, int idx, int cnt, bool &isFind) {
        if(cnt >= len || idx >= len) {
            isFind = true;
            return ;
        }
        if(idx < len && ans[idx] != -1) {
            dfs(ans, n, len, vis, idx + 1, cnt, isFind);
            return ;
        }
        for(int i = n; i > 0; -- i) {
            if(vis[i]) {
                continue;
            }
            if(i == 1) {
                ans[idx] = 1;
                vis[i] = true;
                dfs(ans, n, len, vis, idx + 1, cnt + 1, isFind);
                if(isFind) {
                    return ;
                }
                ans[idx] = -1;
                vis[i] = false;
                continue;
            }
            if(idx + i >= len || ans[idx + i] != -1) {
                continue;
            }
            ans[idx] = ans[idx + i] = i;
            vis[i] = true;
            dfs(ans, n, len, vis, idx + 1, cnt + 2, isFind);
            if(isFind) {
                return ;
            }
            ans[idx] = ans[idx + i] = -1;
            vis[i] = false;
        }
        return ;
    }
};
