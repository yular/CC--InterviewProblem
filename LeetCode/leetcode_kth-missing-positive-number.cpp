/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.size() == 0) {
            return k;
        }
        
        int n = arr.size();
        for(int i = 0, start = 0; i < arr.size(); start = arr[i], ++ i) {
            if(arr[i] - start == 1) {
                continue;
            }
            
            if(start + k < arr[i]) {
                return start + k;
            }
            
            k -= (arr[i] - start - 1);
        }
        return arr[n - 1] + k;
    }
};
