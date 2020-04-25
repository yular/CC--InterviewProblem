/*
*
* Tag: Binary Search
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        
        int cnt = 0;
        for(int v : arr1) {
            if(canFindValue(v, d, arr2)) {
                ++ cnt;
            }
        }
        return arr1.size() - cnt;
    }
private:
    bool canFindValue(int v, int d, vector<int>&arr) {
        int l = 0, r = arr.size() - 1;
        while(l <= r) {
            int mid = (l + r)>>1;
            if(abs(arr[mid] - v) <= d) {
                return true;
            } else if(v < arr[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
