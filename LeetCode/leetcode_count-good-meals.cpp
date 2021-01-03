/*
*
* Tag: Math + Bit Manipulation
* Time: O(n)
* Space: O(n)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int countPairs(vector<int>& deliciousness) {
        if(deliciousness.size() < 2) {
            return 0;
        }
        
        unordered_map<int,int> numCnt;
        int maxVal = 0;
        for(int i = 0; i < deliciousness.size(); ++ i) {
            ++ numCnt[deliciousness[i]];
            maxVal = max(maxVal, deliciousness[i]);
        }
        
        long long ans = 0;
        for(auto it = numCnt.begin(); it != numCnt.end(); it ++) {
            int v = it->first;
            long long n = it->second;
            for(int mask = 1; mask - v <= maxVal; mask <<= 1) {
                if(mask < v) {
                    continue;
                }
                if(mask == v) {
                    ans += calVal(n, 0, v, numCnt);
                    ans %= MOD;
                    continue;
                }
                
                int u = ((mask-1)^v)+1;
                ans += calVal(n, u, v, numCnt);
                ans %= MOD;
            }
            numCnt[v] = 0;
        }
        return ans;
    }
private:
    inline long long calVal(long long n, int u, int v, unordered_map<int,int> &numCnt) {
        long long res = 0;
        if(numCnt.count(u) == 0) {
            return res;
        }
        
        if(u == v) {
            res = (n - 1)*n/2;
        } else {
            res = n*numCnt[u];
        }
        return res;
    }
};
