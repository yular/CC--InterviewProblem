/*
*
* Tag: Greedy + Data Structure
* Time: O(nmlgk)
* Space: O(k)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        if(k == 0 || mat.size() == 0) {
            return -1;
        }
        
        int m = mat[0].size();
        priority_queue<int> curQ;
        for(int i = 0; i < m && i < k; ++ i) {
            curQ.push(mat[0][i]);
        }
        
        int n = mat.size();
        for(int i = 1; i < n; ++ i) {
            priority_queue<int> nxtQ;
            
            while(!curQ.empty()) {
                int v = curQ.top();
                curQ.pop();
                
                for(int j = 0; j < m; ++ j) {
                    int nxtV = mat[i][j] + v;
                    if(nxtQ.size() < k) {
                        nxtQ.push(nxtV);
                    } else if(nxtQ.top() > nxtV) {
                        nxtQ.pop();
                        nxtQ.push(nxtV);
                    }
                }
            }
            
            curQ = nxtQ;
        }
        return curQ.top();
    }
};
