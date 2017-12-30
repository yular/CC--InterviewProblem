/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /*
     * @param : the given array
     * @param : the window size
     * @return: the sum of the count of unique elements in each window
     */
    int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
        int sum = 0;
        if(nums.size() == 0 || k == 0)
            return sum;
        int numOfUniqElements = 0;
        unordered_map<int,int> elementsCount;
        
        int idx = 0;
        for(; idx < min(k, (int)nums.size()); ++ idx) {
            ++ elementsCount[nums[idx]];
            if(elementsCount[nums[idx]] == 1)
                ++ numOfUniqElements;
            else if(elementsCount[nums[idx]] == 2)
                -- numOfUniqElements;
        }
        sum += numOfUniqElements;
        
        for(; idx < nums.size(); ++ idx){
            -- elementsCount[nums[idx - k]];
            if(elementsCount[nums[idx - k]] == 1)
                ++ numOfUniqElements;
            else if(elementsCount[nums[idx - k]] == 0)
                -- numOfUniqElements;
            ++ elementsCount[nums[idx]];
            if(elementsCount[nums[idx]] == 1)
                ++ numOfUniqElements;
            else if(elementsCount[nums[idx]] == 2)
                -- numOfUniqElements;
            sum += numOfUniqElements;
        }
        
        return sum;
    }
};
