#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* josephus(Node* head, int k) {
    if (!head || !head->next)
        return head;

    Node* curr = head;
    int count = 1;
    while (curr->next != curr) { // Loop until one node remains
        if (count == k) { // Check if count equals k
            std::cout << "Eliminated: " << curr->next->data << std::endl;
            Node* temp = curr->next; // Node to be eliminated
            curr->next = temp->next; // Bypass the eliminated node
            delete temp; // Free memory of eliminated node
            count = 1; // Reset count
        } else {
            curr = curr->next; // Move to the next node
            count++; // Increment count
        }
    }
    return curr; // Return the last remaining node
}

int main() {
    int n = 5, k = 3;
    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        curr->next = newNode;
        curr = newNode;
    }
    curr->next = head;  // Make the list circular

    Node* survivor = josephus(head, k);
    std::cout << "The survivor is: " << survivor->data << std::endl;

    // Cleanup the remaining node
    delete survivor;

    return 0;
}
