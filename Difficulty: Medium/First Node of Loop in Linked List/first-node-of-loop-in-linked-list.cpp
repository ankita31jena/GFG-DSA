class Solution {
  public:
    int cycleStart(Node* head) {

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No cycle
        if (fast == nullptr || fast->next == nullptr)
            return -1;

        // Step 2: Find first node of cycle
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }
};