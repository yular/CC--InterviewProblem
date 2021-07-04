/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int countGoodNumbers(long long n) {
        if(n == 1) {
            return 5;
        }
        
        long long m = n/2;
        if(n%2 == 1) {
            ++ m;
        }
        
        long long ans = calFastPow(5, m);
        ans *= calFastPow(4, n/2);
        return ans%MOD;
    }
private:
    long long calFastPow(long long v, long long n) {
        long long res = 1;
        while(n) {
            if(n&1) {
                res *= v;
                res %= MOD;
            }
            n >>= 1;
            v = (v*v)%MOD;
        }
        return res;
    }
};
