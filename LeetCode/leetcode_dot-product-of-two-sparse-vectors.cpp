/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class SparseVector {
public:
    unordered_map<int,int> numDict;
    int numSize;
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] != 0) {
                numDict[i] = nums[i];
            }
        }
        numSize = nums.size();
        
        return ;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if(vec.numSize != numSize) {
            return 0;
        }
        
        int res = 0;
        for(auto it : vec.numDict) {
            int idx = it.first;
            if(numDict.count(idx) > 0) {
                res += it.second*numDict[idx];
            }
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
