/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countOrders(int n) {   
        long long ans = 1;
        for(int i = 2; i <= n; ++ i) {
            long long m = 2*i - 1;
            long long sum = m*(m + 1)/2;
            ans *= (sum%MOD);
            ans %= MOD;
        }
        return ans;
    }
};
