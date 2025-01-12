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

/* Solution 2 - swaps when we find a negative value, same O(n) space as S1, but much less in reality */
class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val < 0) {
                ListNode* temp = new ListNode(curr->next->val);
                temp->next = head;
                head = temp;
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};


/* Solution 1 - Passed, uses multiple pointers, construct brand new list
class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* right_start = new ListNode(-1);

        ListNode* left = nullptr;
        ListNode* right = right_start;
        
        ListNode* left_end = nullptr;

        ListNode* current = head;
        while (current != nullptr) {
            if (current->val < 0) {
                ListNode* temp = new ListNode(current->val);
                temp->next = left;
                if (left_end == nullptr) left_end = temp;
                left = temp;
            } else {
                right->next = new ListNode(current->val);
                right = right->next;
            }

            current = current->next;
        }
        if (left == nullptr) return right_start->next;
        left_end->next = right_start->next;
        return left;
    }

    void print(ListNode* root) {
        ListNode* curr = root;
        while (curr != nullptr) {
            cout << curr->val << ", ";
            curr = curr->next;
        }
    }
}; */
