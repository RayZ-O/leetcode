// Sort a linked list in O(n log n) time using constant space complexity.

class Solution {
    ListNode* halfSplit(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* half = slow->next;
        slow->next = nullptr;
        return half;
    }

    ListNode* merge(ListNode* l1, ListNode*l2) {
        ListNode head(0);
        ListNode* cur = &head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                while (l1 && l1->val <= l2->val) {
                    cur = l1;
                    l1 = l1->next;
                }
            } else {
                cur->next = l2;
                while (l2 && l1->val > l2->val) {
                    cur = l2;
                    l2 = l2->next;
                }
            }
        }
        cur->next = l1 ? l1 : l2;
        return head.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* half = halfSplit(head);
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(half);
        return merge(l1, l2);
    }
};

