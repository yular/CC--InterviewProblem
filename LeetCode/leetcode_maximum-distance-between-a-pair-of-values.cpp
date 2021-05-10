/*
*
* Tag: Tree Map
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) {
            return 0;
        }
        
        int ans = 0, n = nums1.size(), m = nums2.size();
        map<int,int> numDict;
        for(int i = n - 1, j = m - 1; i >= 0; -- i) {
            while(j >= i) {
                numDict[nums2[j]] = max(numDict[nums2[j]], j);
                -- j;
            }
            
            auto it = numDict.lower_bound(nums1[i]);
            if(it == numDict.end()) {
                continue;
            }
            int dis = abs(it->second - i);
            ans = max(ans, dis);
        }
        return ans;
    }
};
