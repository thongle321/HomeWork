#include "SoPhuc.h"
#include <iostream>
using namespace std;

int main()
{
    SoPhuc A, B, C;

    cout << "Nhap A:" << endl;
    A.Nhap();

    cout << "Nhap B:" << endl;
    B.Nhap();

    cout << "A: ";
    A.Xuat();

    cout << '\n';

    cout << "B: ";
    B.Xuat();

    cout << '\n';

    C = A.Cong(A, B);
    cout << "Tong hai so phuc: ";
    C.Xuat();

    cout << '\n';

    C = A.Tru(A, B);
    cout << "Hieu hai so phuc: ";
    C.Xuat();

    cout << '\n';

    // Tính tích và thương
    C = A.Nhan(A, B);
    cout << "Tich hai so phuc: ";
    C.Xuat();

    cout << '\n';

    C = A.Chia(A, B);
    cout << "Thuong hai so phuc: ";
    C.Xuat();

    cout << '\n';
    int kq = A.SoSanh(A, B);
    if (kq == 1)
    {
        cout << "bang nhau: ";
        A.Xuat();
        cout << " = ";
        B.Xuat();
    }
    else
    {
        cout << "khong bang: ";
        A.Xuat();
        cout << " != ";
        B.Xuat();
    }
}