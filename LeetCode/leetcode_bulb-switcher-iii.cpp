/*
*
* Tag: Fenwick Tree
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& lights) {
        if(lights.size() == 0) {
            return 0;
        }
        
        vector<int> tree(lights.size() + 2, 0);
        int ans = 0, cntLight = 0;
        for(int light : lights){
            updateTree(tree, light);
            ++ cntLight;
            if(cntLight == sumTree(tree, cntLight)) {
                ++ ans;
            }
        }
        return ans;
    }
private:
    void updateTree(vector<int> &tree, int start) {
        for(int i = start; i < tree.size(); i += lowbit(i)) {
            ++ tree[i];
        }
        
        return ;
    }
    
    int sumTree(vector<int> &tree, int start) {
        int res = 0;
        for(int i = start; i > 0; i -= lowbit(i)) {
            res += tree[i];
        }
        return res;
    }
    
    int lowbit(int x) {
        return x&-x;
    }
};
