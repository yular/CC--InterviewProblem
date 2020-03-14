/*
*
* Tag: DFS
* Time: O(n) + O(km)
* Space: O(n)
*/

class Solution {
public:
    vector<string> expand(string s) {
        if(s.size() == 0) {
            return {""};
        }
        
        vector<string> options;
        string cur = "";
        bool isOptionStart = false;
        for(char c : s) {
            if(c == '{') {
                if(cur != "") {
                    options.push_back(cur);
                }
                isOptionStart = true;
                continue;
            }
            if(c == ',') {
                continue;
            }
            if(c == '}') {
                isOptionStart = false;
                options.push_back(cur);
                cur = "";
                continue;
            }
            cur += c;
            if(isOptionStart) {
                continue;
            }
            options.push_back(cur);
            cur = "";
            isOptionStart = false;
        }
        
        vector<string> ans;
        string tmp = "";
        dfs(0, tmp, options, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
private:
    void dfs(int idx, string &cur, vector<string> &options, vector<string> &ans) {
        if(idx >= options.size()) {
            ans.push_back(cur);
            return ;
        }
        
        for(char c : options[idx]) {
            string nxt = cur + c;
            dfs(idx + 1, nxt, options, ans);
        }
        return ;
    }
};
