/*
* Algorithm: Brute force
* Time complexity: O(nlogn)
* Memory complexity: O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() == 0)
            return ;
        if(!next_permutation(num.begin(), num.end()))
            sort(num.begin(), num.end());
    }
};
