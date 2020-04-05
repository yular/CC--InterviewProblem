/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countLetters(string s) {
        int ans = 0, cnt = 0, charCnt = 0, lastCharIdx = 0;
        vector<bool> vis(26, false);
        for(int i = 0; i < s.size(); ++ i) {
            int idx = s[i] - 'a';
            if(vis[idx] == false) {
                ++ charCnt;
                vis[idx] = true;
            }
            if(charCnt >= 2) {
                ans += cnt*(cnt + 1)/2;
                cnt = 0;
                charCnt = 1;
                vis[lastCharIdx] = false;
            }
            lastCharIdx = idx;
            ++ cnt;
            if(i == s.size() - 1) {
                ans += cnt*(cnt + 1)/2;
            }
        }
        return ans;
    }
};
