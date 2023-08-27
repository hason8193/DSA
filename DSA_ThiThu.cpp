#include<iostream>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<queue>

using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): value(val), left(nullptr), right(nullptr){}
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

void buildTree(TreeNode*& root, int n, const char* file) {
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
            insert(root,arr[i]);
        }
        ifs.close();
    }
}

void In_thu_tu(TreeNode* root) {
    if (root) {
        In_thu_tu(root->right);
        cout << root->value << " ";
        In_thu_tu(root->left);
    }
}

void In_thu_tu_F(TreeNode* root, ofstream& ofs) {
    if (root) {
        In_thu_tu_F(root->right, ofs);
        ofs << root->value << " ";
        In_thu_tu_F(root->left, ofs);
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
    int k=0;
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root); 
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop(); 
        if (isPrime(current->value)) {
            k++;
        }
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << k;
}

void SNT_F(TreeNode* root, ofstream& ofs) {
    int k = 0;
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root); 
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop(); 
        if (isPrime(current->value)) {
            k++;
        }
        if (current->left != nullptr) {
            q.push(current->left); 
        }
        if (current->right != nullptr) {
            q.push(current->right); 
        }
    }
    ofs << k;
}

void inDuyet(TreeNode* root, int h) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->value << endl;

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }

        level++;
        if (level == h) break; 
    }
}

void inDuyet_F(TreeNode* root, int h, ofstream& ofs) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            ofs << node->value << endl;

            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }

        level++;
        if (level == h) break; 
    }
}

int main(){
    const char* inputFile = "data.txt";
    const char* outputFile = "output.txt";
    int n;
    cin >> n;
    TreeNode* root = nullptr;
    buildTree(root, n, inputFile);
    ofstream ofs(outputFile);
    In_thu_tu(root);
    cout << endl;
    In_thu_tu_F(root,ofs);
    ofs << endl;
    int height = get_H(root);
    cout << "Chieu cao cua cay: " << height << endl;
    ofs << height << endl;
    cout << "Tong so nguyen tren cay: ";
    SNT(root);
    cout << endl;
    SNT_F(root, ofs);
    ofs << endl;
    cout << "In cac nut tren cay theo thu tu de cho:" << endl;
    inDuyet(root, height);
    inDuyet_F(root,height,ofs);
    ofs.close();
}