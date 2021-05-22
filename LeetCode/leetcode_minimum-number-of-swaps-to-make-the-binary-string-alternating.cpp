/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minSwaps(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int cnt0 = 0, cnt1 = 0, n = s.size();
        for(char c : s) {
            if(c == '0') {
                ++ cnt0;
            } else {
                ++ cnt1;
            }
        }
        if(n%2 == 0) {
            if(cnt0 != cnt1) {
                return -1;
            }
            return min( swapCnt(s, cnt0, cnt1, 0, 1), swapCnt(s, cnt1, cnt0, 1, 0) );
        }
        if(abs(cnt0 - cnt1) != 1) {
            return -1;
        }
        if(cnt0 > cnt1) {
            return swapCnt(s, cnt0, cnt1, 0, 1);
        }
        return swapCnt(s, cnt1, cnt0, 1, 0);
    }
private:
    int swapCnt(string &s, int cntfv, int cntsv, int fv, int sv) {
        int res = 0;
        for(int i = 0; i < s.size(); ++ i) {
            int v = s[i] - '0';
            if(i%2 == 0) {
                if(v != fv) {
                    ++ res;
                }
                -- cntfv;
                continue;
            }
            if(v != sv) {
                ++ res;
            }
            -- cntsv;
        }
        return res/2;
    }
};
