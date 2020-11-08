/*
*
* Tag: Data Structure ( fenwick tree )
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int createSortedArray(vector<int>& instructions) {
        if(instructions.size() == 0) {
            return 0;
        }
        
        map<int,int> dict;
        for(int ins : instructions) {
            dict[ins] = 0;
        }
        
        int rank = 1, n = instructions.size();
        for(auto it : dict) {
            dict[it.first] = rank ++;
        }
        
        vector<int> tree(rank + 1, 0);
        unordered_map<int,int> numCnt;
        int tot = 0;
        long long ans = 0;
        for(int i = 0; i < n; ++ i, ++ tot) {
            int idx = dict[instructions[i]];
            int smallCnt = getSmallCnt(idx - 1, tree);
            int largeCnt = tot - numCnt[instructions[i]] - smallCnt;
            ans += min(smallCnt, largeCnt);
            ans %= MOD;
            
            ++ numCnt[instructions[i]];
            updateCnt(idx, tree);
        }
        return ans;
    }
private:
    int getSmallCnt(int idx, vector<int> &tree) {
        int res = 0;
        for(int i = idx; i > 0; i -= lowbit(i)) {
            res += tree[i];
        }
        return res;
    }
    
    void updateCnt(int idx, vector<int> &tree) {
        for(int i = idx; i < tree.size(); i += lowbit(i)) {
            ++ tree[i];
        }
        
        return ;
    }
    
    int lowbit(int x) {
        return x&-x;
    }
};
