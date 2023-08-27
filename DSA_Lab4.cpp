#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int mssv;
    string ten;
    float dtb;
    SinhVien* next;
};

void themSinhVien(SinhVien*& head, int mssv, string ten, float dtb) {
    SinhVien* newSV = new SinhVien;
    newSV->mssv = mssv;
    newSV->ten = ten;
    newSV->dtb = dtb;
    newSV->next = head;
    head = newSV;
}

bool timSinhVien(SinhVien* head, int mssv) {
    SinhVien* current = head;
    while (current != NULL) {
        if (current->mssv == mssv) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void xoaSinhVien(SinhVien*& head, int x) {
    SinhVien* current = head;
    SinhVien* previous = NULL;
    while (current != NULL) {
        if (current->mssv == x) {
            if (previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void inSinhVien(SinhVien* head){
    SinhVien* current = head;
    while(current != nullptr){
        cout << current->mssv << "\t" << current->ten << "\t" << current->dtb << endl;
        current = current->next; 
    }
}

void lietKeSV(SinhVien* head) {
    SinhVien* current = head;
    while (current != NULL) {
        if (current->dtb >= 5.0) {
            cout << current->mssv << "\t" << current->ten << "\t" << current->dtb << endl;
        }
        current = current->next;
    }
}

void xepLoai(SinhVien* head){
    SinhVien* current = head;
    while(current != nullptr)
    {
        if (head->dtb <= 3.6) {
            cout << "Loai yeu";
        }
        else if (head->dtb >= 5.0 && head->dtb < 6.5) {
            cout << "Loai trung binh";
        }
        else if (head->dtb >= 6.5 && head->dtb < 7.0) {
            cout << "Loai trung binh kha";
        }
        else if (head->dtb >= 7.0 && head->dtb < 8.0) {
            cout << "Loai kha";
        }
        else if (head->dtb >= 8.0 && head->dtb < 9.0) {
            cout << "Loai gioi";
        }
        else {
            cout << "Loai xuat sac";
        }
        current = current->next;
    }
}

void sapXep(SinhVien *&head) {
    SinhVien *p, *q, *r;
    r = NULL;
    while (head != r) {
        p = head;
        while (p->next != r) {
            q = p->next;
            if (p->dtb > q->dtb) {
                SinhVien *temp = new SinhVien;
                temp->mssv = p->mssv;
                temp->ten = p->ten;
                temp->dtb = p->dtb;
                p->mssv = q->mssv;
                p->ten = q->ten;
                p->dtb = q->dtb;
                q->mssv = temp->mssv;
                q->ten = temp->ten;
                q->dtb = temp->dtb;
                delete temp;
            }
            p = p->next;
        }
        r = p;
    }
}

void chenSinhVien(SinhVien *&head) {
    SinhVien *newNode = new SinhVien;

    cout << "Nhap mssv: ";
    cin >> newNode->mssv;
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, newNode->ten);
    cout << "Nhap dtb: ";
    cin >> newNode->dtb;

    SinhVien *prev = NULL;
    SinhVien *cur = head;
    while (cur != NULL && cur->dtb < newNode->dtb) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}


int main() {
    SinhVien* danhSach = NULL; 
    int mssv;
    string ten;
    float dtb;

    do {
        cout << "Nhap ma so sinh vien: ";
        cin >> mssv;
        cout << "Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, ten);
        if(ten == "") break;
        cout << "Nhap diem trung binh: ";
        cin >> dtb;
        themSinhVien(danhSach, mssv, ten, dtb);
    } while (ten != "");

    cout << "Nhap ma so sinh vien can tim: ";
    cin >> mssv;
    if (timSinhVien(danhSach, mssv)) {
        cout << "Sinh vien co ma so " << mssv << " co trong lop." << endl;
    }
    else cout << "Sinh vien co ma so " << mssv << " khong co trong lop." << endl;
    cout << "Nhap mssv cua sinh vien can xoa:";
    int x;
    cin >> x;
    xoaSinhVien(danhSach, x);
    cout << "Danh sach sau khi xoa sinh vien do:" << endl;
    inSinhVien(danhSach);
    cout << "Nhung sinh vien co diem trung binh lon hon hoac bang 5 la:" << endl;
    lietKeSV(danhSach);
    cout << "Xep loai sinh vien:" << endl;
    xepLoai(danhSach);
    cout << endl;
    cout << "Sap xep va in ra danh sach sinh vien tang theo dtb:" << endl;
    sapXep(danhSach);
    inSinhVien(danhSach);
    cout << endl;
    cout << "Chen sinh vien moi:" << endl;
    chenSinhVien(danhSach);
    cout << "Danh sach sinh vien sau khi chen sinh vien moi la:" << endl;
    inSinhVien(danhSach);
}
