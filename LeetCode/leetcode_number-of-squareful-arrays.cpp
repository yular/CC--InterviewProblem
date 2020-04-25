/*
*
* Tag: DFS
* Time: O(n!)
* Space: O(n)
*/

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        if(A.size() < 2) {
            return 0;
        }
        
        sort(A.begin(), A.end());
        
        int n = A.size();
        vector<bool> vis(n, false);
        int ans = 0;
        dfs(A, vis, 0, n, -1, ans);
        
        return ans;
    }
    
private:
    void dfs(vector<int> &arr, vector<bool> &vis, int dep, int n, int lastNum, int &ans) {
        if(dep >= n) {
            ++ ans;
            return ;
        }
        
        for(int i = 0; i < n; ++ i) {
            if(vis[i]) {
                continue;
            }
            
            long long sum = (long long)lastNum + arr[i];
            long long v = sum <= 0 ? 0 : sqrt(sum);
            if(lastNum == -1 || v*v == sum) {
                vis[i] = true;
                dfs(arr, vis, dep + 1, n, arr[i], ans);
                vis[i] = false;
            }
            while(i < n - 1 && arr[i] == arr[i + 1]) {
                ++ i;
            }
        }
    }
};
