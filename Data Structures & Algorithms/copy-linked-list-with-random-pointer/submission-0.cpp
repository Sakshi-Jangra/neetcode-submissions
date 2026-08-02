/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
 
        // preserve the LL node map
        unordered_map<Node*, Node*> m;
        Node* deepCopy = new Node(head->val);   // Initialise the head address of deepCopy by copying old head
        // iterators
        Node* oldtemp = head->next;
        Node* newtemp = deepCopy;   

        // preserving the head of oldListNode <-> head of deepcopyNode map
        m[head] = deepCopy;

        // Iterate & copy original LL
        while(oldtemp != NULL){
            Node* copyNode = new Node(oldtemp->val);
            // preserving the oldListNode <-> deepcopyNode map
            m[oldtemp] = copyNode;
            // insert the newly created copy node to deepCopy LL
            newtemp->next = copyNode;
            // move old & new temp iterators ahead
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        // re-init iterators to heads
        oldtemp = head;
        newtemp = deepCopy;

        // re-iterate to replicate the random connections
        while(oldtemp != NULL){
           newtemp->random = m[oldtemp->random];      // using the preseved random connection
           // move old & new temp iterators ahead
           oldtemp = oldtemp->next;
           newtemp = newtemp->next;
        }
        return deepCopy;
    }
};
