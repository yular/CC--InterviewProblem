/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) {
            return head;
        }
        
        getLastNodeOf(head);
        return head;
    }
private:
    Node* getLastNodeOf(Node* head){
        Node *p = head;
        while(p->next != NULL || p->child != NULL) {
            if(p->child != NULL) {
                Node *tail = getLastNodeOf(p->child);
                Node *curNext = p->next;
                p->next = p->child;
                p->next->prev = p;
                p->child = NULL;
                tail->next = curNext;
                if(curNext != NULL){
                    curNext->prev = tail;
                }
                p = tail;
            }
            if(p->next == NULL) {
                break;
            }
            
            p = p->next;
        }
        
        return p;
    }
};
