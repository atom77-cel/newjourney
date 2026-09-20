/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (1) {
        
        struct ListNode* checker = prev;
        for (int i = 0; i < k; i++) {
            checker = checker->next;
            if (checker == NULL) {
                return dummy.next;
            }
        }

      
        struct ListNode* curr = prev->next;
        for (int i = 0; i < k - 1; i++) {
            struct ListNode* then = curr->next;
            curr->next = then->next;
            then->next = prev->next;
            prev->next = then;
        }

        
        prev = curr;
    }

    return dummy.next;
}