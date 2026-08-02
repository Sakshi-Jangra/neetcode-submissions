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
        ListNode* pt1= l1;
        ListNode* pt2= l2;
        ListNode* dummyNode=new ListNode(-1);  //random value in dummyNode. here -1
        ListNode* pt3= dummyNode;
        
        while(pt1!=NULL && pt2!=NULL){
            if(pt1->val < pt2->val){
                pt3->next=pt1;
                pt1=pt1->next;
            }
            else{
                pt3->next=pt2;
                pt2=pt2->next;
            }
            pt3=pt3->next;
        }
        
        while(pt1!=NULL){
            pt3->next=pt1;
            pt3=pt3->next;
            pt1=pt1->next;
        }
        
        while(pt2!=NULL){
            pt3->next=pt2;
            pt3=pt3->next;
            pt2=pt2->next;
        }
        
        return dummyNode->next;
    }
};