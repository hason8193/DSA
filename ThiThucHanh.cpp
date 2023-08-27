#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* CreateTree(){
    return NULL;
}

Node* CreateNode(int x){
    Node* temp = new Node;
    temp->key = x;
    temp->left = temp->right = NULL;
    return temp;
}

void InsertNode(Node*& root, int x){
    if(root == NULL) root = CreateNode(x);
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

void PrintTang(Node* root, ofstream& ofs){
    if(root == NULL) return;
    else if(root != NULL){
        PrintTang(root->left, ofs);
        cout << root->key << " ";
        ofs << root->key << " ";
        PrintTang(root->right,ofs);
    }
}

void PrintGiam(Node* root, ofstream& ofs){
    if(root == NULL) return;
    else if(root != NULL){
        PrintGiam(root->right, ofs);
        cout << root->key << " ";
        ofs << root->key << " ";
        PrintGiam(root->left,ofs);
    }
}

void PrintLeTang(Node* root, ofstream& ofs){
    if(root == NULL) return;
    else if (root->left == NULL && root->right == NULL && root->key % 2 != 0) {
        cout << root->key << " ";
        ofs << root->key << " ";
    }
    PrintLeTang(root->left, ofs);
    PrintLeTang(root->right,ofs);
}

int DemNode(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + DemNode(root->left) + DemNode(root->right);
}

void PrintCanBang(Node* root, ofstream& ofs) {
    if (root == nullptr)
        return;
    int leftCount = DemNode(root->left);
    int rightCount = DemNode(root->right);

    if (leftCount == rightCount){
        cout << root->key << " ";
        ofs << root->key << " ";
    }
    PrintCanBang(root->left, ofs);
    PrintCanBang(root->right, ofs);
}

void InTang(Node* root, int level, ofstream& ofs){
    if(root == NULL) return;
    InTang(root->left, level+1, ofs);
    cout << level << " ";
    ofs << level << " ";
    InTang(root->right, level+1, ofs);
}

int main(){
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";
    Node* root = CreateTree();
    BuildTree(root, inputFile);
    ofstream ofs(outputFile);
    PrintTang(root, ofs);
    cout << endl;
    ofs << endl;
    PrintGiam(root, ofs);
    cout << endl;
    ofs << endl;
    PrintLeTang(root, ofs);
    cout << endl;
    ofs << endl;
    PrintCanBang(root, ofs);
    cout << endl;
    ofs << endl;
    InTang(root, 0, ofs);
    return 0;
}