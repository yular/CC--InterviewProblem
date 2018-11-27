/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name == typed){
            return true;
        }
        if(name.size() > typed.size()) {
            return false;
        }
        int indexOfName = 0, indexOfTyped = 0;
        for(; indexOfName < name.size() && indexOfTyped < typed.size(); ++ indexOfName, ++ indexOfTyped){
            if(indexOfTyped >= typed.size() || name[indexOfName] != typed[indexOfTyped]) {
                return false;
            }
            int cntOfNamed = getNumberOfContinuousSameCharacters(name, indexOfName);
            int cntOfTyped = getNumberOfContinuousSameCharacters(typed, indexOfTyped);
            if(cntOfNamed > cntOfTyped){
                return false;
            }
        }
        
        return indexOfName >= name.size() && indexOfTyped >= typed.size();
    }
private:
    int getNumberOfContinuousSameCharacters(string str, int &index) {
        int cnt = 1;
        while(index + 1 < str.size() && str[index] == str[index + 1]) {
                ++ index;
                ++ cnt;
        }
        return cnt;
    }
};
