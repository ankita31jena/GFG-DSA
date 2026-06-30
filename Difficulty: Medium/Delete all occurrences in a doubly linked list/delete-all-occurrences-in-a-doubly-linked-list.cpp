/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
Node* deleteAllOccurOfX(Node* head, int x) {

    Node* temp = head;

    while(temp != NULL){

        Node* nextNode = temp->next;

        if(temp->data == x){

            if(temp == head)
                head = nextNode;

            if(temp->prev != NULL)
                temp->prev->next = temp->next;

            if(temp->next != NULL)
                temp->next->prev = temp->prev;

            delete temp;
        }

        temp = nextNode;
    }

    return head;
}
};