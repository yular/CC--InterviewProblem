/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if(A.size() == 0){
            return 0;
        }
        
        int ans = INT_MIN, maxSightseeing = A[A.size() - 1] - A.size() + 1;
        for(int i = A.size() - 2; i >= 0; -- i){
            ans = max(ans, A[i] + i + maxSightseeing);
            maxSightseeing = max(maxSightseeing, A[i] - i);
        }
        return ans;
    }
};
