/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    struct Num {
        int val, label;
    };
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        if(num_wanted <= 0 || use_limit <= 0) {
            return 0;
        }
        
        int n = values.size();
        vector<Num> nums(n);
        for(int i = 0; i < n; ++ i){
            Num num;
            num.val = values[i], num.label = labels[i];
            nums[i] = num;
        }
        
        sort(nums.begin(), nums.end(), cmp);
        
        unordered_map<int,int> labelCnt;
        int ans = 0, numCnt = 0;
        for(Num num : nums) {
            ++ labelCnt[num.label];
            if(labelCnt[num.label] > use_limit){
                continue;
            }
            
            ans += num.val;
            ++ numCnt;
            if(numCnt >= num_wanted) {
                break;
            }
        }
        return ans;
    }
private:
    struct comparator {
        bool operator() (const Num &a, const Num &b) {
            return b.val < a.val;
        }
    }cmp;
};
