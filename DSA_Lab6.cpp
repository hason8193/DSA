#include <iostream>
#include <fstream>
#include <queue>
#include<cstdlib>
#include<math.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->value) {
        insert(root->left, val);
    }
    else {
        insert(root->right, val);
    }
}

void buildTree(TreeNode*& root, int n, const char* inputFile) {
    int* arr = new int[n];
    int k;
    ofstream ofs;
    ofs.open(inputFile);
    for(int i = 0; i < n; i++){
        cin >> k;
        arr[i] = k;
        ofs << arr[i] << " ";
    }
    ofs.close();
    ifstream ifs;
    ifs.open(inputFile);
    if (ifs.is_open()){
        for(int i = 0; i < n; i++){
            ifs >> arr[i];
            insert(root,arr[i]);
        }
        ifs.close();
    }
}

void In_thu_tu(TreeNode* root) {
    if (root) {
        In_thu_tu(root->left);
        cout << root->value << " ";
        In_thu_tu(root->right);
    }
}

bool search(TreeNode* root, int val) {
    if (!root) {
        return false;
    }
    if (root->value == val) {
        return true;
    }
    if (val < root->value) {
        return search(root->left, val);
    }
    else {
        return search(root->right, val);
    }
}

TreeNode* tim_MinNode(TreeNode* root) {
    if (!root->left) {
        return root;
    }
    return tim_MinNode(root->left);
}

void deleteNode(TreeNode*& root, int val) {
    if (!root) {
        return;
    }
    if (val < root->value) {
        deleteNode(root->left, val);
    }
    else if (val > root->value) {
        deleteNode(root->right, val);
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        }
        else if (!root->left) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            TreeNode* minRight = tim_MinNode(root->right);
            root->value = minRight->value;
            deleteNode(root->right, minRight->value);
        }
    }
}

int get_H(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int leftHeight = get_H(root->left);
    int rightHeight = get_H(root->right);
    return 1 + max(leftHeight, rightHeight);
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void SNT(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root); 
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop(); 
        if (isPrime(current->value)) {
            cout << current->value << " "; 
        }
        if (current->left != nullptr) {
            q.push(current->left); 
        }
        if (current->right != nullptr) {
            q.push(current->right); 
        }
    }
}

void In_Cay(TreeNode* root){
    if(root == nullptr){
        return;
    }
    In_Cay(root->left);
    cout << root->value << " ";
    In_Cay(root->right);
}

int main() {
    const char* inputFile = "input.txt";
    int n;
    cout << "Nhap n:";
    cin >> n;
    TreeNode* root = nullptr;
    buildTree(root, n, inputFile);
    cout << "Tao cay nhi phan:";
    In_Cay(root);
    cout << endl;
    cout << "In thu tu cay nhi phan: ";
    In_thu_tu(root);
    cout << endl;
    int valToSearch;
    cout << "Nhap 1 gi tri de tim trong cay: ";
    cin >> valToSearch;
    if (search(root, valToSearch)) {
        cout << valToSearch << " o trong cay." << endl;
    }
    else {
        cout << valToSearch << " khong co trong cay." << endl;
    }
    int valToDelete;
    cout << "Nhap 1 gia tri de xoa: ";
    cin >> valToDelete;
    deleteNode(root, valToDelete);
    cout << "Cay nhi phan sau khi xoa gia tri do:";
    In_Cay(root);
    cout << endl;
    int height = get_H(root);
    cout << "Chieu cao cua cay: " << height << endl;
    cout << "Cac so nguyen to cua cay: ";
    SNT(root);
    cout << endl;
    return 0;
}