#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    string ngaySinh;
    char gioiTinh;
    double diemToan;
    double diemLy;
    double diemHoa;
    double diemTrungBinh;
};

double tinhDiemTrungBinh(double diemToan, double diemLy, double diemHoa) {
    return (diemToan + diemLy + diemHoa) / 3;
}

void nhapSinhVien(SinhVien& sv) {
    cin.ignore(); 
    getline(cin, sv.maSV);
    getline(cin, sv.hoTen);
    getline(cin, sv.ngaySinh);
    cin >> sv.gioiTinh;
    cin >> sv.diemToan;
    cin >> sv.diemLy;
    cin >> sv.diemHoa;
    sv.diemTrungBinh = tinhDiemTrungBinh(sv.diemToan, sv.diemLy, sv.diemHoa);
}

void xuatSinhVien(const SinhVien& sv) {
    cout << sv.maSV << "\t" << sv.hoTen << "\t" << sv.ngaySinh << "\t" << sv.gioiTinh << "\t" << sv.diemToan << "\t" << sv.diemLy << "\t" << sv.diemHoa << "\t" << fixed << setprecision(2) << sv.diemTrungBinh << endl;
}

int main() {
    int n;
    cin >> n;
    SinhVien dsSV[100];
    for (int i = 0; i < n; i++) {
        nhapSinhVien(dsSV[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsSV[i].maSV < dsSV[j].maSV) {
                SinhVien temp = dsSV[i];
                dsSV[i] = dsSV[j];
                dsSV[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        xuatSinhVien(dsSV[i]);
    }
    return 0;
}
