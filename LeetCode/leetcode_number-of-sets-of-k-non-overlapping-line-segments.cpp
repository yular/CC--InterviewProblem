/*
*
* Tag: Math + DP
* Time: O(nk)
* Space: O(k)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numberOfSets(int n, int k) {
        if(n < 2 || k < 0 || k > n - 1) {
            return 0;
        }
        
        vector<long long> cur(k + 1, 0), prev(k + 1, 0), acc(k + 1, 0);
        cur[1] = prev[1] = acc[1] = 1;
        long long v = 1;
        for(int i = 3; i <= n; ++ i) {
            cur[1] = (v + (i - 1))%MOD;
            for(int j = 2; j <= k && j < i; ++ j) {
                cur[j] = (acc[j - 1] + prev[j])%MOD;
            }
            for(int j = 1; j <= k && j < i; ++ j) {
                acc[j] = (acc[j] + cur[j])%MOD;
                prev[j] = cur[j];
            }
            v = cur[1];
        }
        return cur[k];
    }
};
