/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int minCharacters(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int> aMChar(2, 0), bMChar(2, 0);
        int ans = n - getMaxCharCnt(a, aMChar) + m - getMaxCharCnt(b, bMChar);
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ans = min(ans, cmpStr(a, aMChar, b, bMChar));
        if(ans == 0) {
            return ans;
        }
        
        ans = min(ans, cmpStr(b, bMChar, a, aMChar));
        return ans;
    }
private:
    int getMaxCharCnt(string &s, vector<int> &mChar) {
        mChar[0] = 'z', mChar[1] = 'a';
        vector<int> cnt(26, 0);
        int res = 0;
        for(char c : s){
            ++ cnt[c - 'a'];
            res = max(res, cnt[c - 'a']);
            mChar[0] = min(mChar[0], (int)c);
            mChar[1] = max(mChar[1], (int)c);
        }
        return res;
    }
    
    int cmpStr(string &a, vector<int> &aMChar, string &b, vector<int> &bMChar) {
        int res = 0;
        if(aMChar[1] < bMChar[0]) {
            return res;
        }
        
        int aIdx = a.size() - 1, bIdx = 0;
        vector<int> aCharCnt(26, 0), bCharCnt(26, 0);
        for(int i = a.size() - 1; i >= 0; -- i) {
            if(a[i] == 'z') {
                ++ res;
                aIdx = i - 1;
                continue;
            }
            ++ aCharCnt[a[i] - 'a'];
        }
        for(int i = 0; i < b.size(); ++ i) {
            if(b[i] == 'a') {
                ++ res;
                bIdx = i + 1;
                continue;
            }
            ++ bCharCnt[b[i] - 'a'];
        }
        
        for(; aIdx >= 0 && bIdx < b.size();) {
            int aCnt = 0, bCnt  = 0, aVal = a[aIdx] - 'a', bVal = b[bIdx] - 'a';
            for(int i = bVal; i <= aVal; ++ i) {
                aCnt += bCharCnt[i];
                bCnt += aCharCnt[i];
            }
            
            if(aCnt == 0 && bCnt == 0) {
                break;
            }
            if(aCnt >= bCnt) {
                -- aIdx;
            } else {
                ++ bIdx;
            }
            ++ res;
        }
        return res;
    }
};
