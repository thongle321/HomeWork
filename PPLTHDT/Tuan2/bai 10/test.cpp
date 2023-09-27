#include <iostream>
#include <cmath>

// Khai báo kiểu cấu trúc Diem
struct Diem
{
    double x;
    double y;
};

// Khai báo kiểu cấu trúc Tam Giác
struct TamGiac
{
    Diem A;
    Diem B;
    Diem C;
};

// Hàm nhập điểm (đỉnh)
void NhapDiem(Diem &D)
{
    std::cout << "Nhap toa do x: ";
    std::cin >> D.x;
    std::cout << "Nhap toa do y: ";
    std::cin >> D.y;
}

// Hàm xuất điểm
void XuatDiem(const Diem &D)
{
    std::cout << "(" << D.x << ", " << D.y << ")";
}

// Hàm tính khoảng cách giữa 2 điểm
double TinhKhoangCach(const Diem &D1, const Diem &D2)
{
    return sqrt(pow(D2.x - D1.x, 2) + pow(D2.y - D1.y, 2));
}

// Hàm nhập tam giác
void NhapTamGiac(TamGiac &TG)
{
    std::cout << "Nhap diem A:\n";
    NhapDiem(TG.A);

    std::cout << "Nhap diem B:\n";
    NhapDiem(TG.B);

    std::cout << "Nhap diem C:\n";
    NhapDiem(TG.C);
}

// Hàm xuất tam giác
void XuatTamGiac(const TamGiac &TG)
{
    std::cout << "Tam giac co cac dinh:\n";
    std::cout << "A ";
    XuatDiem(TG.A);
    std::cout << "\nB ";
    XuatDiem(TG.B);
    std::cout << "\nC ";
    XuatDiem(TG.C);
    std::cout << std::endl;
}

// Hàm tính diện tích tam giác sử dụng công thức Heron
double TinhDienTich(const TamGiac &TG)
{
    double a = TinhKhoangCach(TG.B, TG.C);
    double b = TinhKhoangCach(TG.C, TG.A);
    double c = TinhKhoangCach(TG.A, TG.B);
    double p = (a + b + c) / 2; // Nửa chu vi

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Hàm tính trọng tâm của tam giác
Diem TinhTrongTam(const TamGiac &TG)
{
    Diem TrongTam;
    TrongTam.x = (TG.A.x + TG.B.x + TG.C.x) / 3;
    TrongTam.y = (TG.A.y + TG.B.y + TG.C.y) / 3;
    return TrongTam;
}

int main()
{
    TamGiac tamGiac;

    // Nhập tam giác
    NhapTamGiac(tamGiac);

    // Xuất tam giác
    XuatTamGiac(tamGiac);

    // Tính và xuất diện tích tam giác
    double dienTich = TinhDienTich(tamGiac);
    std::cout << "Dien tich tam giac: " << dienTich << std::endl;

    // Tính và xuất trọng tâm tam giác
    Diem trongTam = TinhTrongTam(tamGiac);
    std::cout << "Trong tam tam giac: ";
    XuatDiem(trongTam);
    std::cout << std::endl;

    return 0;
}
