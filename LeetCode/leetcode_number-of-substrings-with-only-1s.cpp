/*
*
* Tag: string + math
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numSub(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        long long sum = 0, cnt = 0;
        int n = s.size();
        for(int i = 0; i < n; ++ i) {
            if(s[i] == '0') {
                continue;
            }
            
            cnt = 0;
            while(i < n && s[i] == '1') {
                ++ i;
                ++ cnt;
            }
            
            if((cnt&1) == 0) {
                sum += (cnt/2)*(cnt+1);
            } else {
                sum += cnt*((cnt+1)/2);
            }
            sum %= MOD;
            -- i;
        }
        return sum;
    }
};
