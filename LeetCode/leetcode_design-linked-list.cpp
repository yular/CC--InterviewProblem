/*
*
* Tag: Linked List, Design
* Time: O(n), O(1)
* Space: O(n)
*/

class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
        Node(int v): val(v), next(NULL){}
    };
    int len;
    Node *head, *tail;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        len = 0;
        head = new Node(0);
        tail = new Node(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= len) {
            return -1;
        }
        
        Node *p = head->next;
        for(int i = 0; i < index; ++ i, p = p->next);
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        if(tail->next == NULL) {
            tail->next = newNode;
        }
        ++ len;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        if(tail->next != NULL) {
            tail->next->next = newNode;
        }
        tail->next = newNode;
        
        if(head->next == NULL) {
            head->next = newNode;
        }
        ++ len;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > len) {
            return;
        }
        
        if(index == len) {
            addAtTail(val);
            return ;
        }
        
        Node *newNode = new Node(val);
        Node *p = head;
        for(int i = 0; i < index; ++ i, p = p->next) ;
        
        newNode->next = p->next;
        p->next = newNode;
        ++ len;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= len) {
            return;
        }
        
        Node *cur = head->next, *prev = head;
        for(int i = 0; i < index; ++ i, cur = cur->next, prev = prev->next) ;
        
        prev->next = cur->next;
        cur->next = NULL;
        if(index == len - 1){
            tail->next = prev;
        }
        -- len;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
