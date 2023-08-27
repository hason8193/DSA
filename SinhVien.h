#include<bits/stdc++.h>
using namespace std;
class SV{
    private:
    char* MSSV;
    char* Hoten;
    char* Ngaysinh;
    char* Gioitinh;
    float Toan;
    float Ly;
    float Hoa;
    float DTB;
    public:
    SV(){
        MSSV = Hoten = Ngaysinh = Gioitinh = NULL;
        Toan = Ly = Hoa = 0;
    };
    void setMSSV(char* MaSV){
        MSSV = MaSV;
    }
    char* getMSSV(){
        return MSSV;
    }
    void setHoten(char* hoten){
        Hoten = hoten;
    }
    char* getHoten(){
        return Hoten;
    }
    void setNgaySinh(char* ngaysinh){
        Ngaysinh = ngaysinh;
    }
    char* getNgaysinh(){
        return Ngaysinh;
    }
    void setGioitinh(char* gioitinh){
        Gioitinh = gioitinh;
    }
    char* getGioitinh(){
        return Gioitinh;
    }
    void setToan(float toan){
        Toan = toan;
    }
    float getToan(){
        return Toan;
    }
    void setLy(float ly){
        Ly = ly;
    }
    float getLy(){
        return Ly;
    }
    void setHoa(float hoa){
        Hoa = hoa;
    }
    float getHoa(){
        return Hoa;
    }
    void setDTB(float dtb){
        DTB = dtb;
    }
    float getDTB(){
        return DTB;
    }
    void Nhap(){
        cout << "Ma so sinh vien:";
        MSSV = new char[20];
        cin.getline(MSSV, 20);
        cout << "Ho ten:";
        Hoten = new char[50];
        cin.getline(Hoten, 50);
        cout << "Ngay Sinh:";
        Ngaysinh = new char[11];
        cin.getline(Ngaysinh, 11);
        cout << "Gioi tinh:";
        Gioitinh = new char[1];
        cin >> Gioitinh;
        cin.ignore();
        cout << "Toan:";
        cin >> Toan;
        cout << "Ly:";
        cin >> Ly;
        cout << "Hoa:";
        cin >> Hoa;
        TinhDTB();
}

void Xuat(){
        cout << "Ma SV: " << MSSV << endl;
        cout << "Ho ten: " << Hoten << endl;
        cout << "Ngay Sinh: " << Ngaysinh << endl;
        cout << "Gioi tinh: " << Gioitinh << endl;
        cout << "Toan: " << Toan << endl;
        cout << "Ly: " << Ly << endl;
        cout << "Hoa: " << Hoa << endl;
        cout << "Diem Trung Binh: " << DTB << endl;
}
void  TinhDTB(){
        DTB = (Toan + Ly + Hoa) / 3;
}
    bool operator < (const SV& sv2) const {
    return DTB < sv2.DTB;
    }
};