/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        stack<int>st;
        Node *temp=head;
        while(temp!=NULL){
            st.push(temp->data);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            int value=st.top();
            st.pop();
            temp->data=value;
            temp=temp->next;
        }
        return head;
    }
};