/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        if(!num)
            return false;
        for(int i = 0; i < 3; ++ i){
            while(num%fact[i] == 0)
                num /= fact[i];
        }
        return num == 1;
    }
private:
int fact[3]={2,3,5};
};
