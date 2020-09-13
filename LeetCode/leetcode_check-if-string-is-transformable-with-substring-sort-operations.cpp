/*
*
* Tag: Greedy
* Time: O(n + m)
* Space: O(n)
*/

class Solution {
public:
    bool isTransformable(string s, string t) {
        if(s == t) {
            return true;
        }
        if(s.size() != t.size()) {
            return false;
        }
        
        vector<queue<int>> numQue(10);
        for(int i = 0; i < s.size(); ++ i) {
            int v = s[i] - '0';
            numQue[v].push(i);
        }
        
        vector<int> numCnt(10, 0);
        ++ numCnt[s[0] - '0'];
        for(int i = 0; i < t.size();) {
            int idx = t[i] - '0';
            int res = getMatchResult(numCnt, idx);
            if(res < 0) {
                return false;
            } else if(res > 0) {
                if(!numQue[idx].empty()) {
                    numQue[idx].pop();
                }
                -- numCnt[idx], ++ i;
                continue;
            }
            if(numQue[idx].empty()){
                return false;
            }
            
            int nxtIdx = numQue[idx].front();
            for(int j = 0; j < idx; ++ j) {
                if(!numQue[j].empty() && numQue[j].front() < nxtIdx) {
                    return false;
                }
            }
            ++ numCnt[idx];
        }
        return true;
    }
    
private:
    int getMatchResult(vector<int> &numCnt, int v) {
        for(int i = 0; i < v; ++ i) {
            if(numCnt[i] > 0) {
                return -1;
            }
        }
        
        if(numCnt[v] > 0) {
            return 1;
        }
        return 0;
    }
};
