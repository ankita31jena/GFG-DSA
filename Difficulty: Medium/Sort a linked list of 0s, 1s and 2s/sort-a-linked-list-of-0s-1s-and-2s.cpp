class Solution {
  public:
    Node* segregate(Node* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        Node zeroDummy(0);
        Node oneDummy(0);
        Node twoDummy(0);

        Node* zero = &zeroDummy;
        Node* one = &oneDummy;
        Node* two = &twoDummy;

        Node* curr = head;

        while (curr != nullptr) {

            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            }
            else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            }
            else {
                two->next = curr;
                two = two->next;
            }

            curr = curr->next;
        }

        // Terminate the 2s list
        two->next = nullptr;

        // Connect 0s -> 1s -> 2s
        zero->next = (oneDummy.next != nullptr) ? oneDummy.next : twoDummy.next;

        one->next = twoDummy.next;

        return zeroDummy.next;
    }
};