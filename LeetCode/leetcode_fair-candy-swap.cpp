/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> fruitSize;
        int sumOfA = 0, sumOfB = 0;
        for(int i = 0; i < A.size(); ++ i){
            sumOfA += A[i];
        }
        for(int i = 0; i < B.size(); ++ i){
            sumOfB += B[i];
            fruitSize.insert(B[i]);
        }
        vector<int> ans(2);
        int diff = (sumOfA - sumOfB)>>1;
        for(int i = 0; i < A.size(); ++ i){
            if(fruitSize.count(A[i] - diff) != 0){
                ans[0] = A[i];
                ans[1] = A[i] - diff;
            }
        }
        return ans;
    }
};
