#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void readFromFile(char* filename, Node*& list1, Node*& list2) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Khong the mo tap tin " << filename << endl;
        return;
    }

    int m, n;
    inputFile >> m >> n;

    for (int i = 0; i < m; i++) {
        int x;
        inputFile >> x;
        insertNode(list1, x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        inputFile >> x;
        insertNode(list2, x);
    }

    inputFile.close();
}

int countPrimes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (isPrime(current->data)) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void sortPrimes(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        if (isPrime(current->data)) {
            Node* nextNode = current->next;
            while (nextNode != nullptr) {
                if (isPrime(nextNode->data) && nextNode->data < current->data) {
                    int temp = current->data;
                    current->data = nextNode->data;
                    nextNode->data = temp;
                }
                nextNode = nextNode->next;
            }
        }
        current = current->next;
    }
}

void SwapList(Node*& list1, Node*& list2) {
    Node* list1PrimeHead = nullptr;
    Node* list1NormalHead = nullptr;
    Node* list2PrimeHead = nullptr;
    Node* list2NormalHead = nullptr;

    Node* temp = list1;
    Node* nextNode;
    while (temp != nullptr) {
        nextNode = temp->next;
        if (isPrime(temp->data)) {
            insertNode(list1PrimeHead, temp->data);
            delete temp;
        } else {
            insertNode(list1NormalHead, temp->data);
        }
        temp = nextNode;
    }
    list1 = list1PrimeHead;

    temp = list2;
    while (temp != nullptr) {
        nextNode = temp->next;
        if (isPrime(temp->data)) {
            insertNode(list2PrimeHead, temp->data);
            delete temp;
        } else {
            insertNode(list2NormalHead, temp->data);
        }
        temp = nextNode;
    }
    list2 = list2PrimeHead;

    temp = list1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = list2NormalHead;

    temp = list2;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = list1NormalHead;
}


void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void WriteFile(char* filename, int m, int n){
    ofstream ofs(filename);
    ofs << m << " " << n << endl;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        ofs << x << " ";
    }
    ofs << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ofs << x << " ";
    }
    ofs << endl;
    ofs.close();
}

int main() {
    char* inputFile = "input.txt";
    ofstream ofs(inputFile);
    int m, n;
    cin >> m;
    cin >> n;
    WriteFile(inputFile,m,n);
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    readFromFile(inputFile, list1, list2);

    printList(list1);
    printList(list2);

    cout << countPrimes(list1) << endl;
    cout << countPrimes(list2) << endl;
    sortPrimes(list1);
    sortPrimes(list2);
    printList(list1);
    printList(list2);
    SwapList(list1, list2);
    printList(list1);
    printList(list2);

    return 0;
}
