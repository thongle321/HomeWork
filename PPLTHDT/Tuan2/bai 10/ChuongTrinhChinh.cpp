#include <iostream>
#include "Diem.h"
#include "TamGiac.h"
using namespace std;
int main()
{
    TamGiac tamgiac;
    cout << "Nhap tam giac:\n";
    nhaptamgiac(tamgiac);

    cout << "Tam giac vua nhap:\n";
    xuattamgiac(tamgiac);

    float DienTich = dientichtamgiac(tamgiac);
    cout << "Dien tich tam giac: " << DienTich << "\n";

    Diem TrongTam = trongtamtamgiac(tamgiac);
    cout << "Toa do trung tam: ";
    xuatdiem(TrongTam);
    return 0;
}
