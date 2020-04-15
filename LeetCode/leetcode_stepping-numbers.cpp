/*
*
* Tag: DFS
* Time: O(9^(lg(high)))
* Space: O(9^(lg(high)))
*/

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        if(low > high) {
            return {};
        }
        
        if(low == high) {
            return {high};
        }
        
        set<int> vis;
        if(low <= 0) {
            vis.insert(0);
        }
        fillInSteppingNumbers(vis, low, high);
        
        vector<int> ans(vis.begin(), vis.end());
        return ans;
    }
private:
    void fillInSteppingNumbers(set<int> &vis, int low, int high) {
        for(int i = 1; i <= 9; ++ i) {
            long long num = 0;
            generateSteppingNumbers(vis, i, num, low, high);
        }
        
        return ;
    }
    
    void generateSteppingNumbers(set<int> &vis, int cur, long long num, int low, int high) {
        num = num*10 + cur;
        if(num > high) {
            return ;
        }
        if(num >= low && num <= high && vis.count(num) == 0) {
            vis.insert(num);
        }
        
        if(cur >= 1) {
            generateSteppingNumbers(vis, cur - 1, num, low, high);
        }
        if(cur < 9) {
            generateSteppingNumbers(vis, cur + 1, num, low, high);
        }
    }
};
