#include <iostream>
using namespace std;

void VTGiaTriDuongNhoNhat(float a[], int n)
{
    // Tìm giá trị dương nhỏ nhất trong mảng
    float min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] < min)
        {
            min = a[i];
        }
    }

    // Liệt kê các vị trí có giá trị bằng giá trị dương nhỏ nhất
    for (int i = 0; i < n; i++)
    {
        if (a[i] == min)
        {
            cout << "vi tri " << i << endl;
        }
    }
}
void nhap(float a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    float a[100];
    int n;
    nhap(a, n);
    cout << "cac vi tri co gia tri bang gia tri duong nho nhat trong mang la: " << endl;
    VTGiaTriDuongNhoNhat(a, n);

    return 0;
}