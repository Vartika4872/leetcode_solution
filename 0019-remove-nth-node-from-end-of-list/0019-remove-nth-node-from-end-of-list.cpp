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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create dummy node to handle edge case (removing head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete the target node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return dummy->next;
    }
};