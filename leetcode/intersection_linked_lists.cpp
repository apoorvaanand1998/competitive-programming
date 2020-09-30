class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        
        for (ListNode* curr = headA; curr != NULL; curr = curr->next) {
            ++lenA;
        }
        
        for (ListNode* curr = headB; curr != NULL; curr = curr->next) {
            ++lenB;
        }
        
        ListNode* greater = headA;
        ListNode* lesser = headB;
        if (lenA > lenB) {
            while (lenA > lenB) {
                greater = greater->next;
                --lenA;
            }
        } else {
            greater = headB;
            lesser = headA;
            while (lenB > lenA) {
                greater = greater->next;
                --lenB;
            }
        }
        
        while (greater != lesser) {
            greater = greater->next;
            lesser = lesser->next;
        }
        return greater;
    }
};
