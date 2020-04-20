/*
*
* Tag: Hash, Math
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() == 0) {
            return false;
        }
        
        unordered_map<int,int> numCnt;
        int maxCnt = 0;
        for(int c : deck) {
            ++ numCnt[c];
            maxCnt = max(maxCnt, numCnt[c]);
        }
        if(maxCnt < 2) {
            return false;
        }
        if(numCnt.size() == 1) {
            return true;
        }
        
        auto it = numCnt.begin();
        int gcdVal = it->second;
        for(it ++; it != numCnt.end(); it ++) {
            gcdVal = gcd(gcdVal, it->second);
        }
        return gcdVal >= 2;
    }
    
private:
    int gcd(int a, int b) {
        return b == 0? a : gcd(b, a%b);
    }
};
