/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W != 0){
            return false;
        }
        
        map<int,int> numCnt;
        for(int c : hand){
            ++ numCnt[c];
        }
        
        while(numCnt.size() > 0) {
            if(numCnt.size() < W){
                return false;
            }
            
            int groupSize = 0;
            int lastVal = -1;
            for(auto it = numCnt.begin(); it != numCnt.end() && groupSize < W; it ++) {
                if(lastVal > 0 && lastVal + 1 != it->first) {
                    return false;
                }
                ++ groupSize;
                it->second --;
                lastVal = it->first;
                if(it->second > 0) {
                    continue;
                }
                numCnt.erase(it->first);
            }
            if(groupSize < W) {
                return false;
            }
        }
        return true;
    }
};
