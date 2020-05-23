/*
*
* Tag: Segment Tree
* Time: O(nlgn)
* Space: O(n^2)
*/

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        if(positions.size() == 0) {
            return {};
        }
        
        set<int> list;
        for(vector<int> pos : positions) {
            list.insert(pos[0]);
            list.insert(pos[0] +  pos[1] - 1);
        }
        
        int maxVal = 1;
        unordered_map<int,int> dic;
        for(auto it = list.begin(); it != list.end(); it ++) {
            dic[*it] = maxVal ++;
        }
        
        vector<int> tree(5000500, 0), lazy(5000500, 0);
        
        int n = positions.size(), idx = 0, curMax = 0;
        vector<int> ans(n);
        for(vector<int> pos : positions) {
            int l = pos[0], r = pos[0] + pos[1] - 1;
            int v = getMaxHeight(tree, lazy, dic[l], dic[r], 1, maxVal, 1);
            updateTree(tree, lazy, dic[l], dic[r], 1, maxVal, 1, v + pos[1]);
            curMax = max(curMax, v + pos[1]);
            ans[idx ++] = curMax;
        }
        return ans;
    }
    
private:
    void updateTree(vector<int> &tree, vector<int> &lazy, int l, int r, int curL, int curR, int idx, int v) {
        if(l <= curL && curR <= r) {
            tree[idx] = v;
            lazy[idx] = v;
            return ;
        }
        
        int mid = (curL + curR) >> 1;
        pushDown(idx, tree, lazy);
        if(l <= mid) {
            updateTree(tree, lazy, l, r, curL, mid, (idx<<1), v);
        }
        if(mid < r) {
            updateTree(tree, lazy, l, r, mid + 1, curR, (idx<<1) + 1, v);
        }
        tree[idx] = max(tree[idx<<1], tree[(idx<<1) + 1]);
        return ;
    }
    
    int getMaxHeight(vector<int> &tree, vector<int> &lazy, int l, int r, int curL, int curR, int idx) {
        if(l <= curL && curR <= r) {
            return tree[idx];
        }
        
        int mid = (curL + curR) >> 1;
        pushDown(idx, tree, lazy);
        
        int ans = INT_MIN;
        if(l <= mid) {
            ans = max(ans, getMaxHeight(tree, lazy, l, r, curL, mid, (idx<<1) ));
        }
        if(mid < r) {
            ans = max(ans, getMaxHeight(tree, lazy, l, r, mid + 1, curR, ((idx<<1) + 1) ));
        }
        return ans;
    }
    
    void pushDown(int idx, vector<int> &tree, vector<int> &lazy) {
        if(lazy[idx] <= 0) {
            return ;
        }
        
        lazy[idx<<1] = lazy[idx];
        lazy[(idx<<1) + 1] = lazy[idx];
        tree[idx<<1] = lazy[idx];
        tree[(idx<<1) + 1] = lazy[idx];
        lazy[idx] = 0;
        return ;
    }
};
