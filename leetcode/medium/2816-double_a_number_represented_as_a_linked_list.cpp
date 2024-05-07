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
    ListNode* doubleIt(ListNode* head) {
        ListNode* reversed = reverseList(head);
        
        ListNode* curr = reversed;
        ListNode* last = nullptr; // keep track of previous in order to add a carry at end
        int carry = 0;
        while (curr != nullptr) {
            int val = (curr->val << 1) + (carry);
            curr->val = val % 10;
            carry = val / 10;
            last = curr;
            curr = curr->next;
        }
        if (carry >= 1) {
            last->next = new ListNode(carry);
        }

        return reverseList(reversed);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};
