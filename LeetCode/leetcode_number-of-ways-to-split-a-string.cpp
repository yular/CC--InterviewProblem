/*
*
* Tag: Sliding Window
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numWays(string s) {
        if(s.size() < 3) {
            return 0;
        }
        
        int totOne = 0, n = s.size();
        for(char c : s) {
            totOne += (c - '0');
        }
        if(totOne%3 != 0) {
            return 0;
        }
        if(totOne == 0) {
            return (((long long)n - 2)*((long long)n - 1)/2)%MOD;
        }
        
        int cntOne = 0, bnd = totOne / 3;
        long long cnt[2] = {0, 0};
        for(char c : s) {
            cntOne += (c - '0');
            if(cntOne == bnd) {
                ++ cnt[0];
            }
            if(cntOne == bnd*2) {
                ++ cnt[1];
            } else if(cntOne > bnd*2) {
                break;
            }
        }
        return (cnt[0]*cnt[1])%MOD;
    }
};
