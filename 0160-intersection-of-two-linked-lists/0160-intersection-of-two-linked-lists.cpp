/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int getLength(ListNode* head){
    int len = 0; 
    while(head){
        len++;
        head = head->next;
    }
    return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int lenA = getLength(headA);
       int lenB = getLength(headB);

       int diff = abs(lenA - lenB);

       ListNode* a = headA;
       ListNode* b = headB;

       if(lenA > lenB){
        while(diff--)a = a->next;
       } 
       else{
        while(diff--)b = b->next;
       }

       while(a && b){
        if(a == b)
        return a;

        a = a->next;
        b = b->next;
       }
       return NULL;
    }
};