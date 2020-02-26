/*
*
* Tag: Recusrion
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(head == NULL) {
            return ;
        }
        
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};
