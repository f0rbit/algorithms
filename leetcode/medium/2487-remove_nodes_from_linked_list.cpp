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
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* node = head;
        ListNode* greater = removeNodes(node->next);

        node->next = greater;
        if (greater == nullptr || node->val >= greater->val) {
            return node;
        }
        return greater;
    }
};
