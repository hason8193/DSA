#include<iostream>
#include<algorithm>
#include<fstream>
#include<queue>

using namespace std;

struct Node
{
    int key;
    Node* right;
    Node* left;
};

Node* CreateEmptyTree()
{
    return nullptr;
}

Node* CreateNode(int key)
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* InsertNode(Node*& root, int key)
{
    if(root == nullptr)
    {
        root = CreateNode(key);
    }
    if (key < root->key)
    {
        root->left = InsertNode(root->left,key);
    }
    else if (key > root->key)
    {
        root->right = InsertNode(root->right,key);
    }
    return root;
}

void buildTree(Node*& root, int n, const char* file) {
    int* arr = new int[n];
    int k;
    ofstream ofs;
    ofs.open(file);
    ofs << n << endl;
    for(int i = 0; i < n; i++){
        cin >> k;
        arr[i] = k;
        ofs << arr[i] << " ";
    }
    ofs.close();
    ifstream ifs;
    ifs.open(file);
    if (ifs.is_open()){
        ifs >> n;
        for(int i = 0; i < n; i++){
            ifs >> arr[i];
            InsertNode(root,arr[i]);
        }
        ifs.close();
    }
}

bool SearchNode(Node* root, int key)
{
    if(root == nullptr || root->key == key)
    {
        return root != nullptr;
    }
    if(key < root->key)
    {
        return SearchNode(root->left, key);
    }
    return SearchNode(root->right, key);
}

Node* deleteNode(Node*& root, int key) {
    if (root == nullptr) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* minValueNode = root->right;
        while (minValueNode->left != nullptr) {
            minValueNode = minValueNode->left;
        }
        root->key = minValueNode->key;
        root->right = deleteNode(root->right, minValueNode->key);
    }
    return root;
}

int getHeight(Node* root, ofstream& ofs) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(root->left, ofs);
    int rightHeight = getHeight(root->right, ofs);
    return 1 + max(leftHeight, rightHeight);
}

void printTreeInOrder(Node* root, ofstream& ofs) {
    if (root != nullptr) {
        printTreeInOrder(root->left, ofs);
        cout << root->key << " ";
        ofs << root->key << " ";
        printTreeInOrder(root->right, ofs);
    }
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int count = 0;
    if (isPrime(root->key)) {
        count++;
    }
    count += countPrimes(root->left);
    count += countPrimes(root->right);
    return count;
}


void printNodesByLevel(Node* root, int level, ofstream& ofs) {
    if (root == nullptr) {
        return;
    }
    if (level == 0) {
        cout << root->key << " ";
        ofs << root->key << " ";
    }
    else if (level > 0) {
        printNodesByLevel(root->left, level - 1,ofs);
        printNodesByLevel(root->right, level - 1,ofs);
    }
}

int main()
{
    const char* inputFile = "data.txt";
    const char* outputFile = "output.txt";
    Node* root = CreateEmptyTree();
    int n,k;
    cin >> n;
    buildTree(root, n, inputFile);
    ofstream ofs(outputFile);
    cout << "In cay theo thu tu: ";
    printTreeInOrder(root,ofs);
    cout << endl;
    ofs << endl;
    int f;
    cout << "Nhap gia tri muon tim tren cay: ";
    cin >> f;
    if (SearchNode(root, f)) {
        cout << "Node co gia tri " << f << " duoc tim thay tren cay." << endl;
    }
    else {
        cout << "Node co gia tri " << f << " khong duoc tim thay tren cay." << endl;
    }
    int d;
    cout << "Nhap gia tri muon xoa tren cay: ";
    cin >> d;
    root = deleteNode(root, d);
    cout << "Cay sau khi xoa node: " << d << ": ";
    printTreeInOrder(root,ofs);
    cout << endl;
    ofs << endl;
    int h = getHeight(root,ofs);
    cout << "Chieu cao cay: " << h << endl;
    ofs << h << endl;
    int primeCount = countPrimes(root);
    cout << "So so nguyen to tren cay: " << primeCount << endl;
    ofs << primeCount << endl;
    cout << "Node theo thu tu: ";
    for (int i = 0; i < h; i++) {
        printNodesByLevel(root, i,ofs);
    }
    cout << endl;
    ofs << endl;
    ofs.close();
    return 0;
}
