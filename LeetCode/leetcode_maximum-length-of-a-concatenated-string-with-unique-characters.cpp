/*
*
* Tag: DFS + Bit Manipulation
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int maxLength(vector<string>& arr) {
        if(arr.size() == 0){
            return 0;
        }
        
        vector<pair<string,int>> wd;
        for(string s : arr) {
            int bits = 0;
            bool isValid = true;
            for(char c : s ) {
                int mask = 1<<(c - 'a');
                if((bits&mask) > 0) {
                    isValid = false;
                    break;
                }
                bits |= mask;
            }
            
            if(!isValid) {
                continue;
            }
            wd.push_back(make_pair(s, bits));
        }
        
        int ans = 0;
        vector<bool> vis(wd.size(), false);
        dfs(wd, vis, 0, 0, 0, ans);
        return ans;
    }
private:
    void dfs(vector<pair<string,int>> &wd, vector<bool> &vis, int len, int start, int bits, int &ans) {
        ans = max(ans, len);
        
        for(int i = start; i < wd.size(); ++ i) {
            if((bits&wd[i].second) > 0) {
                continue;
            }
            
            dfs(wd, vis, len + wd[i].first.size(), i + 1, (bits|wd[i].second), ans);
        }
        return ;
    }
};
