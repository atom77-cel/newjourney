/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;      // Stack-allocated dummy node
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    int carry = 0;

    // Loop until both lists are fully traversed and no carry remains
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;     // Note: LeetCode uses 'val' instead of 'data'
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;       // Compute carry for the next place value

        // Allocate memory for the current digit node
        struct ListNode *sumnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        sumnode->val = sum % 10;
        sumnode->next = NULL;

        tail->next = sumnode;   // Attach new node to the list
        tail = tail->next;      // Move tail forward
    }

    return dummy.next;          // Return head of the resulting list
}