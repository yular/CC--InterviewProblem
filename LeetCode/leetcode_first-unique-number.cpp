/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/

class FirstUnique {
private:
    queue<int> q;
    unordered_map<int,bool> uniqNum;
public:
    FirstUnique(vector<int>& nums) {
        for(int num : nums) {
            if(uniqNum.count(num) != 0) {
                uniqNum[num] = true;
                continue;
            }
            
            uniqNum[num] = false;
            q.push(num);
        }
        
        return;
    }
    
    int showFirstUnique() {
        int res = -1;
        while(!q.empty()) {
            int cur = q.front();
            if(uniqNum[cur] == false) {
                res = cur;
                break;
            }
            
            q.pop();
        }
        
        return res;
    }
    
    void add(int value) {
        if(uniqNum.count(value) != 0) {
            uniqNum[value] = true;
            return;
        }
        
        uniqNum[value] = false;
        q.push(value);
        return ;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
