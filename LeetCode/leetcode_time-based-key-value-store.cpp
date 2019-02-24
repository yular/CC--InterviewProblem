/*
*
* Tag: Hash + BST
* Time: O(lgn) for both Get and Set operation
* Space: O(n)
*/
class TimeMap {
private:
    unordered_map<string,map<int,string>> storage;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        storage.clear();
    }
    
    void set(string key, string value, int timestamp) {
        storage[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(storage.count(key) == 0){
            return "";
        }
        if(storage[key].count(timestamp) != 0){
            return storage[key][timestamp];
        }
        auto it = storage[key].begin();
        if(it->first > timestamp) {
            return "";
        }
        auto rit = storage[key].rbegin();
        if(rit->first < timestamp) {
            return rit->second;
        }
        
        it = storage[key].lower_bound(timestamp);
        -- it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
