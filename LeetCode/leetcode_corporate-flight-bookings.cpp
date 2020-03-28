/*
*
* Tag: Data Structure Fenwick Tree
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {    
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        if(n == 0) {
            return {};
        }
        
        vector<int> treeIdx(n + 10, 0);
        for(vector<int> booking : bookings) {
            addValue(booking[0], booking[2], treeIdx);
            addValue(booking[1] + 1, -booking[2], treeIdx);
        }
        
        vector<int> ans(n, 0);
        int sum = 0;
        for(int i = 1; i <= n; ++ i) {
            int tot = getSum(i, treeIdx);
            ans[i - 1] = tot;
        }
        return ans;
    }
private:
    void addValue(int idx, int v, vector<int> &treeIdx) {
        for(int i = idx; i < treeIdx.size(); i += lowbit(i)) {
            treeIdx[i] += v;
        }
        return ;
    }
    
    int getSum(int idx, vector<int> &treeIdx){
        int res = 0;
        for(int i = idx; i > 0; i -= lowbit(i)) {
            res += treeIdx[i];
        }
        return res;
    }
    
    int lowbit(int x) {
        return (x&(-x));
    }
};
