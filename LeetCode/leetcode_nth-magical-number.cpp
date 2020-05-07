/*
*
* Tag: Binary Search
* Time: O(lgm)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a, b), r = 1L<<50, mid = 0, ans = 0;
        while(l <= r) {
            mid = (l + r)>>1;
            long long cnt = getCnt(mid, a, b);
            if(cnt >= n) {
                if(cnt == n) {
                    ans = mid;
                }
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans%MOD;
    }
    
private:
    long long getCnt(long long x, int a, int b) {
        long long res = x/a + x/b - x/lcm(a, b);
        return res;
    }
    
    long long lcm(long a, long b) {
        return (a*b)/__gcd(a, b);
    }
};
