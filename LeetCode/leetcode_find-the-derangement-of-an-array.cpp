/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int findDerangement(int n) {
        if(n < 2) {
            return 0;
        }
        if(n == 2) {
            return 1;
        }
        
        long long ans = 0, prev = 0, cur = 1, idx = 2;
        for(; idx < n; ++ idx) {
            ans = ((prev + cur)*idx)%MOD;
            prev = cur;
            cur = ans;
        }
        return ans;
    }
};
