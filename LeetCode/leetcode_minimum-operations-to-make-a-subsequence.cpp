/*
*
* Tag: DP
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        if(target.size() == 0) {
            return 0;
        }
        
        unordered_map<int,int> dict;
        for(int i = 0; i < target.size(); ++ i) {
            dict[target[i]] = i;
        }
        
        int m = target.size(), n = arr.size(), top = 0;
        vector<int> stk(n + 5, 0);
        for(int i = 0; i < n; ++ i) {
            if(dict.count(arr[i]) == 0) {
                continue;
            }
            int v = dict[arr[i]];
            if(top == 0) {
                stk[top ++] = v;
                continue;
            }
            
            if(v < stk[0]) {
                stk[0] = v;
            } else if(v > stk[top - 1]) {
                stk[top ++] = v;
            } else {
                int left = 0, right = top;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (stk[mid] < v) left = mid + 1;
                    else right = mid;
                }
                stk[right] = v;
            }
        }
        return m - top;
    }
};
