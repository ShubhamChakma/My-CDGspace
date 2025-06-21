#include <iostream>
using namespace std;

struct Node {
    int data;            //Defining node
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* rearrangePosi(Node* head) {
    if (!head || !head->next) return head;      // using or gate to check iflist empty or only 1 node
    
    Node* odd = head;          // pointing first node as odd, second node as even, evenhead to remember where second list starting from
    Node* even = head->next;
    Node* evenHead = even;  
    
    while (even && even->next) {
        odd->next = even->next;   
        odd = odd->next;           
        even->next = odd->next;    
        even = even->next;         
    }
    odd->next = evenHead;  //combining odd and even list
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= 6; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    
    cout << "Original list: ";
    printList(head);
    
    head = rearrangePosi(head);
    
    cout << "Rearranged list: ";
    printList(head);
    
    return 0;
}
