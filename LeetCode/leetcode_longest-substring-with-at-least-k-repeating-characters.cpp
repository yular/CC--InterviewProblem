/*
*
* Tag: Brute Force (Or Greedy)
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size(), right_char_cnt = 0, fidx = 0;
        if(!s.size() || k <= 1)
            return n;
        vector<int> cnt(26, 0), totcnt(26, 0);
        for(int i = 0; i < n; ++ i)
            ++ totcnt[s[i] - 'a'];
        for(int i = 0; i < n; ++ i){
            if(totcnt[s[i] - 'a'] < k){
                while(fidx < i){
                    -- cnt[s[fidx] - 'a'];
                    if(cnt[s[fidx] - 'a'] == 0)
                        -- right_char_cnt;
                    if(check(cnt, k))
                        res = max(res, i - fidx - 1);
                    ++ fidx;
                }
                ++ fidx;
                right_char_cnt = 0;
                
                for(int j = 0; j < 26; ++ j)
                    totcnt[j] -= cnt[j];
                
            }else{
                ++ cnt[s[i] - 'a'];
                if(cnt[s[i] - 'a'] == k)
                    -- right_char_cnt;
                else if(cnt[s[i] - 'a'] == 1)
                    ++ right_char_cnt;
                if(!right_char_cnt)
                    res = max(res, i + 1 - fidx);
            }
        }
        return res;
    }
    
private:
    bool check(vector<int> &cnt, int k){
        for(int i = 0; i < cnt.size(); ++ i){
            if(cnt[i] && cnt[i] < k)
                return false;
        }
        return true;
    }
};
