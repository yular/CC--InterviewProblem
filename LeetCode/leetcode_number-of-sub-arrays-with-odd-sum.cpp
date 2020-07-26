/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        
        long long ans = (arr[0]&1);
        vector<long long> cur(2, 0), nxt(2, 0);
        cur[(arr[0]&1)] = 1;
        for(int i = 1; i < arr.size(); ++ i) {
            nxt[0] = nxt[1] = 0;
            int u = (arr[i]&1);
            ++ nxt[u];
            
            for(int j = 0; j < 2; ++ j) {
                int v = (u + j)%2;
                nxt[v] = (cur[j] + nxt[v])%MOD;
            }
            
            for(int j = 0; j < 2; ++ j) {
                cur[j] = nxt[j];
            }
            ans = (ans + cur[1])%MOD;
        }
        return ans;
    }
};
