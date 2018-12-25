/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        if(left > right){
            return ans;
        }
        for(int i = left; i <= right; ++ i){
            if(isSelfDividingNumber(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
private:
    bool isSelfDividingNumber(int v){
        int val = v;
        while(v > 0){
            if(v%10 == 0){
                return false;
            }
            int num = v%10;
            if(val%num != 0){
                return false;
            }
            v /= 10;
        }
        return true;
    }
};
