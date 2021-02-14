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
    int countHomogenous(string s) {
        if(s.size() < 2) {
            return (int)s.size();
        }
        
        long long res = 0, cnt = 0;
        int last = -1, n = s.size();
        for(int i = 0; i < n; ++ i) {
            if(s[i] != last) {
                res += calSum(cnt);
                res %= MOD;
                cnt = 0;
            }
            last = s[i];
            ++ cnt;
            if(i == n - 1) {
                res += calSum(cnt);
                res %= MOD;
            }
        }
        return res;
    }
private:
    long long calSum(long long n) {
        return n*(n + 1)/2;
    }
};
