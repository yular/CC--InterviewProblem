/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int maxNiceDivisors(int primeFactors) {
        int n = primeFactors;
        if(n < 2) {
            return n;
        }
        
        if(n==2) {
            return 2;
        }
        if(n==3) {
            return 3;
        }
        
        if(n%3 == 1) {
            return (calPow(3,((n-4)/3))*4)%MOD;
        } else if(n%3 == 2) {
            return (calPow(3,(n/3))*2)%MOD;
        }
        return calPow(3,n/3);
    }
private:
    long long calPow(long long base, long long n) {
        if(n == 0) {
            return 1;
        }
        long long fact = base, ans = 1, multi = 1;
        while(n > 0) {
            if((n&1) > 0) {
                ans *= fact;
                ans %= MOD;
            }
            
            fact = (fact*fact)%MOD;
            n >>= 1;
        }
        return ans;
    }
};
