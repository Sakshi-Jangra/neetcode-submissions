/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        if(ptr1 == NULL){
            if(ptr2 == NULL){
                return NULL;
            }
            return ptr2;
        }else if(ptr2 == NULL){
                return ptr1;
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* dummyPtr = dummyHead;

        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1->val < ptr2->val){
                dummyPtr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else{
                dummyPtr->next = ptr2;
                ptr2 = ptr2->next;
            }
            dummyPtr = dummyPtr->next;
        }

        while(ptr1 != NULL){
            dummyPtr->next = ptr1;
            ptr1 = ptr1->next;
            dummyPtr = dummyPtr->next;
        }
        while(ptr2 != NULL){
            dummyPtr->next = ptr2;
            ptr2 = ptr2->next;
            dummyPtr = dummyPtr->next;
        }
        return dummyHead->next;
    }
};