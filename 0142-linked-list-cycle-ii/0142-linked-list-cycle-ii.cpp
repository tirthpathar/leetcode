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
    ListNode *detectCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                break;
            }

        }
        if(slow != fast) {
            return NULL;
        }

        while(temp != NULL && temp->next != NULL) {
            if(slow == temp) {
                return slow;
            }

            slow = slow->next;
            temp = temp->next;

            

        }

        return NULL;
        
        
        
        
    }
};