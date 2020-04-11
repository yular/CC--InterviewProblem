/*
*
* Tag: Hash + Math
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        if(queries.size() == 0) {
            return {};
        }
        
        vector<vector<int>> charCnt(s.size(), vector<int>(26, 0));
        for(int i = 0; i < s.size(); ++ i) {
            int idx = s[i] - 'a';
            if(i > 0) {
                for(int j = 0; j < 26; ++ j) {
                    charCnt[i][j] = charCnt[i - 1][j];
                }
            }
            ++ charCnt[i][idx];
        }
        
        vector<bool> ans(queries.size(), false);
        for(int i = 0; i < queries.size(); ++ i) {
            if(queries[i][0] == queries[i][1]) {
                ans[i] = true;
                continue;
            }
            vector<int> cnt = charCnt[queries[i][1]];
            if(queries[i][0] > 0) {
                for(int j = 0; j < 26; ++ j) {
                    cnt[j] -= charCnt[queries[i][0] - 1][j];
                }
            }
            
            int oddCnt = 0;
            for(int j = 0; j < 26; ++ j) {
                if(cnt[j]%2 == 1) {
                    ++ oddCnt;
                }
            }
            -- oddCnt;
            ans[i] = queries[i][2]*2 >= oddCnt;
        }
        return ans;
    }
};
