#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* CreateLinkedList()
{
    return NULL;
}

Node* CreateNode(int x)
{
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void Traverse(Node* head, ofstream& ofs)
{
    Node* current = head;
    while(current != NULL)
    {
        cout << current->data << " ";
        ofs << current->data << " ";
        current = current->next;
    }
    cout << endl;
    ofs << endl;
}


void insertNode(Node*& head, int x)
{
    Node* p = CreateNode(x);
    if(head == NULL)
        head = p;
    else
    {
        Node* current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = p;
    }
}

Node* searchNode(Node* head, int x)
{
    Node* current = head;
    while(current != NULL)
    {
        if(current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

void deleteNode(Node*& head, int x)
{
    if(head == NULL)
        return;
    if(head->data == x)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* current = head;
    while(current->next != NULL)
    {
        if(current->next->data == x)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else current = current->next;
    }
}

// void swapp(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }

void sortList(Node*& head)
{
    if(head == NULL || head->next == NULL)
        return;
    Node* current = head;
    while(current != NULL)
    {
        Node* nextNode = current->next;
        while(nextNode != NULL)
        {
            if(current->data > nextNode->data)
            {
                swap(current->data, nextNode->data);
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

void buildList(Node*& head, int n, const char* file) {
    int k;
    int* arr = new int[n];
    ofstream ofs;
    ofs.open(file);
    ofs << n << endl;
    for (int i = 0; i < n; i++) {
        cin >> k;
        arr[i] = k;
        ofs << arr[i] << " ";
    }
    ofs.close();
    ifstream ifs;
    ifs.open(file);
    if (ifs.is_open()) {
        ifs >> n;
        for (int i = 0; i < n; i++) {
            ifs >> arr[i];
            insertNode(head, arr[i]);
        }
        ifs.close();
    }
}


int main(){
    const char* inputFile = "data.txt";
    const char* outputFile = "output.txt";
    int n,k,x1,x2;
    cin >> n;
    Node* List = CreateLinkedList();
    buildList(List,n,inputFile);
    ofstream ofs(outputFile);
    cout << "In danh sach:";
    Traverse(List,ofs);
    cout << "Nhap phan tu can tim:";
    cin >> x1;
    Node* searchN = searchNode(List, x1);
    if(searchN != NULL) cout << "Tim thay phan tu" << endl;
    else cout << "Khong tim thay phan tu" << endl;
    cout << "Nhap phan tu muon xoa:";
    cin >> x2;
    deleteNode(List,x2);
    cout << "Danh sach sau khi xoa phan tu:";
    Traverse(List,ofs);
    sortList(List);
    cout << "Danh sach sau khi sap xep:";
    Traverse(List,ofs);
    ofs.close();
    return 0;
}
