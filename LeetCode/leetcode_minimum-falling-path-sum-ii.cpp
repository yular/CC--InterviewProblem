/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if(arr.size() == 0 || (arr.size() > 1 && arr[0].size() == 1)){
            return 0;
        }
        
        vector<int> leftMin(arr[0].size()), rightMin(arr[0].size());
        updateMinVec(leftMin, rightMin, arr[arr.size() - 1]);
        for(int i = arr.size() - 2; i >= 0; -- i){
            for(int j = 0; j < arr[i].size(); ++ j){
                int sum = INT_MAX;
                if(j > 0) {
                    sum = min(sum, leftMin[j - 1]);
                }
                if(j < arr[i].size() - 1){
                    sum = min(sum, rightMin[j + 1]);
                }
                arr[i][j] = arr[i][j] + sum;
            }
            updateMinVec(leftMin, rightMin, arr[i]);
        }
        
        int ans = arr[0][0];
        for(int i = 1; i < arr[0].size(); ++ i){
            ans = min(ans, arr[0][i]);
        }
        return ans;
    }
    
private:
    void updateMinVec(vector<int> &leftMin, vector<int> &rightMin, vector<int> arr) {
        leftMin[0] = arr[0];
        for(int i = 1; i < arr.size(); ++ i){
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }
        
        rightMin[arr.size() - 1] = arr[arr.size() - 1];
        for(int i = arr.size() - 2; i >= 0; -- i){
            rightMin[i] = min(rightMin[i + 1], arr[i]);
        }
    }
};
