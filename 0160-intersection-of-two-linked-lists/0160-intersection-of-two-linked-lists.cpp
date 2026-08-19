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

        int lenA = 0;
        int lenB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;


        while(tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }

        while(tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if(lenA > lenB) {
            int x = lenA - lenB;

            for(int i = 1; i <= x; i++) {
                tempA = tempA->next;
            }
        }
        
        else if(lenB > lenA) {
            int y = lenB - lenA;

            for(int i = 1; i <= y; i++) {
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