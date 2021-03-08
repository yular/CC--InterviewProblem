/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int balancedString(string s) {
        if((int)s.size()%4 != 0) {
            return -1;
        }
        
        vector<int> cnt(4, 0);
        int n = s.size();
        for(int i = 0; i < n; ++ i) {
            int idx = getId(s[i]);
            ++ cnt[idx];
        }
        bool isFound = false;
        vector<int> extraCnt(4, 0);
        for(int i = 0; i < 4; ++ i) {
            if(cnt[i] > n/4) {
                extraCnt[i] = cnt[i] - n/4;
                isFound = true;
            }
        }
        if(!isFound) {
            return 0;
        }
        
        int ans = n, l = 0, r = 0;
        vector<int> reExtraCnt(4, 0);
        for(; r < n;) {
            int idx = getId(s[r]);
            ++ reExtraCnt[idx];
            if(l <= r && isValid(extraCnt, reExtraCnt)) {
                ans = min(ans, r - l + 1);
                idx = getId(s[l]);
                -- reExtraCnt[idx];
                ++ l;
                idx = getId(s[r]);
                -- reExtraCnt[idx];
            } else {
                ++ r;
            }
        }
        return ans;
    }
private:
    int getId(char c) {
        switch(c) {
            case 'Q':
                return 0;
            case 'W':
                return 1;
            case 'E':
                return 2;
            case 'R':
                return 3;
        }
        return -1;
    }
    
    bool isValid(vector<int> &a, vector<int> &b) {
        for(int i = 0; i < 4; ++ i){
            if(a[i] > b[i]) {
                return false;
            }
        }
        return true;
    }
};
