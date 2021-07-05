/*
*
* Tag: Data Structure
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        if(order.size() < 3) {
            return (int)order.size();
        }
        
        int ans = 1, minVal = order[0], maxVal = order[0], n = order.size();
        vector<vector<bool>> tree(n + 1, vector<bool>(2, false));
        vector<int> depth(n + 1, 1);
        set<int> vis = {order[0]};
        for(int i = 1; i < n; ++ i){
            int v = order[i];
            if(v < minVal) {
                tree[minVal][0] = true;
                depth[v] = depth[minVal] + 1;
                minVal = v;
                vis.insert(v);
                ans = max(ans, depth[v]);
                continue;
            } else if(v > maxVal) {
                tree[maxVal][1] = true;
                depth[v] = depth[maxVal] + 1;
                maxVal = v;
                vis.insert(v);
                ans = max(ans, depth[v]);
                continue;
            }
            
            auto it = vis.lower_bound(v);
            auto prev = it;
            prev --;
            if(tree[*it][0] == false) {
                tree[*it][0] = true;
                depth[v] = depth[*it] + 1;
            } else {
                tree[*prev][1] = true;
                depth[v] = depth[*prev] + 1;
            }
            ans = max(ans, depth[v]);
            vis.insert(v);
        }
        return ans;
    }
};
