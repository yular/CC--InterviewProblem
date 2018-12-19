/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()){
            return false;
        }
        if(A == B){
            return true;
        }
        for(int startPos = 1; startPos < A.size(); ++ startPos){
            if(isRotatedStringsEqual(A, startPos, B)){
                return true;
            }
        }
        return false;
    }
private:
    bool isRotatedStringsEqual(string A, int startPos, string B){
        int posOfB = 0;
        for(int i = startPos; posOfB < B.size(); i = (i + 1)%A.size(), ++ posOfB){
            if(A[i] != B[posOfB]) {
                return false;
            }
        }        
        return true;
    }
};
