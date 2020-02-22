/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        if(nodes == 0) {
            return 0;
        }
        
        int root = 0;
        unordered_map<int, vector<int>> tree;
        for(int i = 0; i < nodes; ++ i) {
            if(parent[i] < 0) {
                root = i;
                continue;
            }
            tree[parent[i]].push_back(i);
        }
        
        int ans = 0, cnt = 0, sum = 0;
        dfs(tree, value, root, ans, cnt, sum);
        
        return nodes - ans;
    }
private:
    void dfs(unordered_map<int, vector<int>> &tree, vector<int> &value, int root, int &ans, int &cnt, int &sum){
        for(int v : tree[root]) {
            int subsum = 0, subcnt = 0;
            dfs(tree, value, v, ans, subcnt, subsum);
            sum += subsum;
            cnt += subcnt;
        }
        
        sum += value[root];
        ++ cnt;
        if(sum == 0) {
            ans += cnt;
            cnt = 0;
            sum = 0;
        }
        return ;
    }
};
