/*
*
* Tag: Hash Map
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int,int> sumCntMap;
        sumCntMap[0] = 1;
        
        int ans = 0, sum = 0;
        for(int i = 0; i < A.size(); ++ i){
            sum += A[i];
            if(sum >= S){
                ans += sumCntMap[sum - S];
            }
            ++ sumCntMap[sum];
        }
        
        return ans;
    }
};
