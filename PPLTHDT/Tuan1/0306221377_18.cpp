#include <iostream>
using namespace std;
void nhap(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int DemSoChuSo5(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 10 == 5)
        {
            dem++;
        }
    }
    return dem;
}
int main()
{
    int a[100];
    int n;
    nhap(a, n);
    DemSoChuSo5(a, n);
    int kq = DemSoChuSo5(a, n);
    cout << kq;
}
