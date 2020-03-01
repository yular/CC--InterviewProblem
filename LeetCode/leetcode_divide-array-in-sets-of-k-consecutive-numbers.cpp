/*
*
* Tag: Hash, Implementation
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(k > nums.size() || nums.size()%k != 0) {
            return false;
        }
        
        map<int,int> numCnt;
        for(int num : nums) {
            ++ numCnt[num];
        }
        
        while(numCnt.size() > 0){
            int last = -1, setSize = 0;
            for(auto it = numCnt.begin(); it != numCnt.end(); ++ it){
                int cur = it->first;
                -- numCnt[cur];
                if(numCnt[cur] == 0) {
                    numCnt.erase(cur);
                }
                
                if(last != -1 && last + 1 < cur) {
                    return false;
                }
                ++ setSize;
                if(setSize >= k) {
                    break;
                }
                
                last = cur;
            }
            if(setSize < k) {
                return false;
            }
        }
        return true;
    }
};
