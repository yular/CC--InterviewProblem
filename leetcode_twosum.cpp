class Solution {
private:
struct num{
    int val, idx;
    bool operator < (const num a)const{
        return val < a.val;
    }
};
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<num> num_list;
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i ++){
            num tmp;
            tmp.val = numbers[i];
            tmp.idx = i + 1;
            num_list.push_back(tmp);
        }
        sort(num_list.begin(), num_list.end());
        int low = 0, high = num_list.size() - 1;
        while(low <= high){
            int low_val = num_list[low].val, high_val = num_list[high].val;
            if(low_val + high_val == target){
                ans.push_back(min(num_list[low].idx, num_list[high].idx));
                ans.push_back(max(num_list[low].idx, num_list[high].idx));
                break;
            }else if(low_val + high_val < target)
                low ++;
            else
                high --;
        }
        return ans;
    }
};

