/*
*
* Tag: Math
* Time: O(nlgm)
* Space: O(lgm)
*/
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.size() == 0){
            return false;
        }
        
        int allGcd = nums[0];
        for(int i = 1; i < nums.size(); ++ i){
            allGcd = gcd(allGcd, nums[i]);
            if(allGcd == 1){
                break;
            }
        }
        return allGcd == 1;
    }
private:
    int gcd(int a, int b) {    
        return b == 0? a : gcd(b, a % b); 
    } 
};
