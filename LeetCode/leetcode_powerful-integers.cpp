/*
*
* Tag: Implementation
* Time: O((lgn)^2)
* Space: O(lgn)
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(x <= 0 || y <= 0) {
            return {};
        }
        
        vector<int> arrx, arry;
        fillInArr(x, bound, arrx);
        fillInArr(y, bound, arry);
        
        unordered_set<int> vis;
        for(int i = 0; i < arrx.size(); ++ i) {
            for(int j = 0; j < arry.size(); ++ j) {
                int sum = arrx[i] + arry[j];
                if(sum > bound) {
                    break;
                }
                vis.insert(sum);
            }
        }
        
        vector<int> ans(vis.begin(), vis.end());
        return ans;
    }
private:
    void fillInArr(int x, int bound, vector<int> &arr) {
        if(x == 1) {
            arr.push_back(1);
            return ;
        }
        
        long long res = 1;
        for(int i = 0; res <= bound; ++ i, res *= x) {
            arr.push_back(res);
        }
        
        return ;
    }
};
