/*
*
* Tag: Array
* Time: O(1)
* Space: O(n)
*/
class MyHashSet {
private:
    const int N = 1100000;
public:
    vector<bool> hash;
    /** Initialize your data structure here. */
    MyHashSet() {
        hash.resize(N);
        fill(hash.begin(), hash.end(), false);
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
