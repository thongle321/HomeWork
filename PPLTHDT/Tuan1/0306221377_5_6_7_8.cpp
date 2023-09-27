#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int chon;
    int n;
    cout << "1";
    cout << "2";
    cout << "3";
    cout << "4";
    switch (chon)
    {
    case 1:
        cout << "nhap n";
        cin >> n;
        float s = 0;
        for (int i = 0; i <= n; i++)
        {
            s += 1.0 / i;
        }
        cout << s;
        break;
    case 2:
        cout << "Nhap n: ";
        cin >> n;
        float s = 1;
        for (int i = 1; i <= n; i++)
        {
            s *= (2 * i - 1) / (2 * i);
        }
        cout << s;
        break;
    case 3:
        cout << "Nhap n: ";
        cin >> n;

        float p = sqrt(n);
        for (int i = 2; i <= n; i++)
        {
            p = sqrt(i + p);
        }
        cout << p;
        break;
    case 4:
        int n;
        cout << "Nhap n: ";
        cin >> n;
        float p = sqrt(1);
        for (int i = 2; i <= n; i++)
        {
            p = sqrt(i + p);
        }

        cout << p;
        break;
    default:
        break;
    }
}
