/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> dict(arr.begin(), arr.end());
        int ans = 0;
        for(int v : arr) {
            if(dict.count(v + 1) > 0) {
                ++ ans;
            }
        }
        return ans;
    }
};
