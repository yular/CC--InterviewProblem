/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size() == 0) {
            return false;
        }
        if(arr.size() == 1) {
            return true;
        }
        
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for(int i = 2; i < arr.size(); ++ i) {
            if(arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};
