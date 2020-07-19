/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        if(s.size() == 0) {
            return {};
        }
        
        vector<pair<int,int>> charLoc(26, make_pair(-1, -1));
        int n = s.size();
        for(int i = 0; i < n; ++ i) {
            int idx = s[i] - 'a';
            if(charLoc[idx].first == -1) {
                charLoc[idx] = make_pair(i, i);
            }
            
            charLoc[idx].second = max(charLoc[idx].second, i);
        }
        
        int r = n, idx = -1;
        vector<string> ans;
        for(int i = 0; i < n; ++ i) {
            int key = s[i] - 'a';
            if(i != charLoc[key].first) {
                continue;
            }
            
            int curR = findRightBnd(s, s[i], charLoc[key].first, charLoc);
            if(curR == -1) {
                continue;
            }
            
            string res = s.substr(i, curR - i + 1);
            if(r < i || idx == -1) {
                ans.push_back(res);
                ++ idx;
            } else {
                ans[idx] = res;
            }
            r = curR;
        }
        return ans;
    }
    
private:
    int findRightBnd(string &s, char key, int l, vector<pair<int,int>> &charLoc) {
        int idx = key - 'a';
        int r = charLoc[idx].second;
        for(int i = l; i <= r; ++ i) {
            if(charLoc[s[i] - 'a'].first < charLoc[idx].first) {
                return -1;
            }
            r = max(r, charLoc[s[i] - 'a'].second);
        }
        return r;
    }
};
