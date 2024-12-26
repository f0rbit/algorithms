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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* curr = head;
        int index = 0;
        while (curr != nullptr) {
            index++;

            // once we get to m, we need to find the node at m+n
            // if the we don't have the length to find m+n, then cut off the rest
            // of the linked list.
            if (index == m) {
                ListNode* end = curr->next;
                while (end != nullptr) {
                    index++;

                    if (index == m+n || end->next == nullptr) {
                        // if end->next is nullptr (ran out of elements, this will remove the tail end of the list)
                        curr->next = end->next; 
                        break; // get out of the while loop
                    }

                    end = end->next;
                }
                index = 0; // start counting again
            }

            curr = curr->next;
        }

        return head;
    }
};
