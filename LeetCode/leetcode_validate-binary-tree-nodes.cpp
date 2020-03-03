/*
*
* Tag: Tree
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n < 2) {
            return true;
        }
        
        vector<int> degCnt(n, 0);
        for(int i = 0; i < n; ++ i) {
            if(leftChild[i] >= 0) {
                ++ degCnt[leftChild[i]];
                if(degCnt[leftChild[i]] >= 2) {
                    return false;
                }
            }
            
            if(rightChild[i] >= 0) {
                ++ degCnt[rightChild[i]];
                if(degCnt[rightChild[i]] >= 2) {
                    return false;
                }
            }
        }
        
        int zeroDegCnt = 0;
        for(int i = 0; i < n; ++ i) {
            if(degCnt[i] == 0) {
                ++ zeroDegCnt;
            }
        }
        return zeroDegCnt == 1;
    }
};
