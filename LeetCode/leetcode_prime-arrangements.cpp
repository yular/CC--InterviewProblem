/*
*
* Tag: Math
* Time: O(nsqrt(m))
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numPrimeArrangements(int n) {
        if(n < 3) {
            return 1;
        }
        
        int primeCnt = 0;
        for(int i = 2; i <= n; ++ i) {
            if(isPrime(i)) {
                ++ primeCnt;
            }
        }
        
        long long ans = permutation(n - primeCnt) * permutation(primeCnt);
        return ans%MOD;
    }
    
private:
    bool isPrime(int v) {
        for(int i = 2; i*i <= v; ++ i) {
            if(v%i == 0) {
                return false;
            }
        }
        return true;
    }
    
    long long permutation(int n) {
        long long ans = 1;
        for(int i = 2; i <= n; ++ i) {
            ans = (ans*i)%MOD;
        }
        return ans;
    }
};
