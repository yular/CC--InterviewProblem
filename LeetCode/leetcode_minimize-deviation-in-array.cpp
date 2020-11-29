/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
* Credit: 
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        
        set<int> numDict;
        for(int num : nums) {
            if(num%2 == 1) {
                numDict.insert(num*2);
            } else {
                numDict.insert(num);
            }
        }
        
        int ans = *numDict.rbegin() - *numDict.begin();
        while (*numDict.rbegin() % 2 == 0) {
            numDict.insert(*numDict.rbegin() / 2);
            numDict.erase(*numDict.rbegin());
            ans = min(ans, *numDict.rbegin() - *numDict.begin());
        }
        return ans;
    }
};
