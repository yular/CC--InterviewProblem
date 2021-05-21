/*
*
* Tag: Hash
* Time: O(1) , O(n)
* Space: O(n)
*/

class FindSumPairs {
private:
    vector<long long> nums1;
    unordered_map<long long,int> nums2;
    unordered_map<int,long long> num2idx;
public:
    FindSumPairs(vector<int>& _nums1, vector<int>& _nums2) {
        nums1.resize(_nums1.size());
        for(int i = 0; i < _nums1.size(); ++ i) {
            nums1[i] = _nums1[i];
        }
        sort(nums1.begin(), nums1.end());
        
        for(int i = 0; i < _nums2.size(); ++ i) {
            int v = _nums2[i];
            ++ nums2[v];
            num2idx[i] = v;
        }
    }
    
    void add(int index, int val) {
        int v = num2idx[index];
        num2idx[index] += val;
        -- nums2[v];
        
        nums2[num2idx[index]] ++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i < nums1.size() && nums1[i] <= tot; ++ i) {
            long long v = tot - nums1[i];
            if(nums2.count(v) > 0) {
                res += nums2[v];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
