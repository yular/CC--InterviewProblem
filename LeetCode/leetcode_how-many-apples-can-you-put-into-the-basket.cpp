/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        if(arr.size() == 0){
            return 0;
        }
        
        sort(arr.begin(), arr.end());
        int ans = 0, sum = 0;
        for(int v : arr){
            sum += v;
            if(sum > 5000) {
                break;
            }
            
            ++ ans;
        }
        return ans;
    }
};
