#include <iostream>
using namespace std;
bool SNT(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void nhap(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void TongSNT(int a[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (SNT(a[i]) == true)
        {
            tong += a[i];
        }
    }
    cout << tong;
}
int main()
{
    int a[100];
    int n;
    nhap(a, n);
    TongSNT(a, n);
}