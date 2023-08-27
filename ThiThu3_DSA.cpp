#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* CreateTree(){
    return nullptr;
}

Node* CreateNode(int x){
    Node* temp = new Node;
    temp->key = x;
    temp->left = temp->right = nullptr;
    return temp;
}

void InsertNode(Node*& root, int x){
    if(root == nullptr) root = CreateNode(x);
    if (x < root->key){
        InsertNode(root->left,x);
    }
    else if (x > root->key){
        InsertNode(root->right,x);
    }
}

void BuildTree(Node*& root, const char* file){
    int n;
    int* arr = new int[n];
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

void PrintTree(Node* root, ofstream& ofs){
    if(root != nullptr){
        PrintTree(root->left, ofs);
        cout << root->key << " ";
        ofs << root->key << " ";
        PrintTree(root->right,ofs);
    }
}

int chieuCaoTree(Node* root){
    if(root == nullptr) return 0;
    int a = chieuCaoTree(root->right);
    int b = chieuCaoTree(root->left);
    return 1 + max(a,b);
}

int chieuCaoRight(Node* root){
    if(root == nullptr) return 0;
    return chieuCaoTree(root->right);
}

bool soCP(int n){
    if(sqrt(n) * sqrt(n) == n) return 1;
    return 0;
}

int soCPTree(Node* root){
    int sum = 0;
    if(root == nullptr) return 0;
    if(soCP(root->key)) sum += root->key;
    sum += soCPTree(root->right);
    return sum;
}

void InTheoTang(Node* root, int h, ofstream& ofs){
    Node* temp = root;
    if(root == nullptr) return;
    if(h == 0){
        cout << root->key << " ";
        ofs << root->key << " ";
    }
    else if (h > 0){
        InTheoTang(root->left, h-1, ofs);
        InTheoTang(root->right, h-1, ofs);
    }
}

int main(){
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    Node* root = CreateTree();
    BuildTree(root, inputFile);
    ofstream ofs(outputFile);
    cout << "Cau 2: ";
    PrintTree(root, ofs);
    cout << endl;
    ofs << endl;
    cout << "Cau 3: ";
    cout << chieuCaoRight(root) << endl;
    ofs << chieuCaoRight(root) << endl;
    cout << "Cau 4: ";
    cout << soCPTree(root) << endl;
    ofs << soCPTree(root) << endl;
    cout << "Cau 5:" << endl;
    int height = chieuCaoTree(root);
    for(int i = 0; i < height; i++){
        InTheoTang(root,i,ofs);
        cout << endl;
        ofs << endl;
    }
    ofs.close();
}