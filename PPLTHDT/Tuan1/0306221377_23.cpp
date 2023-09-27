#include <iostream>
using namespace std;
void mangtangdan(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
void nhapmang(float a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void xuatmang(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    float a[100];
    int n;
    nhapmang(a, n);
    mangtangdan(a, n);
    xuatmang(a, n);
    return 0;
}