/*
*
* Tag: Trie
* Time: O(n^2)
* Space: O(1)
*/

struct node{
    node* a[2];
    int n = 0;
    node()
    {
        a[0] = nullptr;
        a[1] = nullptr;
    }
    void insert(int v, int i)
    {
        n++;
        if (i < 0)
        {
            return;
        }
        int bit =  v & (1 << i);
        int p = (bit == 0) ? 0 : 1;
        if (a[p] == nullptr)
        {
            a[p] = new node();
        }
        a[p]->insert(v, i-1);
    }
};
class Solution {
public:
    int n;
    node * root;
    int l;
    int h;
    
    int visit(int v, int prefix, int len, node* r) {
        if (r == nullptr) return 0;
        int ans = 0;
        int bit = v & (1 << len);

        int mask = (0xffffffff) << len;
        int xorpre = (prefix ^ v) & mask;
        int lm = (l & mask);
        int hm = (h & mask);

        if (xorpre < lm)
        {
            return 0;
        }
        else if (xorpre == lm || xorpre == hm)
        {
            if (len > 0)
            {
                ans += visit(v, prefix , len - 1, r->a[0]);
                ans += visit(v, prefix | (1 << (len - 1)), len - 1, r->a[1]);
            }
            else
            {
                return r->n;
            }
        }
        else if (xorpre > lm && xorpre < hm){
            ans += r->n;
        }
        else
        {
            return 0;
        }
        return ans;
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        n = nums.size();
        root = new node();
        l = low;
        h = high;
        int len = 14;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            int ans = visit(nums[i], 0, len + 1, root);
            res += ans;
            root->insert(nums[i], len);
        }
        return res;
    }
};
