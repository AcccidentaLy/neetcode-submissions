class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dummy 放在真正的 head 前面
        ListNode dummy(0, head);

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // fast 先走 n + 1 步
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // fast 到达结尾时，slow 正好在待删除节点的前面
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = nodeToDelete->next;
        delete nodeToDelete;

        return dummy.next;
    }
};
