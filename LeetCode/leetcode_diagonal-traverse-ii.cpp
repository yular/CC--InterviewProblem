/*
*
* Tag: Hash, Data Structure, Queue
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        
        int n = nums.size();
        vector<int> rowLen(n, 0), rowIdx(n, -1);
        for(int i = 0; i < n; ++ i) {
            rowLen[i] = nums[i].size();
            rowIdx[i] = -1;
        }
        
        vector<int> ans;
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        rowIdx[0] = 0;
        
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            
            ans.push_back(nums[cur.first][cur.second]);
            int nxtr = cur.first + 1, nxtc = cur.second;
            if(nxtr < n && nxtc < rowLen[nxtr] && nxtc == rowIdx[nxtr] + 1) {
                q.push(make_pair(nxtr, nxtc));
                rowIdx[nxtr] = nxtc;
            }
            nxtr = cur.first, nxtc = cur.second + 1;
            if(nxtr < n && nxtc < rowLen[nxtr] && nxtc == rowIdx[nxtr] + 1) {
                q.push(make_pair(nxtr, nxtc));
                rowIdx[nxtr] = nxtc;
            }
        }
        return ans;
    }
};
