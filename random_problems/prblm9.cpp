#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int calculate_sum(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

int main() {
    
    Node* head = new Node{30, nullptr};
    head->next = new Node{49, nullptr};
    head->next->next = new Node{25, nullptr};
    head->next->next->next = new Node{89, nullptr};

    cout << "Sum of linklist: " << calculate_sum(head) << endl;
     Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}