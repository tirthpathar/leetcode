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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        int countA = 0;
        int countB = 0;

        while(tempA != NULL) {
            countA++;
            tempA = tempA->next;
        }
        
        while(tempB != NULL) {
            countB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if(countA > countB) {
            for(int i = 1; i <= countA-countB; i++) {
                tempA = tempA->next;
            }
        }

        else {
            
            for(int i = 1; i <= countB-countA; i++) {
                tempB = tempB->next;
            }
        }

        while(tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;
        }

        

    return tempA;





    }
};