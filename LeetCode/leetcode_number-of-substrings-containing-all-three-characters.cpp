/*
*
* Tag: Sliding Window
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        vector<int> charCnt(3, 0);
        int l = 0, r = 0, ans = 0, cnt = 0;
        for(; r < s.size(); ++ r) {
            int idx = s[r] - 'a';
            ++ charCnt[idx];
            if(charCnt[idx] == 1) {
                ++ cnt;
            }
            
            while(cnt == 3) {
                ans += s.size() - r;
                idx = s[l] - 'a';
                -- charCnt[idx];
                ++ l;
                if(charCnt[idx] == 0) {
                    -- cnt;
                }
            }
        }
        return ans;
    }
};
