#include <iostream>
using namespace std;
bool mangtangdan(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                return false;
        }
    }
    return true;
}
void nhapmang(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    int a[100];
    int n;
    nhapmang(a, n);
    if (mangtangdan(a, n))
    {
        cout << "tang dan";
    }
    else
    {
        cout << "giam dan";
    }
    return 0;
}