/*
*
* Tag: DFS
* Time: O(n^m)
* Space: Space: O(n)
*/

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        if(nums.size() == 0 && quantity.size() > 0) {
            return false;
        }
        
        unordered_map<int,int> numDict;
        for(int num : nums) {
            ++ numDict[num];
        }
        vector<int> freqs(numDict.size());
        int idx = 0;
        for(auto it : numDict) {
            freqs[idx ++] = it.second;
        }
        
        sort(freqs.begin(), freqs.end(), greater<int>());
        sort(quantity.begin(), quantity.end(), greater<int>());
        
        return canAssignNum(freqs, quantity, 0);
    }
    
private:
    bool canAssignNum(vector<int> &freqs, vector<int>& quantity, int idx) {
        if(idx >= quantity.size()) {
            return true;
        }
        
        for(int &freq : freqs) {
            if(freq < quantity[idx]) {
                continue;
            }
            
            freq -= quantity[idx];
            if(canAssignNum(freqs, quantity, idx + 1)) {
                return true;
            }
            freq += quantity[idx];
        }
        return false;
    }
};
