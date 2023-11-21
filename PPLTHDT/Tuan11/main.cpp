#include <iostream>
#include "hinh.h"
using namespace std;
int main()
{
    int chon = 0;
    Hinh *h = NULL;
    do
    {
        cout << "1. Hinh Chu Nhat" << endl;
        cout << "2. Hinh Vuong" << endl;
        cout << "3. HInh Tam Giac" << endl;
        cout << "4. Hinh Tam Giac Deu" << endl;
        cout << "5. Hinh Tam Giac Vuong" << endl;
        cout << "6. Hinh Tron" << endl;
        cout << "7. Thoat" << endl;
        cout << "Chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
        {
            float chieudai, chieurong;
            cout << "Nhap chieu dai: ";
            cin >> chieudai;
            cout << "Nhap chieu rong: ";
            cin >> chieurong;
            h = new ChuNhat(chieudai, chieurong);
            break;
        }
        case 2:
        {
            float canh;
            cout << "Nhap canh: ";
            cin >> canh;
            h = new HinhVuong(canh);
            break;
        }
        case 3:
        {
            float a, b, c;
            cout << "Nhap canh a: ";
            cin >> a;
            cout << "Nhap canh b: ";
            cin >> b;
            cout << "Nhap canh c: ";
            cin >> c;
            h = new TamGiac(a, b, c);
            break;
        }
        case 4:
        {
            float a;
            cout << "Nhap canh: ";
            cin >> a;
            h = new TamGiacDeu(a);
            break;
        }
        case 5:
        {
            float a, b, c;
            cout << "Nhap canh a: ";
            cin >> a;
            cout << "Nhap canh b: ";
            cin >> b;
            h = new TamGiacVuong(a, b);
            break;
        }
        case 6:
        {
            float r;
            cout << "Nhap ban kinh: ";
            cin >> r;
            h = new Tron(r);
            break;
        }
        case 7:
            break;
        default:
            break;
        }
        if (chon != 0 || chon != 7)
        {
            if (h != nullptr)
            {
                cout << "Chu vi: " << h->ChuVi() << endl;
                cout << "Dien Tich: " << h->DienTich() << endl;
            }
            else
            {
                break;
            }
        }
        delete h;
    } while (chon != 7);
    return 0;
}
