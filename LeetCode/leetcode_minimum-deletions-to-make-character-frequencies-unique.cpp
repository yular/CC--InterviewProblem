/*
*
* Tag: Data Structure (Ordered Map) + Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minDeletions(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        vector<int> charCnt(26, 0);
        for(int i = 0; i < s.size(); ++ i) {
            int idx = s[i] - 'a';
            ++ charCnt[idx];
        }
        
        map<int,int> cntDict;
        for(int i = 0; i < 26; ++ i) {
            if(charCnt[i] <= 0) {
                continue;
            }
            ++ cntDict[charCnt[i]];
        }
        
        int ans = 0;
        for(auto it = cntDict.rbegin(); it != cntDict.rend(); it ++) {
            if(it->second == 1 || it->first <= 0) {
                continue;
            }
            
            ans += (it->second - 1);
            int key = (it->first) - 1;
            cntDict[key] += it->second - 1;
        }
        return ans;
    }
};
