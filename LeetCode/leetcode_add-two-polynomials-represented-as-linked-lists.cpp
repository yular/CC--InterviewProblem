/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        if(poly1 == NULL && poly2 == NULL) {
            return NULL;
        }
        
        map<int,int> dict;
        for(PolyNode* p = poly1; p != NULL; p = p->next) {
            dict[p->power] += p->coefficient;
        }
        for(PolyNode* p = poly2; p != NULL; p = p->next) {
            dict[p->power] += p->coefficient;
        }
        
        PolyNode head;
        PolyNode* p = &head;
        for(auto it = dict.rbegin(); it != dict.rend(); it ++) {
            if(it->second == 0) {
                continue;
            }
            
            PolyNode* nd = new PolyNode(it->second, it->first);
            p->next = nd;
            p = p->next;
        }
        return head.next;
    }
};
