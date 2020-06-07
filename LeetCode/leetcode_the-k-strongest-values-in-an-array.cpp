/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(k)
*/

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if(arr.size() < 2) {
            return arr;
        }
        
        sort(arr.begin(), arr.end());
        
        cmp.m = arr[(int)(arr.size() - 1)/2];
        sort(arr.begin(), arr.end(), cmp);
        
         vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
private:
    struct comparator {
        int m;
        bool operator() (const int a, const int b) {
            return abs(a - m) == abs(b - m) ? b < a : abs(b - m) < abs(a - m);
        }
    } cmp;
};
