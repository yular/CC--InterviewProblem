/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool checkZeroOnes(string s) {
        if(s.size() == 0) {
            return false;
        }
        
        int cnt1 = 0, cnt0 = 0;
        for(int i = 0; i < s.size(); ++ i) {
            int cnt = 0;
            while(i < s.size() && s[i] == '1') {
                ++ cnt, ++ i;
            }
            cnt1 = max(cnt1, cnt);
            cnt = 0;
            while(i < s.size() && s[i] == '0') {
                ++ cnt, ++ i;
            }
            cnt0 = max(cnt0, cnt);
            -- i;
        }
        return cnt1 > cnt0;
    }
};
