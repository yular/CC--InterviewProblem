/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
* Credit: https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/discuss/1163543/C%2B%2B-or-Sorted-Permutation-Rank
*/

class Solution {
private:
    long long MOD = 1000000007;
public:
    int makeStringSorted(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int n = s.length();
        vector<long long> fact(n + 1, 1ll);
        for (int i = 1; i <= s.size(); i++) {
            fact[i] = (fact[i - 1] * i)%MOD;
        }
        
        long long ans = 0;
        vector<int> charCnt(26, 0);
        for(int i = n-1; i >= 0; -- i) {
            long long cnt = 0, res = 1;
            int idx = s[i]-'a';
            charCnt[idx]++;
            
            for(int j = 0; j < 26; ++ j) {
                res = (res*fact[charCnt[j]])%MOD;
                if(j < idx) {
                    cnt += charCnt[j];
                }
            }
            ans = ans%MOD + (((cnt*(fact[n-i-1]))%MOD) * (fastPow(res,MOD-2))%MOD)%MOD;
            ans = ans%MOD;
        }
        return ans;
    }
private:
    long long fastPow(long long v,long long n) {
        long long res = 1;
        while(n>0) {
            if(n&1){
                res = (res*v)%MOD;
            }
            v=(v*v)%MOD;
            n >>= 1;
        }
        return res;
    }
};
