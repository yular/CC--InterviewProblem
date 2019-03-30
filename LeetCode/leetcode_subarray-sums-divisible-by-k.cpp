/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int ans = 0;
        if(A.size() == 0) {
            return ans;
        }
        
        int sum = 0;
        unordered_map<int,int> prefixSumModCnt;
        for(int a : A) {
            sum += a;
            int modV = (sum % K + K)%K;
            if(modV == 0) {
                ++ ans;
            }
            if(prefixSumModCnt.count(modV) != 0){
                ans += prefixSumModCnt[modV];
            }
            
            ++ prefixSumModCnt[modV];
        }
        return ans;
    }
};
