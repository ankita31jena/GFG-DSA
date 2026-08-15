class Solution {
  public:

    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* addOne(Node* head) {

        // Reverse the list
        head = reverse(head);

        Node* curr = head;
        int carry = 1;

        while (curr != nullptr && carry) {

            int sum = curr->data + carry;

            curr->data = sum % 10;
            carry = sum / 10;

            if (curr->next == nullptr && carry) {
                curr->next = new Node(carry);
                carry = 0;
            }

            curr = curr->next;
        }

        // Reverse back
        head = reverse(head);

        return head;
    }
};