/*
*
* Tag: DFS
* Time: O(nm) n is # of nums, and m is # of tree nodes
* Space: O(m^2)
*/

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        if(nums.size() == 0 || edges.size() == 0) {
            return {};
        }
        
        unordered_map<int, vector<int>> coprime;
        unordered_map<int,int> numDep, numIdx;
        init(nums, coprime, numDep, numIdx);
        
        int n = nums.size();
        vector<vector<int>> g(n, vector<int>(0));
        for(vector<int> &e : edges) {    
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        vector<int> ans(n, -1);
        dfs(numDep, numIdx, nums, 0, g, -1, coprime, 0, ans);
        
        return ans;
    }
    
private:
    void init(vector<int>& nums, unordered_map<int, vector<int>> &coprime, unordered_map<int,int> &numDep, unordered_map<int,int> &numIdx) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (auto i : numSet) {
            numDep[i] = numIdx[i] = -1;
            for (auto j : numSet) {
                if (gcd(i, j) == 1) {
                    coprime[i].push_back(j);
                }
            }
        }
        return ;
    }
    
    void dfs(unordered_map<int,int> &numDep, unordered_map<int,int> &numIdx, vector<int>& nums, int rootIdx, vector<vector<int>> &g, int parent, unordered_map<int, vector<int>> &coprime, int dep, vector<int> &ans) {
        int u = nums[rootIdx];
        
        int maxDep = -1;
        for(int v : coprime[u]) {
            if(numDep[v] > maxDep) {
                maxDep = numDep[v];
                ans[rootIdx] = numIdx[v];
            }
        }
        
        int lastDep = numDep[u], lastIdx = numIdx[u];
        numDep[u] = dep;
        numIdx[u] = rootIdx;
        for(int vIdx : g[rootIdx]) {
            if(vIdx == parent) {
                continue;
            }
            dfs(numDep, numIdx, nums, vIdx, g, rootIdx, coprime, dep + 1, ans);
        }
        numDep[u] = lastDep;
        numIdx[u] = lastIdx;
        return;
    }
};
