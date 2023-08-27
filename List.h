#include<bits/stdc++.h>
#include"SinhVien.h"
using namespace std;
typedef struct tagNode{
    SV Info;
    struct tagNode* pNext;
}Node;
typedef struct List{
    Node* pHead;
    Node* pTail;
}LIST;
Node* CreateNode(SV x){
    Node *p;
    p = new Node;
    if ( p == NULL) exit(1);
    p ->Info = x;
    p->pNext = NULL;
    return p;
}
void CreateList(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
void AddHead(LIST &l, Node* p){
    if (l.pHead==NULL){
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void Input(LIST& l, char* fileName){
    ifstream file(fileName);
    if (!file){
        cout << "Khong the mo file!\n";
        return;
    }

    string line;
    while(getline(file, line)){
        char* cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());

        char* token = strtok(cstr, ",");
        SV sv;
        sv.setMSSV(token);

        token = strtok(NULL, ",");
        sv.setHoten(token);

        token = strtok(NULL, ",");
        sv.setNgaySinh(token);

        token = strtok(NULL, ",");
        sv.setGioitinh(token);

        token = strtok(NULL, ",");
        sv.setToan(stof(token));

        token = strtok(NULL, ",");
        sv.setLy(stof(token));

        token = strtok(NULL, ",");
        sv.setHoa(stof(token));

        Node* p = CreateNode(sv);
        AddHead(l, p);

        delete[] cstr;
    }

    file.close();
}

void Output(LIST& l, char* fileName){
    ofstream file(fileName);
    if (!file){
        cout << "Khong the mo file!\n";
        return;
    }

    Node* p = l.pHead;
    while(p != NULL){
        file << p->Info.getMSSV() << ","
             << p->Info.getHoten() << ","
             << p->Info.getNgaysinh() << ","
             << p->Info.getGioitinh() << ","
             << p->Info.getToan() << ","
             << p->Info.getLy() << ","
             << p->Info.getHoa() << ","
             << p->Info.getDTB() << endl;
        p = p->pNext;
    }

    file.close();
}
void Sort(LIST& l){
    Node *p, *q, *min;
    p = l.pHead;
    while (p != l.pTail)
    {
        min = p;
        q = p->pNext;
    }
    while (q != NULL)
    {
        if (q->Info <  p->Info)
        min = q;
        q = q->pNext;
    }
    swap(min->Info, p->Info);
    p = p->pNext;
}
