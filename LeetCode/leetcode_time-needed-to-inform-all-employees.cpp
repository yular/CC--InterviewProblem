/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 0){
            return 0;
        }
        
        unordered_map<int,vector<int>> tree;
        for(int i = 0; i < n; ++ i) {
            int u = manager[i];
            if(u == -1) {
                continue;
            }
            
            tree[u].push_back(i);
        }
        
        return getTimeToInform(headID, tree, informTime);
    }
private:
    int getTimeToInform(int root, unordered_map<int,vector<int>> &tree, vector<int>& informTime) {
        if(tree[root].size() == 0) {
            return 0;
        }
        
        int maxTime = 0;
        for(int v : tree[root]) {
            maxTime = max(maxTime, getTimeToInform(v, tree, informTime));
        }
        
        return maxTime + informTime[root];
    }
};
