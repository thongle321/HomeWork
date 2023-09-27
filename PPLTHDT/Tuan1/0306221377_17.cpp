#include <iostream>
using namespace std;
void nhap(int a[], int n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void TBCsonguyen(int a[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            tong += a[i];
        }
    }
    float tbc = (float)tong / n;
    cout << tbc;
}
int main()
{
    int a[100];
    int n;
    nhap(a, n);
    TBCsonguyen(a, n);
}