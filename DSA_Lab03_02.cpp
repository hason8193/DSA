#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* CreateList(int n) {
    Node* head = new Node{1, nullptr};
    Node* tail = head;
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node{i, nullptr};
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

pair<Node*, Node*> Search(Node* head, int value) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr && current->value != value) {
        prev = current;
        current = current->next;
    }
    return {prev, current};
}

void MoveToBeginning(Node*& head, Node* prev, Node* current) {
    if (prev != nullptr) {
        prev->next = current->next;
        current->next = head;
        head = current;
    }
}

Node* LastNode(Node* head) {
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    return last;
}

void PrintList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Node* head = CreateList(n);
    for (int i = 0; i < m; i++) {
        int studentId;
        cin >> studentId;
        auto [prev, current] = Search(head, studentId);
        MoveToBeginning(head, prev, current);
    }
    PrintList(head);
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}
