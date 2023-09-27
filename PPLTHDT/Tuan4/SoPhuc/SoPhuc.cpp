#include <iostream>
#include "SoPhuc.h"
#include <cmath>
using namespace std;
void SoPhuc::SetPhanThuc(float PhanThuc)
{
    this->a = PhanThuc;
}
void SoPhuc::SetPhanAo(float PhanAo)
{
    this->b = PhanAo;
}
float SoPhuc::GetPhanThuc()
{
    return this->a;
}
float SoPhuc::GetPhanAo()
{
    return this->b;
}
void SoPhuc::Nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> a;
    cout << "Nhap phan ao: ";
    cin >> b;
}
void SoPhuc::Xuat()
{
    cout << a;
    if (b >= 0)
    {
        cout << " + " << b << "i";
    }
    else
    {
        cout << " - " << -b << "i";
    }
}
SoPhuc SoPhuc::Cong(SoPhuc A, SoPhuc B)
{
    SoPhuc sp;
    sp.a = A.a + B.a;
    sp.b = A.b + B.b;
    return sp;
}
// Phương thức tính hiệu số phức
SoPhuc SoPhuc::Tru(SoPhuc A, SoPhuc B)
{
    SoPhuc ps;
    ps.a = A.a - B.a;
    ps.b = A.b - B.b;
    return ps;
}

// Phương thức tính tích số phức
SoPhuc SoPhuc::Nhan(SoPhuc A, SoPhuc B)
{
    SoPhuc ps;
    ps.a = A.a * B.a - A.b * B.b;
    ps.b = A.a * B.b + A.b * B.a;
    return ps;
}

// Phương thức tính thương số phức
SoPhuc SoPhuc::Chia(SoPhuc A, SoPhuc B)
{
    SoPhuc ps;
    float mauso = pow(B.a, 2) + pow(B.b, 2);
    ps.a = (A.a * B.a + A.b * B.b) / mauso;
    ps.b = (A.b * B.a - A.a * B.b) / mauso;
    return ps;
}
int SoPhuc::SoSanh(SoPhuc A, SoPhuc B)
{
    SoPhuc ps;
    ps.a = A.a * A.a + A.b * A.b;
    ps.b = B.a * B.a + B.b * B.b;
    if (a == b)
    {
        return 1; // Bằng nhau
    }
    else
    {
        return 0; // Không bằng nhau
    }
}
