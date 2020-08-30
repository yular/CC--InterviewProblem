/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        if(arr.size() == 0 || m*k <= 0) {
            return false;
        }
        
        for(int i = 0; i + m*k <= arr.size(); ++ i) {
            bool isFound = true;
            for(int j = 0, c = 0; c < m*k && i + c < arr.size(); ++ c, j = (j + 1)%m) {
                if(arr[i + j] != arr[i + c]) {
                    isFound = false;
                    break;
                }
            }
            
            if(isFound) {
                return true;
            }
        }
        return false;
    }
};
