/*
*
* Tag: Math
* Time: O(n*sqrt(m))
* Space: O(1)
*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        for(int num : nums) {
            pair<int,int> res = getDivsSumOf(num);
            if(res.first == 4) {
                ans += res.second;
            }
        }
        return ans;
    }
    
private:
    pair<int,int> getDivsSumOf(int v) {
        pair<int,int> res = make_pair(2, 1 + v);
        for(int i = 2; i*i <= v; ++ i) {
            if(v%i == 0) {
                ++ res.first;
                res.second += i;
                if(res.first > 4) {
                    break;
                }
                if(v/i == i) {
                    continue;
                }
                
                ++ res.first;
                res.second += v/i;
            }
        }
        return res;
    }
};
