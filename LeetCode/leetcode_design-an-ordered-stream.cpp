/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class OrderedStream {
private:
    vector<string> arr;
    int ptr;
public:
    OrderedStream(int n) {
        arr.resize(n+1);
        ptr = 1;
    }
    
    vector<string> insert(int id, string value) {
        arr[id] = value;
        if(id != ptr) {
            return {};
        }
        
        vector<string> ans;
        string cur = "";
        for(; ptr < arr.size() && arr[ptr] != ""; ++ ptr) {
            cur = arr[ptr];
            ans.push_back(cur);
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
