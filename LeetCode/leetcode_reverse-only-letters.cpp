/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int leftPointer = 0, rightPointer = S.size() - 1;
        while(leftPointer < rightPointer) {
            if(!isalpha(S[leftPointer])){
                leftPointer ++;
                continue;
            }
            if(!isalpha(S[rightPointer])){
                rightPointer --;
                continue;
            }
            swap(S[leftPointer], S[rightPointer]);
            leftPointer ++;
            rightPointer --;
        }
        return S;
    }
};
