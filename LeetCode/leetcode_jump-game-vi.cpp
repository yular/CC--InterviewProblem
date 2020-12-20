/*
*
* Tag: DP
* Time: O(nlgk)
* Space: O(k)
*/

class Solution {
private:
    struct node {
        int val, idx;
        bool operator < (const node &a)const{
            return val < a.val;
        }
    };
public:
    int maxResult(vector<int>& nums, int k) {
        if(k == 0 || nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        
        node nd;
        nd.idx = 0, nd.val = nums[0];
        priority_queue<node> pq;
        pq.push(nd);
        
        int ans = INT_MIN, n = nums.size();
        for(int i = 1; i < n; ++ i) {
            int v = nums[i];
            
            while(!pq.empty()) {
                node nd = pq.top();
                if(i - nd.idx > k) {
                    pq.pop();
                    continue;
                }
                
                v = nd.val + nums[i];
                break;
            }
            if(i == n - 1) {
                ans = v;
            }
            node nd;
            nd.idx = i, nd.val = v;
            pq.push(nd);
        }
        return ans;
    }
};
