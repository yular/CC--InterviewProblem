/*
*
* Tag: Map (AVL)
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() != nums2.size()) {
            return -1;
        }
        
        long long ans = 0, maxVal = 0;
        map<int,int> numCnt;
        for(int i = 0; i < nums1.size(); ++ i) {
            ans += abs(nums1[i] - nums2[i]);
            ++ numCnt[nums1[i]];
            maxVal = max((long long)nums1[i], maxVal);
        }
        
        long long tmp = ans;
        for(int i = 0; i < nums1.size(); ++ i) {
            if(nums1[i] == nums2[i]) {
                continue;
            }
            auto it = numCnt.lower_bound(nums2[i]);
            if(it == numCnt.end()) {
                cout<<i<<" "<<maxVal<<endl;
                ans = min(ans, tmp - abs(nums1[i] - nums2[i]) + abs(maxVal - nums2[i]));
                continue;
            }
            ans = min(ans, tmp - abs(nums1[i] - nums2[i]) + abs(it->first - nums2[i]));
            if(it == numCnt.begin()) {
                continue;
            }
            it --;
            ans = min(ans, tmp - abs(nums1[i] - nums2[i]) + abs(it->first - nums2[i]));
        }
        return ans%MOD;
    }
};
